#!/bin/sh

# Only lower volume if its above 0
if [ $(pamixer --get-volume) -gt 0 ]
then
    pactl set-sink-volume @DEFAULT_SINK@ -5%
    # killall slstatus
    # slstatus &
    # echo $(pamixer --get-volume) >> /tmp/xobpipe
    dunstify -a "changeVolume" -u low -i audio-volume-high -r 1212 "Volume" "$(pamixer --get-volume-human)"
    # Play the volume changed sound
    canberra-gtk-play -i audio-volume-change -d "changeVolume"
fi

