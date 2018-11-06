#ifndef PLAYER_H
# define PLAYER_H

#include "Character.hpp"

class	Player : public Character {

	public:

		Player(void);
		Player(int x, int y);
		Player(int x, int y, int life);
		Player(Player &obj);
		virtual ~Player(void);
		Player &operator=(Player const &r);

		int		die(void);

};

#endif