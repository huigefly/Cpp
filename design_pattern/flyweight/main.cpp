#include <stdio.h>
#include <map>
#include <string>
using namespace std;

class CUnit
{
public:
  
  int getNumDoor() {return this->m_nNumDoors;}
  int getArea() {return this->m_nArea;};
  int setInner(int nArea, int nNumDoors) { 
    this->m_nArea = nArea; this->m_nNumDoors = nNumDoors; return 0; 
  }
  int setOutside(const string& sDecorate) {
    this->m_sDecorate = sDecorate;
  }
  
private:
  int m_nArea;
  int m_nNumDoors;
  string m_sDecorate;
};

class CUnitFactory
{
public:
  CUnit * getUnit(const string& sType) {
    map<string, CUnit *>::iterator it = this->m_mapUnits.find (sType);
    if (it != this->m_mapUnits.end ()) {
      return it->second;
    } else {
      CUnit *pUnit = new CUnit();
      if (sType == "big") {
        printf ("set innert big!\n");
        pUnit->setInner (100, 2);
      } else if (sType == "small") {
        printf ("set innert small!\n");
        pUnit->setInner (70, 1);
      }
      this->m_mapUnits[sType] = pUnit;
      
      return pUnit;
    }
  }
  
private:
  map<string, CUnit *> m_mapUnits;
};

int main()
{
  CUnitFactory unitFactory;
  string sAct = "";
  for (int i=0; i<100; i++) {
    unitFactory.getUnit ("big");
    unitFactory.getUnit ("small");
  }

  return 0;
}
