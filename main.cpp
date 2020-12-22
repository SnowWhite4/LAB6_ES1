#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

vector<double> manipulate_vector(vector<double> input_vector)
{
	vector<double> ret;

	sort(input_vector.begin(), input_vector.end());
	for (int i = 0; i < input_vector.size(); i++)  //sort nel vettore di ritorno
		ret.push_back(input_vector[i]);

	reverse(input_vector.begin(), input_vector.end());
	for (int i = 0; i < input_vector.size(); i++)  //reverse nel vettore di ritorno
		ret.push_back(input_vector[i]);
	//stack<double, vector<double>> sortedVector(input_vector);
	return ret;
}
int main()
{
	vector<double> v{ 0.5, 5, 2, 7, 0.1, 8.7, 5.1 };
	vector<double> manipulated = manipulate_vector(v);
	for (int i = 0; i < manipulated.size(); i++)  //sort nel vettore di ritorno
		cout << manipulated[i] << ", ";
	return 0;
}