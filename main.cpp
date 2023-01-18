#include <iostream>
#include "Vector.h"
#include "Stack.h"

using namespace std;

int main()
{
	Vector<int> NewVector;
	NewVector.PushBack(1);
	NewVector.PushBack(2);
	NewVector.PushBack(3);
	NewVector.PushBack(4);
	NewVector.PushBack(5);
	NewVector.PushBack(6);

	cout << "º¤ÅÍ" << endl;
	cout << NewVector[0] << endl;
	cout << NewVector[1] << endl;
	cout << NewVector[2] << endl;
	cout << NewVector[3] << endl;
	cout << NewVector[4] << endl;
	cout << NewVector[5] << endl << endl;

	NewVector.Remove(1);
	NewVector.Remove(3);

	cout << NewVector[0] << endl;
	cout << NewVector[1] << endl;
	cout << NewVector[2] << endl;
	cout << NewVector[3] << endl << endl;



	Stack<char> NewStack;
	NewStack.Push('A');
	NewStack.Push('B');
	NewStack.Push('C');
	NewStack.Push('D');
	NewStack.Push('E');

	cout << "½ºÅÃ" << endl;
	cout << (char)NewStack[0] << endl;
	cout << NewStack[1] << endl;
	cout << NewStack[2] << endl;
	cout << NewStack[3] << endl;
	cout << NewStack[4] << endl << endl;

	NewStack.Pop();
	NewStack.Pop();

	cout << (char)NewStack[0] << endl;
	cout << NewStack[1] << endl;
	cout << NewStack[2] << endl << endl;



	return 0;
}