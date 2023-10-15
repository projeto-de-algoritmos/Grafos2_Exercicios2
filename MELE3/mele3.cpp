#include <bits/stdc++.h>
using namespace std;

typedef struct nxt{
    int offset;
    int fim;
} nxt;

int distancia[1006];
int vis[1006];

typedef struct Item{
    int dado;
    int count;
    nxt prox[50006];
} Item;

void dijkstra(int f, int l, Item lista[]){
    int pos = 0, c = 0, v = 0, kx = 0, ajuste = 0, falta = 0, d = 0;
    priority_queue<pair<int,int>,vector<pair<int,int> >, greater< pair<int,int> > > pq;
    distancia[f] = 0;
    pq.push(make_pair(0, f));
    while(!pq.empty()){
        pos = pq.top().second;
        c = pq.top().first;
        pq.pop();
        d = distancia[lista[pos].dado];
        if(l==pos){
            printf("%d\n", d*5);
            return;
        }
        vis[lista[pos].dado] = 1;
        for(int i = 0; i<lista[pos].count; ++i){
            if(vis[lista[pos].prox[i].fim]==1) continue;
            falta = 0;
            v = abs(lista[pos].dado-lista[pos].prox[i].fim);
            if(d!=0){
                if(lista[pos].prox[i].offset==1){ // elevador reverso, inicia atrasado na outra ponta (offset+1)
                    ajuste = (d/v+1)%2;
                    if(ajuste==1){
                        if(d%v==0) falta = v;
                        else falta = v-(d%v);
                    } else {
                        if(d%v==0) falta = 0;
                        else falta = (v-d%v)+v;
                    }
                }
                else {                           // elevador normal, inicia com os outros
                    ajuste = (d/v)%2;
                    if(ajuste==0){
                        if(d%v==0) falta = 0;
                        else falta = (v-d%v)+v;
                    } else {
                        if(d%v==0) falta = v;
                        else falta = v-(d%v);
                    }
                }
            }
            if((v+c+falta)<distancia[lista[pos].prox[i].fim]){
                distancia[lista[pos].prox[i].fim] = falta+v+c; // ?
                kx = lista[pos].prox[i].fim;
                pq.push(make_pair(distancia[lista[pos].prox[i].fim], kx));
            }   
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int k, n, a, b, id = 0;
    cin >> k >> n;
    for(int i=0;i<1007;++i) distancia[i] = 1000000007;
    Item *elevators = (Item*) calloc(1006, sizeof(Item));
    for(int j=0; j<n; ++j){
        cin >> a;
        cin >> b;
        elevators[a].dado = a;
        elevators[a].prox[elevators[a].count].fim = b;
        elevators[a].prox[elevators[a].count].offset = 0;
        elevators[a].count++;
        elevators[b].dado = b;
        elevators[b].prox[elevators[b].count].fim = a;
        elevators[b].prox[elevators[b].count].offset = 1;
        elevators[b].count++;
    }
    dijkstra(1, k, elevators);
    return 0;
}