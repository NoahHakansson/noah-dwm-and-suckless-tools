#!/bin/sh

    # change brightness
    sudo brightnessctl set 10%-
    # notify
    dunstify -a "changeVolume" -u low -i /home/noah/.config/dunst/brightness.png -r 1212 "Brightness" "$(brightnessctl -m | awk -F[=,] '{print $4}')"
    # Play the volume changed sound
    canberra-gtk-play -i audio-volume-change -d "changeVolume"

