#!/bin/sh

# Only lower volume if its above 0 and not muted
if [ $(pamixer --get-volume) -gt 0 ]
then
    # check if muted
    if [ $(pamixer --get-mute) = "true" ]
    then
        #notify muted
        dunstify -a "changeVolume" -u low -i /home/noah/.config/dunst/volume-mute.png -r 1212 "Volume" "$(pamixer --get-volume-human)"
    else
        # change volume
        pactl set-sink-volume @DEFAULT_SINK@ -5%
        # reload slstatus
        killall slstatus -HUP; slstatus&
        # notify
        #dunstify -a "changeVolume" -u low -i /home/noah/.config/dunst/volume.png -r 1212 "Volume" "$(pamixer --get-volume-human)"
        # Play the volume changed sound
        canberra-gtk-play -i audio-volume-change -d "changeVolume"
    fi
fi

