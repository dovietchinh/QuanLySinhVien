#ifndef __QUANLYSINHVIEN__H__
#define __QUANLYSINHVIEN__H__
#include<string>
#include<list>
using namespace std;
struct sinhvien{
	string name;
	int age;
	float score;
	sinhvien(string name,int age,float score){
		this->name = name;
		this->age = age;
		this->score = score;
	}
};

class QuanLySinhVien{
	private:
		list<sinhvien> data;
		string file_name;
	public:
		QuanLySinhVien(string file_name);
		QuanLySinhVien();
		~QuanLySinhVien();
		void read_data();
		void set_file(string file_name);
		list<sinhvien> get_list();
		bool them(sinhvien p);
		bool xoa(int stt);
		bool sua(int stt, sinhvien p);
		bool saoluu();
		list<sinhvien> timkiem(string search);
		void sapxep();
		void show();
};
#endif
