//
// Created by kirin on 2021-11-23.
//

#include <iostream>
#include <vector>

using namespace std;

//친구비
vector<int> parent;

//Find 연산
int findParent(int node){
    if(parent[node]<0) //값이 음수면 루트 정점
        return node;
    return parent[node] = findParent(parent(node)); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y){
    int xp = findParent(x); //정점 찾기
    int yp = findParent(y);

    if(xp == yp){ //같은 집합에 있다면 유니온 할 수 없음
        return;
    }
    if(parent[xp] > parent[yp]){  //새로운 루트 xp
        parent[yp] = xp;
    }
    else  //새로운 루트 yp
        parent[xp] = yp;
}

int friendshipCost(int n){
    int sum = 0 ; //총 필요한 친구비
    for(int i=1; i<=n; i++){
        // 정점 만나기 전까지는 타고 타고 올라감
        if(parent[i] <0){ //루트 정점이라면
            sum += -parent[i]; //필요한 친구비를 음수로 저장해두었으니 - 붙여서 더해야함
        }
    }
    return sum;
}
int main(){
    int n, m, k, v, w, cost;

    //입력
    cin>>n>>m>>k; //n: 학생 수, m: 친구 관계 수, k: 갖고 있는 돈
    parent.assign(n+1,0);
    for(int i=1; i<=n; i++){
        cin>>cost; //각 학생의 친구비용
        parent[i] = -cost; //루트 정점에 필요한 친구비(음수)를 저장
    }

    //연산
    while(m--){
        cin >> v >> w; //친구 관계 (v,w) 서로 친구
        unionInput(v,w);
    }

    int ans = friendshipCost(n); //필요한 최소비용

    if(ans<=k){
        cout<<ans; //갖고있는 돈보다 적다면
    }
    else
        cout<<"Oh no";//갖고있는 돈보다 많이 필요하다면

    return 0;
}