set -x PATH $PATH /home/r4yish/.local/bin


alias i='git init'
alias p='git push'

function m
  git commit -m $argv  
end

function a
  git add $argv
end

set -g theme_display_git no

alias vi='nvim'
alias d='cd /mnt/d'
alias do='cd /mnt/d/Documents'

alias n='ncmpcpp'

function am
  git commit -am $argv
end
