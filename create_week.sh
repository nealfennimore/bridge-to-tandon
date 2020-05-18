#! /usr/bin/env bash

WEEK=$1
QUESTION_COUNT=$2

for i in $(seq 1 $QUESTION_COUNT); do
    dir="week-$WEEK/q$i"
    cpp_filename="nf2137_hw${WEEK}_q${i}.cpp"

    mkdir -p $dir

tee "$dir/$cpp_filename" <<EOF > /dev/null
    #include <iostream>

    int main() {
        return 0;
    }
EOF

tee "$dir/CMakeLists.txt" <<EOF > /dev/null
    cmake_minimum_required(VERSION 3.15)
    project(hw${WEEK}_q${i})

    set(CMAKE_CXX_STANDARD 14)

    add_executable(hw${WEEK}_q${i} nf2137_hw${WEEK}_q${i}.cpp)
EOF

done