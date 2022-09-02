export PATH="$PATH:$HOME/.local/bin:$HOME/.scripts:$HOME/.cargo/bin:$HOME/.local/share/gem/ruby/3.0.0/bin"
export LANG=en_US.UTF-8
export EDITOR='nvim'

#export ZSH="$HOME/.oh-my-zsh"
#ZSH_THEME="robbyrussell"
## CASE_SENSITIVE="true"
## HYPHEN_INSENSITIVE="true"
#DISABLE_LS_COLORS="false"
## DISABLE_AUTO_TITLE="true"
#ENABLE_CORRECTION="true"
#plugins=(git zsh-z)
#source $ZSH/oh-my-zsh.sh

# bun completions
#[ -s "/home/sheep/.bun/_bun" ] && source "/home/sheep/.bun/_bun"
#
## Bun
#export BUN_INSTALL="/home/sheep/.bun"
#export PATH="$BUN_INSTALL/bin:$PATH"

#source "$HOME/emsdk/emsdk_env.sh"

export WINE="wine64"
export WINEPREFIX="$HOME/.wine"

PS1='%F{yellow}@ %/ $ %f'
bindkey -e
bindkey "^[[1;5C" forward-word
bindkey "^[[1;5D" backward-word
#alias ls='exa'

source ~/.zsh/zsh-autosuggestions/zsh-autosuggestions.zsh

#plc
