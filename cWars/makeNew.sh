#! /bin/bash


if [[ $# -eq 0 ]]; then
	return
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

	## TODO remove spaces that bash puts in the front
	## tried to do it with sed like this but it didnt seem to want to
		## sed -i "s/^[[:space:]]*//" CMakeLists.txt 

	## Make boilerplate cpp file
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
