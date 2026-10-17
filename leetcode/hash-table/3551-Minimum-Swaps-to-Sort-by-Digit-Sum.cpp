class Solution {
public:
    long long digitSum(int n) {
        long long sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums);
        auto lambda = [this](int num1, int num2) {
            long long sum1 = digitSum(num1);
            long long sum2 = digitSum(num2);

            if (sum1 != sum2) return sum1 < sum2;
            return num1 < num2;
        };

        sort(sorted.begin(), sorted.end(), lambda);
        unordered_map<int, int> ind;
        for (int i = 0; i < n; i++) {
            ind[nums[i]] = i;
        }
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == sorted[i]) continue;
            int j = ind[sorted[i]];
            ind[nums[i]] = j;
            ind[nums[j]] = i;
            swap(nums[i], nums[j]);
            swaps++;
        }

        return swaps;
    }
};