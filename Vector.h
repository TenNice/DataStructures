#pragma once

template <typename T>
class Vector
{
protected:
	int Size;
	T* ArrayPosition;

public:
	Vector();
	virtual ~Vector();
	
	void PushBack(T Input);
	void Remove(int Index);

	// operator�� Ŭ������ ������� �ϳ�(public�� �־�� main���� �� �� �ִ�)
	// [] ������ �����Ǹ� ���� �迭ó�� ��� �����ϵ��� ��
	int operator[](int Num)
	{
		return ArrayPosition[Num];
	}
};

template<typename T>
inline Vector<T>::Vector()
{
	Size = 0;
	ArrayPosition = new T[Size];
}

template<typename T>
inline Vector<T>::~Vector()
{
	delete[] ArrayPosition;
}

template<typename T>
inline void Vector<T>::PushBack(T Input)
{
	// ���� �迭���� ����� 1 ū �迭 ���� ����
	T* NewArray = new T[Size + 1];
	// ���� ������ �� �迭�� �ű��
	for (int i = 0; i < Size; i++)
	{
		NewArray[i] = ArrayPosition[i];
	}
	// ���� ���Ե� ������ �������� �ֱ�
	NewArray[Size] = Input;
	// ���� �迭 delete
	delete[] ArrayPosition;
	// ���� ���� �迭 ����Ű�� �ϱ�
	ArrayPosition = NewArray;
	// ������ 1 ����
	Size++;
}

template<typename T>
inline void Vector<T>::Remove(int Index)
{
	// ���� ����Ʈ���� 1 ���� �迭 ���� ����
	T* NewArray = new T[Size - 1];
	// ������ 2���� ���ļ� �ű��. ���� ������ index�� �պκ�
	for (int i = 0; i < Index; i++)
	{
		NewArray[i] = ArrayPosition[i];
	}
	// ������ index�� �޺κ� �ű��
	for (int i = Index; i < Size - 1; i++)
	{
		NewArray[i] = ArrayPosition[i + 1];
	}
	// ���� �迭 ����
	delete[] ArrayPosition;
	// �� �迭 ����Ű�� �ϱ�
	ArrayPosition = NewArray;
	// ������ 1 ���̱�
	Size--;
}

