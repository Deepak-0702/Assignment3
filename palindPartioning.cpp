#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void backtrack(int index, string &s, vector<string> &path, vector<vector<string>> &result) {
        if (index == s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                // Explore further
                backtrack(i + 1, s, path, result);
                // Backtrack
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        backtrack(0, s, path, result);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cout << "Enter string: ";
    cin >> s;

    Solution sol;
    vector<vector<string>> partitions = sol.partition(s);

    cout << "\nAll palindrome partitions:\n";
    for (auto &vec : partitions) {
        cout << "[ ";
        for (auto &word : vec) cout << "\"" << word << "\" ";
        cout << "]\n";
    }

    return 0;
}
