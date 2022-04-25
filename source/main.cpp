#include "utils.hpp" 
#include <string>
#include <vector>
#include <iostream>
#include "quanlysinhvien.hpp"
#include "view.hpp"
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int main(int argc, char** argv){
	string current_path = fs::current_path();
	cout << "current_path: " << current_path << endl;
	string file_name = fs::path(current_path) / "data.txt";
	cout << "file_name : " << file_name << endl;
	View myview(file_name);
	myview.loop();


	return EXIT_SUCCESS;
}
