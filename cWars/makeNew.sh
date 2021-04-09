#! /bin/bash


if [[ $# -eq 0 ]]; then
	echo "failure, must include a name for the new puzzle"
else
	target="$1"
	## add target to the directory CMake
	echo "add_subdirectory($target)" >> CMakeLists.txt

	## make and move into the new directory
	mkdir $target
	cd $target
	## create cmake for the file itself, executable names
	## must be unique in this instance, and cant be the same as folder??
	touch CMakeLists.txt
	executableName="${target}Exec"
	echo -e \
		"add_executable($executableName main.cpp)\n" \
		"set(CMAKE_CXX_STANDARD 11)\n" \
		"set(CMAKE_CXX_STANDARD_REQUIRED True)\n"\
	> CMakeLists.txt

	## removes leading spaces that bash puts in the front
	## inplace sed, sub an empty char if its after the start of line
	sed -i "s/^ //" CMakeLists.txt 

	## Make boilerplate cpp file, with a bunch of escaping
	touch main.cpp;
	echo -e \
			"#include <iostream>\n"\
			"#include <string>\n"\
			"#include <vector>\n"\
			"#include <map>\n"\
			"#include \"assert.h\"\n\n"\
			"int main()\n"\
			"{\n\n\n"\
			"return 0;\n"\
			"}"\
			> main.cpp
fi
