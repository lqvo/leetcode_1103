#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int>ans(num_people);
        int sum0 = 0;
        int n = num_people;
        for (int i = 1; i <= n; i++)sum0 += i;
        if (sum0 > candies) {
            sum0 = 0;
            for (int i = 0; i < n; i++) {
                ans[i] = i + 1;
                sum0 += ans[i];
                if (sum0 > candies) { ans[i] = candies - sum0 + ans[i]; break; }
            }
            return ans;
        }
        if (sum0 == candies) {
            for (int i = 0; i < n; i++)
                ans[i] = i + 1;
            return ans;
        }
        int sum = 0;
        int i = 0;
        while (sum < candies) {
            sum += (i * n + 1 + (i + 1) * n) * n / 2;
            i++;
        }        
        i--;
        int k = n;
        while (sum > candies) {
            sum -= i * n + k;            
            k--;
        }
        for (int j = 0; j < k; j++)
            ans[j] = (1 + i) * i * n / 2 + (i + 1) * j +i + 1;
        for (int j = k + 1; j < n; j++)
            ans[j] = (1 + i) * i * n / 2 + (i + 1) * j + i + 1 - i * n - j - 1;
        int temp_sum = 0;
        for (int i : ans)temp_sum += i;
        ans[k] = candies - temp_sum;
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int>ans = sol.distributeCandies(1000,10);
    for (int i : ans)cout << i << "  ";

    return 0;
}