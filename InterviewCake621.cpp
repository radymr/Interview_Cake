/*
you want to find the product of every integer except the integer at that index.

Write a function get_products_of_all_ints_except_at_index() that takes an array of integers and returns an array of the products.

For example, given:

  [1, 7, 3, 4]

your function would return:

  [84, 12, 28, 21]

by calculating:

  [7*3*4, 1*3*4, 1*7*4, 1*7*3]

Do not use division in your solution. 
*/

#include <windows.h>
#include <array>		//wanted to use for size of array function.
#include <iostream>

using namespace std; 

//INTEGER RND
int RND(int min, int max) {

	int RandomNumber = rand() % (max-min) + min;   // v3 in the range 1985-2014	

	return RandomNumber;
}

int main() {

	//test case
	int array_of_numbers[4];

	//instatiate array for testing. 
	for (int i = 0; i < 4; i++){
		array_of_numbers[i] = RND(1,9);
		cout << array_of_numbers[i] << " ";
	}

	//output array
	int outcome[4];
	int product = 1;

	cout << endl;

	for (int i = 0; i < 4; i++){

		for (int j = 0; j < 4; j++) {
			if(j != i)
				product = product * array_of_numbers[j];
		}

		outcome[i] = product;
		cout << product << endl;
		product = 1;
	}

	system("PAUSE");
}