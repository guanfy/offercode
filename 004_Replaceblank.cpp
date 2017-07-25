#include<iostream>
using namespace std;

void Replace(char str[],int length)
{
	if (str == NULL && length <= 0)
		return;
	int orglen = 0;
	int blankcount = 0;
	int i = 0;
	while(str[i] != '\0')
	{
		++orglen;
		if (str[i] == ' ')
			blankcount++;
		++i;
	}
	int newlen = orglen + blankcount * 2;
	if (newlen > length)
		return;
	int indexorg = orglen;
	int indexnew = newlen;

	while(indexorg >= 0 && indexnew > indexorg)
	{
		if (str[indexorg] == ' ')
		{
			str[indexnew--] = '%';
			str[indexnew--] = '0';
			str[indexnew--] = '2';
		}
		else
		{
			str[indexnew--] = str[indexorg];
		}
		--indexorg;
	}
}


int main()
{
	char s1[] = "   ";
	cout<<s1<<endl;
	Replace(s1,20);
	cout<<s1<<endl;
	return 0;
}








