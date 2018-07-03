/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:08:41 by ovirchen          #+#    #+#             */
/*   Updated: 2018/06/23 13:08:42 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include <zconf.h>
#include "Asteroid.hpp"
#include "Player.hpp"
#include "Rocket.hpp"
#include "Enemy.hpp"
#include "Stars.hpp"
#include "SuperBoss.hpp"

class Game{

public:
	Game();
	Game(Game const &src);
	~Game();

	Game &operator=(Game const &src);

	unsigned int getTime() const;
	unsigned int getNTime() const;
	int getWinX() const;
	int getWinY() const;
	int getPhase() const;
	int getNAster() const;
	int getNRock() const;
	int getNEnem() const;
	int getNStar() const;
	Asteroid * getAsteroids() const;
	Stars * getStars() const;
	Player * getPlayer() const;
	Rocket * getRockets() const;
	Asteroid * getShoot() const;
	Asteroid * getBossShoot() const;
	Enemy * getEnemies() const;
	SuperBoss * getBoos() const;
	void play();
	void print_game();
	void press_key();
	void moveAsteroids();
	void printPlayer();
	void moveRockets();
	void moveEnemies();
	void moveStars();
	void printAll();
	void enemyShoot();
	void printBoss();

private:
	int _win_x;
	int _win_y;
	unsigned int _time;
	int _phase; // 0 - running, 1 - pause, 2 - end
	int _n_aster;
	int _n_rock;
	int _n_enem;
	int _n_star;
	unsigned int _n_time;
	Asteroid *_asteroids;
	Stars *_stars;
	Player *_player;
	Rocket *_rockets;
	Asteroid *_shoot;
	Asteroid *_bossShoot;
	Enemy *_enemies;
	SuperBoss *_boss;
};

#endif
