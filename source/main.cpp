#include "utils.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char** argv){
	string temp=argv[1];
	vector<string> x = split(temp,"123");
	string abc = replace(argv[2],"2","3");
	for(auto i:x) cout << i << " ";
	cout << endl;
	cout <<"abc: "<<abc<<endl;
	return 1;

}
