#ifndef BULLET_H
# define BULLET_H

class Bullet
{  

	public:

		Bullet(void);
		Bullet(int x, int y);
		Bullet(Bullet &obj);
		virtual ~Bullet(void);
		Bullet &operator=(Bullet const &r);

		int			getX(void);
		int			getY(void);
		int			isAlive(void);

		void		moveDown(void);
		void		moveUp(void);

		void		shootBullet(void);
		void		deleteBullet(void);

		void		newLife(int i);
		void		setBullet(int x, int y, int life);

	protected:
		int		_x;
		int		_y;
		int		_life;

};

#endif