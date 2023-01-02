/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Binary.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:30:05 by julpelle          #+#    #+#             */
/*   Updated: 2022/03/25 22:33:09 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BINARY_HPP
# define BINARY_HPP

namespace	ft
{

	template <class Arg1, class Arg2, class Result>
	struct Binary_Function
	{
		typedef Arg1	first_argument_type;
		typedef Arg2	second_argument_type;
		typedef Result	result_type;
	};

}	// end of namespace




# endif