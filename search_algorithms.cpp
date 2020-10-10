///****************************AUTHOR**************************///
//Student Name: Omey Mohan Manyar
//USC Email ID: manyar@usc.edu
///***********************************************************//

#include "search_algorithms.hpp"


//This header file contains all the search algorithm implementations



//Implementation for the search, keeping it standardized based on the algorithm
void search_algo::execute_search(input_container& current_input_container, int h_factor, int g_factor) {


	std::vector<search_node> solution_map;			//This datastrucutre is being used to store the resultant path

	Vec3i size_of_maze = current_input_container.size_of_maze;	//The size of input maze

	Vec3i start_location = current_input_container.entry_position;	//Entry Position of the maze

	Vec3i end_location = current_input_container.exit_position;		//Goal Position

	int no_of_grid_pts = current_input_container.no_of_grids;		//Total Number of nodes

	std::vector<grid_location> maze_map = current_input_container.maze_map;	//The map containing all points and valid action items

	std::unordered_map<Vec3i, std::vector<int>>& grid_map = current_input_container.grid_map;		//Grid map to access the elements in O(1) best case

	if (grid_map.find(start_location) == grid_map.end()) {
		std::cout << "Start location is not present in the bounds" << std::endl;
		savePath(solution_map, 0, false);
		return;
	}


	else if (grid_map.find(start_location) == grid_map.end()) {
		std::cout << "End Location is not present in the map" << std::endl;
		savePath(solution_map, 0, false);
		return;
	}

	else if (grid_map[start_location].size() == 1) {
		std::cout << "Start Location does not have any action moves" << std::endl;
		savePath(solution_map, 0, false);
		return;
	}


	//checks to ensure the validity of start and end points
	else if (!search_utils::is_valid(start_location, size_of_maze)) {
		std::cout << "Start is not a feasible location" << std::endl;
		savePath(solution_map, 0, false);
		return;
	}

	else if (!search_utils::is_valid(end_location, size_of_maze, true)) {
		std::cout << "Goal is not a feasible location" << std::endl;
		savePath(solution_map, 0, false);
		return;
	}



	solution_map.resize(no_of_grid_pts);
	int strt_index = grid_map[start_location].back();

	solution_map[strt_index].initialize_cost(0, 0);
	solution_map[strt_index].parent_node_id = -1;
	//solution_map[strt_index].grid_position.grid_point = maze_map[strt_index].grid_point;
	//solution_map[strt_index].grid_position.action_code = maze_map[strt_index].action_code;
	solution_map[strt_index].grid_position.grid_point = start_location;
	solution_map[strt_index].grid_position.action_code = grid_map[start_location];

	if (start_location == end_location) {
		std::cout << "Start and end are the same" << std::endl;
		savePath(solution_map, 0);
		return;
	}

	//This queue will contain the open list this will contain the f value and the position of the node in the array 
	std::priority_queue <std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> priority_container;

	priority_container.push(std::make_pair(0, strt_index));
	//Inserting the start node on the open list
	
	bool reached_goal = false;


	//Defining the closed list
	std::vector<bool> closed_nodes_list;			//List which keeps a track of the closed nodes
	closed_nodes_list.assign(no_of_grid_pts, false);

	bool found_goal = false;

	while (!priority_container.empty()) {

		//Getting the next element on the open queue
		//First is the cost, second is the index
		std::pair<int, int> current_grid_point = priority_container.top();
		//Removing this element from the open priority container
		priority_container.pop();

		//Adding this vertex to the closed list
		closed_nodes_list[current_grid_point.second] = true;

		//Check if this is the goal node or not
		if (search_utils::check_if_goal(maze_map[current_grid_point.second], end_location)) {
			savePath(solution_map, current_grid_point.second);
			return;
		}

		//Getting the feasible neighbors for current location in consideration
		std::vector<Vec3i> feasible_neighbors = search_utils::get_feasible_neighbors_map(maze_map[current_grid_point.second].grid_point, grid_map[maze_map[current_grid_point.second].grid_point]);


		//Iterating through the feasible neighbors
		for (size_t i = 0; i < feasible_neighbors.size(); i++) {

			Vec3i current_position;
			int current_index = grid_map[feasible_neighbors[i]].back();

			current_position = feasible_neighbors[i];
			//std::cout << "Current position = " << current_position << std::endl;

			//If current node is goal then return and complete the search
			if (search_utils::check_if_goal(maze_map[current_index], end_location)) {
				//add this to the solution map
				search_node goal_node;
				int h_new = 0;
				double distance = search_utils::eucld_dist_heuristic(maze_map[current_grid_point.second].grid_point, feasible_neighbors[i]);
				int node_cost = (int)((distance * g_factor));
				int g_new = solution_map[current_grid_point.second].node_g + (int)(distance * g_factor);
				solution_map[current_index].initialize_cost(h_new, g_new);
				solution_map[current_index].node_cost = node_cost;
				solution_map[current_index].parent_node_id = current_grid_point.second;
				solution_map[current_index].grid_position.grid_point = feasible_neighbors[i];
				solution_map[current_grid_point.second].child_node_id = current_index;
				savePath(solution_map, current_index);
				found_goal = true;
				return;
			}



			//Check if we have already processed this node or not
			else if (!closed_nodes_list[current_index]) {
				double distance = search_utils::eucld_dist_heuristic(maze_map[current_grid_point.second].grid_point, feasible_neighbors[i]);
				int g_new = solution_map[current_grid_point.second].node_g + (int)((distance * g_factor));
				int node_cost = (int)((distance * g_factor));
				int h_new = int(search_utils::eucld_dist_heuristic(current_position, end_location)) * g_factor* h_factor;
				int f_new = g_new + h_new;
				
				if ((solution_map[current_index].node_f == INT_MAX) || (solution_map[current_index].node_f > f_new)) {
					
					priority_container.push(std::make_pair(f_new, current_index));
					solution_map[current_index].initialize_cost(h_new, g_new);
					solution_map[current_index].node_cost = node_cost;
					solution_map[current_index].parent_node_id = current_grid_point.second;
					solution_map[current_index].grid_position.grid_point = feasible_neighbors[i];
					solution_map[current_grid_point.second].child_node_id = current_index;
				}
			}




			else {
				continue;
			}

		}


	}



	if (found_goal == false) {
		std::cout << "Did not find goal" << std::endl;
		savePath(solution_map, 0, false);
	}

	return;




}




void search_algo::savePath(std::vector<search_node> solution_map, int position, bool success_flag) {

	output_container current_output;
	
	
	if (!success_flag) {
		std::cout << "Could not find the goal" << std::endl;
		current_output.search_status = "FAIL";
		file_rw::write_txt(current_output);
		return;
	}
	
	std::cout << "\nThe Path has been Computed" << std::endl;
	
	
	std::stack<int> Path;

	int index = position;

	while (solution_map[index].parent_node_id != -1)
	{
		Path.push(index);
		int temp_index = solution_map[index].parent_node_id;
		index = temp_index;

	}

	Path.push(index);

	current_output.number_of_steps =  Path.size();
	current_output.search_status = "SUCCESS";
	
	int total_cost = 0;

	while (!Path.empty())
	{
		int p = Path.top();
		Path.pop();
		current_output.solution_path.emplace_back(solution_map[p]);
		total_cost += solution_map[p].node_cost;
		

	}
	
	current_output.total_cost = total_cost;
	file_rw::write_txt(current_output);

	return;






}


//Implementation of Astar
void search_algo::execute_A_star(input_container& current_input_container) {

	int h_factor = 1;
	int g_factor = 10;

	execute_search(current_input_container, h_factor, g_factor);


}


//Implementation BFS
void search_algo::execute_BFS(input_container& current_input_container) {

	int h_factor = 0;
	int g_factor = 1;

	execute_search(current_input_container, h_factor, g_factor);

}


void search_algo::execute_UCS(input_container& current_input_container) {

	int h_factor = 0;
	int g_factor = 10;
	
	execute_search(current_input_container, h_factor, g_factor);
}