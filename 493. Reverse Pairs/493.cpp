#include <vector>
using namespace std;

class Solution {
public:
    int mergeAndCount(vector<int>& nums, int l, int m, int r) {
        int qtdInversoes = 0;
        int i = l, j = m + 1, k = 0;

        for (int i = l; i <= m; i++) {
            while (j <= r && nums[i] > 2LL * nums[j]) {
                j++;
            }
            qtdInversoes += j - (m + 1);
        }

        vector<int> aux(r - l + 1);
        i = l, j = m + 1;

        while (i <= m && j <= r) {
            if (nums[i] <= nums[j]) {
                aux[k++] = nums[i++];
            } else {
                aux[k++] = nums[j++];
            }
        }

        while (i <= m) aux[k++] = nums[i++];
        while (j <= r) aux[k++] = nums[j++];

        for (i = l, k = 0; i <= r; i++, k++) {
            nums[i] = aux[k];
        }

        return qtdInversoes;
    }

    int sortAndCount(vector<int>& nums, int l, int r) {
        if (l >= r) return 0;

        int m = l + (r - l) / 2;
        int count = 0;

        count += sortAndCount(nums, l, m);
        count += sortAndCount(nums, m + 1, r);
        count += mergeAndCount(nums, l, m, r);

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return sortAndCount(nums, 0, nums.size() - 1);
    }
};
