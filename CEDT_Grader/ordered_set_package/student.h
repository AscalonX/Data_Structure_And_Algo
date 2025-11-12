#include <vector>
#include <unordered_set>

using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    unordered_set<T> s;

    for(T x : A){
        if(s.find(x) == s.end()){
            v.push_back(x);
            s.insert(x);
        }
    }
    for(T x : B){
        if(s.find(x) == s.end()){
            v.push_back(x);
            s.insert(x);
        }
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;

    unordered_set<T> s1;
    unordered_set<T> s2;
    for(T x : A){
        s1.insert(x);
    }
    for(T x : B){
        s2.insert(x);
    }

    for(T x : A){
        if(s1.find(x) != s1.end() && s2.find(x) != s2.end()){
            v.push_back(x);
        }
    }

    return v;
}
