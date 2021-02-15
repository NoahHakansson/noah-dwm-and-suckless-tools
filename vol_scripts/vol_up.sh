#!/bin/sh

# Limit max volume to 175%
if [ $(pamixer --get-volume) -lt 175 ]
then
    pactl set-sink-volume @DEFAULT_SINK@ +5%
    killall slstatus
    slstatus &
fi

