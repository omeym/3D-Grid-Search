///****************************AUTHOR**************************///
//Student Name: Omey Mohan Manyar
//USC Email ID: manyar@usc.edu
///***********************************************************//


#ifndef SEARCH_UTILITIES_HPP
#define	SEARCH_UTILITIES_HPP
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#include "search_data_structure.hpp"
#include "Vec3i.hpp"



//This is a utilities file which will have all functions needed to perform the search operations

namespace search_utils {

	bool check_if_neighbors(Vec3i current_node, Vec3i queried_node, std::vector<int> action_codes);

	double eucld_dist_heuristic(Vec3i current_node, Vec3i goal_node);

	int manhattan_dist_heuristc(Vec3i current_node, Vec3i goal_node);

	int diagonal_dist(Vec3i current_node, Vec3i goal_node);

	bool is_valid(grid_location current_grid_loc, Vec3i grid_size, bool goal_flag = false);

	bool check_if_goal(grid_location current_grid_loc, Vec3i goal_node);

	std::vector<std::pair<grid_location, int>> get_feasible_neighbors(grid_location current_location, std::vector<grid_location> maze_map, Vec3i size_of_maze);

	std::vector<Vec3i> get_feasible_neighbors_map(Vec3i current_location, std::vector<int> action_codes);

	bool is_valid(Vec3i current_grid_loc, Vec3i grid_size, bool goal_flag = false);


}



#endif // !SEARCH_UTILITIES_HPP
