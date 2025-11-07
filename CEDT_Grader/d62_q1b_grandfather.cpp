#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;
unordered_map<string,string> mp;

string get_godfather(string a){
    if(mp.find(a)!=mp.end()){
        string father = mp[a];
        if(mp.find(father) != mp.end()){
            return mp[father];
        }
        else{
            return "NOLOL";
        }
    }
    else{
        return "NOLOL";
    }
}

int main(){
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(0);

    int n,m;
    cin>>n>>m;

    while(n--){
        string F,S;
        cin>>F>>S;
        mp[S] = F;
    }
    while(m--){
        string A,B;
        cin>>A>>B;

        string GF_A,GF_B;
        GF_A = get_godfather(A);
        GF_B = get_godfather(B);
        // cout<<"GF_A : "<<GF_A<<"\n";

        // cout<<"GF_B : "<<GF_B<<"\n";
        if(GF_A == "NOLOL" || GF_B == "NOLOL" || A==B){
            cout<<"NO\n";
        }
        else if(GF_A == GF_B){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}