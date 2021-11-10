#!/usr/bin/env bash

test1()
{
	gcc -Wall -Werror -Wextra -Wno-format -pedantic -std=gnu89 printf.c  std_funcs.c  test.c  type_funcs.c

	if [ $(echo $?) = 0 ]; then

		valgrind --track-origins=yes ./a.out
		./a.out
		rm a.out

	else
		echo -e "\n Compilation error will not execute!"
	fi
}

test2()
{
	gcc -Wall -Werror -Wextra -Wno-format -pedantic -std=gnu89  std_funcs.c  test1.c

	if [ $(echo $?) = 0 ]; then

		./a.out
		rm a.out

	else
		echo -e "\n Compilation error will not execute!"
	fi
}

test3()
{
	gcc -Wall -Werror -Wextra -Wno-format -pedantic -std=gnu89  std_funcs.c  test2.c
	if [ $(echo $?) = 0 ]; then

		./a.out
		rm a.out

		else
			echo -e "\n Compilation error will not execute!"
	fi
}

test4()
{
	gcc -Wall -Werror -Wextra -Wno-format -pedantic -std=gnu89 printf.c  std_funcs.c  test3.c  type_funcs.c
	if [ $(echo $?) = 0 ]; then

		./a.out
		rm a.out

		else
			echo -e "\n Compilation error will not execute!"
	fi
}

test5()
{

	gcc -Wall -Werror -Wextra -Wno-format -pedantic -std=gnu89 printf.c  std_funcs.c  test4.c  type_funcs.c
	if [ $(echo $?) = 0 ]; then

		./a.out
		rm a.out

		else
			echo -e "\n Compilation error will not execute!"
	fi
}

test6()
{

	gcc -Wall -Werror -Wextra -Wno-format -pedantic -std=gnu89 printf.c  std_funcs.c  test5.c  type_funcs.c
	if [ $(echo $?) = 0 ]; then

		./a.out
		rm a.out

		else
			echo -e "\n Compilation error will not execute!"
	fi
}

test7()
{

	gcc -Wall -Werror -Wextra -Wno-format -pedantic -std=gnu89 printf.c  std_funcs.c  test6.c  type_funcs.c
	if [ $(echo $?) = 0 ]; then

		./a.out
		rm a.out

		else
			echo -e "\n Compilation error will not execute!"
	fi
}

test8()
{

	gcc -Wall -Werror -Wextra -Wno-format -pedantic -std=gnu89 printf.c  std_funcs.c  test7.c  type_funcs.c
	if [ $(echo $?) = 0 ]; then

		./a.out
		rm a.out

		else
			echo -e "\n Compilation error will not execute!"
	fi
}
case $1 in
	test1)
		test1
		;;
	test2)
		 test2
	;;
	test3)
		test3
		;;
	test4)
		test4
		;;
	test5)
		test5
		;;
	test6)
		test6
		;;
	test7)
		test7
		;;
	test8)
		test8
		;;
	*)
		echo "Type a test number!"
		;;

esac
