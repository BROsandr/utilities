set nocompatible            " disable compatibility to old-time vi
set showmatch               " show matching 
set ignorecase              " case insensitive 
set hlsearch                " highlight search 
set incsearch               " incremental search
set guicursor+=n-v-c:blinkon1
set tabstop=4               " number of columns occupied by a tab 
set termguicolors
"set mouse=v                 " middle-click paste with
set softtabstop=4           " see multiple spaces as tabstops so <BS> does the right thing
set shiftwidth=4            " width for autoindents
set autoindent              " indent a new line the same amount as the line just typed
set relativenumber                  " add line numbers
set wildmode=list:longest,list:full   " get bash-like tab completions
"set cc=180                  " set an 80 column border for good coding style
filetype plugin indent on   "allow auto-indenting depending on file type
syntax on                   " syntax highlighting
set mouse=a                 " enable mouse click
set clipboard=unnamedplus   " using system clipboard
filetype plugin on
set cursorline              " highlight current cursorline
set ttyfast                 " Speed up scrolling in Vim
set smarttab
" set spell                 " enable spell check (may need to download language package)
" set noswapfile            " disable creating swap file
" set backupdir=~/.cache/vim " Directory to store backup files.i
"
" mappings
"
nmap <F5> :terminal ./run<Enter>
" Ctrl-j/k deletes blank line below/above, and Alt-j/k inserts.
" nmap <silent><C-j> m`:silent +g/\m^\s*$/d<CR>``:noh<CR>
nmap <silent><C-k> m`:silent -g/\m^\s*$/d<CR>``:noh<CR>
nmap <silent><A-j> :set paste<CR>m`o<Esc>``:set nopaste<CR>
nmap <silent><A-k> :set paste<CR>m`O<Esc>``:set nopaste<CR>

"copy and paste
" copy (write) highlighted text to .vimbuffer
vmap <C-c> y:new ~/.config/nvim/.vimbuffer<CR>VGp:x<CR> \| :!cat  ~/.config/nvim/.vimbuffer \| clip.exe <CR><CR>

call plug#begin()

Plug 'vim-airline/vim-airline'
Plug 'tpope/vim-surround'
Plug 'tpope/vim-commentary'
Plug 'neoclide/coc.nvim', {'branch': 'release'}
Plug 'sheerun/vim-polyglot'
Plug 'https://github.com/LucHermitte/lh-brackets.git'
Plug 'https://github.com/LucHermitte/lh-vim-lib.git'
Plug 'scrooloose/nerdtree'
Plug 'https://github.com/ctrlpvim/ctrlp.vim.git'
Plug 'tpope/vim-fugitive'
" Plug 'ryanoasis/vim-devicons'

call plug#end()

let b:usemarks         = 0
" hi FgCocErrorFloatBgCocFloating guifg=#2e7c1d
" hi FgCocWarningFloatBgCocFloating guifg=#00ff7f
colorscheme darkblue
" autocmd TermOpen * setlocal nonumber norelativenumber
set cin  "включим отступы в стиле Си
" set signcolumn=auto:9
