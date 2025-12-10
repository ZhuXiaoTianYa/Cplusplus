#include <iostream>
#include <vector>
#include <assert.h>


using namespace std;

void test1()
{
	vector<int> v1;
	vector<int> v2(10, 1); //10个1
	vector<int> v3(++v2.begin(), --v2.end());
	for (size_t i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << endl;
	}
	cout << endl;

	vector<int>::iterator it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << endl;
		++it;
	}
	cout << endl;

	vector<int>::reverse_iterator rit = v3.rend()-1;
	while (rit != v3.rbegin())
	{
		cout << *rit << " ";
		rit--;
	}
	cout << endl;
	
	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test2()
{
	vector<int> v1;
	vector<int> v2(10, 1); //10个1
	vector<int> v3(++v2.begin(), --v2.end());
	for (size_t i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << endl;
	}
	cout << endl;

	vector<int>::iterator it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << endl;
		++it;
	}
	cout << endl;

	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;

}

void TestVectorExpand()
{
	size_t sz;
	vector<int> v;
	v.reserve(100); //提前将容量设置好，可以减少扩容的代价
	sz = v.capacity();
	cout << "capacity changed: " << sz << '\n';
	cout << "moving v grow:\n";
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		if (sz != v.capacity())
		{
			sz = v.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

void test3()
{
	vector<int> v1(10, 1);
	v1.reserve(20);
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;

	v1.reserve(15);
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;

	v1.reserve(5);
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
}


void test4()
{
	vector<int> v1(10, 1);
	v1.resize(20);
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;

	v1.resize(15);
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;

	v1.resize(5);
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
}

void test5()
{
	vector<int> v(10, 1);
	v.push_back(2);
	v.insert(v.begin(), 0);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.insert(v.begin()+3, 10);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.clear();

	vector<int> v1(5, 0);
	for (size_t i=0;i<5;i++)
	{
		cin >> v1[i];
	}
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<char> s1; // 结尾没有'\0'
	string s2; // 结尾有'\0' 可以很好的兼容C语言
	// 不要用vector<char>替代string
}

void test6()
{
	vector<string> v;
	string s("xxxxx");
	v.push_back(s);
	v.push_back("yyyyyyy"); //const char* 隐式转换成string
	//for (auto e : v) // 拷贝的代价就很大了
	//{
	//	cout << e << " ";
	//}
	for (auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	// 二维数组
	// 10*5
	vector<int> v1(5,1);
	vector<vector<int>> vv(10,v1);
	vv[2][1] = 2;
}

// vector<vector<int>> 实际上要实例化出两个类
// vector<vector<int>> 与 vector<int> 实例化出两个类
//template<class T>
//class myvector
//{
//	T& operator[](int i)
//	{
//		assert(i > _size);
//		return _a[i];
//	}
//private:
//	T* _a;
//	size_t _size;
//	size_t _capacity;
//};

////vector<int>
//class myvector
//{
//	T& operator[](int i)
//	{
//		assert(i > _size);
//		return _a[i];
//	}
//private:
//	T* _a;
//	size_t _size;
//	size_t _capacity;
//};

////vector<vector<int>>
//class myvector
//{
//	T& operator[](int i)
//	{
//		assert(i > _size);
//		return _a[i];
//	}
//private:
//	T* _a;
//	size_t _size;
//	size_t _capacity;
//};

#include "vector.h"

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();

	//TestVectorExpand();
	//zhutian::teat_vector();
	//zhutian::teat_vector2();
	//zhutian::teat_vector3();
	//zhutian::teat_vector4();
	//zhutian::teat_vector5();
	//zhutian::teat_vector6();
	zhutian::teat_vector7();
	return 0;
}