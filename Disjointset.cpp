#include<bits/stdc++.h>
using namespace std;
#define MX 100
int parent[MX];
int rankParent[MX];

void initSet(int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
        rankParent[i] = 0;

    }
}


int findParent(int x){
    if(x!= parent[x]){
        return parent[x] = findParent(parent[x]);
    }
    else{
        return x;
    }
}



void unionSet(int x,int y){

    int ax = findParent(x);
    int ay = findParent(y);

    if(ax==ay){
        return;
    }


    if(rankParent[ax]<rankParent[ay]){
        parent[ax]=ay;
    }
    else
        if(rankParent[ax]>rankParent[ay]){
            parent[ay]=ax;
        }


    else{
        parent[ay] = ax;
        rankParent[ax]++;
    }
}


void printSet(int n){
    for(int i=0;i<n;i++){
        cout<<"Node: "<<i <<" Parent: "<<parent[i]<<" Rank: "<<rankParent[i]<<endl;
    }
    cout<<endl;
}


int main(){
    int n;
    cin>>n;
    initSet(n);

    unionSet(0,1);
    unionSet(4,2);
    unionSet(3,1);
    unionSet(0,3);
    unionSet(0,4);
    printSet(n);
}
