#!/bin/bash

mkdir $HOME/.smalltools
mkdir $HOME/.smalltools/bin

if [[ ! echo "$PATH"|grep -q "$HOME/.smalltools/bin"]]; then
    PATH= "$HOME/.smalltools/bin:$PATH"
fi

sh addshcmd.sh addshcmd addshcmd.sh
rm addshcmd.sh

addshcmd +1s +1s
rm +1s

addshcmd mvv MVV/mvv_ctrl.sh
mkdir $HOME/.smalltools/mvv
mv MVV/mvv.sh $HOME/.smalltools/mvv
rm -r MVV
