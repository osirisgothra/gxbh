#!/bin/sh
#
# uninstallme.sh
#
# wipe me from the face of the earth!
#
# purpose: DELETE PERMANANTLY all this source and folder from it's storage device/hard disk/etc
#
# syntax: ./uninstallme.sh [--for-sure]
# --for-sure -- skips the are you sure prompt
# REPLY= <- prevents accidental duplicate values, if set this way by some other program

if [ -z $1 ]; then args=$*; else args=none; fi

case $args in
	--help)
		cat $BASH_SOURCE | grep -P "(?<=^\#).*"
		;;
	*)

	if [ -z $1 ] || [ "$1" != "--for-sure" ]; then
		REPLY=
		echo "Are you sure you want to get rid of ALL THE FILES in this directory and all folders below this point??"
		echo -ne "type [i am sure] (no braces) to continue: "
	else
		REPLY="i am sure"
	fi

	if [ "$REPLY" == "i am sure" ]; then
		echo "Ok, really deleting in 5 seconds... ctrl-c aborts.."
		sleep 5
		local lastdir='pwd'
		rm -vfr * .[^.]*
		cd ..
		rmdir -v $lastdir
	else
		echo "Aborting, phrase [$REPLY] didnt match!"
	fi
	;;
esac
