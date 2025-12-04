/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:35:39 by ihogben           #+#    #+#             */
/*   Updated: 2024/01/08 12:35:57 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int fixed_point;
		static const int fract_bits;
	public:
		Fixed();
		Fixed(const Fixed& copy);
		//Added in ex01
		Fixed(const int input);
		Fixed(const float input);

		~Fixed();
		//Copy assignment operator overload
		Fixed &operator=(const Fixed &src);

		//Added in ex01
		float toFloat(void)const;
		int toInt(void)const;

		int getRawBits(void)const;
		void setRawBits(int const raw);
};
//overites the insertion operator to allow us to print Fixed class instances
//added in ex01
std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);