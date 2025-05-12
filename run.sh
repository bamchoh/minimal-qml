#! /bin/bash

if [ 1 -gt $#1 ]; then
  echo "Please set the path of executaable file"
  exit 1
fi

export XDG_RUNTIME_DIR=/run/user/1000
export LD_LIBRARY_PATH=/usr/local/qt6/lib

cage -- $1 --wayland-socket-name wayland-1