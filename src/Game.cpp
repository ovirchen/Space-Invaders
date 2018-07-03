/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:20:18 by ovirchen          #+#    #+#             */
/*   Updated: 2018/06/23 15:20:19 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Game.hpp"

Game::Game() {
	_phase = 1;
	_n_aster = 30;
	_n_rock = 100;
	_n_enem = 20;
	_n_star = 80;
	_n_time = 500;
	_time = 0;
	initscr();
	curs_set(0);
	start_color();
	noecho();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
	init_color(COLOR_WHITE, 500, 500, 500);
	nodelay(stdscr, true);
	keypad(stdscr, true);
	getmaxyx(stdscr, _win_x, _win_y);
	_asteroids = new Asteroid[_n_aster];
	_stars = new Stars[_n_star];
	_player = new Player(_win_x);
	_rockets = new Rocket[_n_rock];
	_shoot = new Asteroid[_n_enem / 2];
	_enemies = new Enemy[_n_enem];
	_boss = new SuperBoss;
	_bossShoot = new Asteroid[30];
}

Game::~Game() {
	attron(COLOR_PAIR(1) | A_BOLD);
	mvprintw(_win_x / 2 - 6, _win_y / 2 - 7, "***GAME OVER***");
	mvprintw(_win_x / 2 - 5, _win_y / 2 - 12, "Press any key to finish");
	attron(COLOR_PAIR(2) | A_BOLD);
	mvprintw(_win_x / 2 - 4, _win_y / 2 - 7, "FINAL SCORE : %d", _player->getScore());
	nodelay(stdscr, false);
	getch();
	endwin();
	std::cout << "Game oveR" << std::endl;
	std::cout << "Final score: " << _player->getScore() << std::endl;
	std::cout << "SuperBoss has " << _boss->getLife() << " lifes" << std::endl;
	delete [] _asteroids;
	delete [] _stars;
	delete [] _rockets;
	delete [] _shoot;
	delete [] _enemies;
	delete [] _bossShoot;
	delete _player;
	delete _boss;
}

Game::Game(Game const &src) {
	*this = src;
}

Game& Game::operator=(Game const &src) {
	if (this != &src)
	{
		_win_x = src.getWinX();
		_win_y = src.getWinY();
		_time = src.getTime();
		_phase = src.getPhase();
		_n_aster = src.getNAster();
		 _n_rock = src.getNRock();
		_n_enem = src.getNEnem();
		_n_star = src.getNStar();
		_n_time = src.getNTime();
		_asteroids = src.getAsteroids();
		_stars = src.getStars();
		_player = src.getPlayer();
		_rockets = src.getRockets();
		_shoot = src.getShoot();
		_bossShoot = src.getBossShoot();
		_enemies = src.getEnemies();
		_boss = src.getBoos();
	}
	return *this;
}

unsigned int Game::getTime() const {
	return _time;
}

SuperBoss* Game::getBoos() const {
	return _boss;
}

Enemy* Game::getEnemies() const {
	return _enemies;
}

Asteroid* Game::getBossShoot() const {
	return _bossShoot;
}

Rocket* Game::getRockets() const {
	return _rockets;
}

Asteroid* Game::getShoot() const {
	return _shoot;
}

unsigned int Game::getNTime() const {
	return _n_time;
}

Player *Game::getPlayer() const {
	return _player;
}

Stars* Game::getStars() const {
	return _stars;
}

Asteroid* Game::getAsteroids() const {
	return _asteroids;
}

int Game::getWinX() const {
	return _win_x;
}

int Game::getWinY() const {
	return _win_y;
}

int Game::getPhase() const {
	return _phase;
}

int Game::getNAster() const {
	return _n_aster;
}

int Game::getNRock() const {
	return _n_rock;
}

int Game::getNEnem() const {
	return _n_enem;
}

int Game::getNStar() const {
	return _n_star;
}

void Game::press_key() {
	int c = getch();
	int i = 0;

	if (c == 27)
		_phase = 2;
	_player->move(_win_x, _win_y, c);
	if (c == ' ') {
		system("afplay blaster.wav&");
		while (_rockets[i].getStatus() && i < _n_rock)
			i++;
		if (i < _n_rock)
			_rockets[i].init(_player->getX(), _player->getY() + 1, _win_y);
	}
	if (c == '\n' && _phase == 0) // Running
	{
		nodelay(stdscr, true);
		_phase = 1;
		return ;
	}
	else if (c == '\n' && _phase == 1) // Pause
	{
		attron(COLOR_PAIR(1) | A_BOLD);
		mvprintw(_win_x / 2 - 6, _win_y / 2 - 7, "***PAUSE***");
		printPlayer();
		nodelay(stdscr, false);
		_phase = 0;
	}
	if (_phase == 0)
		press_key();
}

void Game::play() {
	unsigned int i = 0;
	time_t start;
	time_t end;

	moveStars();
	while (_phase != 2) {
		time(&start);
		if (i % 5 == 0) {
			clear();
			attron(COLOR_PAIR(1) | A_BOLD);
			box(stdscr, 0, 0);
			_time++;
			moveEnemies();
			moveAsteroids();
		}
		if (i % 2 == 0) {
			moveRockets();
			enemyShoot();
		}
		if (i % 100 == 0)
			moveStars();
		printAll();
		if (_time == _n_time) {
			_boss->init(_win_x, _win_y);
			_time = 0;
		}
		if (i % 100 == 0)
			_boss->teleport(_win_x, _win_y);
		printBoss();
		time(&end);
		usleep(10000 - 1000 * difftime(end, start));
		press_key();
		i++;
	}
}

void Game::moveRockets() {
	for (int i = 0; i < _n_rock; i++) {
		if (_rockets[i].getStatus()) {
			_rockets[i].move(_win_y);
			for (int j = 0; j < _n_aster; j++) {
				if (_asteroids[j].getStatus() && _rockets[i].getX() == _asteroids[j].getX() &&
					(_rockets[i].getY() == _asteroids[j].getY() || _rockets[i].getY() == _asteroids[j].getY() - 1)) {
					system("afplay points.wav&");
					attron(COLOR_PAIR(2) | A_BOLD);
					mvprintw(_asteroids[i].getX(), _asteroids[i].getY(), "1");
					refresh();
					usleep(50000);
					_asteroids[j].setStatus(false);
					_rockets[i].setStatus(false);
					_player->scoreUp();
					break;
				}
			}
			if (_rockets[i].getStatus()) {
				for (int j = 0; j < _n_enem; j++) {
					if (_enemies[j].getLife() > 0 && _rockets[i].getX() == _enemies[j].getX() &&
						(_rockets[i].getY() == _enemies[j].getY() ||
						 _rockets[i].getY() == _enemies[j].getY() + 1)) {
						system("afplay points.wav&");
						attron(COLOR_PAIR(2) | A_BOLD);
						mvprintw(_enemies[i].getX(), _enemies[i].getY(), "1");
						refresh();
						usleep(50000);
						_enemies[j].lostLife();
						_rockets[i].setStatus(false);
						_player->scoreUp();
						break;
					}
				}
			}
			if (_rockets[i].getStatus())
				if (_rockets[i].getX() == _boss->getX() && (_rockets[i].getY() == _boss->getY() ||
					 _rockets[i].getY() == _boss->getY() + 1))
				{
					system("afplay points.wav&");
					attron(COLOR_PAIR(2) | A_BOLD);
					mvprintw(_boss[i].getX(), _boss[i].getY(), "2");
					refresh();
					usleep(50000);
					_boss->lostLife();
					_rockets[i].setStatus(false);
					_player->scoreUp();
					_player->scoreUp();
				}
		}
	}
}

void Game::moveEnemies() {
	bool ast = true;
	for (int i = 0; i < _n_enem; i++) {
		if (_enemies[i].getLife() > 0) {
			_enemies[i].move();
			if ((int)clock() % 100 < 30) {
				for (int j = 0; j < _n_aster; j++) {
					if (_asteroids[j].getStatus() && _enemies[i].getX() == _asteroids[j].getX() &&
						_enemies[i].getY() - 1 == _asteroids[j].getY() + (int)_asteroids->getFigure().length()) {
						ast = false;
						break;
					}
				}
				if (ast)
					_enemies[i].move();
			}
		}
		else
			_enemies[i].init(_win_x, _win_y);
		for (int j = 0; j < _n_rock; j++) {
			if (_rockets[j].getStatus() && _enemies[i].getLife() > 0 &&
				_rockets[j].getX() == _enemies[i].getX() &&
				(_rockets[j].getY() == _enemies[i].getY() || _rockets[j].getY() == _enemies[i].getY() - 1))
			{
				system("afplay points.wav&");
				attron(COLOR_PAIR(2) | A_BOLD);
				mvprintw(_enemies[i].getX(), _enemies[i].getY(), "1");
				refresh();
				usleep(50000);
				_enemies[i].lostLife();
				_rockets[j].setStatus(false);
				_player->scoreUp();
			}
		}
		if (_enemies[i].getLife() > 0 && _enemies[i].getX() == _player->getX() &&
			_enemies[i].getY() == _player->getY() + 1)
		{
			system("afplay crash.aiff&");
			attron(COLOR_PAIR(4) | A_BOLD);
			mvprintw(_enemies[i].getX(), _enemies[i].getY(), "#");
			_enemies[i].setLife(0);
			refresh();
			usleep(100000);
			_player->lostLife();
			if (_player->getLife() == 0)
				_phase = 2;
		}
	}
}

void Game::moveStars() {
	for (int i = 0; i < _n_star; i++) {
		if (_stars[i].getStatus())
			_stars[i].move();
		else
			_stars[i].init(_win_x, _win_y);
	}
}

void Game::moveAsteroids() {
	for (int i = 0; i < _n_aster; i++)
	{
		if (!_asteroids[i].getStatus())
			_asteroids[i].init(_win_x, _win_y);
		else
			_asteroids[i].move();
		for (int j = 0; j < _n_rock; j++) {
			if (_rockets[j].getStatus() && _asteroids[i].getStatus() &&
					_rockets[j].getX() == _asteroids[i].getX() &&
					(_rockets[j].getY() == _asteroids[i].getY() || _rockets[j].getY() == _asteroids[i].getY() - 1))
			{
				system("afplay points.wav&");
				attron(COLOR_PAIR(2) | A_BOLD);
				mvprintw(_asteroids[i].getX(), _asteroids[i].getY(), "1");
				refresh();
				usleep(50000);
				_asteroids[i].setStatus(false);
				_rockets[j].setStatus(false);
				_player->scoreUp();
			}
		}
		if (_asteroids[i].getStatus() && _asteroids[i].getX() == _player->getX() &&
				_asteroids[i].getY() == _player->getY() + 1)
		{
			system("afplay crash.aiff&");
			attron(COLOR_PAIR(4) | A_BOLD);
			mvprintw(_asteroids[i].getX(), _asteroids[i].getY(), "#");
			refresh();
			usleep(100000);
			_player->lostLife();
			if (_player->getLife() == 0)
				_phase = 2;
		}
	}
}

void Game::printPlayer() {
	attron(COLOR_PAIR(2) | A_BOLD);
	mvprintw(_player->getX(), _player->getY(), _player->getForm().c_str());
	attroff(COLOR_PAIR(2) | A_BOLD);
	refresh();
}

void Game::print_game() {
	attron(COLOR_PAIR(1) | A_BOLD);
	move(2, 10);
	printw("SCORE : ");
	attron(COLOR_PAIR(2) | A_BOLD);
	printw("%d", _player->getScore());
	attron(COLOR_PAIR(1) | A_BOLD);
	printw("    TIME : ");
	attron(COLOR_PAIR(2) | A_BOLD);
	printw("%u/%u", _time, _n_time);
	attron(COLOR_PAIR(1) | A_BOLD);
	printw("    LIFE : ");
	attron(COLOR_PAIR(2) | A_BOLD);
	for (int i = 0; i < _player->getLife(); i++) {
		printw("|");
	}
	if (_boss->getLife() > 0)
	{
		printw("    SUPERBOSS's LIFE : ");
		attron(COLOR_PAIR(7) | A_BOLD);
		for (int i = 0; i < _boss->getLife(); i++) {
			printw("|");
		}
	}
	attron(COLOR_PAIR(1) | A_BOLD);
	mvprintw(_win_x - 3, 10, "Press ENTER for pause");
	attroff(COLOR_PAIR(1) | A_BOLD);
}

void Game::printAll() {
	size_t l;
	size_t len;
	int k;

	attron(COLOR_PAIR(1));
	attroff(A_BOLD);
	for (int i = 0; i < _n_star; i++) {
		if (_stars[i].getStatus())
			mvprintw(_stars[i].getX(), _stars[i].getY(), _stars[i].getFigure().c_str());
	}
	attron(COLOR_PAIR(3) | A_BOLD);
	for (int i = 0; i < _n_aster; i++) {
		if (_asteroids[i].getY() < _win_y - 3 && _asteroids[i].getStatus())
			mvprintw(_asteroids[i].getX(), _asteroids[i].getY(), _asteroids[i].getFigure().c_str());
	}
	attron(COLOR_PAIR(6) | A_BOLD);
	for (int j = 0; j < _n_rock; j++) {
		if (_rockets[j].getStatus())
			mvprintw(_rockets[j].getX(), _rockets[j].getY(), _rockets[j].getFigure().c_str());
	}
	attron(COLOR_PAIR(5) | A_BOLD);
	for (int j = 0; j < _n_enem; j++) {
		k = 0;
		if ((l = (size_t)_enemies[j].getLife()) > 0) {
			len = _enemies[j].getForm().length();
				while (l > 0 && _enemies[j].getY() + k < _win_y - 1) {
					mvprintw(_enemies[j].getX(), _enemies[j].getY() + k, "%c",
							 (_enemies[j].getForm())[len - l]);
					l--;
					k++;
				}
		}
	}
	refresh();
	print_game();
	printPlayer();
}

void Game::enemyShoot() {
	int k = (int)clock() % (_n_enem * 10);
	if (k < _n_enem && _enemies[k].getLife() == (int)_enemies[k].getForm().length() && _enemies[k].getY() < _win_y - 2)
		for (int j = 0; j < _n_enem / 2; j++) {
			if (!_shoot[j].getStatus()) {
				_shoot[j].init2(_enemies[k].getX(), _enemies[k].getY());
				break ;
			}
		}
	for (int i = 0; i < _n_enem / 2; i++)
	{
		if (_shoot[i].getStatus()) {
			_shoot[i].move();
			for (int j = 0; j < _n_aster; j++) {
				if (_asteroids[j].getStatus() && _shoot[i].getX() == _asteroids[j].getX() &&
					(_shoot[i].getY() == _asteroids[j].getY() || _shoot[i].getY() == _asteroids[j].getY() - 1)) {
					_shoot[i].setStatus(false);
					break;
				}
			}
			if (_shoot[i].getStatus())
			{
				for (int j = 0; j < _n_enem; j++) {
					if (_enemies[j].getLife() > 0 && _shoot[i].getX() == _enemies[j].getX() &&
						(_shoot[i].getY() == _enemies[j].getY() + _enemies[j].getLife() - 1 ||
						 _shoot[i].getY() == _enemies[j].getY() + _enemies[j].getLife() - 2)) {
						_shoot[i].setStatus(false);
						break;
					}
				}
			}
			if (_shoot[i].getStatus() && _shoot[i].getX() == _player->getX() &&
				_shoot[i].getY() == _player->getY()) {
				system("afplay crash.aiff&");
				attron(COLOR_PAIR(4) | A_BOLD);
				mvprintw(_shoot[i].getX(), _shoot[i].getY(), "#");
				refresh();
				_shoot[i].setStatus(false);
				usleep(100000);
				_player->lostLife();
				if (_player->getLife() == 0)
					_phase = 2;
			}
		}
	}
	attron(COLOR_PAIR(4));
	attroff(A_BOLD);
	for (int j = 0; j < _n_enem / 2; j++) {
		if (_shoot[j].getStatus()) {
			mvprintw(_shoot[j].getX(), _shoot[j].getY(), _shoot[j].getFigure().c_str());
		}
	}
	refresh();
}

void Game::printBoss() {
	if (_boss->getLife() != 0)
	{
		mvprintw(_boss->getX() - 1, _boss->getY(), "   ");
		mvprintw(_boss->getX(), _boss->getY(), "    ");
		mvprintw(_boss->getX() + 1, _boss->getY(), "   ");
		_boss->move(_win_x, _win_y);
		int k = clock() % 500;
		if (k < 30) {
			k = 0;
			system("afplay blaster2.wav&");
			while (_bossShoot[k].getStatus() && k < 15)
				k++;
			if (k < 15)
				_bossShoot[k].init2(_boss->getX(), _boss->getY());
		}
		for (int i = 0; i < 30; i++) {
			if (_bossShoot[i].getStatus())
			{
				_bossShoot[i].move();
				if (_bossShoot[i].getX() == _player->getX() && (_bossShoot[i].getY() == _player->getY() ||
						_bossShoot[i].getY() == _player->getY() + 1)) {
					system("afplay crash.aiff&");
					attron(COLOR_PAIR(4) | A_BOLD);
					mvprintw(_bossShoot[i].getX(), _bossShoot[i].getY(), "#");
					refresh();
					_bossShoot[i].setStatus(false);
					usleep(100000);
					_player->lostLife();
					if (_player->getLife() == 0)
						_phase = 2;
				}
				attron(COLOR_PAIR(7));
				attroff(A_BOLD);
				if (_bossShoot[i].getStatus())
					mvprintw(_bossShoot[i].getX(), _bossShoot[i].getY(), _bossShoot[i].getFigure().c_str());
			}
		}
		attron(COLOR_PAIR(7) | A_BOLD);
		mvprintw(_boss->getX() - 1, _boss->getY(), _boss->getForm()[0].c_str());
		mvprintw(_boss->getX(), _boss->getY(), _boss->getForm()[1].c_str());
		mvprintw(_boss->getX() + 1, _boss->getY(), _boss->getForm()[2].c_str());
		refresh();
	}
}
