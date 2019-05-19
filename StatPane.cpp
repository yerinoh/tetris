#include <ncurses.h>
#include "Pane.h"
#include "Board.h"

StatPane::StatPane(int x, int y, int w, int h) : Pane(x,y,w,h){}
  void StatPane::draw(){
    init_pair(6, COLOR_WHITE, COLOR_BLACK);
    init_pair(61, COLOR_BLUE, COLOR_BLACK);
    init_pair(63, COLOR_CYAN, COLOR_BLACK);
    init_pair(64, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(65, COLOR_RED, COLOR_BLACK);
    init_pair(66, COLOR_YELLOW, COLOR_BLACK);
    init_pair(67, COLOR_GREEN, COLOR_BLACK);

    wattron(win_, COLOR_PAIR(6));
    box(win_, 0, 0);
    wattroff(win_, COLOR_PAIR(6));
    mvwprintw(win_, 0, 5, "STATISTICS");

    wattron(win_, COLOR_PAIR(61));
    mvwhline(win_, 2, 2, ACS_CKBOARD, 6);
    mvwhline(win_, 3, 2, ACS_CKBOARD, 2);
    mvwprintw(win_, 2, 12,"%d", block_count[1]);
    wattroff(win_, COLOR_PAIR(61));
    // 첫번째 모양
    wattron(win_, COLOR_PAIR(6));
    mvwhline(win_, 4, 6, ACS_CKBOARD, 8);
    mvwprintw(win_, 4, 16,"%d",block_count[6]);
    wattroff(win_, COLOR_PAIR(6));
    // 두번째 모양
    wattron(win_, COLOR_PAIR(63));
    mvwhline(win_, 6, 2, ACS_CKBOARD, 6);
    mvwhline(win_, 7, 4, ACS_CKBOARD, 2);
    mvwprintw(win_, 6, 12,"%d", block_count[5]);
    wattroff(win_, COLOR_PAIR(63));
    // 세번째 모양
    wattron(win_, COLOR_PAIR(64));
    mvwhline(win_, 8, 10, ACS_CKBOARD, 4);
    mvwhline(win_, 9, 8, ACS_CKBOARD, 4);
    mvwprintw(win_, 8, 16, "%d",block_count[3]);
    wattroff(win_, COLOR_PAIR(64));
    // 네번째 모양
    wattron(win_, COLOR_PAIR(65));
    mvwhline(win_, 10, 2, ACS_CKBOARD, 4);
    mvwhline(win_, 11, 4, ACS_CKBOARD, 4);
    mvwprintw(win_, 10, 12,"%d", block_count[4]);
    wattron(win_, COLOR_PAIR(65));
    // 다섯번째 모양
    wattron(win_, COLOR_PAIR(66));
    mvwhline(win_, 12, 9, ACS_CKBOARD, 4);
    mvwhline(win_, 13, 9, ACS_CKBOARD, 4);
    mvwprintw(win_, 12, 16,"%d", block_count[0]);
    wattroff(win_, COLOR_PAIR(66));
    // 여섯번째 모양
    wattron(win_, COLOR_PAIR(67));
    mvwhline(win_, 14, 2, ACS_CKBOARD, 6);
    mvwhline(win_, 15, 6, ACS_CKBOARD, 2);
    mvwprintw(win_, 14, 12,"%d", block_count[2]);
    wattroff(win_, COLOR_PAIR(67));
    // 일곱번째 모양
    int sum=0;
    for(int i=0;i<7;i++)
      sum+=block_count[i];
    mvwhline(win_, 16, 2, ACS_S7, width_-3);
    mvwprintw(win_, 18,4, "COUNT >>>>> %d",sum);
    wrefresh(win_);
}
