#include <iostream>
#include <vector>

using namespace std;

int main(){
    int k;
    cin>>k;

    // vector<vector<int> > vec(k,vector<int>(k));

    vector<int> deg(k,0);

    int max_cnt = -1;
    for(int i =0;i<k;i++){
        int cnt = 0;
        for(int j=0;j<k;j++){
            // cin>>vec[i][j];
            int tmp;
            cin>>tmp;
            
            cnt += tmp;

            
        }
        max_cnt = max(max_cnt,cnt);
        deg[cnt] += 1;
    }

    for(int i =0;i<=max_cnt;i++){
        cout<<deg[i]<<" ";
    }

}