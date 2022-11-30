#!/bin/bash

if [ $# -gt 2 ]
then
	echo "./rush.sh [all|vector|map|set] [0 < number < 100]"
	exit
fi
if [ "$2" != "" ]
then
	if [ $2 -lt 100 ] && [ $2 -gt 0 ]
	then
		PREC="PREC=""$2"
	else
		echo "0 < PREC < 100"
		exit
	fi
fi
if [ "$1" == "all" ] || [ "$1" == "" ]
then
	TEST="TEST=""0"
elif [ "$1" == "vector" ]
then
	TEST="TEST=""1"
elif [ "$1" == "map" ]
then
	TEST="TEST=""2"
elif [ "$1" == "set" ]
then
	TEST="TEST=""3"
else
	echo "UNKOWN CONTAINER"
	exit 1
fi

make $TEST $PREC re test

if [ $? -ne 0 ]
then
	echo "CHANGE INCLUDE IN include.hpp"
	echo "CHANGE INCLUDE IN include.hpp"
	echo "CHANGE INCLUDE IN include.hpp"
	echo "CHANGE INCLUDE IN include.hpp"
	echo "CHANGE INCLUDE IN include.hpp"
	echo "CHANGE INCLUDE IN include.hpp"
	echo "CHANGE INCLUDE IN include.hpp"
	echo "CHANGE INCLUDE IN include.hpp"
	echo "CHANGE INCLUDE IN include.hpp"
	echo "CHANGE INCLUDE IN include.hpp"
	echo "CHANGE INCLUDE IN include.hpp"
fi
