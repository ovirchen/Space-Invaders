/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperBoss.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 17:34:52 by ovirchen          #+#    #+#             */
/*   Updated: 2018/06/24 17:34:53 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/SuperBoss.hpp"

SuperBoss::SuperBoss(){
	std::srand(time(0));
	_form = new std::string[3];
	_form[0] = " /|";
	_form[1] = "<=|}";
	_form[2] = " \\|";
	_life = 0;
	_x = 0;
	_y = 0;
	_score = 0;
}

void SuperBoss::init(int x, int y){
	_x = (int)clock() % (x - 6) + 4;
	_y = (rand() % (y - 30) + 1) + (y - 30);
	_life = 5;
}

SuperBoss::~SuperBoss() {
}

SuperBoss::SuperBoss(SuperBoss const & src) {
	*this = src;
}

SuperBoss& SuperBoss::operator=(SuperBoss const &src) {
	if (this != &src)
	{
		_x = src.getX();
		_y = src.getY();
		_life = src.getLife();
		_form = src.getForm();
		_score = src.getScore();
	}
	return *this;
}

void SuperBoss::teleport(int x, int y){
	if (_x < (x - 4 )/ 3)
		_x = (int)clock() % (x / 3) + 4;
	else if (_x < 2 * (x - 4 )/ 3)
		_x = (int)clock() % (x  - 4) + 4;
	else
		_x = ((int)clock() % (x / 3) + 2 * x / 3);
	if (_x > x - 6)
		_x = x - 6;
	_y = (rand() % (y - 30) + 1) + (y - 30);
	if (_y > y - 6)
		_y = y - 6;
}

void 	SuperBoss::move( int _win_x, int _win_y) {

	int ch = (int)clock() % 200;
	if (ch < 25)  _x++;
	else if (ch < 50) _y++;
	else if (ch < 70) _y--;
	else if (ch < 95) _x--;
	if (_x > _win_x - 4) {
		_x = _win_x - 4;
		move(_win_x, _win_y);
	}
	else if (_x < 3) {
		_x = 3;
		move(_win_x, _win_y);
	}
	if (_y > _win_y - 6) {
		_y = _win_y - 6;
		move(_win_x, _win_y);
	}
	else if (_y < _win_y / 4) {
		_y = _win_y / 4;
		move(_win_x, _win_y);
	}
}

std::string *SuperBoss::getForm() const {
	return _form;
}

