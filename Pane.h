#ifndef __PANE_H__
#define __PANE_H__

#include "Board.h"
#include <ncurses.h>
#include <iostream>

class Pane{
public:
	int score;
	int block_count[7];
	int width_, height_;
	int x_, y_;
	WINDOW *win_;
	Pane(int x, int y, int w, int h);
	virtual ~Pane(){delwin(win_);}
	virtual void draw(){box(win_,0,0); wrefresh(win_);}
};

class InfoPane : public Pane{
public:
	InfoPane(int x, int y, int w, int h);
	void draw();
};

class BoardPane : public Pane{
public:
	BoardPane(int x, int y, int w, int h);
	void draw();
};

class StatPane : public Pane{
public:
	StatPane(int x, int y, int w, int h);
	void draw();
};

class HelpPane : public Pane{
public:
	HelpPane(int x, int y, int w, int h);
	void draw();
};


class NextPane : public Pane{
public:
	NextPane(int x, int y, int w, int h);
	void draw();
};

#endif
