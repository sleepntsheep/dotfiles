#!/bin/bash

#feh --bg-scale ~/d/pic/wall/momokuri_crop.png &
#setxkbmap -layout 'us,th' -variant ,ThaiMnc -option 'grp:alt_shift_toggle' &
#xrdb ~/.Xresources &
#slstatus &
#redshift &
#xcompmgr &
#mpd &

case $1 in
    dwm)
        wmname LG3D &
        exec dbus-launch dwm
        ;;
    *)
        wmname LG3D &
        exec dbus-launch dwm
        ;;
esac
