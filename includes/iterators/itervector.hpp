/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itervector.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:02:59 by julpelle          #+#    #+#             */
/*   Updated: 2022/12/29 13:11:47 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITERvector_HPP
# define ITERvector_HPP

# include "../All.hpp"

namespace ft {

	template <class Category, class T, class Distance = std::ptrdiff_t,
		class Pointer = T*, class Reference = T&>
	class Itervector
	{
		public:
			// Types
			typedef T				value_type;
			typedef Pointer			pointer;
			typedef Reference		reference;
			typedef Distance		difference_type;
			typedef Category		iterator_category;
			
			// Constructors
			Itervector(void) : _val(0) {}
			Itervector(reference value) : _val(&value) {}
			Itervector(pointer value) : _val(value) {}
			Itervector(const Itervector& it) : _val(it._val) {}

			// Destructor
			~Itervector(void) {}

			// Operators
			template <class Cat, class T2, class Dist, class Point, class Refer>
			// operator Itervector<Cat, const T2, Dist, Point, Refer>() { return Itervector<Cat, const T2, Dist, Point, Refer>(*_val); }
			// Itervector				&operator=(pointer it)
			// {
			// 	_val = it;
			// 	return *this;
			// }
			Itervector				&operator=(const Itervector &it)
			{
				_val = it._val;
				return *this;
			}
			bool					operator==(const Itervector &it) const { return (_val == it._val); }
			bool					operator!=(const Itervector &it) const { return (_val != it._val); }
			bool					operator<(const Itervector& it) const { return (_val < it._val); }
			bool					operator>(const Itervector& it) const { return (_val > it._val); }
			bool					operator<=(const Itervector& it) const { return (_val <= it._val); }
			bool					operator>=(const Itervector& it) const { return (_val >= it._val); }
			reference				operator*(void) { return *_val; }
			pointer					operator->(void) { return _val; }
			reference				operator[](difference_type n) const { return _val[n]; }
			Itervector				&operator++(void)
			{
				++_val;
				return *this;
			}
			Itervector				operator++(int n)
			{
				Itervector tmp = *this;
				++(*this);
				(void)n;
				return (tmp);
			}
			Itervector				&operator--(void)
			{
				--_val;
				return *this;
			}
			Itervector				operator--(int n)
			{
				Itervector tmp = *this;
				(void)n;
				--(*this);
				return (tmp);
			}
			Itervector				operator+(difference_type n) const { return Itervector(_val + n); }
			Itervector				operator-(difference_type n) const { return Itervector(_val - n); }
			difference_type			operator-(const Itervector& it) const { return (_val - it._val); }
			Itervector				&operator+=(difference_type n)
			{
				_val += n;
				return *this;
			}
			Itervector				&operator-=(difference_type n)
			{
				_val -= n;
				return *this;
			}

			// Variables
			value_type				*_val;
			
		private:
			//Friendship :
			template <class Cat, class T2, class Dist, class Point, class Refer>
			friend Dist		operator-(const Itervector<Cat, T2, Dist, Point, Refer> &lhs,
				const Itervector<Cat, T2, Dist, Point, Refer> &rhs);
			template <class Cat, class T2, class Dist, class Point, class Refer>
			friend bool		operator<(const Itervector<Cat, T2, Dist, Point, Refer> &lhs,
				const Itervector<Cat, T2, Dist, Point, Refer> &rhs);
		
	};
	
}	// end of namespace

# endif