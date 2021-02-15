#!/bin/sh

# Only lower volume if its above 0
if [ $(pamixer --get-volume) -gt 0 ]
then
    pactl set-sink-volume @DEFAULT_SINK@ -5%
    killall slstatus
    slstatus &
fi

