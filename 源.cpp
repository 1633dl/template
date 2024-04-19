#include<set>
#include<iostream>
#include"Myclass.hpp"
using namespace std;
int main()
{
	Myclass<int>myclass;
	for (int i = 0; i < 10; i++)
	{
		myclass.M_insert(i * 9);
	}
	pair<set<int>::iterator, bool> max = myclass.get_max();
	pair<set<int>::iterator, bool> min = myclass.get_min();

	cout << "最大值：" << *max.first << endl;
	cout << "最小值：" << *min.first << endl;
	system("pause");
	return 0;
}