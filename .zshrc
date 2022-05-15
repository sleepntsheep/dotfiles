export PATH="$PATH:$HOME/.local/bin"
export EDITOR="nvim"

alias gaa='git add -A'
alias gc='git commit'
alias gp='git push'

PROMPT='%F{green}%n@%m %F{cyan}%~ %# %F{white}'

dircolors -p | sed 's/;42/;01/' > ~/.dircolors
alias ls='ls -F -h --color=always -v --author --time-style=long-iso'
alias ll='ls -l'
alias l='ls -l -a'

bindkey -e
