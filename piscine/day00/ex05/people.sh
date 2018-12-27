#!/bin/sh
ldapsearch -H ldap://ldap-master.42.us.org -x -L "uid=z*" | grep '^cn' | sort -r --ignore-case | cut -b 5-
