#!/bin/sh +x

export CC=$(which clang)
export CXX=$(which clang++)

erradicate () {

        rm -rf CMakeCache.txt CMakeFiles cp.cmake Makefile
}

case "$1" in
on)
	erradicate
	cmake . -DPCH_OFF=true
	make clean
	make VERBOSE=1
        ;;
off)
	erradicate
	cmake . 
	make clean
	make VERBOSE=1
        ;;
*)
	echo "Usage: force_pch.sh {on|off}"
        exit 1
esac

exit 0
