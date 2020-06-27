#include <vector>

using std::vector;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> sum(2);
            for (int i = 0; i < nums.size() - 1; i++) {
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[i] + nums[j] == target) {
                        sum[0] = i;
                        sum[1] = j;
                        return sum;
                    }
                }
            }
            return sum;
        }
};

int main() {
    return 0;
}