#include <process.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include "KeyEvent.h"
#include "ExArray.h"
#include "Frame.h"

using namespace std;
unsigned int __stdcall mythread(void*){
	int i = 0;
	while(1){
		cout << GetCurrentThread() << ": " << i++ << endl;
		Sleep(500);
	}
	return 0;
}

unsigned int __stdcall keyEvent(void*){
	KeyEvent k;
	int i;
	while(1){
		i = k.getKey();
		switch(i){
		case 37 :
			cout << "Left key is pressed" << endl; break;
		case 38 :
			cout << "Up key is pressed " << endl; break;
		case 39 :
			cout << "Right key is pressed " << endl; break;
		case 40 : 
			cout << "Down key is pressed " << endl; break;
		}
	}
	return 0;
}

void dump(list<string> &l){	//	print data of list.
	list<string>::iterator iter = l.begin();

	while(iter != l.end()){
		cout << *iter << endl;
		iter++;
	}
}

int main(){
	/*
	HANDLE handleA, handleB;

	handleA = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
	handleB = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
	
	WaitForSingleObject(handleA, INFINITE);
	WaitForSingleObject(handleB, INFINITE);

	CloseHandle(handleA);
	CloseHandle(handleB);*/
	/*
	ExArray<int> arr1(3);
	ExArray<char> arr2(4);
	ExArray<double> arr3(5);

	arr1.addData(2);
	arr2.addData('A');
	arr3.addData(32.12);

	arr1.printData();
	arr2.printData();
	arr3.printData();

	int num1 = 10, num2 = 40;
	cout << "before : " << num1 << ", " << num2 << endl;
	mySwap(num1, num2);
	cout << "after : " << num1 << ", " << num2 << endl;

	double num1d = 121.11, num2d = 10.5;
	cout << "before : " << num1d << ", " << num2d << endl;
	mySwap(num1d, num2d);
	cout << "after : " << num1d << ", " << num2d << endl;	

	ExArray<int> arr4(5);
	arr4.addData(10);

	mySwap<ExArray<int>>(arr1, arr4);
	arr1.printData();
	arr4.printData();
	
	return 0;*/
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