
#include <ncurses.h>
#include <unistd.h> //задержка
#include "Ncurses.hpp"
#include "Tool.hpp"
#include "Game.hpp"
#include "Character.hpp"
#include "Enemy.hpp"

#define msleep(msec) usleep(msec * 1000)

int main()
{
	unsigned int _usleep;
	Ncurses 	nc;
	Game		game;
	Character	character;
	Enemy		enemy;

	nc.start_ncurses();
	if (nc.use_color() == -1)
		return (-1);
	nc.create_frame();
	move(36, 2);
	attron(COLOR_PAIR(1));
	printw("Press any button to start!");
	attroff(COLOR_PAIR(1));
	nc.help();
	keypad(stdscr, true);
	int x = character.getX();
	int y = character.getY();
	int k = 0;
	move(y, x);
	_usleep = 40000;
	nc.score(game.getScore(), game.getLevel(), game.getLife(), game.EnemyAmount, game.PlayerBulletAmount);
	while (game.checkEndofgame() == 0)
	{
		nc.score(game.getScore(), game.getLevel(), game.getLife(), game.EnemyAmount, game.PlayerBulletAmount);
		game.add_rm_star();
		game.key_nc(k);
		game.drawEnemiesMove();
		k = getch();
		game.drawBulletsMove();
		game.drawEnemyBulletsMove();
		game.makeEnemyBullet();
		timeout(0);
		usleep(_usleep);
		move(36, 2);
		printw("                              ");
	}
	nc.end_win();
	std::cout << "Score = " << game.getScore() * 10 << std::endl;
	// system("Leaks ft_retro");
	return 0;
}
