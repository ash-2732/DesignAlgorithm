#include<bits/stdc++.h>
using namespace std;
const long long N = 1e5+9, M = 1e18;
vector<pair<long long,long long>> graph[N];
vector<bool>visted(N,false);
vector<long long> dist(N,M);
vector<pair<long long,long long>>parent(N);

int main(){
    int n , m;
    cin >> n >> m;
    for( int i = 0; i < m; i++ ){
        long long x,y,wt;
        cin >> x >> y >> wt;
        graph[x].push_back({y,wt});
    }

    set< pair < int , int >> st;

    st.insert({0,0});
    dist[0] = 0;
    parent[0] = {-1,0};

    while(st.size()>0){
        auto node = *st.begin();
         st.erase(st.begin());
        long long v = node.second;
        long long dis = node.first;
        for( auto c : graph[v] ){
            long long cv = c.first;
            long long wt = c.second;
            int np = parent[v].second;
            if(dist[v]+wt<dist[cv]){
                dist[cv] = dist[v] + wt;
                st.insert({dist[cv],cv});
                parent[cv] = {v,parent[v].second+1};
            }
            else if(dist[v]+wt==dist[cv]){
                if((parent[v].second+1)<parent[cv].second){
                    parent[cv].second = parent[v].second+1;
                    parent[cv].first = v;
                }
                else if((parent[v].second+1)==parent[cv].second){
                    if(v<parent[cv].first){
                        parent[cv].first = v;
                    }
                }
            }
        }
    }
    for( int i = 1; i< 2; i++ ){
        if( dist[i] == M){
            cout << "NOT REACHABLE" << endl;
        }
        else{
            vector< int >ans;
            ans.push_back(1);
            int k = 1;
            while( parent[k].first+1 ){
                ans.push_back(parent[k].first);
                k = parent[k].first;
            }
            for( int j = ans.size()-1; j >= 0;j-- ){
                cout << ans[j] << endl;
            }
        }
    }
}