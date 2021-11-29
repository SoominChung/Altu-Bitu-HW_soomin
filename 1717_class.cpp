//
// Created by kirin on 2021-11-23.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//find 연산
int findParent(int node){
    if(parent[node] < 0){ //값이 음수면 루트 정점
        return node; //노드 값 리턴
    }
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//union 연산
void unionInput(int x, int y){
    int xp = findParent(x); //각 노드의 정점 찾음
    int yp = findParent(y);

    if(xp == yp) //같은 집합에 있다면 유니온 할 수 없다.
        return ;
    }
    if(parent[xp]<parent[yp]){ //새로운 루트 yp
        parent[xp] += parent[yp]; //rank 올리고
        parent[xp] = yp; //xp의 정점을 yp로 설정
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, cmd, a ,b;

    //입력
    cin>>n>>m;
    parent.assign(n+1, -1); //idx=1부터 시작하기 위해 크기 n+1로 만듦
    while(m--){
        cin>>cmd>>a>>b;

        //연산
        if(cmd == 0){
            //union
            unionInput(a,b);
        }
        if(cmd == 1){
            //굳이 왜 함수 거치느냐 (parent[a]==parent[b]) 안하고?-> 압축 안됐었을 수도
            if(findParent(a) == findParent(b)){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }
}