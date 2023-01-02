/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:47:33 by julpelle          #+#    #+#             */
/*   Updated: 2022/12/29 13:12:41 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef EQUAL_HPP
# define EQUAL_HPP

# include "../All.hpp"

namespace	ft
{
	
	template <class InputIterator1, class InputIterator2>
	bool
	equal(InputIterator1 first1, InputIterator1 last, InputIterator2 first2)
	{
		while (first1 != last)
		{
			if (!(*first1 == *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	template <class InputIterator1, class InputIterator2>
	bool
	equal(InputIterator1 first1, InputIterator1 last, InputIterator2 first2, Binary_Function<InputIterator1, InputIterator2, bool> pred)
	{
		while (first1 != last)
		{
			if (!pred(first1, first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

}


# endif