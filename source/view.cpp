//#include "view.hpp"
#include <iostream>
#include "../include/quanlysinhvien.hpp"
#include <list>
#include "view.hpp"
#include <stdlib.h>
#define DEBUG
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
	#ifdef DEBUG
		cout << "View::init called" << endl;
	#endif
	system("clear");
	View::display_command();
	cout << "Command :" ;
//	View::view_table(this->database.get_list());
	this->state = STATE(getchar());
	cout << "this state is : " << this->state << endl; 
	getchar();
}

void View::in(){
	#ifdef DEBUG
		cout << "View::in called" << endl; 
	#endif
	system("clear");
	View::display_command();
	View::view_table();
	cout << "press any keys...." <<endl;
	//getchar();
	getchar();
	this->state = INIT;
}

void View::them(){
	#ifdef DEBUG
		cout << "View::them called" << endl;
	#endif
	system("clear");
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
	cout << endl << "them thanh cong...." << endl;
	cout << "press any keys...." << endl;
	//system("read")
	fflush(stdin);
	getchar();
	
	this->state = INIT;
}

void View::sua(){
	system("clear");
	View::display_command();
	View::view_table();
	cout << "sua sinh vien stt: ";
	int stt;
	cin >> stt;
	cout << endl << "name : ";
	string name;
	cin >> name;
	cout << endl << "age: ";
	int age;
	cin >> age;
	cout << endl << "score: ";
	float score;
	cin >> score;
	sinhvien temp(name,age,score);
	this->database.sua(stt,temp);
	cout << endl << "sua thanh cong ...." << endl;
	cout << "press any keys...." << endl;
	getchar();
	this->state = INIT;
};

void View::xoa(){
	system("clear");
	View::display_command();
	View::view_table();
	cout << "xoa sinh vien stt: ";
	int stt;
	cin >> stt;
	this->database.xoa(stt);
	cout << endl << "xoa thanh cong ..." << endl;
	cout << "press any keys...." <<endl; 
	getchar();
	this->state = INIT;
};

void View::timkiem(){
	system("clear");
	View::display_command();
	string search;
	cout << "search term : ";
	cin >> search;
	list<sinhvien> x = this->database.timkiem(search);
	View::view_table(x);
	cout << endl << "press any keys...." << endl;
	fflush(stdin);
	getchar();
	getchar();
	this->state = INIT;
}

void View::sapxep(){
	system("clear");
	View::display_command();
	this->database.sapxep();
	cout << "sap xep thanh cong...." << endl;
	cout << "press any keys...." << endl;
	getchar();
	this->state = INIT;
};
void View::thongke(){
	system("clear");
	View::display_command();
	cout << "thong ke thanh cong ...." << endl;
	cout << "press any keys ..." << endl;
	getchar();
	this->state = INIT;
};

void View::saoluu(){
	system("clear");
	View::display_command();
	this->database.saoluu();
	cout << "saoluu thanh cong ..." << endl;
	cout << "press any keys ..." << endl;
	getchar();
	this->state = INIT;
};

void View::thoat(){
	this->database.saoluu();
}


void View::loop(){
	bool exec = true;
	while(exec){
		switch(this->state){
			case INIT:{
				this->init();
				break;
			}
			case IN:{
				this->in();
				break;
			}	
			case THEM:{		  
				this->them();
				break;
			}
			case SUA:{
				this->sua();
				break;
			}
			case XOA:{
				this->xoa();
				break;
			}
			case TIMKIEM:{
				this->timkiem();
				break;
   			}
			case SAPXEP:{
				this->sapxep();
				break;
			}	
			case THONGKE:{
				this->thongke();
				break;
			}
			case SAOLUU:{
				this->saoluu();
				break;
			}
			case THOAT:{
				this->thoat();
				exec = false;
				break;
			}
			default:{
				cout << "this->state: " << (this->state) << endl;
				//getchar();
				this->state = INIT;
				break;
			}
		}
	}
}








