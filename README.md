1. 把里面的文件都放到～/目录下
2. 编辑.bashrc
```
alias vim='/home/nliu/vim/src/vim'
export VIMRUNTIME='/home/nliu/vim/src/runtime'

source .bashrc
cp .ycm_extra_conf.py ~/ficus
```

3. 常用命令
  - F3 跳转 ctrl+o回退
  - 函数列表 tl
  - 文件列表 tt
  - 关键字查询定位 ff/fj/fk
  - u撤销
  
4. 若需要vim中粘贴复制到系统剪切板功能
  - sudo apt-get install vim-gui-common 或者 gnome
  - 到.vimrc里去更改vmap映射的 "+y/p 键对应的所需快键键即可
