#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int v,e;
    cin>>v>>e;

    vector<bool> visited(v+2,false);

    vector<vector<int> > vec(v+2);

    for(int i =0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;

        vec[v1].push_back(v2);
        vec[v2].push_back(v1);
    }

    int total_island = 0;

    for(int i =1;i<=v;i++){
        if(visited[i] == false){
            // cout<<"START : "<<i<<"\n";
            queue<int> q;

            q.push(i);

            visited[i] = true;

            while(!q.empty()){
                int curr = q.front();

                q.pop();

                for(int x : vec[curr]){
                    // cout<<"YA HOO "<<x<<" \n";
                    if(visited[x] == false){

                        q.push(x);
                        visited[x] = true;
                    }
                }
            }
            total_island += 1;
        }
        // total_island += 1;
    }

    cout<<total_island<<"\n";

}