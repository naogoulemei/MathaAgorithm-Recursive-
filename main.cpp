// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
// #include <iostream>
// #include <string>
// using namespace std;
//class Building
//{
//public:
//	Building();
//public:
//	string s_SittingRoom;
//private:
//	string m_BedRoom;
//};
//
//class Goodgay
//{
//public:
//	Goodgay();
//	
//	void visit();
//private:
//	Building* building;
//
//};
//
//Goodgay::Goodgay()
//{
//	building = new Building;
//}
//void Goodgay::visit()
//{
//	cout<<"正在访访问："<<building->s_SittingRoom<<endl;
//}
//
//
//Building::Building()
//{
//	s_SittingRoom="客厅";
//	m_BedRoom="卧室";
//}
//void test01()
//{
//	Goodgay gg;
//	gg.visit();
//
//}

// typedef enum Tank_Type
// {
// 	Tank_Type_56,
// 	Tank_Type_96
// };
// class Tank
// {
// public:
// 	virtual const string& type() = 0;
// 
// };
// 
// int _tmain(int argc, _TCHAR* argv[])
// {
// 
// 	system("pause");
// 	return 0;
// }

// #include<iostream>
// using namespace std;
// 
// int isswap(int *arr, int from, int to)
// {
// 	for (int i = from; i < to; i++)
// 	{
// 		if (arr[i] == arr[to])
// 			return 0;
// 	}
// 	return 1;
// }
// 
// void swap(int *a, int *b)
// {
// 	int temp;
// 	temp = *a;
// 	*a = *b;
// 	*b = temp;
// }
// void permutations(int *arr, int k, int n)
// {
// 	if (k == n)
// 	{
// 		for (int i = 0; i < n; i++)
// 			cout << arr[i] << " ";
// 		cout << endl;
// 	}
// 	else
// 	{
// 		for (int i = k; i < n; i++)
// 		{
// 			if (isswap(arr, k, i))
// 			{
// 				swap(&arr[k], &arr[i]);
// 				permutations(arr, k + 1, n);
// 				swap(&arr[i], &arr[k]);
// 			}
// 		}
// 	}
// }
// int main()
// {
// 	int a[3] = { 1, 2, 2 };
// 	permutations(a, 0, 3);
// 	system("pause");
// 	return 0;
// }
// 

// 1.将1, 2, 6压入栈中，然后输出栈中所有元素，之后弹出6
// 2.压入7，输出栈中所有元素，之后弹出7
// 3.弹出2，压入5，再压入6，然后输出栈中所有元素，之后弹出6
// 4.压入7，输出栈中所有元素，之后弹出7
// 
// 以此类推，即可得到所有组合。
// 
// 具体程序实现如下 : 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void get_result_in_vector(vector<vector<int> > & vec, int N, vector<int> &tmp, vector<vector<int>>& tmp_result)
{
	for (int i = 0; i < vec[N].size(); ++i)
	{
		tmp.push_back(vec[N][i]);
		if (N < vec.size() - 1)
		{
			get_result_in_vector(vec, N + 1, tmp, tmp_result);
		}
		else
		{
			vector<int> one_result;
			for (int i = 0; i < tmp.size(); ++i)
			{
				one_result.push_back(tmp.at(i));
			}
			tmp_result.push_back(one_result);
		}
		tmp.pop_back();
	}
}

void get_all_combination(vector<vector<int>>& vec, int result[][3])
{
	vector<int> tmp_vec;

	vector<vector<int>> tmp_result;
	get_result_in_vector(vec, 0, tmp_vec, tmp_result);

	//将vector中的数据转化为数组保存
	for (int i = 0; i < tmp_result.size(); i++)
	{
		for (int j = 0; j < tmp_result.at(i).size(); j++)
		{
			result[i][j] = tmp_result.at(i).at(j);
		}
	}
}

int main()
{
	int arr1[] = { 1, 3, 4 };
	int arr2[] = { 2, 5 };
	int arr3[] = { 6, 7 };
	const int first_dimension = sizeof(arr1) / sizeof(arr1[0]) * sizeof(arr2) / sizeof(arr2[0]) * sizeof(arr3) / sizeof(arr3[0]);
	//所有组合的结果
	int result[first_dimension][3];

	cout << arr1 << "   " << arr1 + sizeof(arr1) / sizeof(arr1[0]) << endl;
	vector<vector<int>> vec;
	vec.push_back(vector<int>(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0])));
	vec.push_back(vector<int>(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0])));
	vec.push_back(vector<int>(arr3, arr3 + sizeof(arr3) / sizeof(arr3[0])));
	cout << vec.size() << endl;
	get_all_combination(vec, result);

	//输出结果
	for (int i = 0; i < first_dimension; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << result[i][j] << "\t";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}