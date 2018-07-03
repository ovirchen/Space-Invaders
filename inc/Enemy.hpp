/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurpas <akurpas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:52:37 by ovirchen          #+#    #+#             */
/*   Updated: 2018/06/23 19:25:16 by akurpas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Player.hpp"

#ifndef ENEMY_HPP
# define ENEMY_HPP

class Enemy : public Player
{
public:
	Enemy(void);
	Enemy(int x, int y);
	Enemy(Enemy const & src);
	~Enemy();
	Enemy &operator=(Enemy const &src);

	void move();
	void init(int _win_x, int _win_y);
	void lostLife();
	void setLife(int l);

};

#endif