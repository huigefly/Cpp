#include <stdio.h>

class CMemento
{
public:
  int getValue(){
    return this->m_nValue;
  }
  int setValue(int nValue) {
    this->m_nValue = nValue;
    return 0;
  }
  
  CMemento(int nValue) : m_nValue (nValue) {}
  
private:
  int m_nValue;
};

class CProcess
{
public:
  CMemento* createMemento() {
    CMemento *pMemento = new CMemento(this->m_nProcess);
    return pMemento;
  }
  
  int setProcess(int nValue) {
    this->m_nProcess = nValue;
  }
  
  int process () {
    this->m_nProcess += 1;
    return this->m_nProcess;
  }
  
  CProcess():m_nProcess (0) {}
  
private:
  int m_nProcess;
};

int main()
{
  CProcess process;
  process.process ();
  process.process ();
  CMemento *pMemento = process.createMemento ();
  printf ("1 process value:%d\n", process.process ());
  process.process ();
  process.process ();
  
  printf ("2 process value:%d\n", process.process ());
  process.setProcess (pMemento->getValue ());
  printf ("3 process value:%d\n", process.process ());
  
  delete pMemento;

  return 0;
}