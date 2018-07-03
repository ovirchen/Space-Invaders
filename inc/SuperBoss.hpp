/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperBoss.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 17:34:01 by ovirchen          #+#    #+#             */
/*   Updated: 2018/06/24 17:34:03 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERBOSS_H
# define SUPERBOSS_H

#include "Player.hpp"

class SuperBoss : public Player {

public:
	SuperBoss(void);
	SuperBoss(SuperBoss const & src);
	~SuperBoss();
	SuperBoss &operator=(SuperBoss const &src);
	void move(int _win_x, int _win_y);
	void teleport(int _win_x, int _win_y);
	void init(int _win_x, int _win_y);

	std::string *getForm() const;

protected:

	std::string *_form;
};

#endif
