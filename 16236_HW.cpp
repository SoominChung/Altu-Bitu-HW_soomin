//
// Created by kirin on 2021-11-30.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 401;
typedef pair<int, int> ci;

//아기 상어 :
/**
 * 1. 상어로부터 가장 가까운 거리에 있는 모든 물고기 탐색 (BFS)
 * 2. 우선순위 조건에 맞추어 먹으러 갈 물고기 확정
 *    탐색하는 방향에 우선순위를 두는 걸로 해결되지 않음! (예제 입력 4) 정렬 필요
 * 3. 상어가 이동할 수 있는 곳이 없을 때까지 BFS 탐색 반복
 *
 * 입력 범위가 작기 때문에 매번 BFS 탐색을 반복해도 시간 초과 X
 * 가능한 물고기의 최대 마리 수 : 399마리 (최대 크기 20x20 - 아기상어 있을 곳 1)
 * 최대 BFS 탐색 횟수 : 399회, 1회 탐색마다 while 문은 최대 400회 미만으로 순회
 * 총 연산 횟수 약 160000번으로 충분히 가능
 *
 * 해설 : https://myunji.tistory.com/378
 * *글 자체는 별로 도움이 안되고...그냥 리팩토링하면 코드가 이렇게 되는구나 정도만 봐주세요
 */

pair<int, ci> nextPos(int n, int shark_size, ci &shark, vector<vector<int>> &board) {
    //상하좌우 움직임 표현
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int min_dist = INF; //젤 가까이 있는 먹을 수 있는 물고기 찾기
    queue<ci> q; //상어가 갈 수 있는 곳
    vector<vector<int>> visited(n, vector<int>(n, 0)); //상어의 방문 여부 (소요시간으로 저장)
    vector<ci> list; //상어가 먹을 수 있는 물고기들의 위치

    visited[shark.first][shark.second] = 1; //상어 초기위치는 방문으로 표시
    q.push(shark); //상어 처음 위치부터 시작
    while (!q.empty()) {
        int row = q.front().first; //방문할 row, col 꺼냄
        int col = q.front().second;
        int dist = visited[row][col];
        q.pop(); //pop 잊지 말기

        if (dist >= min_dist) //최단거리 이상은 탐색할 필요 없음
            continue;
        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i]; //상하좌우로 이동해보기
            int nc = col + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] || board[nr][nc] > shark_size)
                continue; //조건에 위배되는 칸이었다면 패스

            visited[nr][nc] = visited[row][col] + 1; //출발시점까지의 소요시간+1
            if (board[nr][nc] && board[nr][nc] < shark_size) { //먹을 수 있는 물고기 발견 (물고기 있고, 상어보다 작음)
                list.emplace_back(nr, nc); //상어 먹킷리스트에 현 위치 추가 (먹을 수 있으니께)
                min_dist = visited[nr][nc]; //지금까지 걸린 시간이 최소 시간
                continue;
            }
            q.push({nr, nc}); //방문할 위치 저장한 queue에 추가
        }
    }

    if (list.empty()) //상어가 갈 수 있는 곳이 없음
        return {min_dist, {-1, -1}}; //최종 min_dist를 return

    sort(list.begin(), list.end(), [](const ci &p1, const ci &p2) { //정렬 (가까운 순으로)
        if (p1.first != p2.first)
            return p1.first < p2.first;
        return p1.second < p2.second;
    });
    return {min_dist - 1, list[0]}; //젤 첨으로 방문할 위치 return
}

int simulation(int n, pair<int, int> &shark, vector<vector<int>> &board) {
    int ans = 0, size = 2, cnt = 0; //초기 아기상어의 크기=2
    while (true) {
        pair<int, ci> result = nextPos(n, size, shark, board); //다음 방문할 위치 받아서 가져옴
        if (result.first == INF) //더 이상 먹을 수 있는 물고기가 공간에 없음
            break;
        ans += result.first; //있다면 거기까지 가는데 소요되는 시간 (min_dist)
        cnt++;
        if (cnt == size) { //상어 크기 증가
            cnt = 0;
            size++;
        }

        //상어 이동
        ci pos = result.second; //다음 행선지로 간다
        board[shark.first][shark.second] = 0; //먹었으니 0으로 표시
        shark = pos; //상어의 위치 업데이트
    }
    return ans; //최종 소요시간 return
}

int main() {
    int n;
    pair<int, int> shark_pos; //상어 위치

    //입력
    cin >> n; //공간 크기 nxn
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j]; //0이면 빈칸, 1~6: 칸에 있는 물고기 크기
            if (board[i][j] == 9) //상어의 초기 위치
                shark_pos = make_pair(i, j); //상어 위치 pair로 함수에 넣을거
        }
    }

    //연산 & 출력
    cout << simulation(n, shark_pos, board);
}