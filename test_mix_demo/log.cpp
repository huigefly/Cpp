#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

class CMylog : public ofstream
{
    const char * szFileName;
public:
    const char * getName() const {return szFileName;}
   // ofstream& operator<<(const char* sInput) {*this<< "__log:" << sInput; return *this; }

    CMylog(){}
    CMylog(const char *pszFileName) : ofstream (pszFileName), szFileName (pszFileName){}
};

// ofstream& operator<<(ofstream& of, const char* sInput) const 
// {
//     of << "__log:" << sInput << endl;
//     return of;
// }

int main()
{
    CMylog mylog ("log.out");
    mylog << "helloworld" << endl;
    cout << mylog.getName() << endl;

    return 0;
}