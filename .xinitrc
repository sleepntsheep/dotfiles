#!/bin/bash

feh --bg-scale ~/d/pic/Wallpaper/everforest.jpg &
setxkbmap -layout 'us,th' -variant ,ThaiMnc -option 'grp:alt_shift_toggle' &
xrdb ~/.Xresources &
dwmblocks &
wmname LG3D &
redshift &
exec dbus-launch dwm 
