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
vim.opt.termguicolors = true
vim.o.backup = false
vim.o.writebackup = false
vim.o.updatetime = 300
vim.o.clipboard = 'unnamedplus'
vim.o.hlsearch = true
vim.o.scrolloff = 999
vim.o.number = true
vim.o.relativenumber = true
vim.o.cursorline = true
vim.o.signcolumn = 'yes'
vim.o.wrap = true
vim.o.cursorline = true

vim.cmd [[:set nofen]]

--vim.g.gruvbox_contrast_light = "hard"
--vim.g.gruvbox_transparent_bg = 1
--vim.o.background = "dark"
--vim.cmd([[colorscheme gruvbox]])
--vim.cmd([[colorscheme dracula]])
--vim.cmd([[colorscheme everforest]])

require('nvim-treesitter.configs').setup {
  ensure_installed = { "html", "python", "lua", "javascript", "c", "cpp"},
  sync_install = false, -- install languages synchronously (only applied to `ensure_installed`)
  ignore_install = { "javascript" },
  highlight = {
    enable = true,              -- false will disable the whole extension
    -- Setting this to true will run `:h syntax` and tree-sitter at the same time.
    -- Set this to `true` if you depend on 'syntax' being enabled (like for indentation).
    -- Using this option may slow down your editor, and you may see some duplicate highlights.
    -- Instead of true it can also be a list of languages
    additional_vim_regex_highlighting = false,
  },
}

opt.foldmethod = "expr"
opt.foldexpr = "nvim_treesitter#foldexpr()"
