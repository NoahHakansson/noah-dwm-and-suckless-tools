#!/bin/sh

# Default directory used to store the temp image file.
cachedir="/tmp/scrotShot"

# If cachedir does not exist, create it
if [ ! -d "$cachedir" ]; then
        notify-send "ScrotShot" "$cachedir does not exist, creating..."
        mkdir -p "$cachedir"
fi

# sleep to counter bug of not working with dwm.
sleep 0.2

scrot -sb -f -o "/tmp/scrotShot/image.png" &&
xclip -selection clipboard -t image/png -i /tmp/scrotShot/image.png &&
rm /tmp/scrotShot/image.png &&
notify-send -u low "ScrotShot" "Screenshot saved to clipboard"
