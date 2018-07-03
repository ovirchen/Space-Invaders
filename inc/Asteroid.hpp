/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:52:51 by ovirchen          #+#    #+#             */
/*   Updated: 2018/06/23 15:52:52 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTEROID_H
# define ASTEROID_H

#include <iostream>
#include <ncurses.h>

class Asteroid {

public:
	Asteroid();
	Asteroid(Asteroid const &src);
	~Asteroid();

	Asteroid &operator=(Asteroid const &src);

	void init(int _win_x, int _win_y);
	void init2(int x, int y);
	void move();

	bool getStatus() const;
	void setStatus(bool f);
	int getX() const;
	int getY() const;
	std::string getFigure() const;

protected:
	int _x;
	int _y;
	std::string _figure;
	bool _status;
};

#endif
