# Noah's dwm and suckless tools
Just my WM etc.. that i use daily, just keeping this git repo for personal convenience.
Feel free to use any of the programs or scripts here as you wish (:

# Personal startup file include: (uses dwm autostart patch)

~/.dwm/autostart.sh
example:

```
#!/bin/sh
sh /home/noah/.screenlayout/dual-monitor.sh # Xorg monitor setup file.
blueman-applet &
sleep .5
volumeicon &
sleep .2
nm-applet &
feh --bg-scale /home/noah/pictures/dball.png
exec slstatus
```
