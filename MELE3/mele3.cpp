#include <bits/stdc++.h>
using namespace std;

typedef struct nxt{
    int offset;
    int fim;
} nxt;

typedef struct Item{
    int dado;
    int count;
    int vis;
    nxt prox[50006];
} Item;

int tempo = 0;

void dijkstra(int f, int l, Item lista[]){
    int pos = 0, c = 0, v = 0, kx = 0, ajuste = 0, falta = 0;
    priority_queue<pair<int,int>,vector<pair<int,int> >, greater< pair<int,int> > > pq;
    pq.push(make_pair(0, f));
    while(!pq.empty()){
        int mint = 47483647;
        pos = pq.top().second;
        c = pq.top().first;
        tempo = c;
        pq.pop();
        if(l==pos){
            printf("%d\n",tempo*5);
            return;
        }
        lista[pos].vis = 1;
        for(int i = 0; i<lista[pos].count; ++i){
            if(lista[lista[pos].prox[i].fim].vis==1) continue;
            falta = 0;
            v = abs(lista[pos].dado-lista[pos].prox[i].fim);
            if(tempo!=0){
                if(lista[pos].prox[i].offset==1){
                    ajuste = (tempo/v+1)%2;
                    if(ajuste==1){
                        if(tempo%v==0) falta = v;
                        else falta = v-(tempo%v);
                    } else {
                        if(tempo%v==0) falta = 0;
                        else falta = (v-tempo%v)+v;
                    }
                }
                else {
                    ajuste = (tempo/v)%2;
                    if(ajuste==0){
                        if(tempo%v==0) falta = 0;
                        else falta = (v-tempo%v)+v;
                    } else {
                        if(tempo%v==0) falta = v;
                        else falta = v-(tempo%v);
                    }
                }
            }
            if((v+c+falta)<mint){
                mint = falta+v+c;
                kx = lista[pos].prox[i].fim;
                pq.push(make_pair(mint, kx));
            }   
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int k, n, a, b, id = 0;
    cin >> k >> n;
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