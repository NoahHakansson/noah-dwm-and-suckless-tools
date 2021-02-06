# noah-dwm-and-suckless-tools, "Version 1.0.0"

Personal startup file include: (uses dwm autostart patch)

~/.dwm/autostart.sh
Contains:

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
