#include <iostream>
#include <vector>

// Given array of stock prices where ith element is stock price on day i,
// returns the max possible profit given one buy and one sell operation
int maxProfit(std::vector<int>& prices){
	if (prices.size() == 0) return 0;
	
	int ans = 0;
	int curMin, curMax;
	curMin = curMax = prices[0];

	for(int i=0; i < prices.size(); i++){
		curMin = std::min(curMin, prices[i]);
		curMax = std::max(curMin, prices[i]);

		ans = std::max((curMax-curMin), ans);
	}

	return ans;
}

bool testCase1(){
	std::vector<int> test{7,1,5,3,6,4};
	int excpected = 5;

	return (maxProfit(test) == excpected) ? true : false;
}

int main(int argc, char const *argv[])
{
	std::cout << "Test 1 ... ";
	testCase1() ? std::cout<<"Passed" : std::cout<<"Failed";

	std::cout << std::endl;
	return 0;
}