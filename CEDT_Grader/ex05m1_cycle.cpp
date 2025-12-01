#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;

bool solve(int n,int e){

    vector<vector<int> > vec(n);
    vector<bool> visited(n,false);

    for(int i =0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;

        vec[v1].push_back(v2);
        vec[v2].push_back(v1);
    }

    for(int i =0;i<n;i++){
        if(visited[i] == false){

            queue<pair<int,int> > q;

            q.push({i,-1});

            while(!q.empty()){
                int curr = q.front().first;
                int par  = q.front().second;
                
                q.pop();

                for(int next : vec[curr]){
                    if(next == par) continue;
                    if(visited[next] == true){
                        return true;
                    }
                    else{
                        q.push({next,curr});
                        visited[next] = true;
                    }
                }
            }
        }
    }

    return false;
}
int main(){
    int g;
    cin>>g;

    while(g--){
        int n,e;
        cin>>n>>e;
        if(e == 0){
            cout<<"NO\n";
            continue;
        }

        bool ans = solve(n,e);

        if(ans){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        

    }
}