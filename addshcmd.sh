#!/bin/bash

#check arg for list, remember to change line number of tail when changing the code.
if [ "$#" -eq 1 ] && [ $1 = "list" ]; then
    tail -n +51 /usr/local/bin/addshcmd | cut -b 2-
    exit
fi

#check arg fro addshcmd
if [ "$#" -ne 2 ]; then
    echo "Usage: addshcmd <name of cmd> <file of cmd> OR addshcmd list to browse commands added by this command"
    exit
fi

#initialize vars
name=$1
file=$2
exist=0

#check file existence
if [ !  -f $file ]; then
    echo "No such file: $file"
    exit
fi

#check and warn about ocuppied cammand
if [ -f /usr/local/bin/$name ]; then
    while true; do
        exist=1
        echo "This command has been implemented, are you sure you want to replace it? [y/n]"
        read yn
        case $yn in
            [Yy] ) rm /usr/local/bin/$name; break;;
            [Nn] ) exit;;
            * ) echo "Please answer y for YES or n for NO.";;
        esac
    done
fi

#add this command adn store it to the list below
cat $file > /usr/local/bin/$name
chmod u+x /usr/local/bin/$name
if [ $exist != 1 ]; then
    echo "#$name" >> /usr/local/bin/addshcmd
fi
#done 深藏功与名
echo "done."
exit

#list of command added:
#addshcmd
#+1s
