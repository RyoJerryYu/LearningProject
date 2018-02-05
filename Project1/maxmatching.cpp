#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
	string fstring1, fstring2;
	cout << "input your strings that you want to match." << endl;
	cin >> fstring1 >> fstring2 ;
	cout << "the two strings is :\"" << fstring1 << "\" and \"" << fstring2 << "\"" << endl;
	fstring1.insert(0, "$");
	fstring2.insert(0, "$");
	int lengthres, i, j;
	int length1 = fstring1.length(), length2 = fstring2.length();
	string results;
	cout << "fstring1.length is: " << length1 << " , fstring2.length is: " << length2 << endl;
	vector<vector<string> > map(length1,vector<string>(length2));

	for (j = 0; j < length2; j++)map[0][j] = "$";
	for (i = 0; i < length1; i++)map[i][0] = "$";

	for (i = 1; i < length1; i++)
	{
		for (j = 1; j < length2; j++)
		{
			if (fstring1[i] == fstring2[j])
			{
				map[i][j] = map[i-1][j-1] + fstring1[i];
			}
			else if (map[i-1][j].length() > map[i][j-1].length())
			{
				map[i][j] = map[i-1][j];
			}
			else
			{
				map[i][j] = map[i][j-1];
			}
		}
	}

	fstring1.erase(0, 1);
	fstring2.erase(0, 1);
	map[length1-1][length2-1].erase(0, 1);
	cout << "the max match string of \"" << fstring1 << "\" and \"" << fstring2 << "\" is: \"" << map[length1-1][length2-1] << "\"" << endl;

	system("pause");
}