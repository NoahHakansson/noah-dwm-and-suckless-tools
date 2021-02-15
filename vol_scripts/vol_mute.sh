#!/bin/sh

# Only mute if volume is above 0
if [ $(pamixer --get-volume) -gt 0 ]
then
    pactl set-sink-mute @DEFAULT_SINK@ toggle
    killall slstatus
    slstatus &
fi

