/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:43:30 by julpelle          #+#    #+#             */
/*   Updated: 2022/07/12 17:43:09 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PAIR_HPP
# define PAIR_HPP

namespace	ft
{

	template <class T1, class T2>
	struct	pair
	{
		public:
			// Types
			typedef T1		first_type;
			typedef T2		second_type;

			// Constructors
			pair(void);
			template <class U, class V>
			pair(const pair<U, V> &pr);
			pair (const first_type &a, const second_type &b);
			
			// Destructor
			~pair(void);

			// Assignation
			pair			&operator= (const pair& pr);

			first_type		first;
			second_type		second;

		private:

	};

	// Constructors
	
	template <class T1, class T2>
	pair<T1, T2>::pair(void) : first(), second()
	{
	}

	template <class T1, class T2>
	template <class U, class V>
	pair<T1, T2>::pair(const pair<U, V> &pr) : first(pr.first), second(pr.second)
	{
	}

	template <class T1, class T2>
	pair<T1, T2>::pair (const first_type &a, const second_type &b) : first(a), second(b)
	{
	}

	// Destructor
	template <class T1, class T2>
	pair<T1, T2>::~pair (void)
	{
	}

	template <class T1, class T2>
	pair<T1, T2>		
	&pair<T1, T2>::operator= (const pair<T1, T2> &pr)
	{
		if (this == &pr)
			return (*this);
		first = pr.first;
		second = pr.scond;
		return (*this);
	}

	template <class T1, class T2>
	bool
	operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first==rhs.first && lhs.second==rhs.second);
	}
	
	template <class T1, class T2>
	bool
	operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs==rhs);
	}
	
	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second));
	}
	
	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(rhs<lhs));
	}
	
	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (rhs<lhs);
	}
	
	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(lhs<rhs));
	}

	template <class T1, class T2>
	pair<T1, T2> make_pair (T1 x, T2 y)
	{
		//std::cout << "pair made \n";
		return pair<T1, T2>(x,y);
	}

	template <class T1, class T2>
	std::ostream &			operator<<( std::ostream & o, pair<T1, T2> const & i )
	{
		std::cout << "pair : \n\t 1st item : " << i.a << "\t 2nd item : " << i.b;
		return o;
	}

}	// end of namespace

# endif