#include "Board.h"
#include <iostream>
#include <ncurses.h>
  // setting board, all 0
Board::Board()
{
  for ( int i = 0; i < 21; i++ )
    for ( int j = 0; j < 12; j++ )
    {
      if ( j == 0 || j == 11 || i == 20 ) board[i][j] = 1;
      else board[i][j] = 0;
    }

  for ( int i = 0; i < 21; i++ )
    for ( int j = 0; j < 12; j++ )
      color[i][j] = 0;
}

int Board::check_full()
{
  int count = 0;
  for ( int i = 0; i < 20; i++ )
  {
    for ( int j = 1; j < 11; j++ )
      if ( board[i][j] == 1 ) count++;

    if ( count == 10 ) return i;
    count = 0;
  }

  return 0;
}

void Board::bomb(int line)
{
  for ( int j = 1; j < 11; j++ )
  {
    board[line][j] = 0;
    color[line][j] = 0;
  }

  for ( int y = line; y > 0; y-- )
  {
    for ( int x = 0; x < 12; x++ )
    {
      board[y][x] = board[y-1][x];
      color[y][x] = color[y-1][x];
    }
  }
}
