/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterMap.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:41:31 by julpelle          #+#    #+#             */
/*   Updated: 2022/12/30 17:19:24 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITERmap_HPP
# define ITERmap_HPP

# include "../All.hpp"
# include "../map/mapNode.hpp"
# include "../iterators/iterTraits.hpp"

namespace	ft
{

	template <class Category, class T, class Distance = std::ptrdiff_t,
		class Pointer = T*, class Reference = T&>
	class Itermap : public iterator<bidirectional_iterator_tag, T>
	{
		public:
			// Types
			typedef T				value_type;
			typedef Pointer			pointer;
			typedef Reference		reference;
			typedef Distance		difference_type;
			typedef Category		iterator_category;
			
			// Constructors
			Itermap(mapNode<value_type> *n = 0);
			Itermap(const Itermap &it);

			// Destructor
			~Itermap(void);

			// Assignation
			Itermap			&operator=(const Itermap &i);

			// Operators
			bool			operator==(const Itermap &i);
			bool			operator!=(const Itermap &i);
			
			reference		operator*(void);
			pointer			operator->(void);
			Itermap			&operator++(void);
			Itermap			operator++(int val);
			Itermap			&operator--(void);
			Itermap			operator--(int val);

			// Attributes
			mapNode<value_type>		*node;

	};
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itermap<Category, T, Distance, Pointer, Reference>::Itermap(mapNode<value_type> *n) : node(n)
	{
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itermap<Category, T, Distance, Pointer, Reference>::Itermap(const Itermap &m) : node(m.node)
	{
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itermap<Category, T, Distance, Pointer, Reference>::~Itermap(void)
	{
	}

	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itermap<Category, T, Distance, Pointer, Reference>			
	&Itermap<Category, T, Distance, Pointer, Reference>::operator=(const Itermap &i)
	{
		if (&i == this)
			return (*this);
		node = i.node;
		return (*this);
	}
	template <class Category, class T, class Distance, class Pointer, class Reference>
	bool			
	Itermap<Category, T, Distance, Pointer, Reference>::operator==(const Itermap &i)
	{
		return (node == i.node);
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	bool			
	Itermap<Category, T, Distance, Pointer, Reference>::operator!=(const Itermap &i)
	{
		return (!(*this == i));
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	typename Itermap<Category, T, Distance, Pointer, Reference>::reference		
	Itermap<Category, T, Distance, Pointer, Reference>::operator*(void)
	{
		return (*(node->valptr));
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	typename Itermap<Category, T, Distance, Pointer, Reference>::pointer			
	Itermap<Category, T, Distance, Pointer, Reference>::operator->(void)
	{
		return (node->valptr);
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itermap<Category, T, Distance, Pointer, Reference>			
	&Itermap<Category, T, Distance, Pointer, Reference>::operator++(void)
	{
		if (node->r_child && node->r_child != node) // si on peut aller sur la droite de l'arbre
		{
			node = node->r_child; // on remonte d'un cran
			while (node->l_child && node->l_child != node) // on va jusqu'au bout de la branche gauche de la branche droite ^^
				node = node->l_child;
		}
		else if (node->type == left) // si on est sur une branche gauche, on remonte d'un cran
			node = node->parent;
		else if (node->type == right && node->valptr) // si on est sur une branche droite
		{
			do
				node = node->parent;
			while (node->type != left); // tant qu'on est pas au sommet de la branche, on remonte
			node = node->parent;
		}
		return (*this);
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itermap<Category, T, Distance, Pointer, Reference>			
	Itermap<Category, T, Distance, Pointer, Reference>::operator++(int val)
	{
		Itermap<Category, T, Distance, Pointer, Reference>		tmp;

		(void)val;
		tmp = *this;
		++(*this);
		return (tmp);
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itermap<Category, T, Distance, Pointer, Reference>			
	&Itermap<Category, T, Distance, Pointer, Reference>::operator--(void)
	{
		if (node->l_child && node->l_child != node) // si on peut aller sur la gauche de l'arbre
		{
			node = node->l_child; // on descends d'un cran
			while (node->r_child && node->r_child != node) // on va jusqu'au bout de la branche droite de la branche gauche ^^
				node = node->r_child;
		}
		else if (node->type == right) // si on est sur une branche droite, on remonte d'un cran
			node = node->parent;
		else if (node->type == left && node->valptr)
		{
			do
				node = node->parent;
			while (node->type != right); // tant qu'on est pas au sommet de la branche, on remonte
			node = node->parent;
		}
		return (*this);
	}
	
	template <class Category, class T, class Distance, class Pointer, class Reference>
	Itermap<Category, T, Distance, Pointer, Reference>			
	Itermap<Category, T, Distance, Pointer, Reference>::operator--(int val)
	{
		Itermap<Category, T, Distance, Pointer, Reference>		tmp;

		(void)val;
		tmp = *this;
		--(*this);
		return (tmp);
	}
	
}	// end of namespace

# endif