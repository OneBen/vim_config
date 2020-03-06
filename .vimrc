" Vundle >>>>>>
    set nocompatible              " be iMproved, required
    filetype off                  " required

    set rtp+=~/.vim/bundle/Vundle.vim
    call vundle#begin()
    " alternatively, pass a path where Vundle should install plugins
    "call vundle#begin('~/some/path/here')

    " let Vundle manage Vundle, required
    Plugin 'VundleVim/Vundle.vim'
    Plugin 'scrooloose/nerdtree'
    Plugin 'flazz/vim-colorschemes'
    Plugin 'easymotion/vim-easymotion'
    Plugin 'bling/vim-airline'
    Plugin 'valloric/youcompleteme'
    Plugin 'octol/vim-cpp-enhanced-highlight'
    Plugin 'elzr/vim-json'

    " All of your Plugins must be added before the following line
    call vundle#end()            " required
    filetype plugin indent on    " required
" <<<<<< Vundle


" airline >>>>>>
    set t_Co=256
    set laststatus=2
    let g:airline_powerline_fonts=1
    let g:airline#extensions#tabline#enabled = 1
    let g:airline#extensions#syntastic#enabled=1
    let g:airline_powerline_fonts=1
    let g:airline_left_sep = ' '
" <<<<<< airline


" NERDTree >>>>>>
"    autocmd vimenter * NERDTree
    nnoremap tt :NERDTree %:h<CR>
    nnoremap <C-h> :bprevious<CR>
    nnoremap <C-l> :bnext<CR>
    nnoremap <C-k> :bdelete<CR>
" <<<<<< NERDTree


" easymotion >>>>>>
    nmap fs <Plug>(easymotion-s)
    nmap ff <Plug>(easymotion-s2)
    "nmap ft <Plug>(easymotion-t2)
    nmap fw <Plug>(easymotion-bd-w)
    nmap fl <Plug>(easymotion-lineforward)
    nmap fj <Plug>(easymotion-j)
    nmap fk <Plug>(easymotion-k)
    nmap fh <Plug>(easymotion-linebackward)
" <<<<<< easymotion

" basic >>>>>>
    syntax on
    syntax enable
    set ruler
    set nu
    set scrolloff=3
    set ts=4 sw=4
    set expandtab
    set nobackup
    set noswapfile
    set cindent
    set autoindent
    set backspace=2
    set showmatch
    set smartindent
    set softtabstop=4
    set shiftwidth=4
    set incsearch
    set hlsearch
    set completeopt=menu
    hi Search term=standout ctermfg=white ctermbg=63
    hi Normal ctermbg=none
    set cursorline
    set cursorcolumn
" <<<<<< basic

let mapleader = ","

" >>> key map <<<
    :map <F2> :e %:p:s,.h$,.X123X,:s,.cpp$,.h,:s,.X123X$,.cpp,<CR>
    :map <F3> ,yy
    
" >>> buffer map <<<
    nnoremap <C-h> :bp<CR>
    nnoremap <C-l> :bn<CR>
    nnoremap <C-^> :bd<CR>

" >>> YouCompleteMe <<<
    let g:ycm_confirm_extra_conf = 0 
    let g:ycm_global_ycm_extra_conf = '~/.ycm_extra_conf.py'
    nnoremap <silent> <Leader>yy :YcmCompleter GoTo<CR>
" nnoremap <silent> <Leader>yt :YcmCompleter GetType<CR>
" nnoremap <silent> <Leader>yp :YcmCompleter GetParent<CR>
" nnoremap <silent> <Leader>yd :YcmCompleter GetDoc<CR>
" nnoremap <silent> <Leader>yf :YcmCompleter FixIt<CR>    
    autocmd CursorMovedI * if pumvisible() == 0|pclose|endif
    autocmd InsertLeave * if pumvisible() == 0|pclose|endif

" >>> color theme <<< 
let g:cpp_class_scope_highlight = 1
let g:cpp_experimental_template_highlight = 1
set background=dark

" jsom.vim
let g:vim_json_syntax_conceal = 0

" copy
vmap <C-y> "+y
vmap <C-p> "+p
" colorscheme MountainDew

"--fold setting--
set foldmethod=syntax " 用语法高亮来定义折叠
set foldlevel=100 " 启动vim时不要自动折叠代码
set foldcolumn=5 " 设置折叠栏宽度

"-- Taglist setting --
"let Tlist_Ctags_Cmd='ctags' "因为我们放在环境变量里，所以可以直接执行
let Tlist_Use_Right_Window=1 "让窗口显示在右边，0的话就是显示在左边
let Tlist_Show_One_File=0 "让taglist可以同时展示多个文件的函数列表
let Tlist_File_Fold_Auto_Close=1 "非当前文件，函数列表折叠隐藏
let Tlist_Exit_OnlyWindow=1 "当taglist是最后一个分割窗口时，自动推出vim
"是否一直处理tags.1:处理;0:不处理
let Tlist_Process_File_Always=1 "实时更新tags
"let Tlist_Inc_Winwidth=0:
nmap tl :Tlist<cr>

nmap <C-c> <Esc>:w<cr>
