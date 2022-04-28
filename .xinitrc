#!/bin/bash

feh --bg-scale ~/d/pic/wall/momokuri_crop.png &
setxkbmap -layout 'us,th' -variant ,ThaiMnc -option 'grp:alt_shift_toggle' &
xrdb ~/.Xresources &
slstatus &
wmname LG3D &
redshift &
xcompmgr &
mpd &
exec dbus-launch dwm 
