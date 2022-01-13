vim.cmd('filetype plugin indent on')

vim.o.fileencoding = 'utf-8'
vim.o.shortmess = vim.o.shortmess .. 'c'
vim.o.hidden = true
vim.o.splitbelow = true
vim.o.mouse = 'a'
vim.o.tabstop = 4
vim.bo.tabstop = 4
vim.o.softtabstop = 4
vim.bo.softtabstop = 4
vim.o.shiftwidth = 4
vim.bo.shiftwidth = 4
vim.o.autoindent = true
vim.bo.autoindent = true
vim.o.expandtab = true
vim.bo.expandtab = true
--vim.opt.termguicolors = true
vim.o.backup = false
vim.o.writebackup = false
vim.o.updatetime = 300
vim.o.clipboard = 'unnamedplus'
vim.o.hlsearch = true
vim.o.scrolloff = 3
vim.o.number = true
vim.o.relativenumber = true
vim.o.cursorline = true
vim.o.signcolumn = 'yes'
vim.o.wrap = true
vim.o.cursorline = true

--vim.g.gruvbox_contrast_light = "hard"
--vim.g.gruvbox_transparent_bg = 1
--vim.o.background = "dark"
--vim.cmd([[colorscheme gruvbox]])
vim.cmd([[colorscheme dracula]])

-- neovide
vim.g.neovide_refresh_rate=75
vim.g.neovide_transparency=1
vim.g.neovide_no_idle=1
vim.g.neovide_cursor_animation_length=0.11
vim.g.neovide_cursor_trail_length=0.8
vim.g.neovide_cursor_antialiasing=0
vim.g.neovide_cursor_vfx_mode="pixiedust"
--vim.o.guifont="Fixedsys Excelsior 3.01-L2,JetbrainsMono Nerd Font:h12"
vim.o.guifont="JetbrainsMono Nerd Font:h12"

