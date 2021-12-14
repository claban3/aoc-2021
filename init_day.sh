#!/bin/bash
new_dir="day-$1";
mkdir $new_dir;
mkdir $new_dir/part-1;
mkdir $new_dir/part-1/cpp;
mkdir $new_dir/part-2;
mkdir $new_dir/part-2/cpp;

cp ./cpp-starter-code/Makefile $new_dir/part-1/cpp;
cp ./cpp-starter-code/problem.cpp $new_dir/part-1/cpp;

cp ./cpp-starter-code/Makefile $new_dir/part-2/cpp;
cp ./cpp-starter-code/problem.cpp $new_dir/part-2/cpp;

touch $new_dir/input.txt;
touch $new_dir/part-1/cpp/sample_input.txt;
touch $new_dir/part-2/cpp/sample_input.txt;
cd $new_dir/part-1;
cargo new rust;
cd ../part-2;
cargo new rust;
