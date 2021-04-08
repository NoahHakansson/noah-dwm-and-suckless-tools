#!/bin/sh

# Only mute if volume is above 0
if [ $(pamixer --get-volume) -gt 0 ]
then
    pactl set-sink-mute @DEFAULT_SINK@ toggle
    if [ $(pamixer --get-mute) = "true" ]
    then
        # reload slstatus
        killall slstatus -HUP; slstatus&
        # notify muted
        #dunstify -a "changeVolume" -u low -i /home/noah/.config/dunst/volume-mute.png -r 1212 "Volume" "$(pamixer --get-volume-human)"
    else
        # reload slstatus
        killall slstatus -HUP; slstatus&
        # notify
        #dunstify -a "changeVolume" -u low -i /home/noah/.config/dunst/volume.png -r 1212 "Volume" "$(pamixer --get-volume-human)"
        # Play the volume changed sound
        canberra-gtk-play -i audio-volume-change -d "changeVolume"
    fi
fi

