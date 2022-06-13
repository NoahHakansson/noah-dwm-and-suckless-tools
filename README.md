# Noah's dwm and suckless tools
Just my WM etc.. (:

# Personal startup file include: (uses dwm autostart patch)

~/.dwm/autostart.sh
example:

```
#!/bin/sh
xset r rate 300 80
setxkbmap -option caps:escape
#feh --bg-scale ~/walls/dark-forest.jpg
unclutter -idle 1 -jitter 2 -root -reset &
picom &
blueman-applet &
sleep .5
nm-applet &
exec slstatus
```
