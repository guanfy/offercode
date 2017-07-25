/*********************************
# File Name: 002_Singleton2.cpp
*********************************/

#include<iostream>
using namespace std;

//借鉴了Java的单例模式的“双检锁”机制，避免多次加锁和解锁操作。
//缺点：如果进行大数据的操作，加锁可能成为性能的一个瓶颈。
class Singleton2{
private:
    Singleton2()
    {
    }
    static Singleton2 * m_pInstance;
public:
    static Singleton2 *getInstance()
    {
	//加锁是一个耗时的操作，加锁前后两次判断实例是否存在，避免加锁过程。
	if (m_pInstance == NULL)
	{   
	    lock();//C++中没有直接的lock操作，可使用其他库，如Boost
	    if(m_pInstance == NULL)
	    {
		 m_pInstance = new Singleton2();

	    }
	    unlock();
	}	    
	return m_pInstance;
    }
    static void DestroyInstance()
    {
	if (m_pInstance != NULL){
	   delete m_pInstance;
	    m_pInstance = NULL;
	}
    }    
};

Singleton2 *Singleton2::m_pInstance = NULL;

int main()
{
    Singleton2 *singleton2Obj = Singleton2::getInstance();
    cout<<singleton2Obj<<endl;
    
    Singleton2 *singleton2Obj2 = Singleton2::getInstance();
    cout<<singleton2Obj2<<endl;

    Singleton2::DestroyInstance();
    return 0;
}

