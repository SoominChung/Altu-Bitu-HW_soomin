//
// Created by kirin on 2021-10-15.
//
#include <string>
#include <vector>

using namespace std;

/**
 * 징검다리를 건널 수 있는 니니즈 친구들의 최댓값
 * -> 니니즈 친구들 n명이 징검다리를 건널 때, 건너 뛰어야 하는 디딤돌 칸 수의 최댓값이 k보다 작은가?
 *
 * left : 배열의 원소가 1이상이기 때문에 최소한 1명은 건널 수 있음
 * right : 아무리 많이 건너도 배열 원소의 최댓값보다 많은 인원이 건널 수는 없음
 */

//cnt명이 건널 때, 건너 뛰어야 하는 디딤돌 칸 수의 최댓값
int jumpDist(vector<int> &stones, int cnt) {
    int dist = 1, prev = -1; //건너뛴 칸, 이전에 밟은 디딤돌
    for (int i = 0; i < stones.size(); i++) { //각 돌에 대한
        if (stones[i] >= cnt) { //밟을 수 있음(한 돌 다같이 한 번에 밟는다고 생각->한 명 한 명 순차적으로 갈 필요가 없겠지)
            dist = max(dist, i - prev); //현재 건너뛴 거리가 기존 dist보다 크다면 대체
            prev = i; //다음 턴에는 현재 값이 이전값
        }
    }
    dist = max(dist, (int) stones.size() - prev); //개울의 오른쪽 건너편까지 이동
    return dist; //전체 징검다리를 돌면서 건너 뛰어야 하는 최대 거리
}

int upperSearch(vector<int> &stones, int left, int right, int target) {
    int ans = 0;
    while (left <= right) {
        //mid만큼의 친구들이 건널 때, 건너 뛰어야 하는 디딤돌 칸 수의 최댓값은 몇칸인가?
        int mid = (left + right) / 2;
        int jump = jumpDist(stones, mid); //mid명일 때 건너 뛰어야 하는 거리의 최댓값

        if (jump <= target) { //최댓값이 가능한 값보다 작거나 같다면
            ans = mid; //mid명은 건널 수 있음
            left = mid + 1; //더 큰 범위로 가서 다시 한 번 탐색해본다
        } else if (jump > target) // 최댓값이 가능한 값보다 크다면
            right = mid - 1; //더 작은 범위로 가서 다시 한 번 탐색
    }
    return ans; //최종 답 리턴
}

int solution(vector<int> stones, int k) {
    int right = 0; //배열 원소의 최댓값
    for (int i = 0; i < stones.size(); i++) //stones 내의 최댓값 찾기 위해 for문 돌려본다
        right = max(right, stones[i]);

    return upperSearch(stones, 1, right, k);
}

int main() {
    vector<int> stones = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    int k = 3;
    cout << solution(stones, k);
}
