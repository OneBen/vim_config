// RUN: %clang_cc1 -verify -fopenmp -x c++ -triple x86_64-unknown-unknown -emit-llvm %s -fexceptions -fcxx-exceptions -o - | FileCheck %s
// RUN: %clang_cc1 -fopenmp -x c++ -std=c++11 -triple x86_64-unknown-unknown -fexceptions -fcxx-exceptions -emit-pch -o %t %s
// RUN: %clang_cc1 -fopenmp -x c++ -triple x86_64-unknown-unknown -fexceptions -fcxx-exceptions -std=c++11 -include-pch %t -verify %s -emit-llvm -o - | FileCheck %s
// expected-no-diagnostics

#ifndef HEADER
#define HEADER

// CHECK: [[KMP_DIM:%.+]] = type { i64, i64, i64 }
extern int n;
int a[10], b[10], c[10], d[10];
void foo();

// CHECK-LABEL: @main()
int main() {
  int i;
// CHECK: [[DIMS:%.+]] = alloca [[KMP_DIM]],
// CHECK: [[GTID:%.+]] = call i32 @__kmpc_global_thread_num([[IDENT:%.+]])
// CHECK: icmp
// CHECK-NEXT: br i1 %
// CHECK: [[CAST:%.+]] = bitcast [[KMP_DIM]]* [[DIMS]] to i8*
// CHECK: call void @llvm.memset.p0i8.i64(i8* [[CAST]], i8 0, i64 24, i32 8, i1 false)
// CHECK: getelementptr inbounds [[KMP_DIM]], [[KMP_DIM]]* [[DIMS]], i32 0, i32 1
// CHECK: store i64 %{{.+}}, i64* %
// CHECK: getelementptr inbounds [[KMP_DIM]], [[KMP_DIM]]* [[DIMS]], i32 0, i32 2
// CHECK: store i64 1, i64* %
// CHECK: [[CAST:%.+]] = bitcast [[KMP_DIM]]* [[DIMS]] to i8*
// CHECK: call void @__kmpc_doacross_init([[IDENT]], i32 [[GTID]], i32 1, i8* [[CAST]])
// CHECK: call void @__kmpc_for_static_init_4(
#pragma omp for ordered(1)
  for (i = 0; i < n; ++i) {
    a[i] = b[i] + 1;
    foo();
// CHECK: invoke void [[FOO:.+]](
// CHECK: load i32, i32* [[CNT:%.+]],
// CHECK-NEXT: sext i32 %{{.+}} to i64
// CHECK-NEXT: store i64 %{{.+}}, i64* [[TMP:%.+]],
// CHECK-NEXT: call void @__kmpc_doacross_post([[IDENT]], i32 [[GTID]], i64* [[TMP]])
#pragma omp ordered depend(source)
    c[i] = c[i] + 1;
    foo();
// CHECK: invoke void [[FOO]]
// CHECK: load i32, i32* [[CNT]],
// CHECK-NEXT: sub nsw i32 %{{.+}}, 2
// CHECK-NEXT: sext i32 %{{.+}} to i64
// CHECK-NEXT: store i64 %{{.+}}, i64* [[TMP:%.+]],
// CHECK-NEXT: call void @__kmpc_doacross_wait([[IDENT]], i32 [[GTID]], i64* [[TMP]])
#pragma omp ordered depend(sink : i - 2)
    d[i] = a[i - 2];
  }
  // CHECK: landingpad
  // CHECK: call void @__kmpc_doacross_fini([[IDENT]], i32 [[GTID]])
  // CHECK: br label %

  // CHECK: call void @__kmpc_for_static_fini(
  // CHECK: call void @__kmpc_doacross_fini([[IDENT]], i32 [[GTID]])
  // CHECK: ret i32 0
  return 0;
}

// CHECK: define {{.+}}TestStruct
template <typename T>
struct TestStruct {
  static const int M = 10;
  static const int N = 20;
  T i;
  T a[N][M];
  T b[N][M];
  T foo(T, T);
  T bar(T, T, T);
  void baz(T, T);
  TestStruct() {
// CHECK: [[CNT:%.+]] = alloca i64,
// CHECK: [[DIMS:%.+]] = alloca [[KMP_DIM]],
// CHECK: [[GTID:%.+]] = call i32 @__kmpc_global_thread_num([[IDENT:%.+]])
// CHECK: icmp
// CHECK-NEXT: br i1 %
// CHECK: [[CAST:%.+]] = bitcast [[KMP_DIM]]* [[DIMS]] to i8*
// CHECK: call void @llvm.memset.p0i8.i64(i8* [[CAST]], i8 0, i64 24, i32 8, i1 false)
// CHECK: getelementptr inbounds [[KMP_DIM]], [[KMP_DIM]]* [[DIMS]], i32 0, i32 1
// CHECK: store i64 %{{.+}}, i64* %
// CHECK: getelementptr inbounds [[KMP_DIM]], [[KMP_DIM]]* [[DIMS]], i32 0, i32 2
// CHECK: store i64 1, i64* %
// CHECK: [[CAST:%.+]] = bitcast [[KMP_DIM]]* [[DIMS]] to i8*
// CHECK: call void @__kmpc_doacross_init([[IDENT]], i32 [[GTID]], i32 1, i8* [[CAST]])
// CHECK: call void @__kmpc_for_static_init_8(
#pragma omp for ordered(2)
    for (T j = 0; j < M; j++)
      for (i = 0; i < n; i += 2) {
        a[i][j] = foo(i, j);
// CHECK: invoke {{.+TestStruct.+foo}}
// CHECK: load i64, i64* [[CNT]],
// CHECK-NEXT: sub nsw i64 %{{.+}}, 1
// CHECK-NEXT: store i64 %{{.+}}, i64* [[TMP:%.+]],
// CHECK-NEXT: call void @__kmpc_doacross_wait([[IDENT]], i32 [[GTID]], i64* [[TMP]])
// CHECK-NEXT: load i64, i64* [[CNT]],
// CHECK-NEXT: load i32, i32* %
// CHECK-NEXT: mul nsw i32 1, %
// CHECK-NEXT: sext i32 %{{.+}} to i64
// CHECK-NEXT: sub nsw i64 %
// CHECK-NEXT: store i64 %{{.+}}, i64* [[TMP:%.+]],
// CHECK-NEXT: call void @__kmpc_doacross_wait([[IDENT]], i32 [[GTID]], i64* [[TMP]])
#pragma omp ordered depend(sink : j, i - 2) depend(sink : j - 1, i)
        b[i][j] = bar(a[i][j], b[i - 1][j], b[i][j - 1]);
// CHECK: invoke {{.+TestStruct.+bar}}
// CHECK: load i64, i64* [[CNT]],
// CHECK-NEXT: store i64 %{{.+}}, i64* [[TMP:%.+]],
// CHECK-NEXT: call void @__kmpc_doacross_post([[IDENT]], i32 [[GTID]], i64* [[TMP]])
#pragma omp ordered depend(source)
        baz(a[i][j], b[i][j]);
      }
  }
  // CHECK: landingpad
  // CHECK: call void @__kmpc_doacross_fini([[IDENT]], i32 [[GTID]])
  // CHECK: br label %

  // CHECK: call void @__kmpc_for_static_fini(
  // CHECK: call void @__kmpc_doacross_fini([[IDENT]], i32 [[GTID]])
  // CHECK: ret
};

TestStruct<int> s;
#endif // HEADER
