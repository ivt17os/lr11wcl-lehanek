#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip> 
#include <windows.h>
#include <fstream>

using namespace std;
#define N 4096

int main(int argc, char** argv ) {
    long long t1, t2, freq;
	string str;
	long long q =0;
	DWORD nRead;
	BOOL bResult;

	cout << "Opening file a.txt\n"; // << argv[1] << "\n";
	
	char * s = new char [N];
	//FILE* fr;
	//fr = fopen("a.txt", "rd");

	HANDLE f = CreateFile (L"a.txt", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	//fgets(s, 512, fr);

	//feof(fr);

	//fclose(fr);

	//ifstream f("a.txt");
	
    QueryPerformanceFrequency((LARGE_INTEGER *)&freq);// запрашиваем число тиков в 1 сек

	
	QueryPerformanceCounter((LARGE_INTEGER *)&t1);// смотрим время после окончания цикла
	
	do {
		bResult = ReadFile(f, s, N, &nRead, NULL);
		for (DWORD i = 0; i<nRead ;i++)
			if (s[i]=='\n') q++;
	} while (!(bResult&&nRead==0));
	
	
	/*while (!feof(fr)){
		ReadFile(f, s, N, &nRead, NULL);
		fgets(s, N, fr);
		q++;
	}*/
	
	//while (!f.eof()){
	//getline(f, str);
	//q++;
	//}
	QueryPerformanceCounter((LARGE_INTEGER *)&t2);// смотрим время после окончания цикла
	CloseHandle(f);
	cout << q <<"\nTime spent:" << fixed << setprecision(3) <<(t2-t1)/(1.*freq) << endl;
	
	system("pause");
	return 0;
}