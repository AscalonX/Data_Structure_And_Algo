#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
    int n;
    cin>>n;
    int m = n;
    unordered_set<int> s;
    int sum = 0;
    while(n--){
        int tmp;
        cin>>tmp;
        if(s.find(tmp) != s.end() || tmp > m|| tmp <1){
            cout<<"NO\n";
            return 0;
        }
        s.insert(tmp);
        sum += tmp;
    }
    // cout<<((m)*(m+1))/2;
    if(sum != ((m)*(m+1))/2){
        cout<<"NO\n";
    }
    cout<<"YES\n";

}