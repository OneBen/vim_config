# 配置及使用
## 配置过程
1. 把里面的文件都放到～/目录下
2. 到.vim/bundle/Vundle目录下拉取VundleVim插件
```
git clone https://github.com/VundleVim/Vundle.vim
```
3. 编辑.bashrc
```
alias vim='/home/nliu/vim/src/vim'
export VIMRUNTIME='/home/nliu/vim/runtime'

source .bashrc
cp .ycm_extra_conf.py ~/ficus
```
4. 进入vim编辑器，命令模式 :PluginInstall 安装插件
```
:PluginInstall
```
5. 若需要vim中粘贴复制到系统剪切板功能
  - sudo apt-get install vim-gui-common 或者 gnome
  - 到.vimrc里去更改vmap映射的 "+y/p 键对应的所需快键键即可


## 常用操作
### 移动跳转命令
  - F3 跳转 ctrl+o回退
  - 函数列表 tl
  - 文件列表 tt
  - 关键字查询定位(当前页面) ff/fj/fk
  - 定位到对应括号位置 %
  - 关键字符定位(当前行) f\*/t\* (\*表示需定位字符) f表示定位到当前字符，t表示定位到字符前一个，用于dt命令
  - 按单词前进w/e(单词首部/尾部) 后退b/ge
  - u撤销 Ctrl+r重做
  - Ctrl+o/i 光标位置回退/前进之前的位置
  - /word 查找单词 或者把光标放到单词上按\* 可以查找当前单词 输入:noh取消高亮单词
  - < 和 >控制缩进  
![move](https://github.com/OneBen/vim_config/blob/master/move.png)

### 常用输入命令
  - daw 删除当前单词
  - di/ci+括号或引号之类的，可以删除/删除并插入括号或引号的内容，需要当前光标移动到括号引号内部

### 常用输入命令
### 替换命令
  - s/old/new/ 用old替换new，替换当前行的第一个匹配
  - s/old/new/g 用old替换new，替换当前行的所有匹配
  - %s/old/new/ 用old替换new，替换所有行的第一个匹配
  - %s/old/new/g 用old替换new，替换整个文件的所有匹配
  - :10,20 s/^/    /g 在第10行知第20行每行前面加四个空格，用于缩进。
  - ddp 交换光标所在行和其下紧邻的一行。（其实就是删除再粘贴）
  
### 折叠
- zc 折叠，只折叠最外层的折叠
- zC 对所在范围内所有嵌套的折叠点进行折叠，包括嵌套的所有折叠.
- zo 展开折叠，只展开最外层的折叠.
- zO 对所在范围内所有嵌套的折叠点展开，包括嵌套折叠.
- \[z 到当前打开的折叠的开始处。
- \]z 到当前打开的折叠的末尾处。
- zj 向下移动。到达下一个折叠的开始处。关闭的折叠也被计入。
- zk 向上移动到前一折叠的结束处。关闭的折叠也被
- zd 删除 (delete) 在光标下的折叠。仅当 ‘foldmethod’ 设为 “manual” 或 “marker” 时有效。
- zD 循环删除 (Delete) 光标下的折叠，即嵌套删除折叠。仅当 ‘foldmethod’ 设为 “manual” 或 “marker” 时有效。
- zE 除去 (Eliminate) 窗口里“所有”的折叠。仅当 ‘foldmethod’ 设为 “manual” 或 “marker” 时有效。

- 假定你已经创建了若干折叠，而现在需要阅览全部文本。你可以移到每个折叠处，并键入”zo”。若要做得更快，可以用这个命令:zr
- zm这将折叠更多 (M-ore)。你可以重复 “zr” 和 “zm” 来打开和关闭若干层嵌套的折叠，不然得一个一个的用zc来折叠.

- 如果你有一个嵌套了好几层深的折叠，你可以用这个命令把它们全部打开:zR
- 这将减少折叠直至一个也不剩。而用下面这个命令你可以关闭所有的折叠:zM

### buffer切换（命令模式）
- :ls b  //List Buffers 查看当前所有的buffer 
- :bn //Buffer Next 下一个buffer 
- :bp //Buffer Previous 上一个buffer
- :bd //Buffer Down 关闭当前buffer
- :b 2(number) //Buffer number 指定第二个buffer
- 可在.vimrc中设置快捷键：
```shell
"按Ctrl+h 向左移动一个buffer
nnoremap <C-h> :bp<CR>
"按Ctrl+l 向右移动一个buffer
nnoremap <C-l> :bn<CR>
"按Ctrl+^ 关闭当前buffer
nnoremap <C-^> :bd<CR>
```
