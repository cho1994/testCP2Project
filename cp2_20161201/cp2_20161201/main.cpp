#pragma once;
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>

using namespace std;

void dump(list<string> &l){	//	print data of list.
	list<string>::iterator iter = l.begin();

	while(iter != l.end()){
		cout << *iter << endl;
		iter++;
	}
}

int main(void){
	//	vector
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.insert(v.begin(), 40);
	v.insert(v.end(), 50);

	for(int i = 0; i < v.size(); i++){
		cout << v[i] << endl;
	}

	cout << "access index at 1 : " << v.at(1) << endl;

	v.erase(v.begin());
	v.erase(v.end() - 1);

	vector<int>::iterator iter = v.begin();

	cout << "access index at 1 with iterator : " << iter[1] << endl;
	
	while(iter != v.end()){
		cout << *iter << endl;
		iter++;
	}
	cout << endl;
	//	list
	list<string> names;
	names.insert(names.begin(), "Konkuk");
	names.insert(names.end(), "University");
	names.insert(names.end(), "SCLAB");
	names.insert(names.end(), "CSY");
	dump(names);
	cout << "===" << endl;
	names.reverse();
	dump(names);
	cout << endl;
	//	map
	map<string, int> m;
	m["Seoul"] = 100;
	m["Daegu"] = 120;
	m["Busan"] = 200;
	
	cout << "Train to Seoul = " << m["Seoul"] << "$"  << endl;
	cout << "Train to Daegu = " << m["Daegu"] << "$" << endl;
	cout << "Train to Busan = " << m["Busan"] << "$" << endl;
	return 0;

}