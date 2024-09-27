//
// Created by kirin on 2021-11-02.
//

#include <iostream>
#include <queue>

using namespace std;

/*
 * <숨바꼭질>
 * 수빈이는 점 N에, 동생은 점 K에 있음. (~100,000)
 * 수빈이는 걷거나 순간이동 가능.
 * 걷기: X일 때 1초 후에 X-1이나 X+1로 이동
 * 순간이동: 1초 후에 2*X로 이동
 *
 * 수빈이가 동생 찾을 수 있는 가장 빠른 시간이 몇 초 후인지
 * */

const int SIZE = 100000;

int bfs(int n, int k){
    vector<int> check(SIZE+1, 0); //방문 여부가 들어간 vector. x 방문할 때까지 걸린 시간을 담아놓았음
    queue<int> q; //큐에 좌표값 저장
    int ans=0;

    check[n]= 1; //시작 노드 방문체크 + 시간 초기화
    q.push(n); //시작 노드 초기화
    while(!q.empty()){
        int x = q.front(); // 현재 탐색하려는 위치
        q.pop(); // 탐색 했으니 뺀다

        if(x==k){ //동생 찾으면 탐색 종료. 시작 위치를 1로 초기화 했기 때문에 1을 빼줌
            ans = check[x]-1;
            break;
        }

        vector<int> child = {x-1, x+1, x*2}; //자식 노드
        for(int i=0; i<3; i++){
            if(child[i]>=0 && child[i] <= SIZE && !check[child[i]]){ // 자식 노드가 범위 안에 있고, 방문한 적 없었다면
                check[child[i]] = check[x]+1; //시간 증가
                q.push(child[i]); //해당 자식 노드를 다음에 방문하기 위해 push
            }
        }
    }
    return ans;
}

/*
 * x좌표 위에서 x-1, x+1, 2*x의 위치로 계속 이동하며 탐색
 * 가장 빠른 시간을 찾아야 하므로 주변 노드부터 탐색하는 풀이로 풀어서 k에 도달하면 바로 탐색 종료
 */

int main(){
    int n,k;

    //입력
    cin>>n>>k;

    //연산 & 출력
    cout<< bfs(n,k)<<'\n';

    return 0;

}