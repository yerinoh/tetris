#include <ncurses.h>
#include "Pane.h"

HelpPane::HelpPane(int x, int y, int w, int h) : Pane(x,y,w,h){}
void HelpPane::draw(){
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	wattron(win_, COLOR_PAIR(3));
	box(win_, 0, 0);
	wattroff(win_, COLOR_PAIR(3));
	mvwprintw(win_, 1,7, "H  E  L  P");
	mvwprintw(win_, 4,6, " <- : Left");
	mvwprintw(win_, 5,6, " -> : Right");
	mvwprintw(win_, 6,6, " ^ : Rotate");
	mvwprintw(win_, 7,6, "SPACE : DROP");
	mvwprintw(win_, 10,6, "Q : quit");
	wrefresh(win_);
}
