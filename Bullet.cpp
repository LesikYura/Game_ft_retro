#include "Bullet.hpp"
#include "Ncurses.hpp"

Bullet::Bullet(void) {}

Bullet::Bullet(int x, int y) : _x(x), _y(y), _life(0) {}

Bullet::Bullet(Bullet &obj) { 
	*this = obj;
}

Bullet::~Bullet(void) {}

Bullet &Bullet::operator=(Bullet const &r) {
	this->_x = r._x;
	this->_y = r._y;
	return (*this);
}

int			Bullet::getX(void) {
	return (this->_x);
}

int			Bullet::getY(void) {
	return (this->_y);
}

void		Bullet::moveDown(void) {
	this->_y++;
}

void		Bullet::moveUp(void) {
	this->_y--;
}

void		Bullet::shootBullet(void)
{
	int x, y;
	x = _x;
	y = _y;
	move(y, x);
	attron(COLOR_PAIR(4)); //Включає та виключає зміну кольру
	printw("'");
	attroff(COLOR_PAIR(4));
}

void		Bullet::deleteBullet(void) 
{
	int x, y;
	x = getX();
	y = getY();
	move(y, x);
	// attron(COLOR_PAIR(3)); //Включає та виключає зміну кольру
	printw(" ");
}

int			Bullet::isAlive(void) {
	return (this->_life);
}

void		Bullet::newLife(int i) {
	this->_life = i;
}

void		Bullet::setBullet(int x, int y, int life){
	(void)life;
	this->_x = x;
	this->_y = y;
	this->_life = 1;
}
