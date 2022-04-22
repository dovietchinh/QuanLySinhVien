#include "utils.hpp"

vector<string> split(string x,string sample=" "){
	vector<string> result;
	size_t npos = x.find(sample);
	while(npos!=string::npos){
		result.push_back(x.substr(0,npos));
		x = x.substr(npos+sample.length());
		npos = x.find(sample);
	}
	result.push_back(x.substr(0,npos));
	return result;
}

string replace(string x,string temp1, string temp2){
	size_t npos = x.find(temp1);
	while(npos!=string::npos){
		x.replace(npos,temp1.length(),temp2);
		npos = x.find(temp1,npos+temp2.length());
	}
	return x;
}

