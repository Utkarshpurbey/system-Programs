#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen(“input.txt”, “r”, stdin);
        freopen(“output.txt”, “w”, stdout);
    #endif
    vector<int> ans;
    cin>>ans;

    cout<<"vector"<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }    

    return 0;
}