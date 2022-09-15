REM ================= PSX DEVELOPMENT ENVIRONMENT VARIABLES =============
REM       RELEASE 1.8 LIBRARY 3.6.1 Date: 1-31-1998 Time: 21:38:44
set PATH=C:\Psyq\bin;
set PSX_PATH=C:\Psyq\bin
set LIBRARY_PATH=C:\Psyq\lib
set C_PLUS_INCLUDE_PATH=C:\Psyq\include
set C_INCLUDE_PATH=C:\Psyq\include
set PSYQ_PATH=C:\Psyq\bin

set COMPILER_PATH=C:\Psyq\bin
set GO32=DPMISTACK 1000000 
set G032TMP=C:\WINDOWS\TEMP
set TMPDIR=C:\WINDOWS\TEMP

ccpsx -O3 -Xo$80010000 main.c -omain.cpe,main.sym,mem.map
cpe2x32 main.cpe
del main.sym
del main.cpe
del mem.map
pause
