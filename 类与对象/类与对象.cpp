#include <iostream>
using namespace std;



//class Date
//{
//public:
//    void Init(int year, int month, int day)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    // void Print(Date* this)
//    void Print()
//    {
//        //this=nullptr;
//        //cout <<this-> _year << "-" <<this-> _month << "-" <<this-> _day << endl;
//        cout << this << endl;
//        cout << _year << "-" << _month << "-" << _day << endl;
//    }
//private:
//    // 为了区分成员变量，⼀般习惯上成员变量
//    //   会加⼀个特殊标识，如_或者m开头
//    int _year; // year_  m_year
//    int _month;
//    int _day;
//};
//
//int main()
//{
//    Date d1;
//    d1.Init(2024, 3, 31);
//    d1.Print();
//	return 0;
//}


//class A
//{
//public:
//	void Print()
//	{
//		cout << "A::Print()" << endl;
//	}
////private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//	p->Print();
//	p->_a=10;
//	return 0;
//}


//class A
//{
//public:
//    void Print()
//    {
//        cout << "A::Print()" << endl;
//        cout << _a << endl;
//    }
//private:
//    int _a;
//};
//int main()
//{
//    A* p = nullptr;
//    p->Print();
//    return 0;
//}


//class Date
//{
//public:
//	// 1.⽆参构造函数
//	Date()
//	{
//		_year = 1;
//		_month = 1;
//		_day = 1;
//	}
//	// 2.带参构造函数
//
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	// 3.全缺省构造函数 
//	// 全缺省函数与默认构造函数Date()构成重载，但是不能同时存在，无参调用存在歧义
//	/*Date(int year = 1, int month = 1, int day = 1)
//	{
//	_year = year;
//	_month = month;
//	_day = day;
//	}*/
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	 }	
// private:
//	 int _year;
//	 int _month;
//	 int _day;
// };
// int main()
// {
//	 //  如果留下三个构造中的第⼆个带参构造，第⼀个和第三个注释掉
//	 // 编译报错： error C2512 : “Date”:没有合适的默认构造函数可⽤
//	 Date d1; //注意这里不能加() Date d1() 因为这会跟函数的声明分不开 如Date f();
//	 // 调⽤默认构造函数
//	 Date d2(2025, 1, 1); // 调⽤带参的构造函数
//	 // 注意：如果通过⽆参构造函数创建对象时，对象后⾯不⽤跟括号，否则编译器⽆法
//	 // 区分这⾥是函数声明还是实例化对象
//	 // warning C4930: “Date d3(void)”: 未调⽤原型函数(是否是有意⽤变量定义的 ? )
//	 Date d3();
//	 d1.Print();
//	 d2.Print();
//	 return 0;
// }


//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1; 
//	d1.Print();
//	return 0;
//}


//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		cout << "Stack(size_t capacity = 3)" << endl;
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败!!!");
//		}
//		_capacity = capacity;
//		_top = 0;
//	}
//private:
//	int* _a;
//	int _capacity;
//	int _top;
//};

//两个栈实现一个队列
//class MyQueue
//{
//private:
//	Stack _pushst;
//	Stack _popst;
//	int _size;
//};
//
//int main()
//{
//	Date d1; 
//	d1.Print();
//
//	Stack st1;
//
//	MyQueue q1;
//
//	return 0;
//}


//
//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//	~Date()
//	{
//		//日期类严格说不需要写构造函数
//		cout << "~Date()" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//
//
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		cout << "Stack(size_t capacity = 3)" << endl;
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败!!!");
//		}
//		_capacity = capacity;
//		_top = 0;
//	}
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_capacity = 0;
//		_a = nullptr;
//	}
//private:
//	int* _a;
//	int _capacity;
//	int _top;
//};
//
////两个栈实现一个队列
//class MyQueue
//{
//private:
//	Stack _pushst;
//	Stack _popst;
//	int _size;
//};
//
//int main()
//{
//	/*Date d1; 
//	Stack st1;*/
//	MyQueue q;
//	return 0;
//}
//



//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(Date& dd) //不能用传值
//	{
//		_year = dd._year;
//		_month = dd._month;
//		_day = dd._day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	 }	
// private:
//	 int _year;
//	 int _month;
//	 int _day;
// };
//
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		cout << "Stack(size_t capacity = 3)" << endl;
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败!!!");
//		}
//		_capacity = capacity;
//		_top = 0;
//	}
//
//	// Stack st2(st1)
//	Stack(Stack& stt)
//	{
//		cout << "Stack(Stack& stt)" << endl;
//		// 深拷贝
//		_a = (int*)malloc(sizeof(int) * stt._capacity);
//		if(_a==nullptr)
//		{
//			perror("malloc fail");
//			exit(-1);
//		}
//		memcpy(_a, stt._a, sizeof(int) * stt._top);
//		_top = stt._top;
//		_capacity = stt._capacity;
//	}
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_capacity = 0;
//		_a = nullptr;
//	}
//private:
//	int* _a;
//	int _capacity;
//	int _top;
//};
//
//class MyQueue
//{
//	Stack _pushst;
//	Stack _popst;
//	int _size = 0;
//};
//
//void func1(Date d) //可以传参传过来，为拷贝一份，浅拷贝
//{
//	d.Print();
//}
//
//void func2(Stack st)
//{
//	//TODO
//}
//
//int main()
//{
//	//Date d1(2023, 10, 22);
//	//func1(d1);
//	//Date d2(d1); //这里也是拷贝构造，对于日期类来说没问题
//
//	//Stack st1;
//	//func2(st1);
//	//Stack st2(st1); //而这里的拷贝构造因为多次析构同一片空间就会崩溃
//
//	MyQueue q1;
//	MyQueue q2(q1);
//
//	return 0;
//}



//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		cout << "Stack(size_t capacity = 3)" << endl;
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败!!!");
//		}
//		_capacity = capacity;
//		_top = 0;
//	}
//
//	// Stack st2(st1)
//	Stack(Stack& stt)
//	{
//		cout << "Stack(Stack& stt)" << endl;
//		// 深拷贝
//		_a = (int*)malloc(sizeof(int) * stt._capacity);
//		if (_a == nullptr)
//		{
//			perror("malloc fail");
//			exit(-1);
//		}
//		memcpy(_a, stt._a, sizeof(int) * stt._top);
//		_top = stt._top;
//		_capacity = stt._capacity;
//	}
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_capacity = 0;
//		_a = nullptr;
//	}
//private:
//	int* _a;
//	int _capacity;
//	int _top;
//};
//
//Stack func1() 
//{
//	Stack st;
//	return st; //这里会发生一次拷贝构造，因为传值返回，返回的不是st本身，而是st拷贝构造形成的临时对象
//}
//
//Stack func2()
//{
//	static Stack st;
//	return st; //这里会发生一次拷贝构造，因为传值返回，返回的不是st本身，而是st拷贝构造形成的临时对象
//}
//
//Stack func2()
//{
//	static Stack st;
//	return st; //这里会发生一次拷贝构造，因为传值返回，返回的不是st本身，而是st拷贝构造形成的临时对象
//}
//
//Stack& func3()
//{
//	static Stack st;
//	return st; //这里不会拷贝构造，因为st不会销毁，所以可以使用引用返回，可以减少一次拷贝构造
//}
//
//int main()
//{
//	func1();
//	func2();
//	func3();
//	return 0;
//}


#include <assert.h>

//class Date
//{
//public:
//	Date(int year = 1990, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& dd) //不能用传值
//	{
//		_year = dd._year;
//		_month = dd._month;
//		_day = dd._day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	 }	
//
//	//类内都不受限制，xy的私有都可以访问
//	bool operator>( const Date& y)
//	{
//		if (_year > y._year)
//		{
//			return true;
//		}
//		else if (_year == y._year && _month > y._month)
//		{
//			return true;
//		}
//		else if (_year == y._year && _month == y._month && _day > y._day)
//		{
//			return true;
//		}
//		return false;
//	}
//
//	bool operator==( const Date& y)
//	{
//		return _year == y._year
//			&& _month == y._month
//			&& _day == y._day;
//	}
//
//	int GetMonthDay(int year, int month)
//	{
//		assert(year >= 1 && month >= 1 & month <= 12);
//		int monthArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//		if (month==2&&(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//			return 29;
//		return monthArray[month];
//	}
//
//	int operator-(const Date& y)
//	{
//		return _year == y._year
//			&& _month == y._month
//			&& _day == y._day;
//	}
//
	//Date operator+=(const int day)
	//{
	//	_day += day;
	//	while (_day > GetMonthDay(_year, _month))
	//	{
	//		_day -= GetMonthDay(_year, _month);
	//		++_month;
	//		if (_month == 13)
	//		{
	//			_year++;
	//			_month = 1;
	//		}
	//	}
	//	return *this;
	//}
//
//
	//Date operator+(const int day)
	//{
	//	Date tmp(*this);
	//	tmp._day += day;
	//	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
	//	{
	//		tmp._day -= GetMonthDay(tmp._year, tmp._month);
	//		++tmp._month;
	//		if (tmp._month == 13)
	//		{
	//			tmp._year++;
	//			tmp._month = 1;
	//		}
	//	}
	//	return tmp;
	//}
//
//
	//Date operator+(const int day)
	//{
	//	Date tmp(*this);
	//	tmp += day;
	//	return tmp;
	//}
//
// private:
//	 int _year;
//	 int _month;
//	 int _day;
// };
//
//
//
////bool operator>(const Date& x, const Date& y)
////{
////	if (x._year > y._year)
////	{
////		return true;
////	}
////	else if (x._year == y._year && x._month > y._month)
////	{
////		return true;
////	}
////	else if (x._year == y._year && x._month == y._month && x._day > y._day)
////	{
////		return true;
////	}
////	return false;
////}
////
////bool operator==(const Date& x, const Date& y)
////{
////	return x._year == y._year
////		&& x._month == y._month
////		&& x._day == y._day;
////}
//
//int main()
//{
//	Date d1(2023, 10, 22);
//	Date d2; //这里也是拷贝构造，对于日期类来说没问题
//
//	//运算符重载：operator+符号作为函数名，自定义类型可以直接使用运算符
//	//函数重载：可以允许参数不同的同名函数重载
//	//他们之间没有关联
//	/*cout << operator>(d1, d2) << endl;
//	cout << operator== (d1, d2) << endl;*/
//	cout << (d1>d2) << endl;
//	cout << (d1==d2)<< endl;
//
//	bool ret1 = d1 > d2; //转化为operator>(d1, d2) (全局的)
//	//转化为operator>(d2) -> operator>(&d1,d2)
//	bool ret2 = d1 == d2; //转化为operator==(d1, d2) (全局的)
//	//转化为operator==(d2) -> operator==(&d1,d2)
//
//	d1.operator>(d2); //也可以显示调用
//	/*d1 == d2;
//	d1 > d2;*/
//
//	//内置类型对象可以直接用各种运算符，内置类型都是简单类型
//	// 语言自己定义，编译直接转换成指令
//	//自定义类型呢？不可以，因为编译器不知道怎么比较
//
//	//一个类需要重载哪些运算符，主要看这个运算符有没有意义
//	//有意义就可以实现，没有意义就不要实现
//	//d1 + d2;
//	d1 - d2;
//	/*d1* d2;
//	d1 / d2;*/
//
//	d2 += 50;
//
//	Date ret3 = (d2 + 50);
//
//	int i = 10, j = 0;
//	i += 50;
//	j += i += 50; //+=从右往左执行
//
//	return 0;
//}





//class Date
//{
//public:
//	Date(int year = 1990, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& dd) //不能用传值
//	{
//		_year = dd._year;
//		_month = dd._month;
//		_day = dd._day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//		int GetMonthDay(int year, int month)
//	{
//		assert(year >= 1 && month >= 1 & month <= 12);
//		int monthArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//		if (month==2&&(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//			return 29;
//		return monthArray[month];
//	}
//
//
//	Date operator+(const int day)
//	{
//		Date tmp(*this);
//		tmp._day += day;
//		while (tmp._day > GetMonthDay(tmp._year, tmp._month))
//		{
//			tmp._day -= GetMonthDay(tmp._year, tmp._month);
//			++tmp._month;
//			if (tmp._month == 13)
//			{
//				tmp._year++;
//				tmp._month = 1;
//			}
//		}
//		return tmp;
//	}
//
//	Date& operator+=(int d)
//	{
//		*this = *this + d;
//		return *this;
//	}
//
//
//
//	//++d1
//	Date& operator++()
//	{
//		*this += 1;
//		return *this;
//	}
//
//	//自定义类型能用前置就用前置
//
//	//d1++
//	Date operator++(int) //(int i)形参可写可不写
//	{
//		Date temp(*this);
//		*this += 1;
//		return temp;
//	}
//
//	//会导致只能这样调用 d1 << cout;
//	//双操作数的运算符，第一个参数是左操作数，第二个参数是右操作数
//	//d1.operator<<(&d1,cout); 有this指针
//	//Date对象默认占据第一个位置，<<实现成成员函数就是不好的
//	/*void operator<< (ostream& out)
//	{
//		out << _year << "年" << _month << "月" << _day << "日" << endl;
//	}*/
//
//
//	//友元函数
//	friend ostream& operator<<(ostream& out, const Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////out是流插入对象，不能加const，要输入数据进去改变
//ostream& operator<<(ostream& out,const Date& d)
//{
//	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
//	return out;
//}
//
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >>d._day;
//	return in;
//}
//
////总结：其他运算符一般是实现为成员函数， 
//// << >> 流运算符一般实现为全局函数，才能让流对象做第一个参数
//// 才符合可读性
//// 流本质是为了解决自定义类型的输入和输出问题
//// printf scanf无法解决自定义类型的输入输出问题
//// 面向对象+运算符重载
//// 与左移右移有双重含义，但是左移右移一般是内置类型int
//
////operaor= 不写编译器会生成默认的
////跟拷贝构造的行为类似，默认的operator= 内置类型值拷贝，自定义类型调用他的赋值
////Date MyQueue 可以不写，默认的operator=就可以用
////Stack必须自己实现operator=，实现深拷贝
//
//
//class MyClass
//{
//public:
//	void MyFunction(int x)
//	{
//		//
//	}
//};
//
//int main()
//{
//	Date d1(2023, 10, 22);
//	Date d2(2022, 1, 22);
//
//	////一个已经存在的对象拷贝初始化另一个对象
//	//Date d3(d1);
//
//	////两个已经存在的对象拷贝
//	//d2=d1 = d3;
//	//d1 = d1;
//	//
//	//// 语法设计，无法逻辑闭环，只能特殊处理
//	//// 特殊处理
//	//++d1;
//	//d1.operator++();
//
//	//d1++;
//	//d1.operator++(1);
//	//cin >> d2;
//	 
//	cout << d1 <<d2<<endl;
//	
//	//MyClass obj;
//	////声明一个成员函数指针
//	//void (MyClass:: * MyFunctionPtr)(int) = &MyClass::MyFunction;
//	////使用.*运算符调用成员函数
//	//(obj.*MyFunctionPtr)(42);
//
//	return 0;
//} 




//
//class date
//{
//public:
//	date(int year = 1990, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	date(const date& dd) //不能用传值
//	{
//		_year = dd._year;
//		_month = dd._month;
//		_day = dd._day;
//	}
//
//	void print()const
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//		int getmonthday(int year, int month)
//	{
//		assert(year >= 1 && month >= 1 & month <= 12);
//		int montharray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//		if (month==2&&(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//			return 29;
//		return montharray[month];
//	}
//
//
//	date operator+(const int day)
//	{
//		date tmp(*this);
//		tmp._day += day;
//		while (tmp._day > getmonthday(tmp._year, tmp._month))
//		{
//			tmp._day -= getmonthday(tmp._year, tmp._month);
//			++tmp._month;
//			if (tmp._month == 13)
//			{
//				tmp._year++;
//				tmp._month = 1;
//			}
//		}
//		return tmp;
//	}
//
//	date& operator+=(int d)
//	{
//		*this = *this + d;
//		return *this;
//	}
//
//	bool operator<(const date& d) const
//	{
//		if (_year < d._year)
//		{
//			return true;
//		}
//		else if (_year == d._year)
//		{
//			if (_month < d._month)
//			{
//				return true;
//			}
//			else if (_month == d._month)
//			{
//				return _day < d._day;
//			}
//		}
//		return false;
//	}
//
//	date& operator++()
//	{
//		*this += 1;
//		return *this;
//	}
//
//	date operator++(int) //(int i)形参可写可不写
//	{
//		date temp(*this);
//		*this += 1;
//		return temp;
//	}
//
//	date* operator&()
//	{
//		return this;
//	}
//
//	// 运算符重载
//	const date* operator&()const
//	{
//		return this;
//	}
//
//	//友元函数
//	friend ostream& operator<<(ostream& out, const date& d);
//	friend istream& operator>>(istream& in, date& d);
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//ostream& operator<<(ostream& out,const date& d)
//{
//	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
//	return out;
//}
//
//istream& operator>>(istream& in, date& d)
//{
//	in >> d._year >> d._month >>d._day;
//	return in;
//}
//
//int main()
//{
//	//const对象和非const对象都可以调用const成员函数
//	const date d1(2025, 11, 19);
//	d1.print();
//
//	date d2(2025, 11, 19);
//	d2.print();
//	d1 < d2;
//	d2 < d1;
//
//	d1.operator&();  //d1.operator&(&d1);
//	// 如果将两个&重载都注释掉,一样可以编译,因为这是默认成员函数
//	// 如果将date*版本注释掉,一样可以走const版本编译
//	cout << &d1 << endl;
//	cout << &d2 << endl;
//	return 0;
//}


//class Time
//{
//public:
//	Time(int hour)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	//Date(int year = 1990, int month = 1, int day = 1)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//
//	//Date(int year = 1990, int month = 1, int day = 1)
//	//	:_year(year),_month(month),_day(day),_ref(year),_n(1)
//	//{
//	//	//初始化列表
//	//	//_ref
//	//	//_n
//	//}
//
//
//	Date(int year = 1990, int month = 1, int day = 1)
//		: _ref(year), _n(1),_t(10) //每个成员定义 _year
//	{
//		// 剩下3个成员没有在初始化列表显示写出来定义
//		// 但是他也会定义,只是内置类型默认给的随机值
//		//如果是自定义类型成员会去调用他的默认构造函数
//
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	// 声明 并没有开空间
//	int _year =1; //缺省值,是给初始化列表的,如果显示的传参了就没用
//	int _month;
//	int _day;
//
//	Time _t; //自定义类型成员(且该类没有默认构造函数时)
//
//	//
//	int& _ref;//引用:必须在定义的时候初始化
//	const int _n; //const:必须在定义的时候初始化
//};
//
//class Stack
//{
//public:
//	Stack(int n = 4)
//		:_a((int*)malloc(sizeof(int)* n))
//		, _top(0)
//		, _capacity(n)
//	{
//		cout << "Stack(int n=4)" << endl;
//		if (_a == nullptr)
//		{
//			perror("malloc fail");
//			exit(-1);
//		}
//		memset(_a, 0, sizeof(int) * n);
//	}
//
//	int* _a;
//	int _top;
//	int _capacity;
//};
//
//
//// 初始化列表解决的问题:
//// 1 必须在定义的地方显式初始化 引用 const 没有默认构造函数自定义成员
//// 2 有些自定义成员想要显式初始化,自己控制
//// 尽量使用初始化列表
//// 构造函数能不能只要初始化列表,不要函数体初始化呢
//// 不能,因为有些初始化或者检查工作,初始化列表也不能全部搞定
//// 80-1--%初始化列表搞定,还要需要函数体,他们可以混着用
//class MyQueue
//{
//public:
//	// 没写初始化列表也会初始化
//	// 不写初始化列表也会走初始化列表,因为初始化列表是它定义的地方
//	// 这里的MyQueue写不写效果一样
//	MyQueue()
//	{}
//
//private:
//	Stack _s1;
//	Stack _s2;
//	int _size = 0;
//};
//
//int main()
//{
//	// 定义:对象整体定义
//	// 每个成员在什么地方定义呢?-->初始化列表
//	Date d1(2023, 1, 3);
//
//	//int& x;
//	//const int y;
//	return 0;
//}



//class A
//{
//public:
//	A() { ++count; }
//	A(const A& t) { ++count; }
//	~A() { --count; }
//
//	//静态成员函数，特点是没有this指针
//	static int GetACount() { return count; }
//private:
//	static int count; //声明
//	//static int count=0; 缺省值这是给初始化列表用的,因为不属于某个对象
//};
//
//int A::count = 0;// 定义初始化，还是在类内访问
//
//void TestA()
//{
//	cout << A::GetACount() << endl;
//	A a1, a2; //有名对象
//	A a3(a1);
//
//	//如果是public
//	// A::count;
//	// a1.count; 但是不属于a1，这里只是标示告诉编译器是A类的
//	// A() 这种写法叫做匿名对象，生命周期只在这一行
//	cout << A::GetACount() << endl;
//	cout << a1.GetACount() << endl; // 也可以
//	cout <<A().GetACount() << endl; // 也可以
//}
//
//
//int main()
//{
//	TestA();
//	cout << sizeof A << endl;//静态成员大小不算在内
//
//	// 总结：静态成员函数和静态成员变量，本质受限制的全局变量和全局函数
//	// 专属这个类，受类域和访问限定符的限制
//	return 0;
//}


//#include <list>
//class A
//{
//public:
//	A(int a) :_a(a) { }
//	//explicit A(int a) :_a(a) { }
//	A(int* a) { }
//private:
//	int _a=0; 
//};
//
//class Date
//{
//public:
//	Date(int year, int month=1, int day=1) //相当于单参数
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year ;
//	int _month;
//	int _day;
//
//};
//
//int main()
//{
//	A aa1(1);
//	A aa2(2);
//
//	// 内置类型对象 隐式转换成自定义类型对象
//	//  能支持这个转化，是因为A的int单参数(支持只传一个参数的半缺省)构造函数支持
//	// 多参数不行
//	// 如果不想隐式让转化发生，构造函数加explicit
//	// 显示转换强转可以 如A	a1=(A)3；
//	A aa3 = 3;
//	// A& ra=3; 临时变量具有常性 
//	const A& ra=3; 
//
//	A aa4 = 3.33;
//
//	int* p = NULL;
//	A aa5 = p;
//
//	int i = 0;
//	double d = i;
//
//	Date d1(2025, 11, 26);
//	Date d2 = (2025, 11, 25); //等价于 Date d2=3;
//	Date d3=2025; 
//	Date d4 = { 2023,11,2 }; //C++11支持多参数
//	const Date& d5 = { 2023,11,2 }; //C++11支持多参数,中间还是走的临时对象
//	
//	list<A> lt;
//	A aa6(1);
//	lt.push_back(aa1);
//	lt.push_back(A(2));
//	lt.push_back(3);
//
//	list<Date> lt1;
//	Date d6(2025, 11, 24);
//	lt1.push_back(d6);
//	lt1.push_back(Date(2025, 1, 1));
//	lt1.push_back({2025,11,1});
//
//
//	return 0;
//}


//class A
//{
//public:
//	// A和B的关系
//	// B就是一个普通类，只是受A的类域和访问限定符限制,本质相当于被封装了一下
//	class B //B天生就是A的友元
//	{
//	public:
//		void func()
//		{
//			A aa;
//			//B 天生就是A的友元
//			aa._a++;
//		}
//	public: 
//		int _b;
//	};
//private:
//	int _a = 0;
//};
//
////这个时候B的大小才算在A中
////class B 
////{
////public:
////	int _b;
////};
////
////class A
////{
////private:
////	int _a = 0;
////	B _b;
////};
//
//int main()
//{
//	cout << sizeof A << endl;
//	A aa;
//	//B bb; 编译器在对变量或者函数时，要去找他的出处，不会到类域中去照除非指定了
//	A::B bb;
//	return 0;
//}



// 扩展：编译器一些构造时的优化 不同编译器可能会不同（了解一下）
class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}
		A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a = aa._a;
		}
		return *this;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};
void f1(A aa)
{}
A f2()
{
	A aa;
	return aa;
}

//int main()
//{
//	A aa1(1); // 构造
//	
//	//等价
//	A aa2(aa1); //拷贝构造
//	A aa3=aa1; //拷贝构造 一个已经存在的对象拷贝构造初始化另一个要创建的对象，拷贝构造
//
//	aa2 = aa3; //这里才是赋值，两个已经存在的对象拷贝，赋值拷贝
//}

//int main()
//{
//	//1、先用1构造一个临时对象 2、再用临时对象拷贝构造aa1
//	//3、同一个表达式中，连续构造+构造 / 构造+拷贝构造 / 拷贝构造+拷贝构造会合二为一
//	// a、构造+构造->构造
//	// b、构造+拷贝构造->构造
//	// c、拷贝构造+拷贝构造->拷贝构造
//	A aa1 = 1; //b
//	const A& aa2 = 2;
//
//	return 0;
//}

//void func(A aa1)
//{
//
//}
//
//int main()
//{
//	// 构造
//	A aa;
//	// 拷贝构造
//	func(aa); //不在同一个表达式，不会优化
//	
//	//构造+拷贝构造->构造
//	func(A(2));
//
//	//构造+拷贝构造->构造
//	func(3);
//
//	return 0;
//}


A func()
{
	A aa;
	return aa;
}

int main()
{
	//连续同一个步骤才会被优化
	A aa1 = func();//拷贝构造+拷贝构造->构造

	//不在同一个步骤，没有第二个拷贝构造所以不会被优化
	A aa2;
	aa2 = func();
	return 0;
}

//int main()
//{
//	// 编译器
//	// 传值传参
//	A aa1;
//	f1(aa1);
//	cout << endl;
//	// 传值返回
//	f2();
//	cout << endl;
//	// 隐式类型，连续构造+拷贝构造->优化为直接构造
//	f1(1);
//	// 一个表达式中，连续构造+拷贝构造->优化为一个构造
//	f1(A(2));
//	cout << endl;
//	// 一个表达式中，连续拷贝构造+拷贝构造->优化一个拷贝构造
//	A aa2 = f2();
//	cout << endl;
//	// 一个表达式中，连续拷贝构造+赋值重载->无法优化
//	aa1 = f2();
//	cout << endl;
//	return 0;
//}
