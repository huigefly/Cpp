#include <stdio.h>

typedef enum{
  ENUM_TYPE_1,
  ENUM_TYPE_2,
  ENUM_TYPE_3,
  ENUM_TYPE_4,
  ENUM_TYPE_5
}ENUM_TYPE_T;

class Context;

class State
{
public:
     virtual void Handle(Context *pContext) = 0;
};

class Context
{
public:
     Context(State *pState) : m_pState(pState){}
     void Request() {
          if (m_pState) {
               m_pState->Handle(this);
          }
     }
 
     void ChangeState(State *pState) {
          m_pState = pState;
     }
 
private:
     State *m_pState; //这里的State指针是实现特定状态相关的关键
};

class StateA : public State
{
public:
  virtual void Handle(Context *pContext) {
    if (pContext) {
      printf ("handle context stateA\n");
    }
  }
};

class StateB : public State
{
public:
  virtual void Handle(Context *pContext) {
    if (pContext) {
      printf ("handle context stateB\n");
    }
  }
};


int main()
{
// first
#if 0
  ENUM_TYPE_T enumValue = ENUM_TYPE_3;
  if (enumValue == ENUM_TYPE_1) {
    // do lots of something.....
    
  } else if (enumValue == ENUM_TYPE_2) {
    // do lots of something.....

  } else if (enumValue == ENUM_TYPE_3) {
    // do lots of something.....

  } else if (enumValue == ENUM_TYPE_4) {
    // do lots of something.....
    
  } else if (enumValue == ENUM_TYPE_5) {
    // do lots of something.....
    
  }  
#endif // 0
  StateA stateA; 
  Context *pContext = new Context(&stateA);
  pContext->Request ();
  
  StateB stateB;
  pContext->ChangeState (&stateB);
  pContext->Request ();
  
  delete pContext;

  return 0;
}

