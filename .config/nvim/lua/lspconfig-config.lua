
-- Setup lspconfig.
local capabilities = require('cmp_nvim_lsp').update_capabilities(vim.lsp.protocol.make_client_capabilities())

local lspconfig = require('lspconfig')

local servers = { 'clangd', 'pylsp', 'sumneko_lua', 'tsserver' }

for _, v in ipairs(servers)
do
    lspconfig[v].setup {capabilities = capabilities}
end


