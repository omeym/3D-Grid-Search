///****************************AUTHOR**************************///
//Student Name: Omey Mohan Manyar
//USC Email ID: manyar@usc.edu
///***********************************************************//

#include "file_rw_utilities.hpp"


void file_rw::split_line(std::stringstream& input_stream, std::vector<std::string>& output_word_vec, const char delimeter) {

	
	std::string current_word;
	output_word_vec.clear();
	while (std::getline(input_stream, current_word, delimeter)) {
		output_word_vec.emplace_back(current_word);

	}

	return;

}





void file_rw::read_txt(input_container& input_vals, const std::string& filename) {
	
	std::ifstream read_file_handle(filename.c_str());
	std::string filedata_buffer;
	
	//std::string content((std::istreambuf_iterator<char>(read_file_handle)),
		//(std::istreambuf_iterator<char>()));

	//std::cout << content << std::endl;
	
	std::string input_line;
	const char delimeter = ' ';	//Space is used as a delimeter in txt file
	
	int number_of_lines = 0;
	
	grid_location current_grid_location;		//The current grid location for the map
	int action_code = 0;						//The corresponding code for the actions available at grid location
	
	//std::stringstream file_data(content);
	//read_file_handle.close();

	std::vector<std::string> current_line;
	std::vector<int> current_line_int;
	int x, y, z;



	//while (!file_data.eof())
	//{
	//	std::getline(file_data, input_line);
	//	std::stringstream current_line_stream(input_line);
	//	//split_line(current_line_stream, current_line);
	//	current_grid_location.action_code.clear();

	//	current_line_int.clear();
	//	std:copy((std::istream_iterator<int>(current_line_stream)),
	//		std::istream_iterator<int>(), std::back_inserter(current_line_int));

	//	////Appending each and every line
	//	if (number_of_lines == 0) {
	//		std::getline(file_data, input_line);
	//		input_vals.Search_Algo = input_line;
	//	}
	//	//Appending the dimentsion of the maze
	//	else if (number_of_lines == 1) {
	//		//split_line(single_line_vals, current_line);
	//		input_vals.size_of_maze.x = current_line_int[0];
	//		input_vals.size_of_maze.y = current_line_int[1];
	//		input_vals.size_of_maze.z = current_line_int[2];

	//	}

	//	//Appending the entry position
	//	else if (number_of_lines == 2) {
	//		//split_line(single_line_vals, current_line);
	//		input_vals.entry_position.x = current_line_int[0];
	//		input_vals.entry_position.y = current_line_int[1];
	//		input_vals.entry_position.z = current_line_int[2];

	//	}

	//	//Appending the exit position
	//	else if (number_of_lines == 3) {
	//		//split_line(single_line_vals, current_line);
	//		input_vals.exit_position.x = current_line_int[0];
	//		input_vals.exit_position.y = current_line_int[1];
	//		input_vals.exit_position.z = current_line_int[2];
	//	}

	//	else if (number_of_lines == 4)
	//	{
	//		input_vals.no_of_grids = current_line_int[0];
	//	}

	//	else {
	//		current_grid_location.grid_point.x = current_line_int[0];
	//		current_grid_location.grid_point.y = current_line_int[1];
	//		current_grid_location.grid_point.z = current_line_int[2];

	//	
	//		for (size_t i = 3; i < current_line_int.size(); ++i) {
	//			current_grid_location.action_code.emplace_back(current_line_int[i]);
	//			input_vals.grid_map[current_grid_location.grid_point].emplace_back(current_line_int[i]);

	//		}
	//		input_vals.grid_map[current_grid_location.grid_point].emplace_back(number_of_lines - 5);
	//		input_vals.maze_map.emplace_back(current_grid_location);
	//		
	//	}

	//	//Incrementing the line number being read

	//	number_of_lines++;
	//}






	//while (!file_data.eof())
	//{
	//		current_line.clear();
	//		std::getline(file_data, input_line);
	//		std::stringstream current_line_stream(input_line);
	//		split_line(current_line_stream, current_line);
	//		current_grid_location.action_code.clear();
	//		////Appending each and every line
	//		if (number_of_lines == 0) input_vals.Search_Algo = current_line[0];

	//		//Appending the dimentsion of the maze
	//		else if (number_of_lines == 1) {
	//			//split_line(single_line_vals, current_line);
	//			x = std::stoi(current_line[0]);
	//			y = std::stoi(current_line[1]);
	//			z = std::stoi(current_line[2]);
	//			input_vals.size_of_maze.x = x;
	//			input_vals.size_of_maze.y = y;
	//			input_vals.size_of_maze.z = z;

	//	}

	//	//Appending the entry position
	//	else if (number_of_lines == 2) {
	//		//split_line(single_line_vals, current_line);
	//		x = std::stoi(current_line[0]);
	//		y = std::stoi(current_line[1]);
	//		z = std::stoi(current_line[2]);
	//		input_vals.entry_position.x = x;
	//		input_vals.entry_position.y = y;
	//		input_vals.entry_position.z = z;

	//	}

	//	//Appending the exit position
	//	else if (number_of_lines == 3) {
	//		//split_line(single_line_vals, current_line);
	//		x = std::stoi(current_line[0]);
	//		y = std::stoi(current_line[1]);
	//		z = std::stoi(current_line[2]);
	//		input_vals.exit_position.x = x;
	//		input_vals.exit_position.y = y;
	//		input_vals.exit_position.z = z;
	//	}

	//	else if (number_of_lines == 4)
	//	{
	//		input_vals.no_of_grids = std::stoi(current_line[0]);
	//	}

	//	else {
	//		//split_line(single_line_vals, current_line);
	//		x = std::stoi(current_line[0]);
	//		y = std::stoi(current_line[1]);
	//		z = std::stoi(current_line[2]);


	//		current_grid_location.grid_point.x = x;
	//		current_grid_location.grid_point.y = y;
	//		current_grid_location.grid_point.z = z;

	//		std::vector<int> loc_action_code;
	//		for (size_t i = 3; i < current_line.size(); ++i) {
	//			current_grid_location.action_code.emplace_back(std::stoi(current_line[i]));
	//			loc_action_code.emplace_back(std::stoi(current_line[i]));
	//		}
	//		loc_action_code.emplace_back(number_of_lines - 5);
	//		input_vals.maze_map.emplace_back(current_grid_location);
	//		Vec3i grid_point(x, y, z);
	//		input_vals.grid_map[grid_point] = loc_action_code;

	//	}

	//	//Incrementing the line number being read
	//	
	//	number_of_lines++;
	//}
	//	
	






	if (read_file_handle.is_open()) {
		while (std::getline(read_file_handle, input_line)) {
			
			current_line.clear();
			current_grid_location.action_code.clear();

			//Getting the line as a SS to split into respective elements
			std::stringstream single_line_vals(input_line);

			//Appending each and every line
			if (number_of_lines == 0) input_vals.Search_Algo = input_line;
			
			//Appending the dimentsion of the maze
			else if (number_of_lines == 1) {
				split_line(single_line_vals, current_line);
				x = std::stoi(current_line[0]);
				y = std::stoi(current_line[1]);
				z = std::stoi(current_line[2]);
				input_vals.size_of_maze.x  = x;
				input_vals.size_of_maze.y = y;
				input_vals.size_of_maze.z = z;
				
			}

			//Appending the entry position
			else if (number_of_lines == 2) {
				split_line(single_line_vals, current_line);
				x = std::stoi(current_line[0]);
				y = std::stoi(current_line[1]);
				z = std::stoi(current_line[2]);
				input_vals.entry_position.x = x;
				input_vals.entry_position.y = y;
				input_vals.entry_position.z =  z;
				
			}

			//Appending the exit position
			else if (number_of_lines == 3) {
				split_line(single_line_vals, current_line);
				x = std::stoi(current_line[0]);
				y = std::stoi(current_line[1]);
				z = std::stoi(current_line[2]);
				input_vals.exit_position.x = x;
				input_vals.exit_position.y = y;
				input_vals.exit_position.z = z;
			}

			else if(number_of_lines == 4)
			{
				input_vals.no_of_grids = std::stoi(input_line);
			}

			else {
				split_line(single_line_vals, current_line);
				x = std::stoi(current_line[0]);
				y = std::stoi(current_line[1]);
				z = std::stoi(current_line[2]);

				current_grid_location.grid_point.x = x;
				current_grid_location.grid_point.y = y;
				current_grid_location.grid_point.z = z;
				
				std::vector<int> loc_action_code;
				for (size_t i = 3; i < current_line.size(); ++i) {
					current_grid_location.action_code.emplace_back(std::stoi(current_line[i]));
					loc_action_code.emplace_back(std::stoi(current_line[i]));
				}
				loc_action_code.emplace_back(number_of_lines - 5);
				input_vals.maze_map.emplace_back(current_grid_location);
				Vec3i grid_point(x,y,z);
				input_vals.grid_map[grid_point] = loc_action_code;

			}

			//Incrementing the line number being read
			number_of_lines++;

		}
	}

	else {
		std::cout << "Unable to open the file: " << filename << std::endl;
	}


	std::cout << "Completed reading from input file" << std::endl;
	read_file_handle.close();


}


void file_rw::write_txt(output_container& output_vals ,const std::string& filename) {

	std::ofstream output_file_handle;
	output_file_handle.open(filename, std::ios::trunc);

	grid_location current_grid_location;	//Temp Variable to store the current locations
	
	if (output_file_handle.is_open()) {

		if (output_vals.search_status.compare("FAIL") == 0) {
			output_file_handle << output_vals.search_status;
			std::cout << "The Search failed for the given inputs" << std::endl;
			output_file_handle.close();
			return;
		}
		//Outputting total cost of the search
		output_file_handle << output_vals.total_cost << "\n";

		//Outputting the total number of steps including the start position and end positions
		output_file_handle << output_vals.number_of_steps << std::endl;

		//Outputting the grid locations visited from start to end
		for (size_t i = 0; i < output_vals.solution_path.size(); ++i) {
			if (i != output_vals.solution_path.size() - 1) {
				output_file_handle << output_vals.solution_path[i].grid_position.grid_point[0]<< " " << output_vals.solution_path[i].grid_position.grid_point[1] << " " << output_vals.solution_path[i].grid_position.grid_point[2] << " " << output_vals.solution_path[i].node_cost << "\n";
			}
			else {
				output_file_handle << output_vals.solution_path[i].grid_position.grid_point[0] << " " << output_vals.solution_path[i].grid_position.grid_point[1] << " " << output_vals.solution_path[i].grid_position.grid_point[2] << " " << output_vals.solution_path[i].node_cost;
			}
			
		}

		std::cout << "The Search Results are stored in filename: " << filename << " in the current directory" << std::endl;
		output_file_handle.close();

		
	}

	else {
		std::cout<<"There is some error with the output filename provided, please check: " << filename << std::endl;
	}

	return;

}

void file_rw::delete_txt_file(const std::string& filename) {

	if (std::remove(filename.c_str()) == 0) {
		std::cout << "Successfully deleted the file with name: " << filename << std::endl;
	}

	else{
		std::cout << "No Such File or Directory Exists to delete, Please Check Filename: " << filename << std::endl;
	}
}



