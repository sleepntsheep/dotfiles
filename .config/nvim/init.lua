-- This file can be loaded by calling `lua require('plugins')` from your init.vim

local vim = vim
local api = vim.api

-- Only required if you have packer configured as `opt`
vim.cmd [[packadd packer.nvim]]

require('packer').startup(function()
    use 'wbthomason/packer.nvim'
    use 'github/copilot.vim'
    use 'preservim/nerdtree'
    use { 'nvim-treesitter/nvim-treesitter', run = ':TSUpdate' }
    use 'nvim-lualine/lualine.nvim'
    use 'kyazdani42/nvim-web-devicons'
    use 'akinsho/bufferline.nvim'
    use 'kyazdani42/nvim-tree.lua'
    use 'neovim/nvim-lspconfig'
    use 'sainnhe/everforest'
    use 'hrsh7th/cmp-nvim-lsp'
    use 'hrsh7th/cmp-buffer'
    use 'hrsh7th/cmp-path'
    use 'hrsh7th/cmp-cmdline'
    use 'hrsh7th/nvim-cmp'
    use 'saadparwaiz1/cmp_luasnip'
    use 'L3MON4D3/LuaSnip'
    use 'lervag/vimtex'
    use 'junegunn/goyo.vim'
    use 'junegunn/limelight.vim'
end)

-- in lua folder
require('treesitter-config')
require('lualine-config')
require('nvim-tree-config')
require('bufferline-config')
require('lspconfig-config')
require('nvim-cmp-config')
require('vimtex-config')
require('goyo-config')

require('options')
require('keybind')

-- snippet
require("luasnip.loaders.from_snipmate").load()

-- colorscheme
vim.g.everforest_better_performance = 1
vim.g.everforest_background = "hard"
vim.g.everforest_transparent_background = 1

vim.cmd [[colorscheme everforest]]

vim.cmd [[autocmd!]]
vim.cmd [[autocmd User GoyoEnter Limelight]]
vim.cmd [[autocmd User GoyoLeave Limelight!]]
vim.cmd [[autocmd VimEnter :TSEnable {c} [{c}]]
vim.cmd [[autocmd VimEnter :TSEnable {cpp} [{cpp}]]

