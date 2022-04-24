#ifndef __VIEW__H__
#define __VIEW__H__
enum STATE{
	INIT,
	THEM,
		THEM_NAME,
		THEM_AGE,
		THEM_SCORE,
	SUA,
		SUA_STT,
		SUA_NAME,
		SUA_AGE,
		SUA_SCORE,
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
		void them();
		void them_name();
		void them_age();
		void them_score();
		void sua();
		void sua_stt();
		void sua_name();
		void sua_age();
		void sua_score();
		void xoa();
		void timkiem();
		void sapxep();
		void thongke();
		void sauluu();
		void display();
};
#endif
