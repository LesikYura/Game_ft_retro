#include "Character.hpp"
# include "Game.hpp"

Character::Character(void) : _life(1) {}

Character::Character(int x, int y) : _x(x), _y(y), _life(1) {}

Character::Character(int x, int y, int life) : _x(x), _y(y), _life(life) {}

Character::Character(Character &obj) { 
	*this = obj;
}

Character::~Character(void) {}

Character &Character::operator=(Character const &r) {
	this->_x = r._x;
	this->_y = r._y;
	this->_life = r._life;
	return (*this);
}

void		Character::setPos(int x, int y) {
	this->_x = x;
	this->_y = y;
}

int			Character::getX(void) {
	if(this->_x > WIDTH + 2)
		this->_x = WIDTH + 2;
	else if(this->_x < 2)
		this->_x = 2;
	return (this->_x);
}

int			Character::getY(void) {
	if(this->_y > HIGHT + 2)
		this->_y = HIGHT + 2;
	else if(this->_y < 2)
		this->_y = 2;
	return (this->_y);
}

void		Character::moveRight(void) {
	this->_x++;
	Character::setPos(_x, _y);
}

void		Character::moveLeft(void) {
	this->_x--;
	Character::setPos(_x, _y);
}

void		Character::moveUp(void) {
	this->_y--;
}

void		Character::moveDown(void) {
	this->_y++;
}

int			Character::collision(int x, int y) {
	if ((this->_x == x && this->_y == y))
	{
		return (1);
	}
	return (0);
}

int			Character::isAlive(void) {
	return (this->_life);
}

void		Character::newLife(int i) {
	this->_life = i;
}
