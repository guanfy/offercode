/*********************************
# File Name: 002_Singleton3.cpp
*********************************/

#include<iostream>
using namespace std;

//静态初始化在程序进入主函数之前，由主线程以单线程方式完成初始化，所以静态初始
//化实例保证了线程安全性；
//避免加锁解锁造成的资源浪费
//但仍需进行实例的销毁

class Singleton3{
public:
    static Singleton3 * GetInstance()
    {
	return const_cast<Singleton3 *>(m_pInstance);
    }

    static void DestoryInstance()
    {
	if (m_pInstance != NULL)
	{
	    delete m_pInstance;
	    m_pInstance = NULL;
	}
    }

private:
    Singleton3()
    {
    }
    static const Singleton3 *m_pInstance;
};

//const只能定义一次，不能再次修改；static保持类内只有一个实例
const Singleton3 *Singleton3::m_pInstance = new Singleton3();

int main()
{
    Singleton3 *singletonObj = Singleton3::GetInstance();
    cout<<singletonObj<<endl;

    Singleton3::DestoryInstance();
}






