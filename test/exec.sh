#!/usr/bin/env bash

all()
{
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 printf.c  std_funcs.c  test.c  type_funcs.c

	if [ $(echo $?) = 0 ]; then

		./a.out
		rm a.out

	else
		echo -e "\n Compilation error will not execute!"
	fi
}

itoa()
{
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89  std_funcs.c  test1.c

	if [ $(echo $?) = 0 ]; then

		./a.out
		rm a.out

	else
		echo -e "\n Compilation error will not execute!"
	fi
}
strlen()
{
	gcc -Wall -Werror -Wextra -pedantic -std=gnu89  std_funcs.c  test2.c
	if [ $(echo $?) = 0 ]; then

                ./a.out
                rm a.out

        else
                echo -e "\n Compilation error will not execute!"
        fi
}

case $1 in
	all)
		all
		;;
	itoa)
		 itoa
	;;
	strlen)
		strlen
		;;

esac
