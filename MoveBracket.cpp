#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;

        int balance = 0;
        int ans = 0;
        for(char c : s){
            if(c == '('){
                balance++;
            } else {
                balance--;
            }
            if(balance < 0){
                ans = max(ans, -balance);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
