
-- keybind
local map = vim.api.nvim_set_keymap
vim.g.mapleader = ';'
map('n', '<TAB>', ':BufferLineCycleNext<CR>', { noremap = true, silent = true })
map('n', '<S-TAB>', ':BufferLineCyclePrev<CR>', { noremap = true, silent = true })
map('n', '<leader>e', ':NvimTreeToggle<CR>', {noremap = true, silent = true})
map('n', '<leader>w', ':w<CR>', {noremap = true})
map('n', '<C-s>', ':w<CR>', {noremap = true})
map('n', '<leader>q', ':q<CR>', {noremap = true})
map('t', '<leader><ESC>', '<C-\\><C-n>', {noremap = true})
map('n', '<leader>r', ':NvimTreeRefresh<CR>', {noremap = true})
map('n', 'H', '^', {noremap = true})
map('n', 'L', '$', {noremap = true})
map('i', 'jk', '<Esc>', {noremap = true})
map('i', '<C-<leader>>', ':ToggleTerm<CR>', {noremap = true})
map('n', '<C-;>', ':ToggleTerm<CR>', {noremap = true})
map('t', '<C-;>', '<C-\\><C-n><CR>:ToggleTerm<CR>', {noremap = true})

