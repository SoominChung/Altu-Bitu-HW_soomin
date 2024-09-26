//
// Created by kirin on 2021-11-04.
//

#include <iostream>
#include <queue>

using namespace std;

/*
 * <숨바꼭질3>
 * 걸으면 1초 후에 X-1, X+1
 * 순간이동 하면 0초 후에 2*X로
 *
 * 동생 찾는 가장 빠른 시간?
 *
 * 다만 각 이동에 가중치가 생겼네요! 하지만 가중치는 겨우 2종류입니다.
 * 어려운 방법 쓰지 않고, 순간이동으로 이동한 정점을 먼저 고려할 수 있는 방법은 어떤게 있을까요?
 *
 * [solution]
 * x좌표 위에서 2*x, x-1, x+1의 위치로 계속 이동하며 탐색
 * 이동에 대한 가중치는 0,1 두 가지 이므로 다익스트라가 아니라 덱으로 풀 수 있음(0-1 BFS)
 *
 * !주의!
 * 순간이동으로 이동하는 경우를 걸어서 이동하는 경우보다 먼저 고려해야 함
 * -> 어차피 순간이동은 push_front 되는데 왜>
 * -> 1에서 2로 이동할 땐 걷는것도 가능하고 순간이동도 가능함
 *    걷는 방법을 먼저 고려하면 check 배열이 갱신되어 순간이동을 고려할 수 없음
 */

const int SIZE = 100000;

int zeroOnebfs(int n, int k){
    vector<int> check(SIZE+1,0); //정점에 도착한 시간
    deque<int> dq; //덱에좌표값 저장
    int ans = 0;

    //시작 위치 초기화
    check[n]=1; //도착 시간 초기화
    dq.push_back(n); //시작 노드 초기화

    while(!dq.empty()){
        int x = dq.front(); //현재 탐색하려는 위치
        dq.pop_front(); //탐색 했으니 pop 해줘야 함

        if(x==k){ //동생 찾으면 탐색 종료.
            ans = check[x]-1; //시작 위치를 1로 초기화 했기 때문에 1을 빼줌
            break;
        }

        int next = x*2; //순간이동
        if(next <= SIZE && !check[next]){ //발 디딜 곳이 범위 안에있고, 탐색 안했었다면
            check[next] = check[x]; // 순간이동은 0초 걸리기 때문에 시간은 전이랑 그대로 유지
            dq.push_front(next); //순간이동이 우선순위이므로 push_front
        }

        next = x-1; //뒤로 걷기
        if(next >= 0 && !check[next]){ //발 디딜 곳이 범위 안에있고, 탐색 안했었다면
            check[next] = check[x] + 1; // 1초를 더함
            dq.push_back(next); // 걷는거는 뒤에 넣어줌
        }

        next = x+1; //앞으로 걷기
        if(next<=SIZE && !check[next]){ //발 디딜 곳이 범위 안에있고, 탐색 안했었다면
            check[next] = check[x] +1; // 걸어갔으니 1초 더함
            dq.push_back(next); // 걸어갔으니 뒤에 넣어줌
        }

    }
    return ans;
}

int main(){
    int n,k;

    //입력
    cin>>n>>k; //수빈 위치 n, 동생 위치 k

    //연산 & 출력
    cout<<zeroOnebfs(n,k)<<'\n';

    return 0;
}