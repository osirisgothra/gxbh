#include <ncurses.h>
#include <curses.h>
#include "terminfo.h"

int main (int argc, const char* argv[], const char* envp[])
{

	WINDOW* TerminalWindow = newwin(0,0,0,0); // create window from terminal
	int curx = getcurx(TerminalWindow);
	curx += getzerocount(curx);        // add 1 if value is greater than zero
	curx--;
	delwin(TerminalWindow);
	return curx;
}
