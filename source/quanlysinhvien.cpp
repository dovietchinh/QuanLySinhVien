#include "quanlysinhvien.hpp"
#include <cassert>
#include "utils.hpp"
#include <fstream>
QuanLySinhVien::QuanLySinhVien(string file_name){
	ifstream f(file_name);
	assert(f.is_open());
	string line;
	while(getline(f,lines)){
		vector<string> temp = split(lines);
		assert(temp.size()==3);
		string name = temp[0];
		int age = std::stoi(temp[1]);
		float score = std::stof(temp[2]);
		sinhvien person = {name,age,score};
	};

};

