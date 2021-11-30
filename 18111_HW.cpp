//
// Created by kirin on 2021-11-30.
//

#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;

// 마인 크래프트 : 집 짓기 위해 최소 시간으로 땅의 높이 일정하게 만들기
/**
 * 1. 가장 낮은 땅의 높이를 h라고 할 때, h-1의 높이를 만드는건 h보다 2*(N*M)의 시간이 더 소요됨
 * 2. 가장 높은 땅의 높이를 h라고 할 때, h+1의 높이를 만드는건 h보다 (N*M)의 시간이 더 소요됨
 * -> 따라서 땅의 높이가 될 수 있는 후보는 (가장 낮은 땅) ~ (가장 높은 땅)
 * -> 가능한 모든 높이에 대해 브루트포스 연산해도 시간 초과 X
 *
 * !주의! 당장 쌓을 블록이 없더라도 언젠가 다른 곳의 블록을 제거해서 쌓을 수 있음.
 */

int mineLand(int n, int m, int b, int height, vector<vector<int>> &land) {
    int tot_time = 0; //걸리는 시간 저장해놓은 변수
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (land[i][j] > height) { //블록 제거
                b += (land[i][j] - height); //인벤토리에 넣음
                tot_time += 2 * (land[i][j] - height); //소요시간은 제거니까 2초x블록개수
            } else if (land[i][j] < height) { //블록 쌓기
                b -= (height - land[i][j]); //인벤토리에서 빼서 사용함
                tot_time += (height - land[i][j]); //소요시간은 쌓기니까 1초x블록개수
            }
        }
    }
    if (b < 0) //최종적으로 블럭이 음수면 불가능한 높이 (이거 판별을 중간에 넣었으면 복잡해졌을텐데 마지막에 빼서 확인해도 되는 거 였음)
        return INF + 1; //min time 초기화 값이 INF 였으니까 자동적으로 얘는 무시될 것임.
    return tot_time;
}

int main() {
    int n, m, b, min_height = 256, max_height = 0; //min, max는 아래 정보로 업뎃할거기 때문에 초기화만

    //입력
    cin >> n >> m >> b; // n: 집 세로, m: 집 가로, b: 현재 인벤토리에 갖고있는 블록
    vector<vector<int>> land(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> land[i][j]; //각 위치의 높이값 저장
            min_height = min(min_height, land[i][j]); //제일 낮은 땅 높이
            max_height = max(max_height, land[i][j]); //제일 높은 땅 높이
        }
    }

    //연산
    int min_time = INF, height = 0;
    for (int i = min_height; i <= max_height; i++) { //최소 높이~ 최대 높이 만드는데에 걸리는 시간 다 탐색
        int t = mineLand(n, m, b, i, land);
        if (t <= min_time) { //가장 빨리 작업이 끝나는 높이
            min_time = t; //더 최솟값 찾으면 업데이트
            height = i; //해당 높이도 업데이트
        }
    }

    //출력
    cout << min_time << ' ' << height;
}