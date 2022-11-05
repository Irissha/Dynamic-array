#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int size, m, k;
	cout << "Введите размер массива: ";
	cin >> size;
	int* arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "Введите номер элемента " << "(от 1 " << "до " << size << "): ";

	do
	{
		cin >> k;
		if (k <= size)
		{
			cout << "Введите количество элементов, которое хотите добавить в массив ";
			cin >> m;
			int* newArray = new int[size + m];
			for (int i = 0; i < k; i++)
			{
				newArray[i] = arr[i];
			}
			for (int i = k; i < k + m; i++)
			{
				newArray[i] = rand() % 100;
			}
			for (int i = k + m; i < size + m; i++)
			{
				newArray[i] = arr[i - m];
			}
			size += m;
			delete[] arr;
			arr = newArray;

			for (int i = 0; i < size; i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;

			delete[]arr;
		}
		else
			cout << "Номер элемента превышает допустимый диапозон! " << size << "\nПопробуйте снова." << endl;
	} while (k > size);
	system("pause");
	return 0;
}