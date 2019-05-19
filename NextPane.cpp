#include <ncurses.h>
#include "Pane.h"

NextPane::NextPane(int x, int y, int w, int h) : Pane(x,y,w,h){}
void NextPane::draw(){
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	wattron(win_, COLOR_PAIR(4));
	box(win_, 0, 0);
	wattroff(win_, COLOR_PAIR(4));
	mvwprintw(win_, 1,3, "NEXT : ");
  wrefresh(win_);
}
