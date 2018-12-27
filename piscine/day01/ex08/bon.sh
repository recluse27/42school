ldapsearch -H ldap://ldap-master.42.us.org -x -L sn='*bon*' | grep 'numEntries' | cut -b 15-
