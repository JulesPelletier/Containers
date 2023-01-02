/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:25:48 by julpelle          #+#    #+#             */
/*   Updated: 2022/07/12 17:10:43 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{
	template <class T, bool v>
	struct 
	integral_constant
	{
		typedef integral_constant<T, v>		type;
		typedef	T							value_type;
		
		static const T						value = v;
	};

	template <class T>
	struct is_integral : public integral_constant<bool, false>{};
	
	template <> struct is_integral<bool> : public integral_constant <bool, true>{};
	template <> struct is_integral<char> : public integral_constant <char, true>{};
	template <> struct is_integral<wchar_t> : public integral_constant <wchar_t, true>{};
	template <> struct is_integral<signed char> : public integral_constant <signed char, true>{};
	template <> struct is_integral<short int> : public integral_constant <short int, true>{};
	template <> struct is_integral<int> : public integral_constant <int, true>{};
	template <> struct is_integral<long int> :  public integral_constant <long int, true>{};
	template <> struct is_integral<long long int> :  public integral_constant <long long int, true>{};
	template <> struct is_integral<unsigned char> :  public integral_constant <unsigned char, true>{};
	template <> struct is_integral<unsigned short int> :  public integral_constant <unsigned short int, true>{};
	template <> struct is_integral<unsigned int> :  public integral_constant <unsigned int, true>{};
	template <> struct is_integral<unsigned long int> :  public integral_constant <unsigned long int, true>{};
	template <> struct is_integral<unsigned long long int> :  public integral_constant <unsigned long long int, true>{};
}


# endif