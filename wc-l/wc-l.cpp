#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip> 
#include <windows.h>
#include <fstream>

using namespace std;

int main(int argc, char** argv ) {
    long long t1, t2, freq;
	string str;
	long long q =0;
	//if (argc == 1) 
    //{
    //    cerr << "Error: need text file\n";
    //    return 1;
    //}
	
	cout << "Opening file a.txt\n"; // << argv[1] << "\n";
	
	char * s = new char [3000];

	FILE* fr;
	fr = fopen ("a.txt", "rb");
	//fgets(s, 512, fr);

	//feof(fr);

	//fclose(fr);

	//ifstream f("a.txt");
	
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);// запрашиваем число тиков в 1 сек

	
	QueryPerformanceCounter((LARGE_INTEGER *)&t1);// смотрим время после окончания цикла
	while (!feof(fr)){
		fgets(s, 3000, fr);
		q++;
	}
	
	//while (!f.eof()){
	//getline(f, str);
	//q++;
	//}
	QueryPerformanceCounter((LARGE_INTEGER *)&t2);// смотрим время после окончания цикла
	fclose(fr);
	cout << q <<"\nTime spent:" << (t2-t1)/(1.*freq) << endl;
	
	system("pause");
	return 0;
}