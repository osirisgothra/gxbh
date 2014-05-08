
# makefile configuration for inkey
# gxbase experimental replacement for: 


inkey: inkey.cpp inkey.h
	g++ inkey.cpp inkey.h -o inkey

clean: inkey
	rm -f inkey

install: inkey
	sudo mkdir -p /usr/local/bin \
		sudo cp inkey /usr/local/bin

uninstall: /usr/local/bin/inkey
	sudo rm -f /usr/local/bin/inkey
	
