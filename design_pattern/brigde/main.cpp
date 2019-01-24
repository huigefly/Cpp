#include <stdio.h>
#include <stdlib.h>

class CMsg
{
public:
  virtual int login() = 0;
  virtual int sendPic() = 0;
  virtual int sendMsg() = 0;
};

class CAct
{
public:
  virtual int connet() = 0;
  virtual int drawPic() = 0;
  virtual int writeText() = 0;
  virtual int playSound() = 0;
};

// detail action 
class CActA : public CAct
{
public:
  virtual int connet() {
    printf ("connect CActA\n");
  }
  virtual int drawPic() {
    printf ("drawPic CActA\n");
  }
  virtual int writeText() {
    printf ("writeText CActA\n");
  }
  virtual int playSound() {
    printf ("playSound CActA\n");
  }
};

class CActB : public CAct
{
public:
  virtual int connet() {
    printf ("connect CActB\n");
  }
  virtual int drawPic() {
    printf ("drawPic CActB\n");
  }
  virtual int writeText() {
    printf ("writeText CActB\n");
  }
  virtual int playSound() {
    printf ("playSound CActB\n");
  }
};

//abstart logic
class CMsgLite : public CMsg
{
public:
  virtual int login() {
    this->m_pAct->connet ();
  }
  virtual int sendPic() {
  }
  virtual int sendMsg() {
  }
  
  CMsgLite(CAct *act) {
    this->m_pAct = act;
  }
  
private:
  CAct *m_pAct;
};

class CMsgPerfect : public CMsg
{
public:
  virtual int login() {
    this->m_pAct->playSound ();
    this->m_pAct->connet ();
  }
  virtual int sendPic() {
    this->m_pAct->drawPic ();
  }
  virtual int sendMsg() {
  }
  
  CMsgPerfect(CAct *act) {
    this->m_pAct = act;
  }
  
private:
  CAct *m_pAct;
};

int main()
{
  CAct *a = new CActA ();
  CMsgPerfect *mp = new CMsgPerfect (a);
  mp->login ();
  
  printf ("--------------------------\n");
  CMsgLite *ml = new CMsgLite (a);
  ml->login ();
  
  return 0;
}