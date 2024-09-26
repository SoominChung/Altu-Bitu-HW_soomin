//
// Created by kirin on 2021-11-03.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5*2; //최대 v-1개의 간선을 지나게 됨

//다익스트라
vector<int> dijkstra(int vertex, int start, vector<vector<ci>>&graph){
    vector<int> dist(vertex+1, INF); //각 간선까지의 dist를 INF로 초기화
    priority_queue<ci, vector<ci>, greater<>> pq; //first : 시작점으로부터의 거리, second : 정점

    //시작 위치 초기화
    dist[start] = 0; //시작점~시작점은 0이니
    pq.push({0,start}); //(시작점으로부터의 거리,정점)

    while(!pq.empty()){
        int weight = pq.top().first; //가중치를 우선순위 큐 first로 넣었음
        int node = pq.top().second; //도착 노드
        pq.pop(); //맨 위에꺼 뺌

        if(weight > dist[node])//이미 확인했던 정점
            continue;
        for(int i=0; i<graph[node].size(); i++){ //도착노드에 시작 노드가 연결된 개수 만큼 iteration
            //graph[시작점].(끝점, 가중치)
            int next_node = graph[node][i].first; //연결된 정점
            int next_weight = weight + graph[node][i].second; //시작점으로부터 연결된 정점까지의 거리
            if(dist[next_node] > next_weight){ //더 짧은 경로로 갈 수 있다면
                dist[next_node] = next_weight; //next_node까지의 최단 거리가 next_weight이니 업데이트
                pq.push({next_weight, next_node}); //queue에도 해당 weight과 node push해줌
            }
        }
    }
    return dist;
}


int main(){
    int vertex, edge, k, u, v, w;

    //입력
    cin>>vertex>>edge>>k; //정점, 간선, 시작 정점
    vector<vector<ci>> graph(vertex+1, vector<ci>(0)); //인접 리스트
    while(edge--){ // 모든 간선에 대해
        cin>>u>>v>>w; //시작점, 끝점, 사이의 가중치
        graph[u].emplace_back(v,w); //방향 그래프
        //graph[시작점].(끝점, 가중치)
    }

    //연산
    vector<int> ans = dijkstra(vertex, k, graph); //시작점으로부터 각 정점까지의 최단경로의 경로값 출력
    //출력
    for(int i=1; i<=vertex; i++){
        if(ans[i] == INF){
            cout<<"INF"; //경로 존재하지 않는 경우
        }
        else
            cout<<ans[i]; //존재할 경우 최단경로 출력
        cout<<'\n';
    }

    return 0;
}