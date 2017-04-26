/*
 * change: zhengfuhui
 * add: thread sec
*/

#include <iostream>
#include <pthread.h>
using namespace std;

class Singleton
{
public:
	static Singleton *GetInstance()
	{
		if (m_Instance == NULL )
		{
		//	Lock(); // C++没有直接的Lock操作，请使用其它库的Lock，比如Boost，此处仅为了说明
			pthread_mutex_lock(&mutex);
			if (m_Instance == NULL )
			{
				m_Instance = new Singleton ();
			}
			pthread_mutex_unlock(&mutex);
		//	UnLock(); // C++没有直接的Lock操作，请使用其它库的Lock，比如Boost，此处仅为了说明
		}
		return m_Instance;
	}

	static void DestoryInstance()
	{
		if (m_Instance != NULL )
		{
			delete m_Instance;
			m_Instance = NULL ;
		}
	}

	int GetTest()
	{
		return m_Test;
	}

private:
	Singleton()
	{ 
		pthread_mutex_init (&mutex, NULL);
		m_Test = 1000; 
	}
	static pthread_mutex_t mutex;
	static Singleton *m_Instance;
	
	int m_Test;
};

pthread_mutex_t Singleton::mutex;
Singleton *Singleton ::m_Instance = NULL;

int main(int argc , char *argv [])
{
	Singleton *singletonObj = Singleton ::GetInstance();
	cout<<singletonObj->GetTest()<<endl;
	Singleton ::DestoryInstance();

	return 0;
}