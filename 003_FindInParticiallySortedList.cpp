/*********************************
# File Name: 003_FindInParticiallySortedList.cpp
*********************************/

#include<iostream>
using namespace std;

//一位数组和二维数组的下标对应关系
//a[i] = r * col + c - 1 

bool Find(int *matrix, int row, int col, int target)
{
    bool flag = false;
    if (matrix != NULL && row > 0 && col > 0)
    {
	for (int r = 0,c = col - 1;r < row,c >= 0;)
	{
	    if (matrix[r * col + c -1] == target)
	    {
		flag = true;
		break;
	    }
	    else if (matrix[r * col + c - 1] > target)
	    {
		c--;
	    }else
	    {
		r++;
	    }
	}
    }
    return flag;
}

int main()
{
    int a[12]={1,2,3,4,6,9,5,8,12,7,9,18};
    cout<<Find(a,3,4,1)<<endl;
    cout<<Find(a,3,4,18)<<endl;
    cout<<Find(a,3,4,9)<<endl;
    cout<<Find(a,3,4,-1)<<endl;
    cout<<Find(a,3,4,11)<<endl;
    cout<<Find(a,3,4,21)<<endl;
}
