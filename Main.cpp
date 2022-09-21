// ������
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<algorithm>
using namespace std;
// ������ 1
void type_of(int num) {
	cout << "INT\n";
}
void type_of(double num) {
	cout << "DOUBLE\n";
}
void type_of(char num){
cout << "CHAR\n";
}

// ������ 2 �������� ����� �� � �� �
int sum_AB(int A, int B) {
	if (B == A + 1)
		return A + B;
	return sum_AB(A, B - 1) + B;
}
// ������ 3 ���������� ��������
// ���������
template<typename T>
void fill_arr(T arr[], const int len, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < len; i++)
		arr[i] = rand() % (end - begin) + begin;
}
// ����� ������� arr � �������
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
	// ������ ������� ����� ��������
	for (int i = 0; i < len; i++) 
		if (arr[i] < 0) {
			first_index = i;
			break;
		}
	// ������ ���������� ����� ��������
	for (int i = len - 1; i >= 0; i--) 
		if (arr[i] < 0) {
			last_index = i;
			break;
		}

	// ����������� ����������
		/*for (int i = last_index - 1; i > 0; i--)
			for (int j = first_index + 1; j < i; j++)
				if (arr[j] > arr[j + 1])
					swap(arr[j], arr[j + 1]);*/

		// ������� ����������
		sort(arr + first_index + 1, arr + last_index - 1);
}

	// ������ 4 ����� �������

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
	// ������ 1
	/*cout << "12 - ";  type_of(12);
	cout << "9.11 - ";  type_of(9.11);
	cout << "\'T\' - ";  type_of('T');*/

	// ������ 2 �������� ����� �� � �� �
	/*cout << "������� 2 �����: ";
	cin >> n >> m;
	cout << "����� ����� �� � �� � = " << sum_AB(n, m) << "\n\n";*/

	// ������ 3 ���������� ��������� ��������� ����� �� -20 �� 20
	/*cout << "����������� ������: \n";
	const int size3= 20;
	int arr3[size3];
	fill_arr(arr3, size3, -20, 20);
	show_arr(arr3, size3);
	midle_sort(arr3, size3);
	cout << "�������� ������:\n";
	show_arr(arr3, size3);*/

	// ������ 4
	cout << "����������� ������:";
	const int size4 = 5;
	int arr4[size4]{ 1, 2, 3, 4, 5 };
	cout << "������� ���������� �������: ";
	cin >> n;
	move_arr(arr4, size4, n);
	cout << "�������� ������:";
	show_arr(arr4, size4);
	return 0;
}