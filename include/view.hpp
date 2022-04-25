#ifndef __VIEW__H__
#define __VIEW__H__
enum STATE{
	INIT='0',
	IN,
	THEM,
	SUA,
	XOA,
	TIMKIEM,
	SAPXEP,
	THONGKE,
	SAOLUU,
	THOAT,
};
class View{
	private:
		STATE state;
		//:QuanLySinhVien database("/home/dovietchinh/code/QuanLySinhVien/data.txt");
		QuanLySinhVien database;
	public:
		static void display_command();
		static void view_table(list<sinhvien> p);
		void view_table();
		View(string);
		void init();
		void in();
		void them();
		//void them_name();
		//void them_age();
		//void them_score();
		void sua();
		void xoa();
		void timkiem();
		void sapxep();
		void thongke();
		void saoluu();
		void display();
		void loop();
		void thoat();
};
#endif
