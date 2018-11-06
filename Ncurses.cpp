
#include "Tool.hpp"
#include "Ncurses.hpp"
#include "Game.hpp"

Ncurses::Ncurses(void){}
Ncurses::~Ncurses(void){}

void	Ncurses::create_frame(void)
{
	refresh();
	box(this->win, 0, 0);
	wrefresh(win);
}

void	Ncurses::score(int score, int level, int life, int enem, int hp)
{
	move(2, 3);
	printw("SCORE: %d", score * 10);

	move(2, 18);
	printw("AMMO: %d", hp);

	move(2, 30);
	printw("LEVEL: %d", level);

	move(2, 45);
	printw("ENEMY: %d", enem);

	move(2, 59);
	attron(COLOR_PAIR(4));
	printw("LIFE: %d", life);
	attroff(COLOR_PAIR(4));
}

void	Ncurses::start_ncurses(void)
{
	int start_y = 1;
	int start_x = 1;

	initscr(); // Переход в curses-режим
	this->win = newwin(HIGHT, WIDTH, start_y, start_x);
	curs_set(0);
}

int		Ncurses::use_color(void)
{
	if (!has_colors())
	{
		printw("Terminal does not support color");
		getch();
		return (-1);
	}
	start_color();
	init_pair(1, 5, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	return (0);
}

void	Ncurses::end_win(void)
{
	endwin(); // Выход из curses-режима. Обязательная команда.
}

void Ncurses::help(void)
{
	move(37, 2);
	printw("1. Move left / right - left / right arrow!");
	move(38, 2);
	printw("2. Shot / Space button!");
	move(39, 2);
	printw("3. Exit / ESC button!");
	move(40, 2);
	printw("4. Cheat_mod / C button!");
	move(42, 2);
	attron(COLOR_PAIR(2));
	printw("HAVE FUN :-)");
	attroff(COLOR_PAIR(2));
}
