#ifndef ENEMY_H
# define ENEMY_H
#include "Character.hpp"

#include <cstdlib>

class	Enemy: public Character {

	public:

		Enemy(void);
		Enemy(int x, int y);
		Enemy(int x, int y, int life);
		Enemy(Enemy &obj);
		virtual ~Enemy(void);
		Enemy &operator=(Enemy const &r);

		int			collision(int x, int y);
		int		leftRightMovement(int y_max, int x_max);

};

#endif