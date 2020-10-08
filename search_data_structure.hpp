#ifndef SEARCH_DATA_STRUCTRUES
#define SEARCH_DATA_STRUCTRUES


#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <functional>
#include <climits>

#include "Vec3i.hpp"



//This class stores the current location of the node and available set of actions
class grid_location {
public:

	//Will always take input as x,y and z
	grid_location(Vec3i current_grid_point, std::vector<int> action_code) {
		this->grid_point = current_grid_point;
		this->action_code = action_code;
	}

	//Default Constructor
	grid_location() {
		grid_point.x = 0;
		grid_point.y = 0;
		grid_point.z = 0;
		this->action_code = { 0 };

	}

	Vec3i grid_point;	//Gives the x,y,z for the current grid_location
	
	std::vector<int> action_code;	//The action for the particular location

	//Equality operator overide
	grid_location operator = (grid_location const& input_obj) {
		grid_location current_obj;
		current_obj.grid_point = input_obj.grid_point;
		current_obj.action_code = current_obj.action_code;

		return current_obj;
	}

	bool operator ==(grid_location& input_obj){
		bool equality_flag = false;

		if ((this->grid_point[0] == input_obj.grid_point[0]) && (this->grid_point[1] == input_obj.grid_point[1]) && (this->grid_point[2] == input_obj.grid_point[2]) && (this->action_code.size() == input_obj.action_code.size())) {

			for (size_t i = 0; i < this->action_code.size(); ++i) {
				if (this->action_code[i] != input_obj.action_code[i]) {
					return equality_flag;
				}
			}

			equality_flag = true;

		}

		return equality_flag;

	}




	//Writing overloaded cout operators
	friend std::ostream& operator<<(std::ostream& input_stream, grid_location& obj);

};



//Overloading of the operator cout
inline std::ostream& operator<<(std::ostream& input_stream, grid_location& obj) {

	input_stream << "The co-ordinates of grid location: "<<obj.grid_point<< "\n";
	input_stream << "The available action items = " << "\n";

	for (auto current_action : obj.action_code) {
		input_stream << current_action << " ";
	}
	input_stream << "\n";

	return input_stream;
}



//The data structure that stores all the actions moves
class action_code_table {

public:
	Vec3i decode_action(int i) {
		return action_code_map[i];
	}

	action_code_table() {

		//Constructing the action code map
		action_code_map.insert(std::make_pair(1, Vec3i(1, 0, 0)));		//1
		action_code_map.insert(std::make_pair(2, Vec3i(-1, 0, 0)));		//2
		action_code_map.insert(std::make_pair(3, Vec3i(0, 1, 0)));		//3
		action_code_map.insert(std::make_pair(4, Vec3i(0, -1, 0)));		//4
		action_code_map.insert(std::make_pair(5, Vec3i(0, 0, 1)));		//5
		action_code_map.insert(std::make_pair(6, Vec3i(0, 0, -1)));		//6
		action_code_map.insert(std::make_pair(7, Vec3i(1, 1, 0)));		//7
		action_code_map.insert(std::make_pair(8, Vec3i(1, -1, 0)));		//8
		action_code_map.insert(std::make_pair(9, Vec3i(-1, 1, 0)));		//9
		action_code_map.insert(std::make_pair(10, Vec3i(-1, -1, 0)));	//10	
		action_code_map.insert(std::make_pair(11, Vec3i(1, 0, 1)));		//11
		action_code_map.insert(std::make_pair(12, Vec3i(1, 0, -1)));	//12
		action_code_map.insert(std::make_pair(13, Vec3i(-1, 0, 1)));	//13
		action_code_map.insert(std::make_pair(14, Vec3i(-1, 0, -1)));	//14
		action_code_map.insert(std::make_pair(15, Vec3i(0, 1, 1)));		//15
		action_code_map.insert(std::make_pair(16, Vec3i(0, 1, -1)));	//16
		action_code_map.insert(std::make_pair(17, Vec3i(0, -1, 1)));	//17
		action_code_map.insert(std::make_pair(18, Vec3i(0, -1, -1)));	//18

	}


private:
	std::unordered_map<int, Vec3i> action_code_map;

};



//This is a generic class that will be used for search
class search_node {
public:

	
	search_node() {
		this->node_h = INT_MAX;
		this->node_g = INT_MAX;
		this->node_f = INT_MAX;
		parent_node_id = -1;
		child_node_id = -1;
		grid_position_index = 0;
		this->node_cost = 0;
	}

	void initialize_cost(int h, int g) {
		this->node_h = h;
		this->node_g = g;
		this->node_f = h + g;
		

	}

	//Overall node cost
	int node_h;				//Heuristic cost till goal node
	int node_g;				//Current cost of the node from source

	//Total Cost
	int node_f;

	int node_cost;		//Cost for particular node


	int parent_node_id;			//Parent Node on the graph
	int child_node_id;

	int grid_position_index;
	
	bool on_open_list = false;

	grid_location grid_position;



};

#endif // !SEARCH_DATA_STRUCTRUES
