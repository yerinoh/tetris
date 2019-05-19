#include "Pane.h"
#include "Board.h"
#include <iostream>

InfoPane::InfoPane(int x, int y, int w, int h) : Pane(x,y,w,h){}
void InfoPane::draw(){
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(21, COLOR_YELLOW, COLOR_BLACK);
    wattron(win_, COLOR_PAIR(2));
    box(win_, 0, 0);
    wattroff(win_, COLOR_PAIR(2));
    mvwprintw(win_, 1,1, "Your level >>>>>> ");
    mvwprintw(win_, 2,1, "Full lines >>>>>> ");
    mvwprintw(win_, 2,width_-6, "%d", score);

    mvwprintw(win_, 3,2, "S C O R E >>>>>> ");
    wattron(win_, COLOR_PAIR(21));
    mvwprintw(win_, 3,19, "%d", score*10);
    wattroff(win_, COLOR_PAIR(21));
    wrefresh(win_);
}
