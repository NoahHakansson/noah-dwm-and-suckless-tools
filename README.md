# Noah's dwm and suckless tools

Personal startup file include: (uses dwm autostart patch)

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
