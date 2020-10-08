///****************************AUTHOR**************************///
//Student Name: Omey Mohan Manyar
//USC Email ID: manyar@usc.edu
///***********************************************************//


#ifndef SEARCH_ALGORITHMS
#define SEARCH_ALGORITHMS

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <climits>
#include <queue>

#include "search_data_structure.hpp"
#include "Vec3i.hpp"
#include "search_utilities.hpp"
#include "file_container_utils.hpp"
#include "file_rw_utilities.hpp"
#include <stack>

namespace search_algo {

	void execute_BFS(input_container& current_input_container);

	void execute_UCS(input_container& current_input_container);

	void execute_A_star(input_container& current_input_container);

	void execute_search(input_container &current_input_container, int h_factor, int g_factor);

	void savePath(std::vector<search_node> solution_map, int position, bool success_flag = true);



}



#endif // SEARCH_ALGORITHMS
