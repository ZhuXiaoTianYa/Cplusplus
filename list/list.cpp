#include <iostream>
#include <list>
#include <algorithm>
#include <assert.h>
#include "list.h"


using namespace std;

void test_list1()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	// 不支持，要求随机迭代器
	/*sort(lt.begin(), lt.end());*/

	string s("adhsaui");
	cout << s << endl;
	sort(s.begin(), s.end());
	cout << s << endl;
}

struct A
{
public:
	A(int a1=1,int a2=1)
		:_a1(a1),_a2(a2)
	{ 
		cout << "A(int a1=1,int a2=1)" << endl;
	}

	A(const A& aa)
		:_a1(aa._a1), _a2(aa._a2)
	{
		cout << "A(const A& aa)" << endl;
	}

	int _a1;
	int _a2;
};

void test_list2()
{
	list<int> lt;
	lt.push_back(1);
	lt.emplace_back(2);
	lt.emplace_back(3);
	lt.emplace_back(4);

	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;


	list<A> lta;
	A aa1(1,1);
	lta.push_back(aa1);
	lta.push_back(A(2, 2)); //构造+拷贝构造
	//lta.push_back(3,3);

	lta.emplace_back(aa1);
	lta.emplace_back(A(2,2));
	cout << endl;
	// 支持直接传构造A对象的参数emplace_back
	lta.emplace_back(3,3);
}

void test_list3()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);

	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	auto it = lt.begin();
	int k = 3;
	while (k--)
	{
		++it;
	}
	lt.insert(it, 30);

	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	int x = 0;
	cin >> x;
	it = find(lt.begin(), lt.end(), x);
	if (it != lt.end())
	{
		lt.erase(it);
	}
	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

}

void test_list4()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);

	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	// 升序
	lt.sort();
	//降序 - 仿函数
	//less<int> ls;
	greater<int> gt;
	lt.sort(gt);

	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.reverse();
	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	reverse(lt.begin(), lt.end());
	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}


void test_list5()
{
	list<int> lt,lt2;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);

	lt2.push_back(1);
	lt2.push_back(3);
	lt2.push_back(4);
	lt2.push_back(7);
	lt2.push_back(27);
	lt2.push_back(68);

	// merge 合并链表会挪空一个链表
	lt.merge(lt2);


	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto& e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;
}


void test_list6()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(1);
	lt.push_back(3);
	lt.push_back(1);
	lt.push_back(6);

	lt.sort();
	// 去重要求是有序的
	lt.unique();

	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_list7()
{
	// 一个链表的节点转移给另外一个
	list<int> lt,lt2;
	list<int>::iterator it;

	for (int i = 0; i < 4; i++)
		lt.push_back(i);
	for (int i = 0; i < 3; i++)
		lt2.push_back(i*10);

	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto& e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;


	it = lt.begin();
	++it;
	// 剪切拿走
	lt.splice(it, lt2);

	for (auto& e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto& e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;
	cout << endl;

	// 把最近用的节点转移到第一个
	// 可能就得new一个在头，再删掉原来的
	// 这个时候就可以用splice转移
	// 调整当前链表节点的顺序
	list<int> lt3;
	lt3.push_back(1);
	lt3.push_back(2);
	lt3.push_back(3);
	lt3.push_back(4);
	lt3.push_back(5);
	for (auto& e : lt3)
	{
		cout << e << " ";
	}
	cout << endl;
	int x = 0;
	cin >> x;
	//it = find(lt3.begin(), lt3.end(), x);
	it = find(lt3.begin(), lt3.end(),x);
	if (it != lt3.end())
	{
		//lt3.splice(lt3.begin(), lt3, it,lt3.end());
		lt3.splice(lt3.begin(), lt3, it);
	}
	for (auto& e : lt3)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{

	//test_list1();
	//test_list2();
	//test_list3();
	//test_list4();
	//test_list5();
	//test_list6();
	//test_list7();

	//zhutian::teat_list1();
	//zhutian::teat_list2();
	zhutian::teat_list3();
	return 0;
}