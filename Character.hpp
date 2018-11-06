#ifndef CHARACTER_H
# define CHARACTER_H

#include "Ncurses.hpp"
#include "Bullet.hpp"
// #include "Game.hpp"

class	Character {

	public:

		Character(void);
		Character(int x, int y);
		Character(int x, int y, int life);
		Character(Character &obj);
		virtual ~Character(void);
		Character &operator=(Character const &r);

		void		setPos(int x, int y);
		void		newLife(int i);

		int			getX(void);
		int			getY(void);

		void		moveRight(void);
		void		moveLeft(void);
		void		moveUp(void);
		void		moveDown(void);

		int			isAlive(void);

		int			collision(int x, int y);

	protected:
		int			_x;
		int			_y;
		int			_life;

};

#endif