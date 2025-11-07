#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(0);

    int n,m,k;
    cin>>n>>m>>k;
    vector<int> n_vec(n);
    vector<int> m_vec(m);
    for(int i =0 ;i<n;i++){
        cin>>n_vec[i];
    }
    for(int i=0;i<m;i++){
        cin>>m_vec[i];
    }


    sort(n_vec.begin(),n_vec.end());
    // cout<<"\n";
    // for(int x : n_vec){
    //     cout<<x<<" ";
    // }
    // cout<<"\n";
    for(int question : m_vec){

        int upper_value = question+k;
        int lower_value = question-k;
        // cout<<"("<<upper_value<<"|"<<lower_value<<")\n";
        auto upper_position = upper_bound(n_vec.begin(),n_vec.end(),upper_value);
        auto lower_position = lower_bound(n_vec.begin(),n_vec.end(),lower_value);
        cout<<(upper_position-lower_position)<<" ";
    }
}