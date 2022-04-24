#include "utils.hpp" 
#include <string>
#include <vector>
#include <iostream>
#include "quanlysinhvien.hpp"
#include "view.hpp"
using namespace std;

int main(int argc, char** argv){
	string file_name = "/home/dovietchinh/code/QuanLySinhVien/data.txt";
	View myview(file_name);
	myview.view_table();


	return EXIT_SUCCESS;
}
