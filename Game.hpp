#ifndef GAME_H
# define GAME_H

#include "Character.hpp"
# include "Player.hpp"
# include "Enemy.hpp"
# include "Bullet.hpp"
# include "Tool.hpp"
# include <cstdlib>

class	Game {

	public:

		Game(void);
		Game(Game &obj);
		virtual ~Game(void);
		Game &operator=(Game const &r);

		void	makeEnemy(void);
		void	makePlayer(void);

		void	makePlayerBullet(void);
		void	makeEnemyBullet(void);

		void	drawBulletsMove(void);
		void	drawEnemyBulletsMove(void);


		int		checkEndofgame(void);
		int		getScore(void);
		int		getLife(void);
		int		getLevel(void);
		void	setEndgame(int i);
		int		countBullet(void);


		void	drawEnemiesMove(void);//for vizu
		void	deleteMove(void);//for vizu

		void	drawPlayerMove(void);//for vizu

		void	drawPlayer(void);//for vizu
		void	drawEnemy(void);//for vizu

		int		getMenu(void);
		void	menuInput(int c);
		void	moveMenu(int i);


		int		getBulletCount(void);

		int		EnemyAmount;
		int		PlayerBulletAmount;

		int		key_nc(int k);
		void	add_rm_star(void);

	  private:

		

		int		_enemydeath;
		int		_endofgame;
		int		_score;
		int		_level;

		Character character;
		Enemy 	*_enemy;
		Player	_player;

		Bullet	*_bullet;
		Bullet	*_enemybullet;
		int		_bulletspd;
		int		_enemybulletspd;


		int		_AsteroidAmount;
		int		_EnemyBulletAmount;

		int		_hitCheck(int x, int y);
		int		_playerHitCheck(int x, int y);
};

#endif
