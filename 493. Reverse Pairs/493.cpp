#include <vector>
using namespace std;

class Solution {
public:

    pair<int, vector<int>> mergeAndCount(vector<int>& numsA, vector<int>& numsB) {

    }

    pair<int, vector<int>> sortAndCount(vector<int>& nums) {
        
        if (nums.size() <= 1) {
            return {0, nums};
        }

        int mid = nums.size() / 2;

        vector<int> A(nums.begin(), nums.begin() + mid);
        vector<int> B(nums.begin() + mid, nums.end());

        auto [ra, sortedA] = sortAndCount(A);
        auto [rb, sortedB] = sortAndCount(B);
        auto [r, sortedNums] = mergeAndCount(sortedA, sortedB);

        return {ra + rb + r, sortedNums};
    }

    int reversePairs(vector<int>& nums) {
        
    }
};