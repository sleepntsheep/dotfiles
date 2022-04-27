
local lspconfig = require('lspconfig')

lspconfig.pylsp.setup {
    flags = {
        debounce_text_changes = 150,
    },
}

lspconfig.clangd.setup {
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

lspconfig.sumneko_lua.setup {
    settings = {
    Lua = {
      runtime = {
        -- Tell the language server which version of Lua you're using (most likely LuaJIT in the case of Neovim)
        version = 'LuaJIT',
        -- Setup your lua path
        --path = lua,
      },
      diagnostics = {
        -- Get the language server to recognize the `vim` global
        globals = {'vim'},
      },
      workspace = {
        -- Make the server aware of Neovim runtime files
        library = vim.api.nvim_get_runtime_file("", true),
      },
      -- Do not send telemetry data containing a randomized but unique identifier
      telemetry = {
        enable = false,
      },
    },
  },
}
