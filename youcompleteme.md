# 安装youcompleteme问题
- 一般情况下 PluginInstall的时候往往装不上youcompleteme，得自己编译


## 依赖
- youcompleteme需要的依赖比较多，在网上多搜搜基本可以找全
- 插件要求的vim版本8.0以上（包中vim已经满足）


## 问题：Your C++ compiler does NOT fully support C++11. 解决
1. Install a package with repository for your system:
  - On CentOS, install package centos-release-scl available in CentOS repository:
  ```shell
  $ sudo yum install centos-release-scl
  ```
  - On RHEL, enable RHSCL repository for you system:
  ```shell
  $ sudo yum-config-manager --enable rhel-server-rhscl-7-rpms
  ```
2. Install the collection:
```shell
$ sudo yum install devtoolset-6
```
3. Start using software collections:
```shell
$ scl enable devtoolset-6 bash
```
注意：要在同一个用户下执行3个命令
4. 最后使用sudo ./install.py 安装
