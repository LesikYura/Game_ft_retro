#include "Player.hpp"

Player::Player(void) : Character() {}

Player::Player(int x, int y) : Character(x, y, 5) {}

Player::Player(Player &obj) { 
	*this = obj;
}

Player::~Player(void) {}

Player &Player::operator=(Player const &r) {
	this->_x = r._x;
	this->_y = r._y;
	this->_life = r._life;
	return (*this);
}

int			Player::die(void) {
	this->_life--;
	if (this->_life <= -1)
		return (1);
	return (0);
}