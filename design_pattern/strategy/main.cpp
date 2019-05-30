#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

// strategy
class ITranslate
{
public:
    virtual string exec(const string& sInput) = 0;
    virtual ~ITranslate(){}
};

class Chinese : public ITranslate
{
public:
    string exec(const string& sInput){
        // detail
        return "";
    }
};

class English : public ITranslate
{
public:
    string exec(const string& sInput){
        // detail
        return "helloworld";
    }
};


// factory
typedef enum
{
    INVALID = -1,
    CHINESE,
    ENGLISH,
    JAPAN,
    // .....
    NONE
}ENUM_LANGUAGE_T;

class CTranslateFactory
{
public:
    ITranslate* get(ENUM_LANGUAGE_T type){
        switch(type){
            case CHINESE:{
                return new Chinese();
            }
            case ENGLISH:{
                return new English();
            }
            case JAPAN:{
            }
            default:{
                break;    
            }
        }
        return NULL;
    }
    
    CTranslateFactory(){
    }
};

int main()
{
    ITranslate *pTranslate = NULL;
    CTranslateFactory factory;
    pTranslate = factory.get(ENGLISH);
    if (pTranslate) {
        string sInfo = pTranslate->exec("ÄãºÃ");
        if (sInfo.size () > 0) {
            printf ("info:%s\n", sInfo.c_str ());
        }
    }

    return 0;
}