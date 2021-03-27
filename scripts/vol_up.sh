#!/bin/sh

# Limit max volume to 200%
if [ $(pamixer --get-volume) -lt 200 ]
then
    pactl set-sink-volume @DEFAULT_SINK@ +5%
    # killall slstatus
    # slstatus &
    # echo $(pamixer --get-volume) >> /tmp/xobpipe
    dunstify -a "changeVolume" -u low -i /home/noah/.config/dunst/volume.png -r 1212 "Volume" "$(pamixer --get-volume-human)"
    # Play the volume changed sound
    canberra-gtk-play -i audio-volume-change -d "changeVolume"

fi

