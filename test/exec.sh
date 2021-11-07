#!/usr/bin/env bash

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c

if [ $(echo $?) = 0 ]; then

	./a.out

else
	echo -e "\n Compilation error will not execute!"
fi
