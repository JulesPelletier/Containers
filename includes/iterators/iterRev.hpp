/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterRev.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:07:26 by julpelle          #+#    #+#             */
/*   Updated: 2022/12/29 13:11:39 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITERREV_HPP
# define ITERREV_HPP

# include "../All.hpp"

namespace ft	{

	template <class Iterator>
	class IterRev
	{
		public:
			// Types
			typedef Iterator								iterator_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::iterator_category	iterator_category;
			
			// Constructors
			IterRev(void) {_base = iterator_type(); }
			IterRev(iterator_type it) {_base = it; }
			IterRev(const IterRev<iterator_type> &it) { *this = it; }

			// Destructor
			~IterRev(void) {}

			// Operators
			iterator_type		base() const { return _base; }
			IterRev				&operator=(const IterRev &it) 
			{
				_base = it.base();
				return *this;
			}
			reference			operator*(void) const
			{
				iterator_type tmp = _base;
				return (*(--tmp));
			}
			pointer				operator->(void) const
			{
				iterator_type tmp = _base;
				return (&(*(--tmp)));
			}
			reference			operator[](difference_type n) const { return (*((*this + n))); }
			IterRev				&operator++(void)
			{
				_base--;
				return *this;
			}
			IterRev				operator++(int n)
			{
				iterator_type tmp = _base;
				--_base;
				(void)n;
				return (tmp);
			}
			IterRev				&operator--(void)
			{
				_base++;
				return *this;
			}
			IterRev				operator--(int n)
			{
				iterator_type tmp = _base;
				++_base;
				(void)n;
				return (tmp);
			}
			IterRev				operator+(difference_type n) const { return IterRev(_base - n); }
			IterRev				operator-(difference_type n) const { return IterRev(_base + n); }
			IterRev				&operator+=(difference_type n)
			{
				_base -= n;
				return *this;
			}
			IterRev				&operator-=(difference_type n)
			{
				_base += n;
				return *this;
			}
			
		protected:
			// Variables
			iterator_type				_base;
			
	};
	template <class Iterator1, class Iterator2>
	bool
	operator==(const IterRev<Iterator1> &lhs, const IterRev<Iterator2> &rhs)
	{
		return (lhs.base() == rhs.base());
	}
	
	template <class Iterator1, class Iterator2>
	bool
	operator!=(const IterRev<Iterator1> &lhs, const IterRev<Iterator2> &rhs)
	{
		return (lhs.base() != rhs.base());
	}
	
	template <class Iterator1, class Iterator2>
	bool
	operator<(const IterRev<Iterator1> &lhs, const IterRev<Iterator2> &rhs)
	{
		return (lhs.base() > rhs.base());
	}
	
	template <class Iterator1, class Iterator2>
	bool
	operator<=(const IterRev<Iterator1> &lhs, const IterRev<Iterator2> &rhs)
	{
		return (!(lhs.base() > rhs.base()));
	}
	
	template <class Iterator1, class Iterator2>
	bool
	operator>(const IterRev<Iterator1> &lhs, const IterRev<Iterator2> &rhs)
	{
		return (rhs.base() < lhs.base());
	}
	
	template <class Iterator1, class Iterator2>
	bool
	operator>=(const IterRev<Iterator1> &lhs, const IterRev<Iterator2> &rhs)
	{
		return (!(lhs.base() < rhs.base()));
	}
	
	template <class Iterator>
	IterRev<Iterator>
	operator+(typename IterRev<Iterator>::difference_type n, const IterRev<Iterator> &rev_it)
	{
		return (IterRev<Iterator>(rev_it.base() - n));
	}
	
	template <class Iterator>
	typename Iterator::difference_type
	operator-(const IterRev<Iterator> &lhs, const IterRev<Iterator> &rhs)
	{
		return (rhs.base() - lhs.base());
	}
	
}	// end of namespace

# endif