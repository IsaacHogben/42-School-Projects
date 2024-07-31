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
		int 				fixed_point;
		static const int 	fract_bits;
	public:
		Fixed();
		Fixed(const Fixed& copy);
		//Added in ex01
		Fixed(const int input);
		Fixed(const float input);

		~Fixed();
		//Copy assignment operator overload
		Fixed &operator=(const Fixed &src);

		//Comparison Operators
		bool operator>(Fixed fixed)const;
		bool operator<(Fixed fixed)const;
		bool operator>=(Fixed fixed)const;
		bool operator<=(Fixed fixed)const;
		bool operator==(Fixed fixed)const;
		bool operator!=(Fixed fixed)const;

		//Arithmetic Operators
		float operator+(Fixed fixed)const;
		float operator-(Fixed fixed)const;
		float operator*(Fixed fixed)const;
		float operator/(Fixed fixed)const;

		//Pre-increment Operators
		Fixed operator++();
		Fixed operator--();

		//Post-increment Operators
		Fixed operator++(int);
		Fixed operator--(int);

		//Added in ex01
		float toFloat(void)const;
		int toInt(void)const;

		int getRawBits(void)const;
		void setRawBits(int const raw);

		//Added in ex02
		static Fixed &min(Fixed &first, Fixed &second);
		static const Fixed &min(Fixed const &first, Fixed const &second);
		static Fixed &max(Fixed &first, Fixed &second);
		static const Fixed &max(Fixed const &first, const Fixed &second);
};
//overites the insertion operator to allow us to print Fixed class instances
//added in ex01
std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);