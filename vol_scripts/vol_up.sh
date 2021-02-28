#!/bin/sh

# Limit max volume to 200%
if [ $(pamixer --get-volume) -lt 200 ]
then
    pactl set-sink-volume @DEFAULT_SINK@ +5%
    killall slstatus
    slstatus &
fi

