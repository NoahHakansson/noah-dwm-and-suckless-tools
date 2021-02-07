#!/bin/sh

# Limit max volume to 155%
if [ $(pamixer --get-volume) -lt 155 ]
then
    pactl set-sink-volume @DEFAULT_SINK@ +5%
    killall slstatus; slstatus &
fi

