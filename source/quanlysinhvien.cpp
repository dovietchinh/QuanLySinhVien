#include "quanlysinhvien.hpp"
#include <cassert>
#include "utils.hpp"
#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;
QuanLySinhVien::QuanLySinhVien(string file_name){
	this->file_name = file_name;
};
QuanLySinhVien::QuanLySinhVien(){
	return;
}
void QuanLySinhVien::set_file(string file_name){
	this->file_name = file_name;
}

QuanLySinhVien::~QuanLySinhVien(){
	this->saoluu();
};

list<sinhvien> QuanLySinhVien::get_list(){
	return this->data;
}
void QuanLySinhVien::read_data(){
	ifstream f(this->file_name);
	assert(f.is_open());
	string line;
	while(getline(f,line)){
		vector<string> temp = split(line,",");
		assert(temp.size()==3);
		string name = temp[0];
		int age = std::stoi(temp[1]);
		float score = std::stof(temp[2]);
		sinhvien person = {name,age,score};
		this->data.push_back(person);
	};


}

bool QuanLySinhVien::them(sinhvien p){
	this->data.push_back(p);
	return true;
};

bool QuanLySinhVien::xoa(int stt){
	if(stt>this->data.size()) return false;
	stt--;
	list<sinhvien> ::iterator it = this->data.begin();
	std::advance(it,stt);
	this->data.erase(it);
	return true;
};

bool QuanLySinhVien::sua(int stt, sinhvien p){
	if(stt>this->data.size()) return false;
	if(stt<1) return false;
	stt--;
	list<sinhvien>::iterator it = this->data.begin();
	std::advance(it,stt);
	*it = p;
	return true;
};

bool QuanLySinhVien::saoluu(){
//	this->file_name;
	ofstream f(this->file_name, ofstream::out);
	assert(f.is_open());
	for(auto x: this->data){
		string temp = x.name +"," + std::to_string(x.age) + "," + std::to_string(x.score);
		f << temp << endl;
	}
	return true;
	
};

list<sinhvien> QuanLySinhVien::timkiem(string search){
	list<sinhvien> result;
	for(auto x: this->data){
		if(x.name.find(search)!=string::npos){
			result.push_back(x);
		}
	}
	return result;
};
bool sosanh(sinhvien x,sinhvien y){
	return x.age < y.age;
}
void QuanLySinhVien::sapxep(){
	//std::sort(this->data.begin(),this->data.end(),sosanh);
	this->data.sort([](sinhvien a,sinhvien b){return a.age < b.age;});
};

void QuanLySinhVien::show(){
	cout << "display";
	for(auto x: this->data){
		cout << x.name << " " << x.age << " " << x.score << endl;
	}
}
















