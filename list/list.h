#pragma once
#include <memory>
#include <iostream>
#include <list>
#include <string>
#include <assert.h>

namespace zhutian
{
	template<class T>
	class list_node
	{
	public:
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;

		list_node(const T& x=T())
			:_data(x),_next(nullptr),_prev(nullptr)
		{ }
	};

	template<class T,class Ref,class Ptr>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T,Ref,Ptr> Self;
		Node* _node;
		
		list_iterator(Node* n)
			:_node(n)
		{}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)
		{
			Self tmp = *this;
			_node = _node->_prev;
			return tmp;
		}

		Self operator++(int)
		{
			Self tmp = *this;
			_node = _node->_next;
			return tmp;
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		bool operator!=(const Self& s)const
		{
			return _node != s._node;
		}

		bool operator==(const Self& s)const
		{
			return _node == s._node;
		}
		
	};

	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T,const T&,const T*> const_iterator;

		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}

		list()
		{
			empty_init();
		}

		list(const list<T>& lt)
		{
			empty_init();
			for (auto& e : lt)
			{
				push_back(e);
			}
		}

		list(const std::initializer_list<T>& il)
		{
			empty_init();
			for (auto& e : il)
			{
				push_back(e);
			}
		}

		list& operator=(list lt)
		{
			swap(lt);
			return *this;
		}

		void swap(list& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		iterator begin()
		{
			//return iterator (_head->_next);
			return _head->_next;
		}

		iterator end()
		{
			//return iterator (_head);
			return _head;
		}

		const_iterator begin()const
		{
			//return iterator (_head->_next);
			return _head->_next;
		}

		const_iterator end()const
		{
			//return iterator (_head);
			return _head;
		}

		iterator insert(iterator pos, const T& x)
		{
			Node* newnode = new Node(x);
			Node* cur = pos._node;
			Node* prev = pos._node->_prev;
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			++_size;
			return newnode;
		}

		void push_back(const T& x)
		{
			//Node* newnode = new Node(x);
			//Node* tail = _head->_prev;

			//tail->_next = newnode;
			//newnode->_prev = tail;
			//newnode->_next = _head;
			//_head->_prev = newnode;
			//++_size;

			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(),x);
		}

		size_t size()const
		{
			return _size;
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		iterator erase(iterator& pos)
		{
			assert(pos != end());
			Node* cur = pos._node;
			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			--_size;
			return next;
		}

		bool empty()const 
		{
			return _size == 0;
		}

		void clear()
		{
			auto it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}



	private:
		Node* _head;
		size_t _size;
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

	template<class container>
	void print_container(const container& v)
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

	void teat_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			std::cout << *it << " ";
			//it++;
			++it;
		}
		std::cout << std::endl;

		print_container(lt);

		for (auto e : lt)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}

	void teat_list2()
	{
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);
		lt1.push_back(5);
	
		print_container(lt1);
		list<int> lt2(lt1);
		print_container(lt2);

		list<int> lt3;
		lt3.push_back(2);
		lt3.push_back(3);
		lt3.push_back(4);
		lt3.push_back(5);
		lt3.push_back(6);
		print_container(lt3);
		lt1 = lt3;
		print_container(lt1);

	}

	void func(const list<int>& lt)
	{
		print_container(lt);
	}

	void teat_list3()
	{
		//直接构造
		list<int> lt1({ 0,1,2,3,4,5,6,7,8,9 });
		//list<int> lt1{0,1,2,3,4,5,6,7,8,9};
		//隐式类型转换 
		list<int> lt0={ 0,1,2,3,4,5,6,7,8,9 };
		auto il = { 0,1,2,3,4,5,6,7,8,9 };
		//cout << typeid({ 0,1,2,3,4,5,6,7,8,9 }).name() << endl;
		//std::initializer_list<int>
		std::cout << typeid(il).name() << std::endl;
		std::cout << sizeof il << std::endl;
		print_container(lt1);
		func({ 0,1,2,3,4,5,6,7,8,9 ,10});


	}
}