<<<<<<< HEAD
#include<iostream> 
#include<thread> 
using namespace std;

class arrayModifier {
public:

	void operator()(int a[], int len) {
		for (int i = 0; i < len; i++) {
			a[i] *= 2;
		}
	}

	void invers(int a[], int len) {
		for (int i = 0; i < len; i++) {
			a[i] *= -1;
		}
	}
};

int main() {
	const int length = 5;
	int arr[length] = { 1, 2, 3, 4, 5 };
	arrayModifier obj;
	cout << "Output the array before threads\n";
	for (int i = 0; i < length; i++) {
		cout << arr[i] << ' ';
	}
	// Инициализируется объект функцией 
	thread arr_thread(obj, arr, length);
	// Инициализируется обычным открытым методом 
	thread arr_thread2(&arrayModifier::invers, &obj, arr, length);
	if (arr_thread.joinable()) arr_thread.join();
	if (arr_thread2.joinable()) arr_thread2.join();

	cout << "\nOutput th array after threads\n";
	for (int i = 0; i < length; i++) {
		cout << arr[i] << ' ';
	}
=======


int main()
{


	int test;

>>>>>>> f8606ea... test
	return 0;
}