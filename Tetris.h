#ifndef __TETRIS_H__
#define __TETRIS_H__
#include <ncurses.h>
#include <iostream>
#include <cstdlib>
#include "Pane.h"
#include "Board.h"
#include "Block.h"

class Tetris {
  Pane *infoPane_, *helpPane_, *nextPane_, *boardPane_, *statPane_;
  WINDOW* win_;

public:
  Tetris();
  ~Tetris();
  int kbhit(void);

  void play();
  void updateScreen();
  void update_score();
  void move(Block &b, Board &oldb, int input_key);
  void draw_board(Block &b, Board &oldb);
  void new_board(Board &oldb);

  bool collision(Block &b, Board &oldb, int nt_x, int nt_y);
  bool gameOver_function(Board &oldb);

private:
  bool gameOver;
};

#endif
