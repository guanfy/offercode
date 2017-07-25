#include<iostream>
using namespace std;

class CMyString{
	public:
		CMyString(char *pData = NULL){
			if (pData == NULL){
				m_pData = new  char [1];
				m_pData[0] = '\0';
			}else{
				int length = strlen(pData);
				m_pData = new char[length+1];
				strcpy(m_pData,pData);
			}
		}
		
		~CMyString(void){
			delete []m_pData;
		}

		CMyString(const CMyString &str){
			m_pData = str.m_pData;
		}

		CMyString & operator = (const CMyString & ex)
		{
			if (this == &ex)
				return *this;
			
			delete []m_pData;
			m_pData = NULL;
			
			m_pData = new char [strlen(ex.m_pData)+1];
			strcpy(m_pData,ex.m_pData);

			return *this;
		}
		void Print(){
			cout<<m_pData<<endl;		
		}
private:
	char *m_pData;
};

//普通赋值
void test1(){
	cout<<"test1()begins:"<<endl;
	char *text = "helloworld";
	CMyString str1(text);
	CMyString str2;
	str2 = str1;
	cout<<"The result is "<<text<<endl;
	cout<<"The actual result is ";
	str2.Print();
	cout<<"test1()end"<<endl;
}

//自身赋值
void test2(){
	cout<<"test2()begins:"<<endl;
	char *text = "123456";
	CMyString str1(text);
	str1 = str1;
	
	cout<<"The result is "<<text<<endl;
	cout<<"The actual result is ";
	str1.Print();
	cout<<endl;
}

//连续赋值
void test3(){
	cout<<"test3()begins:"<<endl;
	char *text = "123456";
	CMyString str1(text);
	CMyString str2,str3;
	str2 = str3 =str1;
	
	cout<<"The result is "<<text<<endl;
	cout<<"The actual result is ";
	str1.Print();
	str2.Print();
	str3.Print();
	cout<<endl;

}

int main(){
	test1();
	test2();
	test3();

	return 0;
}