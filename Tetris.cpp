#include "Tetris.h"

using namespace std;

Tetris::Tetris() {
  initscr();
  start_color();
  cbreak();
  refresh();

  infoPane_ = new InfoPane(1, 1, 25, 5);
  helpPane_ = new HelpPane(1, 6, 25, 12);
  nextPane_ = new NextPane(1, 18, 25, 5);
  boardPane_ = new BoardPane(30, 0, 22, 22);
  statPane_ = new StatPane(60, 3, 20, 20);

  gameOver = false;
}

Tetris::~Tetris() {
  delete infoPane_;
  delete helpPane_;
  delete nextPane_;
  delete boardPane_;
  delete statPane_;
  endwin();
}

void Tetris::updateScreen() {
  infoPane_ -> draw();
  helpPane_ -> draw();
  nextPane_ -> draw();
  boardPane_ -> draw();
  statPane_ -> draw();
}

void Tetris::update_score() {
  infoPane_ -> score += 1;
  infoPane_ -> draw();
}

void Tetris::move(Block &b, Board &oldb, int input_key)
{
  keypad(stdscr, TRUE);

    if(input_key==KEY_LEFT)
    {
        if (!collision(b, oldb, -1, 0) )
        b.Block_move(1);
    }
    else if(input_key== KEY_RIGHT)
    {
      if (!collision(b, oldb, 1, 0) )
        b.Block_move(2);
    }
    else if(input_key== 'g'||input_key==KEY_DOWN)
    {
      if (!collision(b, oldb, 0, 1) )
        b.Block_move(0);
    }
    else if(input_key==KEY_UP)
    {
       if (!collision(b, oldb, 0, 0) )
        b.Block_move(3);
    }
    else if(input_key==32)
    {
       while(!collision(b, oldb, 0, 1))
        b.Block_move(0);
    }
}
void Tetris::play() {
  updateScreen();

  Board board;

  int input;
  int temp = 1;
  srand(time(NULL));
  int count=rand()%7;
  statPane_->block_count[count]+=1;
  statPane_ -> draw();
  Block block = Block(count);
  clock_t start;
  while(input != 'q')
  {
    block.draw();

    input = 'g';
    move(block, board, input);

    start = clock();
    while ( (clock() - start ) < CLOCKS_PER_SEC )
    {
      if (kbhit())
      {
        input = getch();
        move(block, board, input);
        break;
      }
    }

    while ( temp != 0 )
    {
      temp = board.check_full();
      if ( temp != 0 )
      {
        board.bomb(temp);
        // erase_line(temp);
        new_board(board);
        update_score();
      }
    }
    temp = 1;
    if ( gameOver_function(board) ) break;
    if ( gameOver == true ) break;
  }
}

bool Tetris::collision(Block &b, Board &oldb, int nt_x, int nt_y)
{
  int type = b.block_form;
  int rot = b.rotate_num;
  if ( nt_x == 0 && nt_y == 0 )
  {
    for ( int x = 0; x < 4; x++ )
      for ( int y = 0; y < 4; y++ )
        if ( b.block_[type][( rot + 1 ) % 4][y][x] == 1 &&
          oldb.board[b.pos_y + y][b.pos_x + x] == 1 )
          return true;
  }
  else
  {
    for ( int x = 0; x < 4; x++ )
      for ( int y = 0; y < 4; y++ )
        if ( b.block_[type][rot][y][x] == 1 &&
          oldb.board[b.pos_y + y + nt_y][b.pos_x + x + nt_x] == 1)
        {
          if ( nt_y == 1)
            draw_board(b, oldb);
          return true;
        }
  }
  return false;
}

void Tetris::new_board(Board &oldb)
{
  init_pair(50, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(51, COLOR_BLUE, COLOR_BLUE);
  init_pair(52, COLOR_GREEN, COLOR_GREEN);
  init_pair(53, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(54, COLOR_RED, COLOR_RED);
  init_pair(55, COLOR_CYAN, COLOR_CYAN);
  init_pair(56, COLOR_WHITE, COLOR_WHITE);
  init_pair(57, COLOR_BLACK, COLOR_BLACK);

  win_ = newwin(10, 20, 1, 31);
  wbkgd(win_, COLOR_PAIR(57));
  wrefresh(win_);

  for ( int y = 0; y < 20; y++ )
  {
    for ( int x = 1; x < 11; x++ )
    {
      win_ = newwin(1, 2, y + 1, 29 + x * 2);
      wbkgd(win_, COLOR_PAIR(oldb.color[y][x]));
      wrefresh(win_);
    }
  }
}
void Tetris::draw_board(Block &b, Board &oldb)
{
  for ( int x = 0; x < 4; x++ )
    for ( int y = 0; y < 4; y++ )
      if ( b.block_[b.block_form][b.rotate_num][y][x] == 1 )
      {
        oldb.board[b.pos_y + y][b.pos_x + x] = 1;
        oldb.color[b.pos_y + y][b.pos_x + x] = b.block_form + 50;
      }
  if ( oldb.board[4][1] == 1 || oldb.board[5][1] ||
      oldb.board[4][2] == 1 || oldb.board[5][2] )
  {
    gameOver = true;
  }
  else
  {
    int check=rand()%7;
    statPane_->block_count[check]+=1;
      statPane_ -> draw();
    b = Block(check);
    b.draw();
  }
}

bool Tetris::gameOver_function(Board &oldb)
{
  for (int i = 1; i < 11; i++)
    if (oldb.board[0][i] == 1) return true;
  return false;
}

int Tetris::kbhit(void)
{
  struct timeval tv;
  fd_set read_fd;

  tv.tv_sec=0;
  tv.tv_usec=0;
  FD_ZERO(&read_fd);
  FD_SET(0,&read_fd);

  if(select(1, &read_fd, NULL, NULL, &tv) == -1) return 0;
  if(FD_ISSET(0,&read_fd)) return 1;

  return 0;
}
