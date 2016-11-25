#include <process.h>
#include <iostream>
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

int main(){
	/*
	HANDLE handleA, handleB;

	handleA = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
	handleB = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
	
	WaitForSingleObject(handleA, INFINITE);
	WaitForSingleObject(handleB, INFINITE);

	CloseHandle(handleA);
	CloseHandle(handleB);*/
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
	
	return 0;
}