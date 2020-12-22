#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;

bool notNegative(double d)
{
	if (d >= 0)
		return true;
	return false;
}

vector<double> manipulate_vector(vector<double>& input_vector)
{
	vector<double> ret;
	vector<double> origin = input_vector;
	origin.resize(origin.size() / 2);

	sort(input_vector.begin(), input_vector.end());
	for (int i = 0; i < input_vector.size(); i++)  //sort nel vettore di ritorno
		ret.push_back(input_vector[i]);

	reverse(input_vector.begin(), input_vector.end());
	for (int i = 0; i < input_vector.size(); i++)  //reverse nel vettore di ritorno
		ret.push_back(input_vector[i]);
	
	double sum = accumulate(input_vector.begin(), input_vector.end(), 0.0);
	ret.push_back(sum);   //somma degli elementi in ret

	double sum1 = accumulate(origin.begin(), origin.end(), 0.0); 
	ret.push_back(sum1);   //somma degli elementi della prima metà in ret

	double num_not_negative = count_if(input_vector.begin(), input_vector.end(), notNegative);
	ret.push_back(num_not_negative);   //conta numeri positivi

	return ret;
}
int main()
{
	vector<double> v{ 0.5, 5, -2, 7, 0.1, 8.7, 5.1 }; //24.4
	vector<double> manipulated = manipulate_vector(v);
	for (int i = 0; i < manipulated.size(); i++)  //sort nel vettore di ritorno
		cout << manipulated[i] << ", ";
	return 0;
}