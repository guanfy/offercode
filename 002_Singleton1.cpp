#include<iostream>
using namespace std;

//解法一：只适用于单线程

class Singleton1{

    //防止类外调用类的构造函数创造实例，需将构造函数定义为：private
private:
    Singleton1()
    {
    }
    static Singleton1* m_pInstance;
    
    //提供一个全局访问点，static,返回类内部唯一构造的实例
public:
    static Singleton1* getInstance()
    {
	if(m_pInstance == NULL)
	{
	    m_pInstance = new Singleton1();
	}
	return m_pInstance;
    }
   
    static void destoryInstance()
    {
	if (m_pInstance != NULL)
	{
	    delete m_pInstance;
	    m_pInstance = NULL;
	}
    }
};

//Singleton1实例初始化
//    Singleton1* Singleton1::m_pInstance = new Singleton1();
    Singleton1* Singleton1::m_pInstance = NULL;

//单线程获取多次实例
void Test1()
{
    //预期结果：两个实例指针指向的地址相同
    Singleton1* singletonObj = Singleton1::getInstance();
    cout<<singletonObj<<endl;
    
    Singleton1* singletonObj2 = Singleton1::getInstance();
    cout<<singletonObj2<<endl;

    Singleton1::destoryInstance();

}

int main()
{
    Test1();
    return 0;

}






