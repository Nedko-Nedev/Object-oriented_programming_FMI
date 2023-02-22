#include <iostream>
using std::cin;
using std::cout;
using std::endl;
test test
int getNum(const int* arr, int n, char ch) 
{
	int br = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > ch)
		{
			br++;
		}
	}
	return br;
}

void task1()
{
	int n;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; ++i) 
	{
		cin >> arr[i];
	}

	char ch;
	cin >> ch;
	
	cout << getNum(arr, n, ch) << endl;
	delete[] arr;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int min2(const int& a, const int& b)
{
	return min(a, b);
}

int min3(int& a, int& b)
{
	return min2(a, b);
}

int min4(const int* a, const int* b) 
{
	return min2(*a, *b);
}

int min5(int* a, int* b) 
{
	return min3(*a, *b);
}

void task2() 
{
	const int a = 3, b = 4;
	int c = 5, d = 2;
	cout << min(a, b) << endl;
	cout << min(c, d) << endl;

	cout << min2(a, b) << endl;
	cout << min2(c, d) << endl;

	// cout << min3(a, b) << endl;
	// cout << min3((1 + 8), (2 + 5)) << endl;
	cout << min3(c, d) << endl;

	cout << min4(&a, &b) << endl;
	cout << min4(&c, &d) << endl;

	// cout << min5(&a, &b) << endl;
	cout << min5(&c, &d) << endl;
}

struct Student
{
	unsigned int fn;
	char name[100];
};

void initStudent(Student& st) {
	cin.getline(st.name, 100);
	cin >> st.fn;
}

void task3() 
{
	Student s;
	initStudent(s);
	cout << s.name << endl;
	cout << s.fn << endl;
	Student st = { 10, "Gosho" };
	Student st2 = { 20, "Sasho" };

	Student* pSt = &st;
	pSt = &st2;
	pSt->fn = 30;

	const Student* pCSt = &st;
	pCSt = &st2;
	// pCSt->name = "pesho";
	// pCSt->fn = 30;

	Student* const cPSt = &st;
	// cPSt = &st2;
	cPSt->fn = 40;

	const Student* const cpCSt = &st;
	// cpCSt = &st2;
	// cpCSt->fn = 40;

	// Student& refNotDefined;

	Student& refSt = st;
	refSt = st2;
	refSt.fn = 20;

	const Student& refCSt = st;
	// refCSt = st2;
	// refCSt.fn = 50;
}

int main()
{
	// task1();
	// task2();
	task3();

	return 0;
}
