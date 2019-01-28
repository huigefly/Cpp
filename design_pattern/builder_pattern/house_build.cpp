#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

class CHouse
{
public:
  virtual string& door() = 0;
  virtual string& window() = 0;
  virtual string& wall() = 0;
  
protected:
  string m_sDoor;
  string m_sWindow;
  string m_sWall;
};

class CStoneHouse : public CHouse
{
public:
  virtual string& door() {
    return this->m_sDoor;
  }
  virtual string& window() {
    return this->m_sWindow;
  }
  virtual string& wall() {
    return this->m_sWall;
  }

  CStoneHouse() {
    this->m_sDoor = "stone door";
    this->m_sWindow = "stone window";
    this->m_sWall = "stone wall";
  }
  
private:

};

class CWoodHouse : public CHouse
{
public:
  virtual string& door() {
    return this->m_sDoor;
  }
  virtual string& window() {
    return this->m_sWindow;
  }
  virtual string& wall() {
    return this->m_sWall;
  }

  CWoodHouse() {
    this->m_sDoor = "wood door";
    this->m_sWindow = "wood window";
    this->m_sWall = "wood wall";
  }
  
private:

};

class CHouseBuilder 
{
public:
  virtual int buildDoor() = 0;
  virtual int buildWindow() = 0;
  virtual int buildWall() = 0;
  
  CHouse *getHouse() {
    return this->m_pHouse;
  }
  
protected:
  CHouse *m_pHouse;
};

class CStoneHouseBuilder : public CHouseBuilder
{
public:
  virtual int buildDoor() {
    this->m_pHouse->door ();
    return 0;
  }
  virtual int buildWindow() {
    this->m_pHouse->window ();
    return 0;
  }
  virtual int buildWall() {
    this->m_pHouse->wall ();
    return 0;
  }

  CStoneHouseBuilder() {
    this->m_pHouse = new CStoneHouse();
  }
};

class CWoodHouseBuilder : public CHouseBuilder
{
public:
  virtual int buildDoor() {
    this->m_pHouse->door ();
    return 0;
  }
  virtual int buildWindow() {
    this->m_pHouse->window ();
    return 0;
  }
  virtual int buildWall() {
    this->m_pHouse->wall ();
    return 0;
  }

  CWoodHouseBuilder() {
    this->m_pHouse = new CWoodHouse();
  }
};

class CDirector
{
public:
  int create() {
    this->m_pDirector->buildDoor ();
    this->m_pDirector->buildWindow ();
    this->m_pDirector->buildWall ();
    return 0;
  }
  
  CDirector(CHouseBuilder *pHouseBuilder) {
    this->m_pDirector = pHouseBuilder;
  }
  
private:
  CHouseBuilder *m_pDirector;
};

int main()
{
  CHouseBuilder *pHouseBuilder = new CWoodHouseBuilder();
  CDirector director (pHouseBuilder);
  director.create ();
  CHouse *pHouse = pHouseBuilder->getHouse ();
  
  printf ("%s\n", pHouse->door ().c_str ());
  printf ("%s\n", pHouse->window ().c_str ());
  printf ("%s\n", pHouse->wall ().c_str ());
  
  delete pHouseBuilder;

  return 0;
}
