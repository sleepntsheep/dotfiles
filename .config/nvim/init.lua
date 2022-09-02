-- This file can be loaded by calling `lua require('plugins')` from your init.vim

local api = vim.api
local opt = vim.opt


-- Plugins
-- Only required if you have packer configured as `opt`
vim.cmd [[packadd packer.nvim]]
require('packer').startup(function()
    use 'wbthomason/packer.nvim'
    use { 'nvim-treesitter/nvim-treesitter', run = ':TSUpdate' }
    use 'nvim-lualine/lualine.nvim'
    use 'kyazdani42/nvim-web-devicons'
    use 'akinsho/bufferline.nvim'
    use 'kyazdani42/nvim-tree.lua'
    use 'neovim/nvim-lspconfig'
    use 'hrsh7th/cmp-nvim-lsp'
    use 'hrsh7th/cmp-buffer'
    use 'hrsh7th/cmp-path'
    use 'hrsh7th/cmp-cmdline'
    use 'hrsh7th/nvim-cmp'
    use 'saadparwaiz1/cmp_luasnip'
    use 'L3MON4D3/LuaSnip'
    use 'lervag/vimtex'
    use 'andweeb/presence.nvim'
    use({
        "catppuccin/nvim",
        as = "catppuccin"
    })
    use {"akinsho/toggleterm.nvim", tag = 'v2.*'}
end)

-- snippet
require("luasnip.loaders.from_snipmate").load()

-- colorscheme
vim.g.catppuccin_flavour = "mocha" -- latte, frappe, macchiato, mocha
vim.cmd[[colorscheme catppuccin]]

require "options"

require "toggleterm-config"
require "lualine-config"
require "nvim-tree-config"
require "keybind"
require "nvim-cmp-config"
require "lspconfig-config"
require('bufferline').setup {}
require "vimtex-config"
require("presence"):setup {}
