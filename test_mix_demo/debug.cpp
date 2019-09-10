#include <cstdio>
#include <iostream>
using namespace std;

#define DEBUG(x) cout<<#x<<"="<<x<<endl 
#define TRACE(x) cout<<#x<<endl;x
#define FILED(a) char *a##_string;int a##__size
class Record{
	FILED(ONE);
	FILED(TWO);
	FILED(THREE);
};
int main(){

	int a=10;
	DEBUG (a);

	//for (int i=1; i<100; i++)
		TRACE(a);
	return 0;
}
