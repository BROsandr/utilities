" This file is supposed to be loaded by VSVim - visual studio extension

set clipboard=unnamedplus
set hlsearch
set ignorecase
set incsearch

" copied from Vim 7.3's mswin.vim:

" CTRL-X and SHIFT-Del are Cut
vnoremap <C-X> "+x
vnoremap <S-Del> "+x

" CTRL-C and CTRL-Insert are Copy
vnoremap <C-C> "+y
vnoremap <C-Insert> "+y

" CTRL-V and SHIFT-Insert are Paste
map <C-V>		"+gP
map <S-Insert>		"+gP
imap <C-V>		<Esc>"+gpa

cmap <C-V>		<C-R>+
cmap <S-Insert>		<C-R>+


" My mappings
" let mapleader = ","
nmap <C-O> :vsc View.NavigateBackward<CR>
nmap <C-I> :vsc View.NavigateForward<CR>

" imap <C-N> <C-O>:vsc Edit.LineDown<CR>
" imap <C-P> <C-O>:vsc Edit.LineUp<CR>
nmap g] :vsc Edit.GoToNextIssueinFile<CR>
nmap g[ :vsc Edit.GoToPreviousIssueinFile<CR>
nmap gd :vsc Edit.GoToDefinition<CR>
nmap gy :vsc Edit.GoToTypeDefinition<CR>
" nmap gi :vsc Edit.GoToImplementaion<CR>
nmap gr :vsc Edit.FindAllReferences<CR>
nmap gk :vsc Edit.QuickInfo<CR>
nmap <Leader>rn :vsc Refactor.Rename<CR>
nmap <Leader>f :vsc Edit.FormatSelection<CR>
vmap <Leader>f :vsc Edit.FormatSelection<CR>
imap <C-W> <C-O>:vsc Edit.WordDeleteToStart<CR>
nmap gf :vsc Edit.GoToAll<CR>
nmap gi :vsc View.ShowSmartTag<CR>
map gcc :vsc Edit.ToggleLineComment<CR>
nmap <Leader>s :vsc Debug.StepInto<CR>
nmap <Leader>o :vsc Debug.StepOut<CR>
nmap <Leader>n :vsc Debug.StepOver<CR>
" fun! ToggleW00tMode()
"     if !exists('b:w00t')
"         let b:w00t=1
"     else
"         unlet b:w00t
"     endif

"     return ""
" endfun

" inoremap <C-w> <C-r>=ToggleW00tMode()<Cr>

" " Do something different depending on the value of b:w00t
" inoremap <expr> o exists('b:w00t') ? '0' : 'o'
