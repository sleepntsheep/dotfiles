#!/bin/bash

feh --bg-scale ~/d/Pictures/Random/wall2.png &
setxkbmap -layout 'us,th' -variant ,ThaiMnc -option 'grp:alt_shift_toggle'
xrdb ~/.Xresources
exec dbus-launch dwm
dwmblocks &
