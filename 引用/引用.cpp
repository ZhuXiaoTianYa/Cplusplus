#include <iostream>
using namespace std;

//int main()
//{
//	int a = 10;
//	int& b = a;
//	cout << "a: " << a << endl;
//	cout << "b: " << b << endl;
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int& b = a;
//	int& c = b;
//	cout << "&a: " << &a << endl;
//	cout << "&b: " << &b << endl;
//	cout << "&b: " << &c << endl;
//	return 0;
//}


//int main()
//{
//
//	//int& ra;
//	/*编译报错 创建别名时必须初始化，否则会报错*/
//
//	int a = 10;
//	int b = 20;
//	int& c = a;
//	c = b; //并非让c引用b 因为C++不能更改引用指向 这里为赋值
//
//	cout << "&a: " << &a<<endl;
//	cout << "&b: " << &b << endl;
//	cout << "&c: " << &c << endl;
//	return 0;
//}
//


//void Swap(int& x, int& y)
//{
//	int temp = x;
//	x = y;
//	y = temp;
//}
//
//int main()
//{
//	int x = 10;
//	int y = 20;
//	cout << "x: " << x << endl;
//	cout << "y: " << y << endl;
//
//	Swap(x, y);
//
//	cout << "x: " << x << endl;
//	cout << "y: " << y << endl;
//	return 0;
//}



//int main()
//{
//	const int a = 10;
//	// 编译报错：error C2440: “初始化”: 无法从“const int”转换为“int &”
//	// 这里的引用是对a访问权限的放大
//	//int& ra = a;
//
//	const int& ra = a;
//
//	//编译报错：error C3892: “ra”: 不能给常量赋值
//	//ra++;
//
//	//这里的引用是对b访问权限的缩小
//	int b = 20;
//	const int& rb = b;
//
//	//编译报错 error C3892: “rb”: 不能给常量赋值
//	//rb++;
//
//	return 0;
//}


//int main()
//{
//	int a = 10;
//
//	const int& ra = 30;
//
//	//编译报错：error C2440: “初始化”: 无法从“int”转换为“int &”
//	//int& rb = a * 3;
//	const int& rb = a * 3;
//
//	double d = 3.14;
//
//	//编译报错：error C2440: “初始化”: 无法从“double”转换为“int &”
//	//int& rd = d;
//
//	const int& rd = d;
//
//	return 0;
//}


//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = Add(1, 2);
//	cout << "Add(1,2) is :" << ret << endl; //3或随机值
//
//	Add(3, 4);
//
//	cout << "Add(1,2) is :" << ret << endl; //7或随机值
//	return 0;
//}




//int main()
//{
//	int a = 10;
//
//	int* pa = &a;
//
//	int& ra = a;
//
//	return 0;
//}
