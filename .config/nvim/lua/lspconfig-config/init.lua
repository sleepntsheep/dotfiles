
local lspconfig = require('lspconfig')

lspconfig.pyright.setup {
    on_attach = attach,
    flags = {
        debounce_text_changes = 150,
    },
}

lspconfig.clangd.setup {
    on_attach = attach,
    flags = {
        debounce_text_changes = 150,
    },
}

lspconfig.tsserver.setup {
    on_attach = function(client, bufnr)
       client.resolved_capabilities.document_formatting = false
       vim.api.nvim_buf_set_keymap(bufnr, "n", "<space>fm", "<cmd>lua vim.lsp.buf.formatting()<CR>", {})
    end,
}

