#ifndef __BLOCK_H__
#define __BLOCK_H__

class Block {
public:
  int x_, y_;
  WINDOW* win_;
  int width_, height_;
  int block_form;
  int rotate_num;
  int block_[7][4][4][4];
  int pos_x, pos_y;

  Block();
  Block(int block_type);
  ~Block();

  void draw();
  void erase();
  void Block_move(int selector);
};

#endif
