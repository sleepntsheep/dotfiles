#!/bin/sh

session=${1:-dwm}

case $session in 
    dwm  ) sbar & exec dbus-launch dwm ;;
    gnome) exec gnome-session ;;
    *    ) exec dbus-launch sowm ;;
esac
