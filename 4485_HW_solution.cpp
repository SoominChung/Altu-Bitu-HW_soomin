//
// Created by kirin on 2021-11-09.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * 상하좌우로 이동 가능 -> 연결됐다는 것
 * 시작 지점이 (0, 0)인 다익스트라
 */

typedef pair<int, int> ci;
const int INF = 1e5 * 2; //최대 N*N 칸을 지나게 됨

int dijkstra(int n, vector<vector<int>> &board) {
    // 상하좌우 방향으로 이동 가능
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int ans = 0; //잃는 최소 금액 초기화
    vector<vector<int>> dist(n, vector<int>(n, INF)); //각 idx까지 가는데에 소요된 루피
    priority_queue<pair<int, ci>, vector<pair<int, ci>>, greater<>> pq;

    //시작 위치 초기화
    dist[0][0] = board[0][0]; //0~0까지 거리는 0
    pq.push(make_pair(dist[0][0], make_pair(0, 0)));

    while (!pq.empty()) {
        int weight = pq.top().first; //해당 칸으로 움직이면 잃는 루피 수
        int row = pq.top().second.first; //x 축
        int col = pq.top().second.second; //y 축
        pq.pop(); //pop 잊지 말기

        if (row == n - 1 && col == n - 1) { //제일 오른쪽 아래 칸 도착
            ans = weight; //최소 잃는 루피 (답)
            break;
        }
        if(weight > dist[row][col]) //이미 확인했던 좌표
            continue;
        for (int i = 0; i < 4; i++) { //상하좌우방향으로 확인해봄
            int nr = row + dr[i];
            int nc = col + dc[i];
            if ((nr < 0) || (nr >= n) || (nc < 0) || (nc >= n)) //범위를 벗어난다면
                continue;

            int next_weight = weight + board[nr][nc]; //시작점으로부터 연결된 좌표까지의 거리
            if (dist[nr][nc] > next_weight) { //더 짧은 경로로 갈 수 있다면
                dist[nr][nc] = next_weight; //next_weight으로 업데이트해주고
                pq.push({next_weight, {nr, nc}}); //다음 탐색을 위한 push
            }
        }
    }
    return ans;
}

int main() {
    int n, num = 1;

    while (true) {
        //입력
        cin >> n;
        if (n == 0) //n이 0이면 종료
            break;

        vector<vector<int>> board(n, vector<int>(n, 0)); //nxn 크기의 board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> board[i][j]; //각 칸마다 잃는 루피 수
        }

        //연산 & 출력
        cout << "Problem " << num++ << ": " << dijkstra(n, board) << '\n';
    }
}