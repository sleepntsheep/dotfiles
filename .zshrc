export PATH=$HOME/bin:/usr/local/bin:$PATH

# Path to your oh-my-zsh installation.
export ZSH="/home/sheep/.oh-my-zsh"

ZSH_THEME="robbyrussell"

CASE_SENSITIVE="true"

HYPHEN_INSENSITIVE="true"

DISABLE_MAGIC_FUNCTIONS="true"

DISABLE_LS_COLORS="true"

ENABLE_CORRECTION="true"

COMPLETION_WAITING_DOTS="true"

DISABLE_UNTRACKED_FILES_DIRTY="true"

plugins=(git yarn vscode pyenv fzf)

source $ZSH/oh-my-zsh.sh
export EDITOR=vim
# alias zshconfig="mate ~/.zshrc"
# alias ohmyzsh="mate ~/.oh-my-zsh"

[ -f ~/.fzf.zsh ] && source ~/.fzf.zsh

shisutemu
