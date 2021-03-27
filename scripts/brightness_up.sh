#!/bin/sh

    sudo brightnessctl set +10%
    dunstify -a "changeVolume" -u low -i /home/noah/.config/dunst/brightness.png -r 1212 "Brightness" "$(brightnessctl -m | awk -F[=,] '{print $4}')"

