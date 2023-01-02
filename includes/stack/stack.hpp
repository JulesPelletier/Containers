/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:58:06 by julpelle          #+#    #+#             */
/*   Updated: 2022/12/29 13:12:34 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef stack_HPP
# define stack_HPP

# include "../All.hpp"
# include "../iterators/iterRev.hpp"
# include "../iterators/itervector.hpp"
# include "../iterators/types.hpp"

namespace ft 
{

	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			// Types
			typedef T						value_type;
			typedef size_t 					size_type;
			typedef Container				container_type;
			
			// Constructors
			explicit stack(const container_type & ctnr = container_type());
			explicit stack(const stack &s);

			// Destructor
			~stack(void);

			// Assignation
			stack							&operator=(const stack &s);

			// Capacity		
			bool 							empty (void) const;
			size_type 						size (void) const;
			value_type						&top (void);
			const value_type				&top (void) const;
			void 							push (const value_type& val);
			void 							pop (void);

		private:
			container_type	_cont;
	};
	
	// Constructors

	template <class T, class Container>
	stack<T, Container>::stack(const container_type &cntr) : _cont(cntr)
	{
	}

	template <class T, class Container>
	stack<T, Container>::stack(const stack &s) : _cont(s._cont)
	{
	}

	// Destructor
	
	template <class T, class Container>
	stack<T, Container>::~stack(void)
	{
	}
	
	// Assignation 

	template <class T, class Container>
	stack<T, Container>				
	&stack<T, Container>::operator=(const stack &s)
	{
		if (this == &s)
			return (*this);
		_cont = s._cont;
		return (*this);
	}

	// Capacity		
	template <class T, class Container>
	bool 							
	stack<T, Container>::empty (void) const
	{
		return (_cont.empty());
	}
	
	template <class T, class Container>
	typename stack<T,Container>::size_type 						
	stack<T, Container>::size (void) const
	{
		return (_cont.size());
	}
	
	template <class T, class Container>
	typename stack<T,Container>::value_type						
	&stack<T, Container>::top (void)
	{
		return (_cont.back());
	}
	
	template <class T, class Container>
	const typename stack<T,Container>::value_type				
	&stack<T, Container>::top (void) const
	{
		return (_cont.back());

	}
	
	template <class T, class Container>
	void 							
	stack<T, Container>::push (const value_type& val)
	{
		return (_cont.push_back(val));
	}
	
	template <class T, class Container>
	void 							
	stack<T, Container>::pop (void)
	{
		return (_cont.pop_back());
	}

	// Relational Operators

	template <class T, class Container>
	bool
	operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (!(lhs != rhs));
	}
	
	template <class T, class Container>
	bool
	operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs < rhs || rhs < lhs);
	}
	
	template <class T, class Container>
	bool
	operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs._cont < rhs._cont);
	}
	
	template <class T, class Container>
	bool
	operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (!(lhs > rhs));
	}
	
	template <class T, class Container>
	bool
	operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (rhs < lhs);
	}
	
	template <class T, class Container>
	bool
	operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (!(lhs < rhs));
	}
	
}	// end of namespace

# endif