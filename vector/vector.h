#pragma once
#include <memory>
#include <iostream>
#include <list>
#include <string>
#include <assert.h>

namespace zhutian
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		//vector()
		//{ }

		//C++11 强制生成默认构造函数
		vector() = default;

		vector(const vector<T>& v)
		{
			//提前开好空间减少扩容消耗
			reserve(v.size());
			//& 防止是string之类的
			for (auto& e : v)
			{
				push_back(e);
			}
		}

		//
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			// 这里不能用<=，对于vector可以，但是对于链表等不连续的空间就不行
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		vector(size_t n, const T& val=T())
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		vector(int n, const T& val = T())
		{
			reserve(n);
			for (int i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old_size = size();
				T* tmp = new T[n];
				
				// 会导致像vector<string> vector<vector<int>>这样的在扩容时出错
				//memcpy(tmp, _start, size() * sizeof(T));
				for (size_t i = 0; i < old_size; i++)
				{
					tmp[i] = _start[i];
				}

				delete[] _start;
				_start = tmp;
				_finish = _start + old_size;
				_end_of_storage = _start + n;
			}
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin()const
		{
			return _start;
		}

		const_iterator end()const
		{
			return _finish;
		}

		size_t size()const
		{
			return _finish - _start;
		}

		size_t capacity()const
		{
			return _end_of_storage - _start;
		}

		void push_back(const T& x)
		{
			// 扩容
			if (_finish == _end_of_storage)
			{
				reserve(size() != 0 ? capacity() * 2 : 4);
			}
			*_finish = x;
			++_finish; 
		}

		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}


		const T& operator[](size_t i)const
		{
			assert(i < size());
			return _start[i];
		}

		bool empty()
		{
			return _start == _finish;
		}

		// 迭代器失效
		//void insert(iterator pos, const T& x)
		//{
		//	// 扩容
		//	if (_finish == _end_of_storage)
		//	{
		//		reserve(size() != 0 ? capacity() * 2 : 4);
		//	}

		//	iterator end = _finish - 1;
		//	while (end >= pos)
		//	{
		//		*(end + 1) = *end;
		//		--end;
		//	}
		//	*pos = x;
		//	++_finish;
		//}

		// 不能加引用,加引用find、范围for、insert等就不支持了,而且
		//iterator insert(iterator& pos, const T& x)
		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start );
			assert(pos <= _finish);

			// 扩容
			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
				reserve(size() != 0 ? capacity() * 2 : 4);
				pos = _start + len;
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}

		void resize(size_t n, T val = T())
		{
			if (n < size())
			{
				_finish = _start +n;
			}
			else
			{
				reserve(n);
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);

			iterator it = pos + 1;
			while (it != end())
			{
				*(it - 1) = *it;
				it++;
			}
			--_finish;
			return pos;
		}

		void pop_back()
		{
			assert(!empty());
			--_finish;
		}

		void clear()
		{
			_finish = _start;
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		// 类里面可以用类名替代类型，类外不行
		//vector<T>& operator=(vector<T> v)
		vector& operator=(vector v)
		{
			swap(v);
			return *this;
		}

		//// v1=v3
		//vector<T>& operator=(const vector<T>& v)
		//{
		//	if (this != &v)
		//	{
		//		clear();
		//		reserve(v.size());
		//		for (auto& e : v)
		//		{
		//			push_back(e);
		//		}
		//	}
		//	return *this;
		//}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}


	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};

	template<class container>
	void print_vector(const container& v)
	{
		// 类名::名称 可能是类中的某个类型，也有可能是类静态成员
		// 规定：没有实例化的类模板里取东西，编译器不能区分这里的
		// const_iterator是类型还是静态变量
		// 这个时候在前面加一个typename就可以告诉编译器是类型
		// 这也是typename在模板template<class T>与template<typename T>一样
		// 但是class与typename不同
		// vector<T>::const_iterator it = v.begin();

		// 这里用auto更方便
		//typename vector<T>::const_iterator it = v.begin();
		auto it = v.begin();

		while (it != v.end())
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;

		for (auto e : v)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}

	void teat_vector()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		//for (size_t i = 0; i < v.size(); i++)
		//{
		//	std::cout << v[i] << " ";
		//}
		//std::cout << std::endl;

		print_vector(v);
		for (size_t i = 0; i < v.size(); i++)
		{
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;

		vector<double> vd;
		vd.push_back(1.1);
		vd.push_back(2.2);
		vd.push_back(3.3);
		vd.push_back(4.4);
		vd.push_back(5.5);
		print_vector(vd);
	}

	void teat_vector2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		print_vector(v);

		//v.insert(v.begin() + 2, 30) ;

		//print_vector(v);
		std::cout << v.capacity() << std::endl;

		int x;
		std::cin >> x;
		auto pos = std::find(v.begin(), v.end(), x);
		if (pos != v.end())
		{
			// insert以后,迭代器pos就失效了,不要直接访问,要访问就要更新这个迭代器的值
			/*v.insert(pos, 40);
			(*pos)*=10;*/
			v.insert(pos, 40);

			std::cout << v.capacity() << std::endl;
			//pos=v.insert(pos, 40);
			*(pos+1) *= 10;
		}
		print_vector(v);

	}


	void teat_vector3()
	{
		//std::vector<int> v;
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(4);
		v.push_back(5);

		print_vector(v);

		//auto it = v.begin();
		////删除所有的偶数
		//while (it != v.end())
		//{
		//	if (*it % 2 == 0)
		//	{
		//		v.erase(it);
		//	}
		//	++it;
		//}
		//print_vector(v);

		auto it = v.begin();
		//删除所有的偶数
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it=v.erase(it);
			}
			else
			{
				++it;
			}
		}
		print_vector(v);

	}

	void teat_vector4()
	{
		int i = int();
		int j = int(1);
		int z(2);

		vector<int> v;
		v.resize(10, 1);
		v.reserve(20);
		print_vector(v);
		cout << v.size() << endl;
		cout << v.capacity() << endl;

		v.resize(15, 2);
		print_vector(v);
		cout << v.size() << endl;
		cout << v.capacity() << endl;

		v.resize(25, 3);
		print_vector(v);
		cout << v.size() << endl;
		cout << v.capacity() << endl;

		v.resize(5, 4);
		print_vector(v);
		cout << v.size() << endl;
		cout << v.capacity() << endl;
	}

	void teat_vector5()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		print_vector(v);

		vector<int> v1 = v;
		print_vector(v1);

		vector<int> v2 ;
		v2.push_back(10);
		v2.push_back(20);
		v2.push_back(30);
		print_vector(v2);

		v = v2;
		print_vector(v);
		print_vector(v2);

	}

	void teat_vector6()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		print_vector(v1);


		vector<int> v2(v1.begin(), v1.begin() +3);
		print_vector(v2);

		// 可以用别的容器迭代器初始化，所以迭代器区间初始化函数写为模板函数
		// 要求类型是匹配的,int 与 int ，string 与 string
		std::list<int>  lt;
		lt.push_back(10);
		lt.push_back(10);
		lt.push_back(10);
		vector<int> v3(lt.begin(), lt.end());
		print_vector(lt);
		print_vector(v3);

		vector<std::string> v4(5, "101010");
		print_vector(v4);

		vector<std::string> v5(5);
		print_vector(v5);

		vector<int> v6(5, 1);
		print_vector(v6);

		//vector<int> v7(5u,1);
		//print_vector(v7);

		vector<int> v8(5, 1);
		print_vector(v8);
	}


	void teat_vector7()
	{
		vector<string> v1;
		v1.push_back("1111111");
		v1.push_back("1111111");
		v1.push_back("1111111");
		v1.push_back("1111111");
		v1.push_back("1111111");
		print_vector(v1);

		v1.push_back("1111111");
		print_vector(v1);


	}
}