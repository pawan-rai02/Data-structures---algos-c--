#include<iostream>
using namespace std;

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <array>
#include <bitset>





void BFS(int G[][7], int start, int n){
    int i=start;
    queue<int>q;
    int visited[7]={0};
    cout<<i<<" ";
    visited[i]=1;
    q.push(i);
    while(!q.empty()){
        i=q.front();
        q.pop();
        for(int j=1;j<n;j++){
            if(G[i][j]==1 && visited[j]==0){
                cout<<j<<" ";
                visited[j]=1;
                q.push(j);
            }
        }
    }
}


void DFS(int G[][7], int start, int n){
    static int visited[7]={0};
    if(visited[start]==0){
        cout<<start<<" ";
        visited[start]=1;
        for(int j=1;j<n;j++){
            if(G[start][j]==1 && visited[j]==0) DFS(G,j,n);
        }
    }
}



   int main(){ 
    int G[7][7]={
        {0,0,0,0,0,0,0},{0,0,1,1,0,0,0},{0,1,0,0,1,0,0},{0,1,0,0,1,0,0},{0,0,1,1,0,1,1},{0,0,0,0,1,0,0},{0,0,0,0,1,0,0}
        };

        cout<<"Breadth First Search  :";
        BFS(G,1,7);
        cout<<"\n"<<"Depth First Search :";
        DFS(G,1,7);
    return 0;
}