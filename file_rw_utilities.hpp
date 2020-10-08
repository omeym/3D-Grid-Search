///****************************AUTHOR**************************///
//Student Name: Omey Mohan Manyar
//USC Email ID: manyar@usc.edu
///***********************************************************//


#ifndef READ_WRITE_UTILITIES
#define	READ_WRITE_UTILITIES

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

#include "file_container_utils.hpp"

namespace file_rw {

	//This function will read the input file name
	void read_txt(input_container& input_vals, const std::string& filename = "input.txt");

	//This function will output the appropriate solution file
	void write_txt(output_container& output_vals, const std::string& filename = "output.txt");

	//This function will delete any output file in current directory
	void delete_txt_file(const std::string& filename = "output.txt");

	//This function splits the string into a word
	void split_line(std::stringstream& input_stream, std::vector<std::string>& output_word_vec, const char delimeter = ' ');

	
	
}




#endif // !READ_WRITE_UTILITIES
