#pragma once

template <typename T>
class Stack
{
protected:
	int Size, Current;
	T* Array;

public:
	Stack();
	Stack(int Size);
	virtual ~Stack();

	void Push(T Input);
	T Pop();

	int operator[](int Index)
	{
		return Array[Index];
	}
};

template<typename T>
inline Stack<T>::Stack()
{
	int Size = 100;
	Current = 0;
	Array = new T[Size];
}

template<typename T>
inline Stack<T>::Stack(int Size)
{
	this->Size = Size;
	Current = 0;
	Array = new T[this->Size];
}

template<typename T>
inline Stack<T>::~Stack()
{
	delete[] Array;
}

template<typename T>
inline void Stack<T>::Push(T Input)
{
	Array[Current++] = Input;
}

template<typename T>
inline T Stack<T>::Pop()
{
	return Array[Size--];
}
