/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapNode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:47:36 by julpelle          #+#    #+#             */
/*   Updated: 2022/12/29 13:12:20 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef mapNode_HPP
# define mapNode_HPP

# include "../All.hpp"

namespace	ft
{

	template <typename T>
	struct mapNode
	{
		// Constructors
		mapNode(void);
		mapNode(const T &v, t_node typ, mapNode<T> *u = 0, mapNode<T> *l = 0, mapNode<T> *r = 0);
		mapNode(const mapNode<T> &t);

		// Destructor
		~mapNode(void);

		// Assignation
		mapNode<T>		&operator=(const mapNode<T> &m);

		// Atributes
		t_node		type;
		mapNode		*parent;
		mapNode		*l_child;
		mapNode		*r_child;
		T			val;
		T			*valptr;
	};
	
	// Constructors

	template <typename T>
	mapNode<T>::mapNode(void) : type(node), parent(this), l_child(this), r_child(this), val(), valptr(0)
	{

	}

	template <typename T>
	mapNode<T>::mapNode(const T &v, t_node typ, mapNode<T> *u, mapNode<T> *l,
	mapNode<T> *r) : type(typ), parent(u), l_child(l), r_child(r), val(v), valptr(0)
	{
		valptr = &val;
	}

	template <typename T>
	mapNode<T>::mapNode(const mapNode<T> &m) : type(node), parent(this), l_child(this), r_child(this), val(m.val), valptr(0)
	{
		if (!(m.valptr))
			valptr = 0;
		else
			valptr = m.valptr;
	}

	// Destructor

	template <typename T>
	mapNode<T>::~mapNode(void)
	{
	}

	// Assignation

	template <typename T>
	mapNode<T>
	&mapNode<T>::operator=(const mapNode<T> &m)
	{
		if (*this == m)
			return (*this);
		val = m.val;;
		if (!(m.valptr))
			valptr = 0;
		else
			valptr = m.valptr;
		return (*this);
	}



}	// end of namespace



# endif