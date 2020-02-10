1. 把里面的文件都放到～/目录下
2. 编辑.bashrc
```
alias vim='/home/nliu/vim/src/vim'
export VIMRUNTIME='/home/nliu/vim/src/runtime'

source .bashrc
cp .ycm_extra_conf.py ~/ficus
```

3. 若需要vim中粘贴复制到系统剪切板功能
  - sudo apt-get install vim-gui-common 或者 gnome
  - 到.vimrc里去更改vmap映射的 "+y/p 键对应的所需快键键即可
  
4. 常用移动跳转命令
  - F3 跳转 ctrl+o回退
  - 函数列表 tl
  - 文件列表 tt
  - 关键字查询定位(当前页面) ff/fj/fk
  - 定位到对应括号位置 %
  - 关键字符定位(当前行) f\*/t\* (\*表示需定位字符) f表示定位到当前字符，t表示定位到字符前一个，用于dt命令
  - 按单词前进w/e(单词首部/尾部) 后退b/ge
  - di/ci+括号或引号之类的，可以删除/删除并插入括号或引号的内容，需要当前光标移动到括号引号内部
  - u撤销 Ctrl+r重做
  - Ctrl+o/i 光标位置回退/前进之前的位置
  - /word 查找单词 或者把光标放到单词上按\* 可以查找当前单词
  
![move](https://github.com/OneBen/vim_config/blob/master/move.png)

5.替换命令
  - s/old/new/ 用old替换new，替换当前行的第一个匹配
  - s/old/new/g 用old替换new，替换当前行的所有匹配
  - %s/old/new/ 用old替换new，替换所有行的第一个匹配
  - %s/old/new/g 用old替换new，替换整个文件的所有匹配
  - :10,20 s/^/    /g 在第10行知第20行每行前面加四个空格，用于缩进。
  - ddp 交换光标所在行和其下紧邻的一行。（其实就是删除再粘贴）
  

