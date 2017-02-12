#!/bin/bash

#check +1s
if [ ! -f /usr/local/bin/+1s ]; then
    echo "This huaji command needs +1s, plz install it first"
    exit
fi

#check args
case $# in
    [0] ) echo "ERROR";;
    [1] ) echo $1;;
    *)    sm_error "You are even wrong in printing error message?! MDZZ";;
esac
+1s
exit
