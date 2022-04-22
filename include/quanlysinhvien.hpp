#ifndef __QUANLYSINHVIEN__H__
#define __QUANLYSINHVIEN__H__
#include<string>
#include<list>
using namespace std;
struct sinhvien{
	string name;
	int age;
	float score;
};

class QuanLySinhVien{
	private:
		list<sinhvien> data;
	public:
		QuanLySinhVien(string file_name);
		~QuanLySinhVien();
		bool them(sinhvien p);
		bool xoa(int stt);
		bool sua(int stt);
		void saoluu();
		void timkiem(string search);
		void sapxep();
};
#endif
