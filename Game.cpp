# include "Game.hpp"
# include "Ncurses.hpp"

Game::Game(void) {

	this->EnemyAmount = 10;
	this->_EnemyBulletAmount = 10;
	this->PlayerBulletAmount = 10;

	this->_bullet = new Bullet[this->PlayerBulletAmount];
	this->_enemybullet = new Bullet[this->_EnemyBulletAmount];
	this->_enemy = new Enemy[this->EnemyAmount];

	this->_score = 0;
	this->_bulletspd = 50;
	this->_enemybulletspd = 30;
	this->_enemydeath = 0;
	this->_level = 0;
	this->_endofgame = 0;

	makeEnemy();
	makePlayer();
	this->_player.newLife(5);
}

Game::Game(Game &obj) { 
	*this = obj;
}

Game::~Game(void) {
	delete [] this->_bullet;
	delete [] this->_enemybullet;
	delete [] this->_enemy;
//	delete [] this->_asteroid;
}

Game &Game::operator=(Game const &r) {
	this->_player = r._player;
	this->_endofgame = r._endofgame;
	return (*this);
}

int			Game::checkEndofgame(void) {
	return (this->_endofgame);
}

void		Game::makeEnemy(void) {

	delete [] this->_enemybullet;
	delete [] this->_enemy;


	this->EnemyAmount = 10 + (this->_level * 2);

	this->_enemybullet = new Bullet[this->_EnemyBulletAmount];
	this->_enemy = new Enemy[this->EnemyAmount];

	delete [] this->_bullet;
	this->PlayerBulletAmount = 16 + this->_level;
	this->_bullet = new Bullet[this->PlayerBulletAmount];
	for (int i = 0; i < this->PlayerBulletAmount; i++) {
		if (this->_bullet[i].isAlive()) {
			this->_bullet[i].newLife(0);
			this->_bullet[i].deleteBullet();
		}
	}

	this->_level++;
	for (int i = 0; i < this->EnemyAmount; i++) {
		int x_fix = (2 + (rand() % WIDTH + 3));
		if(x_fix > WIDTH - 2)
			x_fix = WIDTH - 2;
		else if(x_fix < 2)
			x_fix = 2;
		_enemy[i].setPos(x_fix, 1 + (rand() % 3 + 1));
		_enemy[i].newLife(1);
	}
}

void		Game::makePlayer(void) {
	_player = Player(WIDTH/2, HIGHT - 2);
}

void		Game::makePlayerBullet(void) {
	for (int i = 0; i < this->PlayerBulletAmount; i++) {
		if (!this->_bullet[i].isAlive()) {
			this->_bullet[i].setBullet(_player.getX(), _player.getY(), 1);
			return;
		}
	}
}

void		Game::makeEnemyBullet(void) {
	int rd = 0;

	for (int i = 0; i < _EnemyBulletAmount; i++) {
		rd = rand();
		if ((rd % _bulletspd == 0) && !_enemybullet[i].isAlive() && _enemy[i].isAlive()) {
			_enemybullet[i].setBullet(_enemy[i].getX(), _enemy[i].getY(), 1);
			return;
		}
	}
}

int		Game::_playerHitCheck(int x, int y) {
	if (_player.collision(x, y)) {
		if(_player.die())
			setEndgame(1);
		return (1);
	}
	return (0);
}

int		Game::_hitCheck(int x, int y) {
	for (int i = 0; i < this->EnemyAmount; i++){
		if (_enemy[i].isAlive() && _enemy[i].collision(x, y)) {
			_score = _score + 1;
			return (1);
		}
	}
	return (0);
}

void		Game::drawBulletsMove(void) {
	for (int i = 0; i < this->PlayerBulletAmount; i++) {
		if (this->_bullet[i].isAlive()) {
			this->_bullet[i].deleteBullet();//vizu
			this->_bullet[i].moveUp();
			this->_bullet[i].shootBullet(); //vizu
			if (this->_bullet[i].getY() == 2) {
				this->_bullet[i].newLife(0);
				this->_bullet[i].deleteBullet();
			}
			if (_hitCheck(this->_bullet[i].getX(), this->_bullet[i].getY())) {
				this->_bullet[i].newLife(0);
				this->_bullet[i].deleteBullet();//vizu
			}
		}
	}
}

void		Game::drawEnemyBulletsMove(void) {
	for (int i = 0; i < this->_EnemyBulletAmount; i++) {
		if (this->_enemybullet[i].isAlive()) {
			this->_enemybullet[i].deleteBullet();//vizu
			this->_enemybullet[i].moveDown();
			this->_enemybullet[i].shootBullet();//vizu
			if (this->_enemybullet[i].getY() >= (HIGHT - 1)) {
				this->_enemybullet[i].newLife(0);
				this->_enemybullet[i].deleteBullet();
			}
			if (_playerHitCheck(this->_enemybullet[i].getX(), this->_enemybullet[i].getY())) {
				this->_enemybullet[i].newLife(0);
				this->_enemybullet[i].deleteBullet();//vizu
			}
		}
	}	
}

void Game::drawEnemiesMove(void)
{
	_enemydeath = 0;

	deleteMove();
	for (int i = 0; i < this->EnemyAmount; i++)
	{
		if (_enemy[i].isAlive())
		{
			if (_enemy[i].leftRightMovement(HIGHT, WIDTH))
			{
				if (_player.die())
					setEndgame(1);
			}
		}
		if (!_enemy[i].isAlive())
			_enemydeath++;
	}
	if (_enemydeath == EnemyAmount)
		makeEnemy();
	int x, y;
	attron(COLOR_PAIR(2));
	mvprintw(_player.getY(), _player.getX(), "#");
	attroff(COLOR_PAIR(2));
	for (int i = 0; i < this->EnemyAmount; i++)
	{
		if (_enemy[i].isAlive())
		{
			x = _enemy[i].getX();
			y = _enemy[i].getY();
			move(y, x);
			attron(COLOR_PAIR(3)); //Включає та виключає зміну кольру
			printw("Y");
			attroff(COLOR_PAIR(3));
		}
	}

}

int			Game::countBullet(void) {
	int amount = 0;
	for (int i = 0; i < this->PlayerBulletAmount; i++) {
		if (!this->_bullet[i].isAlive())
			amount++;
	}
	return (amount);
}

int			Game::getScore(void) {
	return (this->_score);
}

int			Game::getLevel(void) {
	return (this->_level);
}

int			Game::getLife(void) {
	return (this->_player.isAlive());
}

void		Game::setEndgame(int i) {
	this->_endofgame = i;
}

int			Game::getBulletCount(void) {
	return (this->PlayerBulletAmount);
}

void		Game::deleteMove(void)
{
	int x, y;
	for (int i = 0; i < this->EnemyAmount; i++)
	{
		if (_enemy[i].isAlive())
		{
			x = _enemy[i].getX();
			y = _enemy[i].getY();
			move(y, x);
			printw(" ");
		}
	}
}

int		Game::key_nc(int k)
{
	int x, y;
	x = _player.getX();
	y = _player.getY();
	if (k == 99) {
		this->_player.newLife(1000);
	}
	if (k == 27) {
		setEndgame(1);
	}
	if (k == 32)
	{
		makePlayerBullet();
	}
	if (k == 260 && x > 2)
	{
		mvprintw(y, x, " ");
		_player.moveLeft();
		k = 0;
	}
	else if (k == 261 && x < 69)
	{
		mvprintw(y, x, " ");
		_player.moveRight();
		k = 0;
	}
	return (k);
}

void	Game::add_rm_star(void)
{
	int star_x, star_y;

	if ((star_y = HIGHT + 1 - rand() % HIGHT) >= (HIGHT - 2))
		star_y = star_y - 2;
	if ((star_x = WIDTH + 1 - rand() % WIDTH) >= (WIDTH - 2))
		star_x = star_x - 3;

	if (star_x > WIDTH - 2)
		star_x = WIDTH - 2;
	else if (star_x < 2)
		star_x = 2;
	if (star_y < 3)
		star_y = 3;
	mvprintw(star_y, star_x, "*");

	for (int i = 1; i < 100; i++)
	{
		if ((star_y = HIGHT + 3 - rand() % HIGHT) >= (HIGHT - 2))
			star_y = star_y - 5;
		if ((star_x = WIDTH + 1 - rand() % WIDTH) >= (WIDTH - 2))
			star_x = star_x - 3;
		mvprintw(star_y, star_x, " ");
	}
}