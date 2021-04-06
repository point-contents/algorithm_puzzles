#! /bin/bash

if [ $# -eq 0  ]; then 
	clang-format -style=Webkit -dump-config  > .clang-format
	find . -iname "*.cpp" | xargs clang-format -i 
	rm -rf build ; mkdir build ; cd build ; cmake .. ; make
else
	if [ $1 = "rebuild" ]; then
		clang-format -style=Webkit -dump-config  > .clang-format
		find . -iname "*.cpp" | xargs clang-format -i 
		cd build ; make 
	else
		echo "I dont understand"
	fi
fi

