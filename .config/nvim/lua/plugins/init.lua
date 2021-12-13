-- This file can be loaded by calling `lua require('plugins')` from your init.vim

-- Only required if you have packer configured as `opt`
vim.cmd [[packadd packer.nvim]]

return require('packer').startup(function()
  use 'wbthomason/packer.nvim'
  use 'github/copilot.vim'
  use 'mountain-theme/vim'
  use 'preservim/nerdtree'
  use { 'nvim-treesitter/nvim-treesitter', run = ':TSUpdate' }
  use 'nvim-lualine/lualine.nvim'
  requires = {'kyazdani42/nvim-web-devicons', opt = true}
end)