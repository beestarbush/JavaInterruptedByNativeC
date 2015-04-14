#!/bin/bash

echo "Compiling Java code..."
javac StartProgram.java InterruptHandler.java InterruptListener.java

echo "Generating C header file for current Java Class..."
javah StartProgram
javah -stubs StartProgram

echo "Compile the C code..."
gcc -I /usr/lib/jvm/jdk-8-oracle-arm-vfp-hflt/include/ -I /usr/lib/jvm/jdk-8-oracle-arm-vfp-hflt/include/linux/ -fPIC -c StartProgramImp.c StartProgram.h

echo "Linking into shared libraries..."
gcc -shared -W1,-soname,libnativeclass.so.1 -o libnativeclass.so.1.0 StartProgramImp.o

echo "Renaming library files to usefull names..."
cp libnativeclass.so.1.0 libnativeclass.so

echo "Setting library path..."
export LD_LIBRARY_PATH='pwd':$LD_LIBRARY_PATH

echo "Application can now be run with: java -Djava.library.path=. StartProgram"