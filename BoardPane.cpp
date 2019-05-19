#include <ncurses.h>
#include "Pane.h"
#include "Board.h"
BoardPane::BoardPane(int x, int y, int w, int h) : Pane(x,y,w,h){}
void BoardPane::draw(){
    init_pair(5, COLOR_BLUE, COLOR_BLACK);  // BoardPane 색
    wattron(win_, COLOR_PAIR(5));
    mvwhline(win_, 1, 0, ACS_DIAMOND, width_);
    mvwvline(win_, 1, 0, ACS_DIAMOND, height_-2);
    mvwvline(win_, 1, width_-1, ACS_DIAMOND, height_-2);
    mvwhline(win_, height_-1, 0, ACS_DIAMOND, width_);
    wattroff(win_, COLOR_PAIR(5));

    wrefresh(win_);
}
