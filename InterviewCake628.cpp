/*
Writing coding interview questions hasn't made me rich. Maybe trading Apple stocks will.

I have an array stock_prices_yesterday where:

    The indices are the time in minutes past trade opening time, which was 9:30am local time.
    The values are the price in dollars of Apple stock at that time.

For example, the stock cost $500 at 10:30am, so stock_prices_yesterday[60] = 500.

Write an efficient algorithm for computing the best profit I could have made from 1 purchase and 1 sale of 1 Apple stock yesterday.

No "shorting"—you must buy before you sell. You may not buy and sell in the same time step (at least 1 minute must pass).
*/

#include <iostream>					//std cout
#include "RandomNumberGenerator.h"	//RND(int min, int max)

using namespace std;

int main() {

	int stock_prices_yesterday [450];

	//fill an array for testing purposes.
	for (int i = 0; i < 450; i++) {
		stock_prices_yesterday[i] = RND(300, 700);
		cout << stock_prices_yesterday[i] << " ";
	}

	//My guess is O(n) is going to be best case scenario
	//will try a solution that passes through entire array 1 time.
	//worst case scenario is there is a negative profit if the prices do nothing but go down all day. 
	
	int lowest_price = stock_prices_yesterday[0];
	int max_profit = 0, test = 0;

	for (int j = 0; j < 450; j++) {

		if(stock_prices_yesterday[j] < lowest_price) {
			lowest_price = stock_prices_yesterday[j];
			cout << "lowest price so far: " << lowest_price << endl;
		}

		test = stock_prices_yesterday[j] - lowest_price;
		cout << "Profit for this minute: " << test << endl;

		if(max_profit < test) {
			max_profit = test; 
		}
	}

	cout << "Maximum profit = " << max_profit << endl;

	system("PAUSE");
}