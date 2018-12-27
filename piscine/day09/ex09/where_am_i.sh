#!/bin/sh
if [[ $(arp -a | awk -F ' ' '{print $2}' | tr -d '()') ]]; then
    arp -a | awk -F ' ' '{print $2}' | tr -d '()'
else
    echo "I am lost!\n"
fi
