local map = vim.api.nvim_set_keymap
vim.g.mapleader = ';'
map('n', '<TAB>', ':BufferLineCycleNext<CR>', { noremap = true, silent = true })
map('n', '<S-TAB>', ':BufferLineCyclePrev<CR>', { noremap = true, silent = true })
map('n', '<leader>e', ':NvimTreeToggle<CR>', {noremap = true, silent = true})
map('n', '<leader>w', ':write<CR>', {noremap = true})
map('n', '<leader>q', ':quit<CR>', {noremap = true})
map('n', '<leader>wq', ':wq<CR>', {noremap = true})
map('t', '<leader><ESC>', '<C-\\><C-n>', {noremap = true})
map('n', '<leader>r', ':NvimTreeRefresh<CR>', {noremap = true})
