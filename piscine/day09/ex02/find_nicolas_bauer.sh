cat $1 | grep -i 'nicolas\sbauer' | awk '{print $(NF-1)}'
