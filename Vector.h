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

	// operator는 클래스의 멤버여야 하네(public에 있어야 main에서 쓸 수 있다)
	// [] 연산자 재정의를 통해 배열처럼 사용 가능하도록 함
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
	// 기존 배열보다 사이즈가 1 큰 배열 새로 생성
	T* NewArray = new T[Size + 1];
	// 기존 데이터 새 배열에 옮기기
	for (int i = 0; i < Size; i++)
	{
		NewArray[i] = ArrayPosition[i];
	}
	// 새로 삽입된 데이터 마지막에 넣기
	NewArray[Size] = Input;
	// 기존 배열 delete
	delete[] ArrayPosition;
	// 새로 만든 배열 가리키게 하기
	ArrayPosition = NewArray;
	// 사이즈 1 증가
	Size++;
}

template<typename T>
inline void Vector<T>::Remove(int Index)
{
	// 기존 사이트보다 1 작은 배열 새로 생성
	T* NewArray = new T[Size - 1];
	// 데이터 2번에 걸쳐서 옮기기. 먼저 삭제할 index의 앞부분
	for (int i = 0; i < Index; i++)
	{
		NewArray[i] = ArrayPosition[i];
	}
	// 삭제할 index의 뒷부분 옮기기
	for (int i = Index; i < Size - 1; i++)
	{
		NewArray[i] = ArrayPosition[i + 1];
	}
	// 기존 배열 삭제
	delete[] ArrayPosition;
	// 새 배열 가리키게 하기
	ArrayPosition = NewArray;
	// 사이즈 1 줄이기
	Size--;
}

