#pragma warning(disable:4996) // Очень важно - без этого strcat не работает.

#include <iostream>
#include <stdlib.h>  // rand(), srand()
#include <windows.h> // time()
#include <math.h>    // библиотека матеши
#include <time.h>

using namespace std;

void SumP(int* arr, int length, int* sum, int* proiz) {
	for (int i = 0; i < length; i++) {
		*sum += arr[i];
		*proiz *= arr[i];
	}
}

void NumCounter(int* arr, int length, int* zero, int* plus,int* minus) {
	for (int i = 0; i < length; i++) {
		if (arr[i] == 0) {
			*zero += 1;
		}
		else if (arr[i] < 0) {
			*minus += 1;
		}
		else {
			*plus += 1;
		}
	}
}

void subsets(int* A, int* B, int R = 10, int T = 4) {
	int count = 0;
	for (int i = 0; i < 6; i++, *A++) {}

	if (*A == *B) {
		count++;
	}

	for (int i = 0; i < 4; i++, *A++, *B++) {
		if (*A == *B && count > 0) {
			count++;
		}
		else if (count == 0 && *A != *B) {
			cout << "\nне является подмножеством ";
		}
		else {
			break;
		}
	}
	if (count > 1) {
		cout << "\nЯвляется подмножеством на " << count-1 << " числа.";
	}
}

void rand1(int* arr, int length)
{
	for (int i = 0; i < length; i++) {
		*(arr + i) = rand() % 25;
	}
}
void print1(int* arr, int length)
{
	for (int i = 0; i < length; i++) {
		cout << *(arr + i) << " ";
	} cout << endl;
}

int* append(int* arr, int& length)
{
	int* new_block = new int[length], k = 0;
	int* arr2 = new int[length + length], * p = arr2;
	while (k != length)
	{
		*(new_block + k) = 9;
		k++;
	}
	for (int i = 0; i < length; i++, arr2++, arr++)
		*arr2 = *arr;

	for (int i = 0; i < length; i++, arr2++, new_block++)
		*arr2 = *new_block;

	length *= 2;


	return p;
}
int* insertion(int* arr, int* block, int length, int length2, int index)
{
	int* ptr = new int[length + length2];
	for (int i = 0; i < index; i++, ptr++, arr++)
	{
		*ptr = *arr;
	}
	for (int i = 0; i < length2; i++, ptr++, block++)
	{
		*ptr = *block;
	}
	for (int i = index; i < length; i++, ptr++, arr++)
	{
		*ptr = *arr;
	}
	block -= length2;
	ptr = ptr - length + length2;
	return ptr;
}
int* delition(int* arr, int& length, int index)
{
	int* ptr = new int[length];
	for (int i = 0; i < index; i++, ptr++, arr++)
	{
		*ptr = *arr;
	}
	length -= index;
	ptr -= index;
	return ptr;
}

int main()
{
	setlocale(0, "");
	srand(time(NULL));
	//system("color B5");
	cout << "Задание 1\n";
	const int length = 5;
	int arrt[length]{ 5,5,5,5,5 };
	int sum = 0; int proiz = 1;

	cout << "\nМассив: ";
	for (int i = 0; i < length; i++) {
		cout << arrt[i] << " ";
	}

	SumP(&arrt[0], length, &sum, &proiz);

	cout << "\nСумма: " << sum << "\nПроизведение: " << proiz << endl;


	cout << "\n\n\nЗадание 2\n";

	int zero = 0, plus = 0, minus = 0;
	int arrd[length] = { -1,0,-3,4,5 };

	cout << "\nМассив: ";
	for (int i = 0; i < length; i++) {
		cout << arrd[i] << " ";
	}

	NumCounter(&arrd[0], length, &zero, &plus, &minus);

	cout << "\nПлюсы: " << plus << "\nМинусы: " << minus << "\nНули: " << zero << endl;


	cout << "\n\n\nЗадание 3\n";
	const int R = 10;
	int A[R] = { 3,4,8,7,2,9,8,4,6,7 };
	int B[4] = { 8,4,5,9 };
	cout << "\nA: ";
	for (int i = 0; i < R; i++) {
		cout << A[i] << " ";
	}
	cout << "\nB: ";
	for (int i = 0; i < 4; i++) {
		cout << B[i] << " ";
	}
	subsets(&A[0], &B[0]);

	cout << "\n\n\nЗадание 4\n";
	int size = 6;

	int* arr = new int[size];
	int* block = new int[size];

	cout << "Массив: "; rand1(arr, size); print1(arr, size);
	cout << "Блок: "; rand1(block, size); print1(block, size);

	cout << "Массив2: "; int* pointer = append(arr, size);
	for (int i = 0; i < size; i++)
	{
		cout << *(pointer + i) << " ";
	}

	delete[]arr;
	delete[]block;

	cout << "\n\n\nЗадание 5\n";

	/*int* arr3 = new int[size];
	int* block3 = new int[size];

	cout << "Массив: "; rand1(arr3, size); print1(arr3, size);
	cout << "Блок: "; rand1(block3, size); print1(block3, size);

	cout << "Массив2: "; int* pointer3 = insertion(arr3, block3, size, size+size, 4);
	for (int i = 0; i < size; i++)
	{
		cout << *(pointer3 + i) << " ";
	}
	delete[]arr3;
	delete[]block3;*/

	cout << "\n\n\nЗадание 6\n";

	int* arr2 = new int[size];
	int* block2 = new int[size];

	cout << "Массив: "; rand1(arr2, size); print1(arr2, size);
	cout << "Блок: "; rand1(block2, size); print1(block2, size);

	cout << "Массив2: "; int* pointer2 = delition(arr2, size, 3);
	for (int i = 0; i < size; i++)
	{
		cout << *(pointer2 + i) << " ";
	}
	delete[]arr2;
	delete[]block2;

}
