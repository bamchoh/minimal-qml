#!/bin/bash

rm -rf CMakeCache.txt 
~/qt-raspi/bin/qt-cmake CMakeLists.txt 
cmake --build . --clean-first --parallel 4
ssh -t bamchoh@192.168.0.7 sudo killall minimal-qml
scp minimal-qml bamchoh@192.168.0.7:~/
ssh -t bamchoh@192.168.0.7 sudo ~/run.sh
