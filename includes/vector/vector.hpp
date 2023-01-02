/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:58:48 by julpelle          #+#    #+#             */
/*   Updated: 2022/12/30 17:44:47 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef vector_HPP
# define vector_HPP

# include "../All.hpp"
# include "../iterators/iterRev.hpp"
# include "../iterators/itervector.hpp"
# include "../iterators/types.hpp"

namespace ft {

	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			// Types
			typedef	Alloc					allocator_type;
			typedef T						value_type;
			typedef T*						pointer;
			typedef T&						reference;
			typedef const T*				const_pointer;
			typedef const T&				const_reference;
			typedef size_t 					size_type;
			typedef std::ptrdiff_t			difference_type;
			
			typedef Itervector<random_access_iterator_tag, T>			iterator;
			typedef Itervector<random_access_iterator_tag, const T>		const_iterator;
			typedef IterRev<iterator>									reverse_iterator;
			typedef IterRev<const_iterator>								const_reverse_iterator;

			// Constructors
			explicit vector(const allocator_type& alloc = allocator_type());
			explicit vector(size_type n, const value_type &val = value_type(),
				const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, 
				const allocator_type& alloc = allocator_type());
			vector(const vector &v);

			// Destructor
			~vector(void);

			// Operator
			
			vector							&operator=(const vector &v);

			// Iterators
			iterator						begin (void);
			const_iterator					begin (void) const;
			iterator						end (void);
			const_iterator					end (void) const;
			reverse_iterator				rbegin (void);
			const_reverse_iterator			rbegin (void) const;
			reverse_iterator				rend (void);
			const_reverse_iterator			rend (void) const;
		
			// Capacity		
			size_type 						size (void) const;
			size_type 						max_size (void) const;
			void							resize (size_type n, value_type val = value_type());
  			size_type						capacity (void) const;
			bool 							empty (void) const;
  			void							reserve (size_type n);
		
			// Element Access
			reference 						operator[] (size_type n);
			const_reference 				operator[] (size_type n) const;
			reference 						at (size_type n);
			const_reference 				at (size_type n) const;
			reference 						front (void);
			const_reference 				front (void) const;
			reference 						back (void);
			const_reference 				back (void) const;
			
			// Modifiers		
			template <class InputIterator>
			void							assign (InputIterator first, InputIterator last);
			void							assign (size_type n, const value_type &val);
			void 							push_back (const value_type& val);
			void 							pop_back();

			iterator						insert (iterator it, const value_type &val);
			void							insert (iterator it, size_type n, const value_type &val);
			template <class	InputIterator>
			void							insert (iterator it, InputIterator fst, InputIterator lst);
			iterator 						erase (iterator position);
			iterator 						erase (iterator first, iterator last);
			void 							swap (vector& x);
			void							clear (void);
			
			// Allocator
			allocator_type 					get_allocator (void) const;

			// Utils

		private:
			size_type		_len;
			size_type		_cap;
			value_type		*_tab;
			allocator_type	_all;
	};
	
	// Constructors
	template <class T, class Alloc>
	vector<T, Alloc>::vector(const allocator_type& alloc) : _len(0), _cap(0), _tab(0),  _all(alloc)
	{
	}
	
	template <class T, class Alloc>
	vector<T, Alloc>::vector(size_type n, const value_type &val,
		const allocator_type& alloc) : _len(0), _cap(0), _tab(0), _all(alloc)
	{
		insert(begin(), n, val);
	}

	template <class T, class Alloc>
	template <class InputIterator>
	vector<T, Alloc>::vector(InputIterator first, InputIterator last,
		const allocator_type& alloc) : _len(0), _cap(0), _tab(0), _all(alloc)
	{
		insert(begin(), first, last);
	}
	
	template <class T, class Alloc>
	vector<T, Alloc>::vector(const vector &v) : _len(0), _cap(0), _tab(0)
	{
		_all = v._all;
		if (v.size())
			insert(begin(), v.begin(), v.end());
	}
	
	// Destructor
	
	template <class T, class Alloc>
	vector<T, Alloc>::~vector(void)
	{
	}

	template <class T, class Alloc>
	vector<T, Alloc>
	&vector<T, Alloc>::operator=(const vector &v)
	{
		if (&v == this)
			return (*this);
		_all = v.get_allocator();
		assign(v.begin(), v.end());
		return (*this);
	}

	// Iterators

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator
	vector<T, Alloc>::begin(void)
	{
		return (iterator(_tab));
	}
	
	template <class T, class Alloc>
	typename vector<T, Alloc>::const_iterator
	vector<T, Alloc>::begin(void) const
	{
		return (const_iterator(reinterpret_cast<const T*>(_tab)));
	}
	
	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator
	vector<T, Alloc>::end(void)
	{
		return (iterator(_tab + _len));
	}
	
	template <class T, class Alloc>
	typename vector<T, Alloc>::const_iterator
	vector<T, Alloc>::end(void) const
	{
		return (const_iterator(reinterpret_cast<const T*>(_tab + _len)));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reverse_iterator				
	vector<T, Alloc>::rbegin(void)
	{
		return (reverse_iterator(end()));
	}
	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reverse_iterator			
	vector<T, Alloc>::rbegin(void) const
	{
		return (const_reverse_iterator(end()));
	}
	
	template <class T, class Alloc>
	typename vector<T, Alloc>::reverse_iterator			
	vector<T, Alloc>::rend(void)
	{
		return (reverse_iterator(begin()));
	}
	
	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reverse_iterator			
	vector<T, Alloc>::rend(void) const
	{
		return (const_reverse_iterator(begin()));
	}

	// Capacity

	template<class T, class Alloc>
	typename vector<T, Alloc>::size_type
	vector<T, Alloc>::size(void) const
	{
		return (_len);
	}
	
	template<class T, class Alloc>
	typename vector<T, Alloc>::size_type
	vector<T, Alloc>::max_size(void) const
	{
		return (_all.max_size());
	}

	template <class T, class Alloc>
	void
	vector<T, Alloc>::resize(size_type n, value_type val)
	{
		size_type			nb;
		std::allocator<T>	alloc;

		if (n < _len) // si on a trop d'elements
		{
			for (iterator it = end() - (_len - n); it != end(); ++it)
				alloc.destroy(it._val);	// on detruit les elements en trop
		}
		else if (n > _len) // sinon
		{
			reserve(n); // on ajuste la capacite
			nb = n - _len;
			for (iterator it = end(); nb; --nb, ++it)
				alloc.construct(it._val, val); // on construit les elements manquants
		}
		_len = n;
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::size_type
	vector<T, Alloc>::capacity(void) const
	{
		if (_cap >= _len)
			return (_cap);
		else
			return (!_cap ? 0 : powl(2, _cap - 1));
	}

	template<class T, class Alloc>
	bool
	vector<T, Alloc>::empty(void) const
	{
		if (_len == 0)
			return (true);
		return (false);
	}

	template <class T, class Alloc>
	void
	vector<T, Alloc>::reserve(size_type n)
	{
		std::allocator<T>	alloc;
		size_type			old_cap = capacity();
		size_type			new_cap;
		T		 			*new_space;
	
		if (n <= old_cap) // si on a assez de places
			return ;
		while (n > (new_cap = capacity())) // si on a pas assez de places, on incremente la capacite de x
			++_cap;
		new_space = alloc.allocate(new_cap); // on alloue la nouvelle capacite
		for (size_type i = 0; i < _len; ++i)
		{
			alloc.construct(new_space + i, _tab[i]); // on construit les elements
			alloc.destroy(_tab + i); // on detruit la copie
		}
		alloc.deallocate(_tab, old_cap); // on desalloue la copie
		_tab = new_space; // on met le nouvel espace a la place de l'ancien
	}

	// Element Access

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference
	vector<T, Alloc>::operator[] (size_type n)
	{
		return (at(n));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference
	vector<T, Alloc>::operator[] (size_type n) const
	{
		return (at(n));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference
	vector<T, Alloc>::at (size_type n)
	{
		return (_tab[n]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference
	vector<T, Alloc>::at (size_type n) const
	{
		return (_tab[n]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference
	vector<T, Alloc>::front (void)
	{
		return (*begin());
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference
	vector<T, Alloc>::front (void) const
	{
		return (*begin());
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference
	vector<T, Alloc>::back (void)
	{
		return (*(end() - 1));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference
	vector<T, Alloc>::back (void) const
	{
		return (*(end() - 1));
	}

	// Modifiers

	template <class T, class Alloc>
	template <class InputIterator>
	void
	vector<T, Alloc>::assign(InputIterator first, InputIterator last)
	{
		clear();
		insert(end(), first, last);
	}

	template <class T, class Alloc>
	void
	vector<T, Alloc>::assign(size_type n, const value_type &val)
	{
		clear();
		insert(end(), n, val);
	}


	template <class T, class Alloc>
	void
	vector<T, Alloc>::push_back (const value_type& val)
	{
		insert(end(), val);
	}

	template <class T, class Alloc>	
	void
	vector<T, Alloc>::pop_back()
	{
		if (_len)
			erase(end() - 1);
	}
	

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator
	vector<T, Alloc>::insert(iterator it, const value_type &val)
	{
		difference_type		diff = it - begin();
	
		insert(it, (size_type)1, val);
		return (begin() + diff);
	}
	
	template <class T, class Alloc>
	void
	vector<T, Alloc>::insert(iterator it, size_type n, const value_type &val)
	{
		std::allocator<T>	alloc;
		iterator			old_end(end());
		difference_type		diff = it - begin();
	
		if (!n)
			return ;
		reserve(_len + n); // on augmente la capacite
		it = begin() + diff;
		_len += n;
		for (iterator b(end() - 1), a(b - n); a >= it; --a, --b) // pour les nouveaux elements
		{
			if (b >= old_end) // si pas assez de place, on construit le nouvel element
				alloc.construct(b._val, *a);
			else // sinon on l'affecte
				*b = *a;
		}
		for (; n; --n, ++it)
		{
			if (it >= old_end) // si on est au dela de l'espace precedent
				alloc.construct(it._val, val); // on construit la nouvel valeur
			else // sinon on met la val a la position it
				*it = val;
		}
	}

	template <class T, class Alloc>
	template <class InputIterator>
	void
	vector<T, Alloc>::insert(iterator it, InputIterator fst, InputIterator lst)
	{
		std::allocator<T>	alloc;
		iterator			old_end(end());
		difference_type		diff = it - begin();
	
		if (fst == lst)
			return ;
		reserve(_len + (lst - fst)); // on aumgente la capacite
		it = begin() + diff;
		_len += lst - fst;
		for (iterator b(end() - 1), a(b - (lst - fst)); a >= it; --a, --b) // pour les nouveaux elements
		{
			if (b >= old_end) // si pas assez de place, on construit le nouvel element
				alloc.construct(b._val, *a);
			else // sinon on l'affecte
				*b = *a;
		}
		for (; fst != lst; ++fst, ++it)
		{
			if (it >= old_end) // si on est au dela de l'espace precedent
				alloc.construct(it._val, *fst);  // on construit la nouvel valeur
			else // sinon on met la val a la position it
				*it = *fst;
		}
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator
	vector<T, Alloc>::erase (iterator position)
	{
		return (erase(position, position + 1));
	}
	
	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator
	vector<T, Alloc>::erase (iterator first, iterator last)
	{
		iterator	tmp(first);

		for (; last != end(); ++first, ++last)
			*first = *last;
		resize(_len - (last - first));
		return (tmp);
	}
	
	template <class T, class Alloc>
	void 
	vector<T, Alloc>::swap (vector & x)
	{
			T			*new_tab(_tab);
			size_type	new_size(_len);
			size_type	new_cap(_cap);
		allocator_type	new_alloc(_all);

		_tab = x._tab;
		_len = x._len;
		_cap = x._cap;
		_all = x._all;
		x._tab = new_tab;
		x._len = new_size;
		x._cap = new_cap;
		x._all = new_alloc;
	}
	

	template <class T, class Alloc>
	void
	vector<T, Alloc>::clear(void)
	{
		resize(0);
	}

	// Allocator

	template <class T, class Alloc>
	typename vector<T, Alloc>::allocator_type 
	vector<T, Alloc>::get_allocator() const
	{
		return (_all);
	}

	// Relational Operators

	template <class T>
	bool
	operator==(const vector<T> &lhs, const vector<T> &rhs)
	{
		return (lhs < rhs || rhs < lhs ? false : true);
	}
	
	template <class T>
	bool
	operator!=(const vector<T> &lhs, const vector<T> &rhs)
	{
		return (!(lhs == rhs));
	}
	
	template <class T>
	bool
	operator<(const vector<T> &lhs, const vector<T> &rhs)
	{
		typename vector<T>::const_iterator		lhs_it(lhs.begin());
		typename vector<T>::const_iterator		rhs_it(rhs.begin());
	
		for (; rhs_it != rhs.end(); ++lhs_it, ++rhs_it)
		{
			if (lhs_it == lhs.end() || *lhs_it < *rhs_it)
				return (true);
		}
		return (false);
	}
	
	template <class T>
	bool
	operator<=(const vector<T> &lhs, const vector<T> &rhs)
	{
		return (!(lhs > rhs));
	}
	
	template <class T>
	bool
	operator>(const vector<T> &lhs, const vector<T> &rhs)
	{
		return (rhs < lhs);
	}
	
	template <class T>
	bool
	operator>=(const vector<T> &lhs, const vector<T> &rhs)
	{
		return (!(lhs < rhs));
	}
	
	template <class T>
	void
	swap(vector<T> &x, vector<T> &y)
	{
		x.swap(y);
	}

  
}	// end of namespace

# endif