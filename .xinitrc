#!/bin/sh

xrandr --dpi 141
xrdb -load "$HOME/.Xresources"

case $1 in 
    c* ) exec cinnamon ;;
    *    ) exec dwm ;;
esac
