///****************************AUTHOR**************************///
//Student Name: Omey Mohan Manyar
//USC Email ID: manyar@usc.edu
///***********************************************************//



/////Standard C++ Header Files/////////////
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iostream>

////Headers for Standard DataStructures/////
#include <unordered_map>
#include <string>
#include <vector>
#include <map>
#include <algorithm>


///////////////Custom Headers///////////////
#include "file_rw_utilities.hpp"
#include "file_container_utils.hpp"
#include "search_data_structure.hpp"
#include "Vec3i.hpp"
#include "search_algorithms.hpp"
#include <chrono>
#include <ctime>


int main() {

	std::cout << "Starting Search" << std::endl;
	std::chrono::time_point<std::chrono::system_clock> start, end;
	//Defining the input container
	input_container search_input;
	start = std::chrono::system_clock::now();
	//Parsing the input container to be defined using input.txt file
	file_rw::read_txt(search_input);

	end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	
	std::cout<< "elapsed time: " << elapsed_seconds.count() << "s\n";
	
	start = std::chrono::system_clock::now();
	if (search_input.Search_Algo == "A*") {
		search_algo::execute_A_star(search_input);
	}

	else if (search_input.Search_Algo == "UCS") {
		search_algo::execute_UCS(search_input);
	}

	else if (search_input.Search_Algo == "BFS") {
		search_algo::execute_BFS(search_input);
	}

	
	end = std::chrono::system_clock::now();
	
	elapsed_seconds = end - start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";



	
	return 0;
}
