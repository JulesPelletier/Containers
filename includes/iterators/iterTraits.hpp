/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterTraits.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:41:31 by julpelle          #+#    #+#             */
/*   Updated: 2022/12/29 13:11:43 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITERTRAITS_HPP
# define ITERTRAITS_HPP

# include "../All.hpp"

namespace	ft
{

    template<typename Category, typename T, typename Distance = ptrdiff_t,
                        typename Pointer = T*, typename Reference = T&>
        class iterator
        {
            typedef Category	iterator_category;
            typedef T			value_type;
            typedef Distance	difference_type;
            typedef Pointer	    pointer;
            typedef Reference	reference;
        };

	template<class iterator>
		class iterator_traits
		{
			typedef typename iterator::iterator_category	iterator_category;
			typedef typename iterator::value_type			value_type;
			typedef typename iterator::difference_type		difference_type;
			typedef typename iterator::pointer				pointer;
			typedef typename iterator::reference			reference;
		};

	template<class T>
		class iterator_traits<T*>
		{
			typedef random_access_iterator_tag	iterator_category;
			typedef T							value_type;
			typedef ptrdiff_t					difference_type;
			typedef T*						    pointer;
			typedef T&						    reference;
		};

	template<class T>
		class iterator_traits<const T*>
		{
			typedef random_access_iterator_tag	iterator_category;
			typedef T							value_type;
			typedef ptrdiff_t					difference_type;
			typedef const T*					pointer;
			typedef const T&					reference;
		};
	
}	// end of namespace

# endif