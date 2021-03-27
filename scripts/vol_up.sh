#!/bin/sh

# Limit max volume to 200% and dont change if muted
if [ $(pamixer --get-volume) -lt 200 ]
then
    # check if muted
    if [ $(pamixer --get-mute) = "true" ]
    then
        #notify
        dunstify -a "changeVolume" -u low -i /home/noah/.config/dunst/volume-mute.png -r 1212 "Volume" "$(pamixer --get-volume-human)"
    else
        # change volume
        pactl set-sink-volume @DEFAULT_SINK@ +5%
        # notify
        dunstify -a "changeVolume" -u low -i /home/noah/.config/dunst/volume.png -r 1212 "Volume" "$(pamixer --get-volume-human)"
        # Play the volume changed sound
        canberra-gtk-play -i audio-volume-change -d "changeVolume"
    fi

fi

