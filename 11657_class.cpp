//
// Created by kirin on 2021-11-02.
//

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
typedef long long ll; //모든 간선의 가중치가 음수일 때
typedef tuple<int,int,int> ti;
const int INF = 1e6*5;

//벨만-포드
vector<ll> bellmanFord(int n, int m, int start,vector<ti> &edges){
    //오버플로우 x, 언더플로우 o
    //500 * 6000 * (-10000) => int 범위 넘어감 (next_weight이 for,for 동안 계속 갱신된거)
    vector<ll> dist(n+1, INF); //각 도시까지의 거리 담은 vector

    dist[start] =0; //시작 위치 초기화

    for(int i=1; i<=n; i++){ //각 도시에 대해 탐색
        bool flag = true; //갱신 되면 false로 바뀔 거
        for(int j=0; j<m; j++){ //모든 간선에 대해
            //s->d로 가는 간선의 가중치가 w
            int s = get<0>(edges[j]); //시작점
            int d = get<1>(edges[j]); //도착점
            int w = get<2>(edges[j]); //가중치

            if(dist[s] == INF) //아직 시작점에서 s로 가는 경로가 발견되지 않았으므로 갱신할 수 없음
                continue;

            ll next_weight = w+dist[s]; //현재 가중치 + s까지의 거리
            if(dist[d] > next_weight){ //더 짧은 경로로 갈 수 있다면
                if(i==n) //n번째 갱신이었다면 음의 사이클이 발생한 것
                    return {INF+1};
                //n번째 전까지의 갱신은 next_weight으로 업데이트 해줌
                dist[d] = next_weight; //s->d까지의 최단거리 업데이트!
                flag = false; //갱신 마친 후에는 false로 바꿔줌
            }
        }
        if(flag)//더 이상 갱신되지 않으면
            break;
    }

    return dist; //각 도시까지의 최단거리가 담긴 vector return
}

int main(){
    int n,m, a,b,c,;

    //입력
    cin>>n>>m; //n개의 도시, 다른 도시에 도착하는 버스 m개
    vector<ti> edges(m); //간선 정보를 저장할 벡터
    for(int i=0; i<m; i++){ //각 버스 마다의 정보 저장
        cin>>a>>b>>c; //a:시작 도시, b:도착 도시, c:버스 타고 걸리는 시간
        edges[i] = {a,b,c}; //방향 그래프
    }

    //연산
    vector<ll> ans = bellmanFord(n,m,1,edges);

    //출력
    if(ans[0]==INF+1){
        cout<<-1; //어떤 도시 가는 과정에서 시간 무한히 돌릴 수 있다면 -1 출력
        return 0;
    }
    for(int i=2; i<=n; i++){ //n-1개의 도시로 가는 최단 거리 출력
        cout<<((ans[i]==INF)?-1:ans[i])<<'\n'; //경로 없으면 -1
    }

}