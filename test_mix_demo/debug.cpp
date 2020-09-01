#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

#define DEBUG(x) cout<<#x<<"="<<x<<endl 
#define TRACE(x) cout<<#x<<endl;x
#define FILED(a) char *a##_string;int a##__size
class Record{
	FILED(ONE);
	FILED(TWO);
	FILED(THREE);
};

/*

*/
string get()
{
	string sBuf = "";
	char *pszBuf = new char[64];
	sprintf (pszBuf, "hellworold____nishuosha");
	printf("%s\n", pszBuf);
	sBuf = pszBuf;
	printf("%s\n", sBuf.c_str());
	delete[] pszBuf;
	return sBuf;
}

int main(){

	int a=10;
	DEBUG (a);

	string sBuf = get();
	printf("get buf:%s\n", sBuf.c_str());
	//for (int i=1; i<100; i++)
		TRACE(a);
	return 0;
}
