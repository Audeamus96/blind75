#include <iostream>
#include <unordered_set>
#include <vector>

bool containsDuplicate(std::vector<int>& nums) {
	std::unordered_set<int> dupe;

	for(int i=0; i < nums.size(); i++){
		if (dupe.find(nums[i]) == dupe.end())
			dupe.insert(nums[i]);
		else
			return true;
	}
	
	return false; 
}

bool test1() { 
	std::vector<int> test {1,2,3,1};
	bool expected = true;
	return (containsDuplicate(test) == expected) ? true : false;
}
bool test2() { 
	std::vector<int> test {1,2,3,4};
	bool expected = false;
	return (containsDuplicate(test) == expected) ? true : false;
}
bool test3() {
	std::vector<int> test {1,1,1,3,3,4,3,2,4,2};
	bool expected = true;
	return (containsDuplicate(test) == expected) ? true : false;
}

int main(int argc, char** argv) {
	std::cout << "Test 1 ... ";
	test1() ? std::cout<< "Passed" : std::cout<<"Failed";
	std::cout << std::endl;
	std::cout << "Test 2 ... ";
	test2() ? std::cout<< "Passed" : std::cout<<"Failed";
	std::cout << std::endl;
	std::cout << "Test 3 ... ";
	test3() ? std::cout<< "Passed" : std::cout<<"Failed";
	std::cout << std::endl;
}
