//#include "view.hpp"
#include <iostream>
#include "../include/quanlysinhvien.hpp"
#include <list>
#include "view.hpp"

void View::view_table(list<sinhvien> p){
	int max_length=0;
	for(auto x:p){
		if(max_length < x.name.length()) max_length = x.name.length();
	};
	cout << "  |";
	for(int i=0;i<max_length+4+6+8;i++){
		cout << "-";
	}
	cout << endl;

	cout << "  |";
	for(int i=0;i<(max_length/2);i++){
		cout << " ";
	};
	cout << "name";
	
	for(int i=0;i<max_length/2+1;i++){
		cout << " ";
	}
	cout << "|" << " age "<< "|" << " score " << "|" <<endl;

	for(auto x:p){
		cout << "  |";
		for(int i=0;i<max_length+4+6+8;i++){
			cout << "-";
		}
		cout << endl;
		cout << "  |";
		cout << x.name;
		for(int i=0;i<max_length+4 -x.name.length();i++){
			cout << " ";
		}
//		cout << "|" << x.age << "|" << x.score << "|" << endl;
		printf("| %02d  | %2.2f |\n",x.age,x.score);
	};
	cout << "  |";
	for(int i=0;i<max_length+4+6+8;i++){
		cout << "-";
	}
	cout << endl;
}
void View::view_table(){
	list<sinhvien> p = this->database.get_list();
	this->view_table(p);
}
void View::display_command(){
	cout << "   Danh sach thao tac :" << endl;
	cout << " 1,In danh sach sinhvien"<< endl;
	cout << " 2,Them"<< endl;
	cout << " 3,Sua"<< endl;
	cout << " 4,Xoa"<< endl;
	cout << " 5,Tim kiem"<< endl;
	cout << " 6,Sap xep"<< endl;
	cout << " 7,Thong ke"<< endl;
	cout << " 8,Sao luu"<< endl;
	cout << " 9,Thoat"<< endl;
}

View::View(string file_name){
	this->database.set_file(file_name);
	this->database.read_data();
	this->state = INIT;
};

void View::init(){
	View::display_command();
	View::view_table(this->database.get_list());
}
void View::them(){
	View::display_command();
View::view_table(this->database.get_list());
	cout << "them sinh vien .... " <<endl;
	cout << "name : ";
	string name;
	cin >> name;
	cout << endl <<"age: ";
	int age;
	cin >> age;
	cout << endl << "score: ";
	float score;
	cin >> score;
	sinhvien temp(name,age,score);
	this->database.them(temp);
}











