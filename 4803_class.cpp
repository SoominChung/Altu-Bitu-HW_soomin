//
// Created by kirin on 2021-11-23.
//

#include <iostream>
#include <vector>

using namespace std;

vector<bool> cycle;
vector<int> parent;

//find 연산
int findParent(int node){
    if(parent[node] < 0){ //값이 음수면 루트 정점
        return node;
    }
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//union 연산
void unionInput(int x, int y){
    int xp = findParent(x); //두 node의 정점 찾기
    int yp = findParent(y);

    if(xp == yp){ //같은 집합에 있다면 유니온 불가능
        cycle[xp] = true;
        return ;
    }
    if(cycle[xp]||cycle[yp]){ //둘 중 하나라도 사이클이 있으면 표시
        cycle[xp] = cycle[yp] = true;
    }
    if(parent[xp]<parent[yp]){ //새로운 루트 xp
        parent[xp] += parent[yp]; //rank 추가하고
        parent[yp] = xp; //parent로 삼는다
    }
    else{ //새로운 루트 yp
        parent[yp] += parent[xp]; //rank 추가
        parent[xp] = yp; //parent로 경로 추가
    }
}

int cntTree(int n){
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(parent[i] <0 && !cycle[i]){ //루트 정점인데 사이클도 없을 떄
            cnt++; //개수 추가
        }
    }
    return cnt;
}

void printResult(int num, int cnt){
    //tree 개수에 따라 출력
    cout<<"Case "<<num;
    if(cnt==0)
        cout<<": No trees.\n";
    else if(cnt==1)
        cout<<": There is one tree.\n";
    else
        cout<<": A forest of "<<cnt<<"trees.\n";
}

int main(){
    int n,m,a,b, test_case = 0;

    while(true){
        test_case++;

        //입력
        cin>>n>>m;
        if(n==0 && m==0){ //종료 조건
            break;
        }
        parent.assign(n+1, -1); //idx 1부터 쓸거라 n+1로 만듦
        cycle.assign(n+1, false);
        while(m--){//무방향 그래프
            cin>>a>>b;
            unionInput(a,b);
        }

        //연산
        int tree_cnt = cntTree(n);

        //출력
        printResult(test_case, tree_cnt);
    }
}