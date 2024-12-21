#include <vector>
using namespace std;

class Solution {
public:

    pair<int, vector<int>> mergeAndCount(vector<int>& numsA, vector<int>& numsB) {
        int i = 0, j = 0, inversoes = 0;
        vector<int> merged;

        for (int i = 0; i < numsA.size(); i++) {
            while (j < numsB.size() && numsA[i] > 2LL * numsB[j]) {
                j++;
            }
            inversoes += j;
        }
        
        i = 0, j = 0;
        while (i < numsA.size() && j < numsB.size()) {
            if (numsA[i] <= numsB[j]) {
                merged.push_back(numsA[i++]);
            } else {
                merged.push_back(numsB[j++]);
            }
        }

        while (i < numsA.size()) merged.push_back(numsA[i++]);
        while (j < numsB.size()) merged.push_back(numsB[j++]);

    return {inversoes, merged};
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
        auto [inversoes, sorted] = sortAndCount(nums);

        return inversoes;
    }
};