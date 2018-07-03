/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurpas <akurpas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:51:10 by ovirchen          #+#    #+#             */
/*   Updated: 2018/06/23 19:01:00 by akurpas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Player.hpp"

Player::Player(){
	_form = "+}";
	_life = 3;
	_x = 0;
	_y = 0;
	_score = 0;
}

Player::Player( int x){
	_form = "+}";
	_life = 3;
	_x = x / 2 - 1;
	_y = 4;
	_score = 0;
}

Player::~Player() {

}

Player::Player(Player const & src){
 	*this = src;
}

Player& Player::operator=(Player const &src) {
	if (this != &src) {
		_x = src.getX();
		_y = src.getY();
		_life = src.getLife();
		_form = src.getForm();
		_score = src.getScore();
	}
	return *this;
}

void 	Player::move( int _win_x, int _win_y, int ch) {
	mvprintw(_x, _y, " ");
    if (ch == KEY_DOWN)  _x++;
    if (ch == KEY_UP)    _x--;
    if (ch == KEY_LEFT)  _y--;
    if (ch == KEY_RIGHT) _y++;
	if (_x > _win_x - 3)
		_x = _win_x - 2;
	else if (_x < 1)
		_x = 1;
	if (_y > _win_y - 3)
		_y = _win_y - 2;
	else if (_y < 1)
		_y = 1;
}

int Player::getX() const {
	return _x;
}

int Player::getY() const {
	return _y;
}

std::string Player::getForm() const {
	return _form;
}

int Player::getLife() const {
	return _life;
}

int Player::getScore() const {
	return _score;
}

void Player::scoreUp() {
	++_score;
}

void Player::lostLife() {
	--_life;
}