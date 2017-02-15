#!/bin/bash

cd ${HOME}/.smalltools/mvv/
case $1 in
    "kill" )    lsof "mvv_transfer_log" | grep sh | awk '{print $2}' | xargs kill; echo "mvv_transfer killed at $(date)" >> mvv_transfer_log;;
    "start" )   nohup sh mvv.sh >> mvv_transfer_log &
                echo "mvv_transfer starts at $(date)" >> mvv_transfer_log;;
    "peek" )    lsof "mvv_transfer_log" | grep sh | xargs echo;;
    * )         echo "Usage: kill, start, peek";;
esac
