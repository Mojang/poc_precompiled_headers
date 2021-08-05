#!/bin/sh +x

export CC=$(which clang)
export CXX=$(which clang++)

cmake . -DPCH_OFF=true

make VERBOSE=1
