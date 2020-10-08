///****************************AUTHOR**************************///
//Student Name: Omey Mohan Manyar
//USC Email ID: manyar@usc.edu
///***********************************************************//

#ifndef VEC3i_HPP
#define VEC3i_HPP
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <stdint.h>

//This is a general purpose class to be used to define any 3D point, direction vector, etc
class Vec3i {
public:


	Vec3i(long long int x, long long int y, long long int z) : x(x), y(y), z(z) {};

	Vec3i() {
		this->x = 0;
		this->y = 0;
		this->z = 0;

	}
	//operator overloading for []
	int operator[](const int& i) {
		if (i == 0) {
			return x;
		}
		else if (i == 1) {
			return y;
		}
		else if (i == 2) {
			return z;
		}
		else {
			std::cout << "Please enter a number between 0 and 2 to access elements" << std::endl;
			
		}

		return -1;
	}

	//Cannot use this since hash will be overloading this operator
	//void operator()(const int x, const int y, const int z) {
	//	this->x = x;
	//	this->y = y;
	//	this->z = z;
	//}

	//Operator Overloading for == 
	bool operator == (const Vec3i input_obj) const{
		if ((input_obj.x == x) && (input_obj.y == y) && (input_obj.z == z)) {
			return true;
		}

		else {
			return false;
		}
	}

	//Operator Overloading for =
	void operator = (Vec3i input_obj) {
		this->x = input_obj.x;
		this->y = input_obj.y;
		this->z = input_obj.z;
	}

	void* operator new(size_t size) {
		void* p = ::new::Vec3i();
		return p;
	}


	friend Vec3i operator +(Vec3i input_obj);

	friend Vec3i operator -(Vec3i input_obj);

	friend Vec3i operator *(Vec3i input_obj);

	//Cout operator overloading
	friend std::ostream& operator<<(std::ostream& input_stream, Vec3i& vector);

	int abs() {
		int distance = sqrt(pow((this->x), 2) + pow((this->x), 2) + pow((this->x), 2));
		return distance;
	}
	
	


	long long int x;
	long long int y;
	int z;

};



inline Vec3i operator +(Vec3i input_obj1, Vec3i input_obj2){
	Vec3i output_obj;
	int x = input_obj1[0] + input_obj2[0];
	int y = input_obj1[1] + input_obj2[1];
	int z = input_obj1[2] + input_obj2[2];
	output_obj.x = x;
	output_obj.y = y;
	output_obj.z = z;
	return output_obj;
}

inline Vec3i operator-(Vec3i input_obj1, Vec3i input_obj2) {
	
		Vec3i output_obj;
		int x = input_obj1[0] - input_obj2[0];
		int y = input_obj1[1] - input_obj2[1];
		int z = input_obj1[2] - input_obj2[2];
		output_obj.x = x;
		output_obj.y = y;
		output_obj.z = z;
		return output_obj;
}

inline Vec3i operator*(Vec3i input_obj1, Vec3i input_obj2) {
	Vec3i output_obj;
	int x = input_obj1[0] * input_obj2[0];
	int y = input_obj1[1] * input_obj2[1];
	int z = input_obj1[2] * input_obj2[2];
	output_obj.x = x;
	output_obj.y = y;
	output_obj.z = z;
	return output_obj;

}



inline std::ostream& operator <<(std::ostream& input_stream, Vec3i& vector) {

	input_stream << "X = " << vector[0] << " Y = " << vector[1] << " Z = " << vector[2] << "\n";
	return input_stream;

}


//Hash Function for the class Vec3i
namespace std {
	template<>
	struct hash<Vec3i> {

		std::size_t operator()(const Vec3i& input_obj)const {

			return (((std::hash<int>()(input_obj.x) ^ (std::hash<int>()(input_obj.y) << 1)) >> 1) ^ (std::hash<int>()(input_obj.z) << 1));
		}


	};

}







#endif // !VEC3i_HPP

