#!/usr/bin/env bash
mkdir build
pushd ./build
cmake ..
cmake --build .
popd
