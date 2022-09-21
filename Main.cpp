// шаблон
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<algorithm>
using namespace std;
// Задача 1
void type_of(int num) {
	cout << "INT\n";
}
void type_of(double num) {
	cout << "DOUBLE\n";
}
void type_of(char num){
cout << "CHAR\n";
}

// Задача 2 Рекурсия суммы от А до В
int sum_AB(int A, int B) {
	if (B == A + 1)
		return A + B;
	return sum_AB(A, B - 1) + B;
}
// Задача 3 сортировка середины
// случайные
template<typename T>
void fill_arr(T arr[], const int len, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < len; i++)
		arr[i] = rand() % (end - begin) + begin;
}
// вывод массива arr в консоль
template<typename T>
void show_arr(T arr[], const int len) {
	cout << '[';
	for (int i = 0; i < len; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
// 
template<typename T>
void midle_sort(T arr[], const int len) {
	int first_index = 0, last_index = 0;
	// индекс первого отриц элемента
	for (int i = 0; i < len; i++) 
		if (arr[i] < 0) {
			first_index = i;
			break;
		}
	// индекс последнего отриц элемента
	for (int i = len - 1; i >= 0; i--) 
		if (arr[i] < 0) {
			last_index = i;
			break;
		}

	// пузырьковая сортировка
		/*for (int i = last_index - 1; i > 0; i--)
			for (int j = first_index + 1; j < i; j++)
				if (arr[j] > arr[j + 1])
					swap(arr[j], arr[j + 1]);*/

		// быстрая сортировка
		sort(arr + first_index + 1, arr + last_index - 1);
}

	// Задача 4 сдвиг массива

template<typename T>
void move_arr(T arr[], const int len, int num) {
	if(num >= 0)
	for(int j = 0; j < num; j++)
		for (int i = len - 2; i >= 0; i--)
			swap(arr[i], arr[i + 1]);
	else
		for (int j = num; j < 0; j++)
			for (int i = 0; i < len - 1; i++)
				swap(arr[i], arr[i + 1]);
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
	// Задача 1
	/*cout << "12 - ";  type_of(12);
	cout << "9.11 - ";  type_of(9.11);
	cout << "\'T\' - ";  type_of('T');*/

	// Задача 2 Рекурсия суммы от А до В
	/*cout << "Введите 2 числа: ";
	cin >> n >> m;
	cout << "Сумма чисел от А до В = " << sum_AB(n, m) << "\n\n";*/

	// Задача 3 Сортировка элементов случайных чисел от -20 до 20
	/*cout << "изначальный массив: \n";
	const int size3= 20;
	int arr3[size3];
	fill_arr(arr3, size3, -20, 20);
	show_arr(arr3, size3);
	midle_sort(arr3, size3);
	cout << "итоговый массив:\n";
	show_arr(arr3, size3);*/

	// Задача 4
	cout << "изначальный массив:";
	const int size4 = 5;
	int arr4[size4]{ 1, 2, 3, 4, 5 };
	cout << "введите количество сдвигов: ";
	cin >> n;
	move_arr(arr4, size4, n);
	cout << "итоговый массив:";
	show_arr(arr4, size4);
	return 0;
}