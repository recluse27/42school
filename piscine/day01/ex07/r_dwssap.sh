#!/bin/sh
cat /etc/passwd | sed '1,10d' | sed -n 'p;n' | cut -d: -f 1 | rev | sort -r | sed -n "${T_FILE1},${T_FILE2} p" | tr -s '\n' ',\' | sed 's/, */, /g' | sed 's/..$/./g'
