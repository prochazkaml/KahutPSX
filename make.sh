#!/bin/sh

./buildassets.sh

export WINEPREFIX=$HOME/.psyq
wineconsole tools/make32.bat

mv main.exe ./root/KAHUT.EXE
mkpsxiso -y build.xml

./run.sh
