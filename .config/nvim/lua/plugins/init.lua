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
    use 'kyazdani42/nvim-web-devicons'
    use 'akinsho/bufferline.nvim'
    use 'kyazdani42/nvim-tree.lua'
    use 'neovim/nvim-lspconfig'
    use 'dylanaraps/wal.vim'
    use 'wakatime/vim-wakatime'
    use 'eddyekofo94/gruvbox-flat.nvim'
    use 'morhetz/gruvbox'
    use {'neoclide/coc.nvim', branch = 'release'}
    use 'Mofiqul/dracula.nvim'
    use 'sainnhe/everforest'
end)
