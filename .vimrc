set number
set relativenumber
set nocompatible
set incsearch
set autoindent
set ruler
set autowrite
set linebreak
set spell
set et
set title
set mouse=v
set history=500
set tabstop=4
"set matchtime=2
"set matchpairs+=<:>

filetype plugin indent on  " Load plugins according to detected filetype.
syntax on                  " Enable syntax highlighting.

set expandtab              " Use spaces instead of tabs.
set softtabstop =4         " Tab key indents by 4 spaces.
set shiftwidth  =4         " >> indents by 4 spaces.
set shiftround             " >> indents to next multiple of 'shiftwidth'.

set backspace   =indent,eol,start  " Make backspace work as you would expect.
set hidden                 " Switch between buffers without having to save first.
set laststatus  =2         " Always show statusline.
set display     =lastline  " Show as much as possible of the last line.

set showmode               " Show current mode in command-line.
set showcmd                " Show already typed keys when more are expected.

set incsearch              " Highlight while searching with / or ?.
set hlsearch               " Keep matches highlighted.

set ttyfast                " Faster redrawing.
set lazyredraw             " Only redraw when necessary.

set splitbelow             " Open new windows below the current window.
set splitright             " Open new windows right of the current window.

set cursorline             " Find the current line quickly.
set wrapscan               " Searches wrap around end-of-file.
set report      =0         " Always report changed lines.
set synmaxcol   =200       " Only highlight the first 200 columns.

set list                   " Show non-printable characters.
if has('multi_byte') && &encoding ==# 'utf-8'
  let &listchars = 'tab:▸ ,extends:❯,precedes:❮,nbsp:±'
else
  let &listchars = 'tab:> ,extends:>,precedes:<,nbsp:.'
endif

set packpath=~/vimfiles,~/vimfiles/after


"" PLUGIN
call plug#begin('~/.vim/plugged')
    Plug 'wakatime/vim-wakatime'
    Plug 'junegunn/fzf.vim'
    Plug 'itchyny/lightline.vim'
    Plug 'terryma/vim-multiple-cursors'
    Plug 'preservim/nerdtree'
    Plug 'tpope/vim-surround'
    "Plug 'pradyungn/Mountain', {'rtp': 'vim'}
call plug#end()

let g:fzf_preview_window = ['down:40%:hidden', 'ctrl-/']
let g:fzf_buffers_jump = 1
let g:fzf_commits_log_options = '--graph --color=always --format="%C(auto)%h%d %s %C(black)%C(bold)%cr"'
let g:fzf_tags_command = 'ctags -R'
let g:fzf_commands_expect = 'alt-enter,ctrl-x'

nnoremap <C-w> :NERDTreeToggle<CR>
nnoremap <C-f> :NERDTreeFind<CR>

colorscheme sheep16

