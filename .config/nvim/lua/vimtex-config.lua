

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
