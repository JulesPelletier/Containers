/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   All.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:55:43 by julpelle          #+#    #+#             */
/*   Updated: 2022/12/29 19:46:02 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ALL_HPP
# define ALL_HPP

///////////////////////
// Include Libraries //
///////////////////////

# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include <memory>
# include <fstream>
# include <cstddef>
# include <deque>
# include <vector>
# include <stack>
# include <map>

///////////////////////
//       Utils       //
///////////////////////

// Color
# include "utils/colors.hpp"

// Pair
# include "utils/pair.hpp"
# include "utils/less.hpp"
# include "utils/binary.hpp"

// Node
# include "utils/node.hpp"

// Extras
# include "utils/enable_if.hpp"
# include "utils/is_integral.hpp"
# include "utils/equal.hpp"

///////////////////////
//     Containers    //
///////////////////////

# include "vector/vector.hpp"
# include "stack/stack.hpp"
# include "map/map.hpp"

///////////////////////
//     Iterators     //
///////////////////////

# include "iterators/iterRev.hpp"
# include "iterators/itervector.hpp"
# include "iterators/iterMap.hpp"
# include "iterators/iterTraits.hpp"
# include "iterators/types.hpp"

///////////////////////
//       Tests       //
///////////////////////

# include "../tests/basic/basicTest.hpp"
# include "../tests/basic/showContainer.hpp"
# include "../tests/preliminary/preliminary.hpp"
# include "../tests/vector/vectorTest.hpp"
# include "../tests/map/mapTest.hpp"
# include "../tests/compare/compare.hpp"
# include "../tests/preliminary/preliminary.hpp"

///////////////////////
//     Functions     //
///////////////////////

int 	error_msg(std::string msg, int color, int ret);
void 	print_header(std::string msg, std::string arg);





#endif