#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main(){
    int n,e,k;
    cin>>n>>e>>k;

    vector<vector<int> > vec(n+5);


    for(int i =0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;

        vec[v1].push_back(v2);
        vec[v2].push_back(v1);
    }
    int max_count = -1;
    for(int i =0;i<n;i++){
        queue<int> q;
        vector<bool> visited(n+2,false);

        q.push(i);
        visited[i] = true;
        int cnt = 0;
        for(int j =0;j<k;j++){
            int s = q.size();
            for(int l = 0;l<s;l++){
                int f = q.front();

                q.pop();

                for(int x : vec[f]){
                    if(visited[x] == false){
                        q.push(x);
                        cnt += 1;
                        visited[x] = true;
                    }
                }
            }
        }
        max_count = max(max_count,cnt+1);
    }
    cout<<max_count;
}