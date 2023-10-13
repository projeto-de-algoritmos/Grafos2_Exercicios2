#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int distancia[10006];

map<string,int> ids;

typedef struct Item{
    int index;
    int cost;
    struct Item *prox;
} Item;

Item *insereNo(Item *cabeca, int ind, int custo){
    Item *n = (Item*) malloc(sizeof(Item));
    n->prox = cabeca->prox;
    n->cost = custo;
    n->index = ind;
    cabeca->prox = n;
    return n;
}

void dijkstra(int f, int l, Item lista[]){
    int pos = 0, c = 0;
    Item trash;
    distancia[f] = 0;
    priority_queue<pii,vector<pii>, greater< pii > > heap;
    heap.push(pii(0, f));
    while(!heap.empty()){
        pos = heap.top().second;
        c = heap.top().first;
        heap.pop();
        trash = lista[pos];
        while(trash.prox!=NULL){
            if((trash.prox->cost+c)<distancia[trash.prox->index]){
                heap.push(make_pair((trash.prox->cost+c), (trash.prox->index)));
                distancia[trash.prox->index] = trash.prox->cost+c;
            }
            trash = *trash.prox;
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
        Item *cities = (Item*) malloc((10006)*sizeof(Item));
        for(int k=0; k<n; ++k){
            cin >> line;
            ids[line] = k+1;
            cin >> p;
            for(int i=0; i<p; ++i){
                cin >> nr >> cost;
                insereNo(&cities[nr], k+1, cost);
            }
        }
        cin >> r;
        char c1[20], c2[20];
        for(int i=0; i<r; ++i){
            for(int j=0; j<n+1; ++j) distancia[j] = 1200000;
            cin >> c1 >> c2;
            int kx = ids[c1];
            int ky = ids[c2];
            dijkstra(kx, ky, cities);
            printf("%d\n", distancia[ky]);
        }
        free(cities);
        ids.clear();
    }
    return 0;
}