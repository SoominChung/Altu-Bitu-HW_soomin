//
// Created by kirin on 2021-11-02.
//

#include <iostream>
#include <vector>

using namespace std;

// A->B로 가는 배열 최솟값 ,간선이 여러 개일 수 있다 (중복 간선)
// 플로이드 워셜

const int INF = 1e7; //최대 n-1개의 간선을 지나게 됨

void floydWarshall(int n, vector<vector<int>> &graph){
    for(int k=1; i<=n; k++){ //중간에 거치는 정점을 구현하기 위한 3중 for문
        for(int i=1; i<=n; i++){ //정점 i에서 j로 간다
            for(int j=1; j<=n; j++){
                int dist = graph[i][k] + graph[k][j]; // i -> k -> j (중간에 k를 거쳐서 i에서 j로 감)
                graph[i][j] = min(graph[i][j], dist); //i->j와 i->k->j 중 더 짧은 경로
            }
        }
    }
}

int main(){

    int n,m,a,b,c;

    //입력
    cin>>n>>m; //n: 도시 개수, m: 한 도시에서 출발해서 다른 도시에 도착하는 버스
    vector<vector<int>> graph(n+1, vector<int>(n+1,INF));
    for(int i=1; i<=n; i++){
        graph[i][i] =0; //자기 자신-> 자기 자신의 거리는 0이므로 초기화
    }

    while(m--){
        cin>>a>>b>>c; //a: 버스 시작 도시, b: 도착 도시, c:한 번 타는데 드는 비용
        graph[a][b] = min(graph[a][b],c); //중복 간선 들어올 수 있으므로 최솟값 사용
    }

    //연산
    floydWarshall(n, graph);

    //출력
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<((graph[i][j]==INF)?0:graph[i][j])<<' '; //경로가 없는 경우 INF값이 들어있을 것이고, 0 출력하면 됨.
        }
        cout<<'\n';
    }

    return 0;
}