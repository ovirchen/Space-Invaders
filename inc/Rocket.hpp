/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rocket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:52:44 by ovirchen          #+#    #+#             */
/*   Updated: 2018/06/23 15:52:45 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROCKET_H
# define ROCKET_H

#include "Asteroid.hpp"

class Rocket : public Asteroid{

public:
	Rocket();
	Rocket(Rocket const &src);
	~Rocket();

	Rocket &operator=(Rocket const &src);

	void init(int x, int y, int _win_y);
	void move(int _win_y);

};

#endif
