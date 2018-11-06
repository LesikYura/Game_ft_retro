#include "Enemy.hpp"

Enemy::Enemy(void) : Character() {}

Enemy::Enemy(int x, int y) : Character(x, y, 1) {}

Enemy::Enemy(int x, int y, int life)
{
	x = this->_x;
	y = this->_y;
	life = this->_life;
}

Enemy::Enemy(Enemy &obj) { 
	*this = obj;
}

Enemy::~Enemy(void) {}

Enemy &Enemy::operator=(Enemy const &r) {
	this->_x = r._x;
	this->_y = r._y;
	this->_life = r._life;
	return (*this);
}

int			Enemy::leftRightMovement(int y_max, int x_max) {
	float prob = 1.0 * rand() / RAND_MAX;

	if (prob < 0.47) {
		if (this->_x > 2)	moveLeft();
		else				moveRight();
	}
	else if (prob < 0.95) {
		if (this->_x < x_max - 3)	moveRight();
		else				moveLeft();
	}
	else {
		if (this->_y < (y_max - 3))	moveDown();
		else {
			//delete the enemy?
			this->_life = 0;
			return (1);
		}
	}
	return (0);
}

int			Enemy::collision(int x, int y) {
	if ((this->_x == x && this->_y == y))
	{
		this->_life = 0;
		return (1);
	}
	return (0);
}


