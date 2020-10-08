///****************************AUTHOR**************************///
//Student Name: Omey Mohan Manyar
//USC Email ID: manyar@usc.edu
///***********************************************************//

#include "search_utilities.hpp"



//Checks if the current_node and the queried nodes are neighbors or not
bool search_utils::check_if_neighbors(Vec3i current_node, Vec3i queried_node, std::vector<int> action_codes) {

	Vec3i dist_vec = current_node - queried_node;

	if ((abs(dist_vec[0]) > 1) || (abs(dist_vec[1]) > 1) || (abs(dist_vec[2]) > 1)) {
		return false;
	}
	else {
		return true;
	}

}


//Check if node is valid and within limits with available nodes, in case of goal its ok to not have any action moves
bool search_utils::is_valid(grid_location current_grid_loc, Vec3i grid_size, bool goal_flag) {

	//Checking if the current grid node lies outside the grid
	if ((current_grid_loc.grid_point[0] > grid_size[0]) || (current_grid_loc.grid_point[1] > grid_size[1]) || (current_grid_loc.grid_point[2] > grid_size[2])) {
		return false;
	}

	//Checking if the current grid node is blocked and has no action moves
	else if (current_grid_loc.action_code.size() == 0 && !goal_flag) {
		return false;
	}

	//Otherwise this is a valid node
	else {
		return true;
	}

}

//Validity Check Overload with Vec3i
bool search_utils::is_valid(Vec3i current_grid_loc, Vec3i grid_size, bool goal_flag) {

	//Checking if the current grid node lies outside the grid
	if ((current_grid_loc[0] > grid_size[0]) || (current_grid_loc[1] > grid_size[1]) || (current_grid_loc[2] > grid_size[2])) {
		return false;
	}

	//Otherwise this is a valid node
	else {
		return true;
	}

}


//Eucleadean distance heuristic
double search_utils::eucld_dist_heuristic(Vec3i current_node, Vec3i goal_node) {

	double distance = sqrt(pow((goal_node[0] - current_node[0]),2) + pow((goal_node[1] - current_node[1]), 2) + pow((goal_node[2] - current_node[2]),2));
	return distance;
}


//Manhattan Distance Heuristic
int search_utils::manhattan_dist_heuristc(Vec3i current_node, Vec3i goal_node) {

	int distance = abs(goal_node[0] - current_node[0]) + abs(goal_node[1] - current_node[1]) + abs(goal_node[2] - current_node[2]);

	return distance;
}


//Diagonal Distance Heuristic
int search_utils::diagonal_dist(Vec3i current_node, Vec3i goal_node) {

	
	std::vector<int> diagonal_dist{ abs(current_node[0] - goal_node[0]), abs(current_node[1] - goal_node[1]) , abs(current_node[2] - goal_node[2]) };

	return *max_element(diagonal_dist.begin(), diagonal_dist.end());
	


} 


//Check whether the current grid location is a goal node
bool search_utils::check_if_goal(grid_location current_grid_loc, Vec3i goal_node) {

	if (current_grid_loc.grid_point == goal_node) {
		return true;
	}

	else {
		return false;
	}
}


//Get the neighbors which are a feasible
std::vector<std::pair<grid_location, int>> search_utils::get_feasible_neighbors(grid_location current_location, std::vector<grid_location> maze_map, Vec3i size_of_maze) {
	
	//std::cout << "The available moves at this point = " << current_location.action_code.size() << std::endl;

	action_code_table lookup_table;
	std::vector<std::pair<grid_location, int>> feasible_neighbors;

	std::vector<Vec3i> maze_map_pose;

	for (size_t i = 0; i < maze_map.size(); i++) {
		maze_map_pose.emplace_back(maze_map[i].grid_point);
	}

	for (size_t i = 0; i < current_location.action_code.size(); i++) {
		Vec3i current_move = lookup_table.decode_action(current_location.action_code[i]);
		//std::cout << "The decoded move = " << current_move << std::endl;
		Vec3i updated_position = current_move + current_location.grid_point;
		//std::cout << "The updated position = " << updated_position <<std::endl;

		std::vector<Vec3i>::iterator position_itr = std::find(maze_map_pose.begin(), maze_map_pose.end(), updated_position);

		int position_index = position_itr - maze_map_pose.begin();

		if (position_itr == maze_map_pose.end()) {
			//std::cout << "Returned because reached goal" << std::endl;
			continue;
		}

		if (!is_valid(maze_map[position_index], size_of_maze)) {
			//std::cout << "Next iteration because in valid" << std::endl;
			continue;
		}
		
		
		feasible_neighbors.emplace_back(std::make_pair(maze_map[position_index], position_index));
		
	}


	return feasible_neighbors;


}


//Get the neighbors which are a feasible
std::vector<Vec3i> search_utils::get_feasible_neighbors_map(Vec3i current_location, std::vector<int> action_codes) {

	//std::cout << "The available moves at this point = " << current_location.action_code.size() << std::endl;

	action_code_table lookup_table;
	std::vector<Vec3i> feasible_neighbors;

	for (int i = 0; i < action_codes.size()-1; i++) {
		Vec3i current_move = lookup_table.decode_action(action_codes[i]);

		Vec3i updated_postion = current_location + current_move;
		feasible_neighbors.emplace_back(updated_postion);
	}

	return feasible_neighbors;


}