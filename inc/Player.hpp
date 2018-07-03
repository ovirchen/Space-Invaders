/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurpas <akurpas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:52:30 by ovirchen          #+#    #+#             */
/*   Updated: 2018/06/23 19:25:45 by akurpas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <ncurses.h>
#include <iostream>

class Player {

public:
	Player(void);
	Player(int x);
	Player(Player const & src);
	~Player();
	Player &operator=(Player const &src);
	void move( int _win_x, int _win_y, int c);

	int getX() const;
	int getY() const;
	std::string getForm() const;
	int getLife() const;
	int getScore() const;
	void scoreUp();
	void lostLife();

protected:
	int _x;
	int _y;
	int	_life;
	std::string _form;
	int _score;
};

#endif