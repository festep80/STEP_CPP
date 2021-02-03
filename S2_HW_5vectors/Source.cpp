#include<iostream>
#include<vector>
#include<ctime>
#include <fstream>
#include <algorithm>
#include <random>

using namespace std;

int main()
{
	srand(time(NULL));

	vector<int>v1, v2(10, 0), v3, v4, v5;
	
	for (int i = 0; i < 10; i++)
	{
		int x;
		cout << "Enter " << i + 1 << " element: "; cin >> x; v1.push_back(x);
	}
	int numbersV3 = 0;
	cout << "\n\nEnter numbers of elements for v3: "; cin >> numbersV3;
	for (int i = 0; i < numbersV3; i++)
	{
		v3.push_back(rand() % 100 + 1);
	}
	v4 = v1;
	auto it5 = v5.cbegin();
	v5.insert(it5, v3.begin() + 1, v3.end() - 1);
	/*for (int i = 1; i < v3.size() - 1; i++)
	{
		v5[i] = v3[i];
	}*/
	cout << "\n==========================\n" << endl;
	for (int i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << "\t";
	}
	ofstream fout;
	fout.open("Numbers.txt");
	if (fout.is_open())
	{
		for (int i = v1.size()-1; i >= 0; i--)
		{
			fout << v1[i] << "\t";
		}
	}
	fout.close();
	cout << "\n==========================\n" << endl;
	for (int i = 0; i < v2.size(); i++)
	{
		v2[i] = i + 1;
	}
	auto engine = default_random_engine{};
	shuffle(begin(v2), end(v2), engine);
	auto it2 = v2.cbegin();
	v2.erase(it2 + 1);
	v2.pop_back();
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << "\t";
	}
	cout << "\n==========================\n" << endl;	
	int step = 0;
	int n = v4.size();
	for (int i = 0; i < n; i++)
	{
		auto it4 = v4.cbegin()+step;
		v4.insert(it4 + 1, v4[step]);
		step += 2;
	}
	cout << "\n==========================\n" << endl;
	v5.clear();
	for (int i = 0; i < v4.size(); i+=2)
	{
		v5.push_back(v4[i]);
	}
	for (int i = 0; i < v5.size(); i++)
	{
		v5[i] = v5[i] / 2;
	}
	for (int i = 0; i < v5.size(); i++)
	{
		cout << v5[i] << "\t";
	}
	cout << "\n==========================\n" << endl;
	v4.swap(v5);
	system("pause");
	return 0;
}