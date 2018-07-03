/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stars.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurpas <akurpas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 13:39:25 by akurpas           #+#    #+#             */
/*   Updated: 2018/06/24 13:48:58 by akurpas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Stars.hpp"

Stars::Stars() {
	std::srand(time(0));
    _x = 0;
    _y = 0;
    _status = true;
    _figure = '.';
}

void Stars::init(int _win_x, int _win_y) {
    _x = rand() % (_win_x - 4) + 2;
    _y = rand() % (_win_y - 4) + 2;
    _status = true;
    _figure = '.';
}


Stars::Stars(Stars const &src) {
    *this = src;
}

Stars::~Stars() {

}

Stars& Stars::operator=(Stars const &src) {
    if (this != &src)
    {
        _x = src.getX();
        _y = src.getY();
        _figure = src.getFigure();
        _status = src.getStatus();
    }
    return *this;
}

void Stars::move() {
    --_y;
    if (_y < 1)
        _status = false;
}
