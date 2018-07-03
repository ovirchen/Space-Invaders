/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stars.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurpas <akurpas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 13:39:25 by akurpas           #+#    #+#             */
/*   Updated: 2018/06/24 13:48:58 by akurpas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STARS_HPP
# define STARS_HPP 

# include "Asteroid.hpp"

class Stars : public Asteroid
{
	public:
		Stars();
		~Stars();
		Stars(Stars const &src);
    
		Stars 	&operator=(Stars const &rhs);

		void	move(void);
		void	init(int _win_x, int _win_y);
};

#endif
