#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int> &nums, vector<bool> &used, vector<int> &curr, vector<vector<int>> &ans) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // Skip used numbers
            if (used[i]) continue;

            // Skip duplicates: only use the first unused instance
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;

            // Choose
            used[i] = true;
            curr.push_back(nums[i]);

            // Explore
            backtrack(nums, used, curr, ans);

            // Unchoose (backtrack)
            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> used(nums.size(), false);

        backtrack(nums, used, curr, ans);
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    Solution sol;
    vector<vector<int>> result = sol.permuteUnique(nums);

    cout << "\nUnique permutations:\n";
    for (auto &perm : result) {
        cout << "[ ";
        for (int x : perm) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
