#include <ncurses.h>
#include "Pane.h"

Pane::Pane(int x, int y, int w, int h) :x_(x), y_(y), width_(w), height_(h){
    win_ = newwin(h, w, y, x);
    for(int i=0;i<7;i++)
    {
      block_count[i]=0;
    }
  }
