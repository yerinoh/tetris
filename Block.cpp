#include <ncurses.h>
#include "Block.h"

const int block[7][4][4][4] =
{
  // O-Block
  {
    {
      { 0, 1, 1, 0 },
      { 0, 1, 1, 0 },
      { 0, 0, 0, 0 },
      { 0, 0, 0, 0 }
    },
    {
      { 0, 1, 1, 0 },
      { 0, 1, 1, 0 },
      { 0, 0, 0, 0 },
      { 0, 0, 0, 0 }
    },
    {
      { 0, 1, 1, 0 },
      { 0, 1, 1, 0 },
      { 0, 0, 0, 0 },
      { 0, 0, 0, 0 }
    },
    {
      { 0, 1, 1, 0 },
      { 0, 1, 1, 0 },
      { 0, 0, 0, 0 },
      { 0, 0, 0, 0 }
    }
  },
  // L-Block
  {
    {
      { 0, 1, 0, 0 },
      { 0, 1, 0, 0 },
      { 0, 1, 1, 0 },
      { 0, 0, 0, 0 }
    },
    {
      { 0, 0, 1, 0 },
      { 1, 1, 1, 0 },
      { 0, 0, 0, 0 },
      { 0, 0, 0, 0 }
    },
    {
      { 1, 1, 0, 0 },
      { 0, 1, 0, 0 },
      { 0, 1, 0, 0 },
      { 0, 0, 0, 0 }
    },
    {
      { 0, 0, 0, 0 },
      { 1, 1, 1, 0 },
      { 1, 0, 0, 0 },
      { 0, 0, 0, 0 }
    }
  },
  // J-Block
  {
    {
      { 0, 1, 0, 0 },
      { 0, 1, 0, 0 },
      { 1, 1, 0, 0 },
      { 0, 0, 0, 0 }
    },
    {
      { 0, 0, 0, 0 },
      { 1, 1, 1, 0 },
      { 0, 0, 1, 0 },
      { 0, 0, 0, 0 }
    },
    {
      { 0, 1, 1, 0 },
      { 0, 1, 0, 0 },
      { 0, 1, 0, 0 },
      { 0, 0, 0, 0 }
    },
    {
      { 1, 0, 0, 0 },
      { 1, 1, 1, 0 },
      { 0, 0, 0, 0 },
      { 0, 0, 0, 0 }
    }
    },
    // S-Block
    {
    {
      { 0, 1, 0, 0 },
      { 0, 1, 1, 0 },
      { 0, 0, 1, 0 },
      { 0, 0, 0, 0 }
    },
    {
      { 0, 1, 1, 0 },
      { 1, 1, 0, 0 },
      { 0, 0, 0, 0 },
      { 0, 0, 0, 0 }
    },
    {
      { 0, 1, 0, 0 },
      { 0, 1, 1, 0 },
      { 0, 0, 1, 0 },
      { 0, 0, 0, 0 }
    },
    {
      { 0, 1, 1, 0 },
      { 1, 1, 0, 0 },
      { 0, 0, 0, 0 },
      { 0, 0, 0, 0 }
    }
  },
  // Z-Block
  {
    {
      { 0, 1, 0, 0 },
      { 1, 1, 0, 0 },
      { 1, 0, 0, 0 },
      { 0, 0, 0, 0 }
    },
    {
      { 1, 1, 0, 0 },
      { 0, 1, 1, 0 },
      { 0, 0, 0, 0 },
      { 0, 0, 0, 0 }
    },
    {
      { 0, 1, 0, 0 },
      { 1, 1, 0, 0 },
      { 1, 0, 0, 0 },
      { 0, 0, 0, 0 }
    },
    {
      { 1, 1, 0, 0 },
      { 0, 1, 1, 0 },
      { 0, 0, 0, 0 },
      { 0, 0, 0, 0 }
    }
  },
  // T-Block
  {
    {
      { 0, 1, 0, 0 },
      { 1, 1, 1, 0 },
      { 0, 0, 0, 0 },
      { 0, 0, 0, 0 }
    },
    {
      { 0, 1, 0, 0 },
      { 1, 1, 0, 0 },
      { 0, 1, 0, 0 },
      { 0, 0, 0, 0 }
    },
    {
      { 0, 0, 0, 0 },
      { 1, 1, 1, 0 },
      { 0, 1, 0, 0 },
      { 0, 0, 0, 0 }
    },
    {
      { 0, 1, 0, 0 },
      { 0, 1, 1, 0 },
      { 0, 1, 0, 0 },
      { 0, 0, 0, 0 }
    }
  },
  // I-Block
  {
    {
      { 0, 1, 0, 0 },
      { 0, 1, 0, 0 },
      { 0, 1, 0, 0 },
      { 0, 1, 0, 0 }
    },
    {
      { 0, 0, 0, 0 },
      { 1, 1, 1, 1 },
      { 0, 0, 0, 0 },
      { 0, 0, 0, 0 }
    },
    {
      { 0, 1, 0, 0 },
      { 0, 1, 0, 0 },
      { 0, 1, 0, 0 },
      { 0, 1, 0, 0 }
    },
    {
      { 0, 0, 0, 0 },
      { 1, 1, 1, 1 },
      { 0, 0, 0, 0 },
      { 0, 0, 0, 0 }
    }
  }
};

Block::Block(){}
Block::Block(int block_type)
{
  for ( int t = 0; t < 7; t++ )
    for ( int r = 0; r < 4; r++ )
      for ( int x = 0; x < 4; x++ )
        for ( int y = 0; y < 4; y++ )
          block_[t][r][x][y] = block[t][r][x][y];
  x_ = 37;
  y_ = 1;
  width_ = 2;
  height_ = 1;
  pos_x = 4;
  pos_y = 0;
  block_form = block_type;
  rotate_num = 0;
}

Block::~Block()
{
  delwin(win_);
}

void Block::draw()
{
  init_pair(10, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(11, COLOR_BLUE, COLOR_BLUE);
  init_pair(12, COLOR_GREEN, COLOR_GREEN);
  init_pair(13, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(14, COLOR_RED, COLOR_RED);
  init_pair(15, COLOR_CYAN, COLOR_CYAN);
  init_pair(16, COLOR_WHITE, COLOR_WHITE);
  for ( int x = 0; x < 4; x++ )
    for ( int y = 0; y < 4; y++ )
      if ( block[block_form][rotate_num][y][x] == 1 )
        {
        win_ = newwin(height_, width_, y_ + y, x_ + 2 * x);
        wbkgd(win_, COLOR_PAIR(block_form + 10));
        wrefresh(win_);
      }
}

void Block::Block_move(int selector)
{
 erase();
  if(selector==0)
 {
   y_+= 1;
   pos_y=pos_y + 1;
   draw();
 }
 else if(selector==1)
 {
   x_-= 2;
   pos_x=pos_x - 1;
   draw();
 }
 else if(selector==2)
 {
    x_+=2;
   pos_x=pos_x + 1;
   draw();
 }
 else
 {
  rotate_num++;
  if ( rotate_num == 4 )
    rotate_num = 0;
  draw();
 }
}

void Block::erase()
{
  init_pair(57, COLOR_BLACK, COLOR_BLACK);
  for ( int x = 0; x < 4; x++ )
    for ( int y = 0; y < 4; y++ )
      if ( block[block_form][rotate_num][y][x] == 1 )
      {
        win_ = newwin(height_, width_, y_ + y, x_ + 2 * x);
        wbkgd(win_, COLOR_PAIR(57));
        wrefresh(win_);
      }
}
