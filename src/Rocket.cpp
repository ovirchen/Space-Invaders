/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rocket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:51:48 by ovirchen          #+#    #+#             */
/*   Updated: 2018/06/23 15:51:50 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Rocket.hpp"

Rocket::Rocket() {
	_x = 0;
	_y = 0;
	_status = false;
	_figure = "-";
}

Rocket::~Rocket() {
}

Rocket::Rocket(Rocket const &src) {
	*this = src;
}

Rocket& Rocket::operator=(Rocket const &src) {
	if (this != &src)
	{
		_x = src.getX();
		_y = src.getY();
		_figure = src.getFigure();
		_status = src.getStatus();
	}
	return *this;
}

void Rocket::init(int x, int y, int _win_y) {
	_x = x;
	_y = y;
	if (_y < _win_y - 2)
		_status = true;
}

void Rocket::move(int _win_y) {
	_y++;
	if (_y > _win_y - 2)
		_status = false;
}
