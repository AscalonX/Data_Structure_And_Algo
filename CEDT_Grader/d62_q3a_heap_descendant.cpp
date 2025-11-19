#include <iostream>
#include <queue>

using namespace std;

int main(){
    int max_n;
    cin>>max_n;

    int start;
    cin>>start;

    queue<int> q;
    q.push(start);

    int cnt = 0;

    vector<int> vec;
    while(!q.empty()){
        int curr = q.front();
        // cout<<curr<< " ";
        vec.push_back(curr);
        q.pop();
        int left = curr*2 + 1;
        int right = curr*2 + 2;
        if(left < max_n){
            q.push(left);
            // cout<<left<<" ";
        }
        if(right< max_n){
            q.push(right);
            // cout<<right<<" ";
        }
    }

    cout<<vec.size()<<"\n";

    for(int x : vec){
        cout<<x<<" ";
    }
    return 0;
}