/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:52:14 by ovirchen          #+#    #+#             */
/*   Updated: 2018/06/23 15:52:15 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Asteroid.hpp"

Asteroid::Asteroid() {
	std::srand(time(0));
	_x = 0;
	_y = 0;
	_status = false;
	std::string form[3] = {"|", "||", "|||"};
	_figure = form[clock() % 3];
}

Asteroid::~Asteroid() {
}

Asteroid::Asteroid(Asteroid const &src) {
	*this = src;
}

Asteroid& Asteroid::operator=(Asteroid const &src) {
	if (this != &src) {
		_x = src.getX();
		_y = src.getY();
		_figure = src.getFigure();
		_status = src.getStatus();
	}
	return *this;
}

void Asteroid::init(int _win_x, int _win_y) {
	_x = (int)clock() % (_win_x - 4) + 2;
	_y = (rand() % (_win_y - 30) + 1) + (_win_y - 35);
	_status = true;
}

void Asteroid::init2(int x, int y) {
	_x = x;
	_y = y;
	_figure = "-";
	_status = true;
}

void Asteroid::move() {
	--_y;
	if (_y < 1)
		_status = false;
}

bool Asteroid::getStatus() const{
	return _status;
}

void Asteroid::setStatus(bool f) {
	_status = f;
}


int Asteroid::getX() const{
	return _x;
}

int Asteroid::getY() const {
	return _y;
}

std::string Asteroid::getFigure() const {
	return _figure;
}