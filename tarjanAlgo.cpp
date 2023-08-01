#include<bits/stdc++.h>
int const N = 1e5 + 10;
#define V 5
using namespace std;


unordered_map< int , vector < int >> adj;

void DFS( int u , vector< int >&disc , vector< int > &low , stack< int > &mystack , vector< bool > &presentInStack ){
    static int time = 0;
    disc[u] = low[u] = time;
    time += 1;
    mystack.push(u);
    presentInStack[u] = true;
    for( int v : adj[u] ){
        if( disc[v] == -1 ){    // if v is not visited
            DFS( v , disc , low , mystack , presentInStack );
            low[u] = min( low[u] , low[v] );
        }
        // Differentiate back edge and cross edge
        else if( presentInStack[v] ){
            low[u] = min( low[u] , disc[v] );
        }
    }
    if( low[u] == disc[u] ){   // if u is head node of SSC
        cout << "SCC is: ";
        while( mystack.top() != u ){
            cout << mystack.top() <<" ";
            presentInStack[mystack.top()] = false;
            mystack.pop();
        }
        cout << mystack.top() << endl;
        presentInStack[mystack.top()] = false;
        mystack.pop();
    }
}
void findSCC_Trajan(){
    vector< int > disc(V , -1) , low(V , -1);
    vector< bool > presentInStack(V , false);
    stack< int > mystack;
    for( int i = 0; i < V; i++ ){
        if( disc[i] == -1 ){
            DFS( i , disc , low , mystack , presentInStack);
        }
    }
}
int main(){


    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(1);
    adj[0].push_back(3);
    adj[3].push_back(4);

    findSCC_Trajan();
    
    return 0;
}