#ifndef __BOARD_H__
#define __BOARD_H__

class Board {
public:
  int board[21][12];
  int color[21][12];

  Board();
  int check_full();
  void bomb(int line);
};
#endif
