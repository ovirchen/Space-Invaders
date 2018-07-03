/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurpas <akurpas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:51:22 by ovirchen          #+#    #+#             */
/*   Updated: 2018/06/23 19:25:23 by akurpas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Enemy.hpp"

Enemy::Enemy( void ){
	std::srand(time(0));
	int i;
	std::string	form[5] = {"<@", "{$#", "<[D]", "(D-[]" , "<}[#]<"};
	_form = form[(i = clock() % 5)];
	_x = 0;
	_y = 0;
	_life = i + 2;
}

void Enemy::init(int x, int y){
	int i;
	std::string	form[5] = {"<@", "{$#", "<[D]", "(D-[]" , "<}[#]<"};
	_form = form[(i = clock() % 5)];
	_life = i + 2;
	_x = clock() % (x - 4) + 2;
	_y =(clock() % (y - 30) + 1) + (y - 35);
}

Enemy::Enemy(Enemy const & src){
 	*this = src;
}

Enemy& Enemy::operator=(Enemy const &src) {
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


Enemy::~Enemy( void ) {

}

void 	Enemy::move() {
	--_y;
	if (_y < 1) {
		++_y;
		--_life;
		if (_life < 0)
			_life = 0;
	}
}

void Enemy::lostLife() {
	--_life;
	_y++;
}

void Enemy::setLife(int l) {
	_life = l;
}

