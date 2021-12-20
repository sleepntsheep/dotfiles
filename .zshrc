# pywal colors
#(cat ~/.cache/wal/sequences &)
source ~/.cache/wal/colors-tty.sh
ZSH_THEME="lambda"

CASE_SENSITIVE="true"

HYPHEN_INSENSITIVE="true"}}}

DISABLE_MAGIC_FUNCTIONS="true"

DISABLE_LS_COLORS="true"

ENABLE_CORRECTION="true"

COMPLETION_WAITING_DOTS="true"

DISABLE_UNTRACKED_FILES_DIRTY="true"

plugins=(git yarn)

alias py='python'
source $ZSH/oh-my-zsh.sh
export EDITOR=vim
alias vi='nvim'

#[ -f ~/.fzf.zsh ] && source ~/.fzf.zsh

export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion

export PATH=$HOME/bin:/usr/local/bin:$PATH:$HOME/.local/bin

# Path to your oh-my-zsh installation.
export ZSH="/home/sheep/.oh-my-zsh"


#. "${HOME}/.cache/wal/colors.sh"

shisutemu

