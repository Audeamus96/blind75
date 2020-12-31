#include <vector>
#include <iostream>
#include <unordered_map>

// Question #1, Given array of integers nums and integer target, return indices
// of the two numbers that add up to target.

// unordered_map was chosen  since find() constant average time complexity. 

std::vector<int> twoSum(std::vector<int> &nums, int target){
	std::vector<int> ans;
	std::unordered_map<int,int> map;	//map of form <nums[i], i>

	for (int i=0; i < nums.size(); i++) {
		int diff = target - nums[i];	 
		if(map.find(diff) != map.end()) {   // if diff is in map
			ans.push_back(map[diff]);       // add indexes to ans and return
			ans.push_back(i);
			break;
		}
		map[nums[i]] = i;
	}
	return ans;
}

// Tests

bool testCase1(){
	std::vector<int> expectedAns{0,1};
	std::vector<int> test{2,7,11,15};
	
	return (expectedAns == twoSum(test,9)) ? true : false;
}

bool testCase2(){
	std::vector<int> expectedAns{1,2};
	std::vector<int> test{3,2,4};
	
	return (expectedAns == twoSum(test,6)) ? true : false;
}

bool testCase3(){
	std::vector<int> expectedAns{0,1};
	std::vector<int> test{3,3};
	
	return (expectedAns == twoSum(test,6)) ? true : false;
}

int main(int argc, char** argv) {	
	
	std::cout << "Test 1 ... ";
	testCase1() ? std::cout<<"Passed" : std::cout<<"Failed";
	std::cout << std::endl << "Test 2 ... ";
	testCase2() ? std::cout<<"Passed" : std::cout<<"Failed";
	std::cout << std::endl << "Test 3 ... ";
	testCase3() ? std::cout<<"Passed" : std::cout<<"Failed";
	std::cout << std::endl;
	return 0;
}
