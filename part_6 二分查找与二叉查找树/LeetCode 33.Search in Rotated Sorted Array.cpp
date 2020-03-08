#include <stdio.h>

#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
		int beg = 0;
		int end = nums.size()-1;
		while(beg <= end){
			int mid = (beg+end)/2;
			if(nums[mid] == target){
				return mid;
			}else if(nums[mid] < target){
				if(nums[beg] < nums[mid]){
					beg = mid+1;
				}else{//nums[beg] > nums[mid]
					if(nums[beg] > target){
						beg = mid+1;
					}else{
						end = mid-1;
					}
				}
			}else{// nums[mid] > target
				if(nums[beg] < nums[mid]){
					if(nums[beg] <= target){
						end = mid -1;
					}else{
						beg = mid+1;
					}
				}else{//nums[beg] > nums[mid] > target
					beg = mid+1;
				}
			}
		}
		return -1;
    }
};

int main(){
	int test[] = {9, 12, 15, 20, 1, 3, 6, 7};
	std::vector<int> nums;
	Solution solve;
	for (int i = 0; i < 8; i++){
		nums.push_back(test[i]);
	}
	for (int i = 0; i < 22; i++){
		printf("%d : %d\n", i, solve.search(nums, i));
	}
	return 0;
}
