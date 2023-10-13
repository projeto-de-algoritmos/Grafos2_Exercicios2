#include <bits/stdc++.h>
using namespace std;

int distancia[10006];

map<string,int> ids;

typedef struct prox{
    int index;
    int cost;
} prox;

typedef struct Item{
    int count;
    prox adja[10006];
} Item;

void dijkstra(int f, int l, Item lista[]){
    int pos = 0, c = 0;
    distancia[f] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int> >, greater< pair<int,int> > > pq;
    pq.push(make_pair(0, f));
    while(!pq.empty()){
        pos = pq.top().second;
        c = pq.top().first;
        pq.pop();
        if(pos==l){
            printf("%d\n", distancia[l]);
            return;
        }
        for(int i = 0; i<lista[pos].count; i++){
            if((lista[pos].adja[i].cost+c)<distancia[lista[pos].adja[i].index]){
                distancia[lista[pos].adja[i].index] = lista[pos].adja[i].cost+c;
                pq.push(make_pair(lista[pos].adja[i].cost+c, lista[pos].adja[i].index));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t, n, p, nr, cost, r;
    char line[20];
    cin >> t;
    for(int j=0; j<t; ++j){
        cin >> n;
        Item *cities = (Item*) malloc(10006*sizeof(Item));
        for(int k=0; k<n; ++k){
            cin >> line;
            ids[line] = k+1;
            cin >> p;
            for(int i=0; i<p; ++i){
                cin >> nr >> cost;
                cities[nr].adja[cities[nr].count].cost = cost;
                cities[nr].adja[cities[nr].count].index = k+1;
                cities[nr].count++;
            }
        }
        cin >> r;
        char c1[20], c2[20];
        for(int i=0; i<r; ++i){
            for(int j=0; j<n+1; ++j) distancia[j] = 1200000;
            cin >> c1 >> c2;
            dijkstra(ids[c1], ids[c2], cities);
        }
        free(cities);
        ids.clear();
    }
    return 0;
}