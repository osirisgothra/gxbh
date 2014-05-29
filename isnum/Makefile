#
# Makefile
#
# outputs: isnum (binary)
# inputs: isnum.cpp
#
# program name: isnum
#
# purpose: can be used as a shell expression to determine if a number is a number, or to get the integral, decimal, or hexidecimal
#          value(s) of each argument. At least one item should be passed or isnum will fail.
#
# return values:  first of all, if no values are given, the program returns '1' and writes a zero (0) to standard output.
#                 if there are arguments, the values defined in the table below are written on each line per argument to
#           		  standard output and the program returns '0'.
#
# value table
#
# string value						printted result
# -----------------------------------------------------------------------------------------------------------------------------
# valid number            decimal representation of that number, converted to base 10.
# valid floating point#		same as input, but overflow checks are made, exponent representation typical of C libraries is given
# text or unsupported#    a value of -1 is written to standard output to signify a unsupported value
#                         if you work with signed decimals you might want to change this to MIN(float) or something like it to 
#                         differentiate between the two.
#
# Program Compiling, Setup and Installation/Requirements
# -----------------------------------------------------------------------------------------------------------------------------
# Simple enough however I didnt include an configure script, or a configure.in so autoconf is not required at all
# There are however these requirements: <stdio.h> <stdlib.h> and <string.h> which are typically included with
#                                       gc++, but you also need <iostream> so you will need v4.7 or compatible
#                                       usually this is also included with most installations of gcc and its companion headers
#
# Installation (needs sudo permissions)
# -----------------------------------------
#
# To compile and install, type 'make install' --- you will be prompted to enter your password by sudo
#
# If you want to get rid of it just type 'make uninstall' --- see above comment
#
# I even included 'uninstallme.sh' which will get rid of the source tree all together
# and wipe it off the face of the earth, if you just want this gone, type ./uninstallme.sh at the command prompt
# assuming you are in this file's directory!
#
# enjoy (questions can be fwded to osirisgothra@hotmail.com)
# 
# THIS SOFTWARE IS PUBLIC DOMAIN, NO LICENSE, NO OWNERSHIP CLAIMS BY THE ORIGINAL AUTHOR!
# NO LIABILITIES EITHER, I HERBY GIVE UP ALL OWNERSHIP OF THE DOCUMENTS IN THIS SOURCE TREE*

isnum: isnum.cpp
		   g++ isnum.cpp -o isnum
		   
clean: 
			 rm -f ./isnum
			 
install: ./isnum
			sudo mv -f ./isnum /usr/bin

uninstall: /usr/bin/isnum
			sudo rm -f -v /usr/bin/isnum


# *=j/k
