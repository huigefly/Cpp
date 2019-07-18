#include <stdio.h>
#include <stdlib.h>

class CA
{
public:
  int show() {
    printf ("show A:%d, buf:%s,p:%p\n", this->m_nValue, this->m_pszBuf, this->m_pszBuf);
  }
  
  
  CA(){
  }
  CA(int nValue){
    this->m_nValue = nValue;
    this->m_pszBuf = (char *)malloc (1024);
    sprintf (this->m_pszBuf, "helloworld!");
  }
  CA(const CA& a) {
    this->m_nValue = a.m_nValue;
    this->m_pszBuf = (char *)malloc (1024);
    sprintf (this->m_pszBuf, "%s", a.m_pszBuf);
  }
  virtual ~CA(){
    free (this->m_pszBuf);
    this->m_pszBuf = NULL;
  }

private:
  int m_nValue;
  char *m_pszBuf;

};

int main()
{
  CA *a = new CA(991);
  a->show ();
  
  CA *a1 = new CA(*a);
  #if 1
  // if free resource, pointer null
  delete a ;
  a = NULL;
  #endif //0
  
  a1->show ();
  
  return 0;
}