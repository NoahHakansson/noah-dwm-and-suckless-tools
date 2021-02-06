# noah-dwm-and-suckless-tools

Personal configuratio files include:

~/.dwm/autostart.sh
Contains:
"""
#!/bin/sh
sh /home/noah/.screenlayout/dual-monitor.sh # Xorg monitor setup file.
blueman-applet &
sleep .5
volumeicon &
sleep .2
nm-applet &
feh --bg-scale /home/noah/pictures/dball.png
exec slstatus
"""