///****************************AUTHOR**************************///
//Student Name: Omey Mohan Manyar
//USC Email ID: manyar@usc.edu
///***********************************************************//

#ifndef FILE_CONTAINER_HPP
#define FILE_CONTAINER_HPP

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "search_data_structure.hpp"
#include "Vec3i.hpp"
#include <map>
#include <unordered_map>

//This class will contain all the data from text file in appropriate format
class input_container {
public:

	//The Type of Search Algorithm to use
	std::string Search_Algo;
	
	//The size of the maze
	Vec3i size_of_maze;

	//Entrance Postion in the grid
	Vec3i entry_position;

	//Exit Position in the grip
	Vec3i exit_position;

	//The number of grid locations where a valid move is available
	int no_of_grids = 0;

	//The Locations in the maze that have a valid move
	std::vector<grid_location> maze_map;

	std::unordered_map<Vec3i, std::vector<int>> grid_map;


};

//Node Defination for the output path
//Each node in the graph will be of this type

//This container will be used to write the output file
class output_container {
public:
	
	//This Should change to FAIL if the algorithm fails
	std::string search_status;
	
	//The total cost of the search algorithm
	int total_cost;

	//The Total Number of Points in the Solution
	int number_of_steps;


	//This will be the map of feasible output points
	std::vector<search_node> solution_path;



};






#endif // !File_CONTAINER_HPP