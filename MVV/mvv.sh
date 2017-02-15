#!bin/bash

while true; do
    echo "Transfer start at $(date)"
    if [[ $(find ${HOME}/Downloads/*.mp4 -not -path "." 2>> err_log) ]]; then
        mv ${HOME}/Downloads/*.mp4 $HOME/Desktop/Done_Seeding_Out
        echo "*.mp4 moved"
    fi

    if [[ $(find ${HOME}/Downloads/*.avi -not -path "." 2>> err_log) ]]; then
        mv ${HOME}/Downloads/*.avi $HOME/Desktop/Done_Seeding_Out
        echo "*.avi moved"
    fi

    if [[ $(find ${HOME}/Downloads/*.mkv -not -path "." 2>> err_log) ]]; then
        mv ${HOME}/Downloads/*.mkv $HOME/Desktop/Done_Seeding_Out
        echo "*.mkv moved"
    fi

    boom=$(find ${HOME}/Downloads/* -type d 2>>/dev/null)
    for subd in $boom; do

        if [[ $(find $subd/*.mp4 $subd/*.avi $subd/*.mkv -not -path "." 2>> err_log) ]]; then
            mv "$subd"/ ${HOME}/Desktop/Done_Seeding_Out 2>> err_log
            echo "Folder $subd moved"
            continue
        fi

    done
    echo "Transfer done at $(date)"
    sleep 3h
done
