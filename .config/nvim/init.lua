-- This file can be loaded by calling `lua require('plugins')` from your init.vim

local vim = vim
local api = vim.api
local opt = vim.opt

-- Options
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
-- vim.o.clipboard = 'unnamedplus'
vim.o.hlsearch = true
vim.o.scrolloff = 999
vim.o.number = true
vim.o.relativenumber = true
vim.o.cursorline = true
vim.o.signcolumn = 'yes'
vim.o.wrap = true
vim.o.cursorline = true
vim.cmd [[:set nofen]]

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

-- in lua folder

-- snippet
require("luasnip.loaders.from_snipmate").load()

-- colorscheme
vim.g.catppuccin_flavour = "mocha" -- latte, frappe, macchiato, mocha
vim.cmd[[colorscheme catppuccin]]

require('toggleterm-config')

-- Setup lualine
require('lualine').setup {
    options = {
        icons_enabled = true,
        -- theme = '',
        component_separators = { left = '', right = ''},
        section_separators = { left = '', right = ''},
        disabled_filetypes = {},
        always_divide_middle = true,
    },
    sections = {
        lualine_a = {'mode'},
        lualine_b = {'branch', 'diff', 'diagnostics'},
        lualine_c = {'filename'},
        lualine_x = {'encoding', 'fileformat', 'filetype'},
        lualine_y = {'progress'},
        lualine_z = {'location'}
    },
    inactive_sections = {
        lualine_a = {},
        lualine_b = {},
        lualine_c = {'filename'},
        lualine_x = {'location'},
        lualine_y = {},
        lualine_z = {}
    },
    tabline = {},
    extensions = {}
}

-- Setup bufferline
require('bufferline').setup {}

-- Setup lspconfig.
local capabilities = require('cmp_nvim_lsp').update_capabilities(vim.lsp.protocol.make_client_capabilities())
local lspconfig = require('lspconfig')
local servers = { 'rust_analyzer', 'clangd', 'pylsp', 'sumneko_lua', 'tsserver', 'html', 'eslint', 'texlab' }
for _, v in ipairs(servers)
    do
        lspconfig[v].setup {
            capabilities = capabilities
        }
    end

-- Setup nvim-tree
vim.g.nvim_tree_refresh_wait = 50
require'nvim-tree'.setup {
    disable_netrw       = true,
    hijack_netrw        = true,
    open_on_setup       = false,
    ignore_ft_on_setup  = {},
    open_on_tab         = false,
    hijack_cursor       = false,
    update_cwd          = false,
    diagnostics = {
        enable = false,
        icons = {
            hint = "",
            info = "",
            warning = "",
            error = "",
        }
    },
    update_focused_file = {
        enable      = false,
        update_cwd  = false,
        ignore_list = {}
    },
    system_open = {
        cmd  = nil,
        args = {}
    },
    filters = {
        dotfiles = false,
        custom = {}
    },
    git = {
        enable = true,
        ignore = false,
        timeout = 500,
    },
    view = {
        width = 25,
        height = 30,
        hide_root_folder = false,
        side = 'left',
        mappings = {
            custom_only = false,
            list = {}
        },
        number = false,
        relativenumber = true,
        signcolumn = "yes"
    },
    trash = {
        cmd = "trash",
        require_confirm = true
    }
}

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

-- Setup nvim-tree
local cmp = require "cmp"
local luasnip = require "luasnip"

cmp.setup({
    snippet = {
        expand = function(args)
            luasnip.lsp_expand(args.body) -- For `luasnip` users.
        end,
    },
    window = {
        -- completion = cmp.config.window.bordered(),
        -- documentation = cmp.config.window.bordered(),
    },
    mapping = cmp.mapping.preset.insert({
        ['<C-b>'] = cmp.mapping.scroll_docs(-4),
        ['<C-f>'] = cmp.mapping.scroll_docs(4),
        ['<C-Space>'] = cmp.mapping.complete(),
        ['<C-e>'] = cmp.mapping.abort(),
        ['<CR>'] = cmp.mapping.confirm({ select = true }), -- Accept currently selected item. Set `select` to `false` to only confirm explicitly selected items.
    }),
    sources = cmp.config.sources({
        { name = 'nvim_lsp' },
        { name = 'luasnip' },
    }, {
        { name = 'buffer' },
    })
})

-- Use buffer source for `/` (if you enabled `native_menu`, this won't work anymore).
cmp.setup.cmdline('/', {
    mapping = cmp.mapping.preset.cmdline(),
    sources = {
        { name = 'buffer' }
    }
})

-- Use cmdline & path source for ':' (if you enabled `native_menu`, this won't work anymore).
cmp.setup.cmdline(':', {
    mapping = cmp.mapping.preset.cmdline(),
    sources = cmp.config.sources({
        { name = 'path' }
    }, {
        { name = 'cmdline' }
    })
})

local has_words_before = function()
    local line, col = unpack(vim.api.nvim_win_get_cursor(0))
    return col ~= 0 and vim.api.nvim_buf_get_lines(0, line - 1, line, true)[1]:sub(col, col):match("%s") == nil
end
cmp.setup({
    mapping = {
        ["<Tab>"] = cmp.mapping(function(fallback)
            if cmp.visible() then
                cmp.select_next_item()
            elseif luasnip.expand_or_jumpable() then
                luasnip.expand_or_jump()
            elseif has_words_before() then
                cmp.complete()
            else
                fallback()
            end
        end, { "i", "s" }),
        ["<S-Tab>"] = cmp.mapping(function(fallback)
            if cmp.visible() then
                cmp.select_prev_item()
            elseif luasnip.jumpable(-1) then
                luasnip.jump(-1)
            else
                fallback()
            end
        end, { "i", "s" }),
    },
})

-- Setup vimtex
vim.g.vimtex_view_general_viewer = 'zathura'
vim.g.vimtex_view_method = 'zathura'
vim.g.tex_comment_nospell = 1
--vim.g.vimtex_compiler_progname = 'nvr'
vim.g.vimtex_view_general_options = [[--unique file:@pdf\#src:@line@tex]]
vim.g.maplocalleader = "\\"
vim.g.vimtex_compiler_latexrun_engines = {
    _                = 'pdflatex',
    pdflatex         = 'pdflatex',
    lualatex         = 'lualatex',
    xelatex          = 'xelatex',
}
