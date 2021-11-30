//
// Created by kirin on 2021-11-30.
//

#include <iostream>
#include <vector>

using namespace std;

vector<bool> truth; //진실을 아는지 여부
vector<int> parent;

//거짓말 : 과장 하면서 거짓말쟁이로 알려지지 않을 수 있는 파티 최대 갯수
/**
 * 1. 각 사람들은 다양한 파티를 통해 연결됐다고 할 수 있음
 * 2. 연결된 사람들은 같은 집합에 속함
 * 3. 각 집합에 속한 사람들 중 한 명이라도 진실을 안다면 그 집합의 사람들이 속한 파티에는 거짓말을 할 수 없음
 * -> 유니온 파인드로 사람들을 집합으로 묶은 뒤, 파티마다 거짓말을 할 수 있는지 확인하기
 *
 * !주의! 파티 정보를 입력받으며 바로 거짓말 가능 여부를 판단할 수 없음 (예제 입력 4)
 *       각 파티에서 한 사람만 저장해둔 뒤, 마지막에 거짓말 가능 여부 한 번에 판단
 */

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //루트 정점
        return node; //정점이니까 return
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x); //정점 찾기
    int yp = findParent(y);

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return;
    if (truth[xp] || truth[yp]) //둘 중 하나라도 진실을 믿는 사람이 있다면 표시
        truth[xp] = truth[yp] = true;
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp];  //rank+1
        parent[yp] = xp; //yp의 parent는 xp
    } else { //새로운 루트 yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}

int liarParty(vector<int> &parties) {
    int cnt = 0;
    for (int i = 0; i < parties.size(); i++) { //전체 m개의 파티에 대해 탐색
        int root = findParent(parties[i]); //파티 집합의 루트 정점
        if (!truth[root]) //root가 진실 모르는 사람이라면
            cnt++; //거짓말 가능
    }
    return cnt;
}

int main() {
    int n, m; //n: 사람 수, m: 파티 수
    //입력
    cin >> n >> m;
    truth.assign(n + 1, false); //진실 아는 사람 표시
    parent.assign(n + 1, -1);

    int init, p;
    cin >> init; //진실 아는 인원
    while (init--) { //진실을 아는 사람들
        cin >> p; //그 사람 번호
        truth[p] = true;
    }

    int cnt, first_person, people;
    vector<int> parties;
    while (m--) {
        cin >> cnt >> first_person; //각 파티에 오는 사람 수 , 첫 사람

        //연산
        parties.push_back(first_person); //파티 정보로 각 파티의 첫번째 사람만 저장
        while (--cnt) {
            cin >> people; //두번째 부터의 사람들
            unionInput(first_person, people); //첫 사람과 그 외의 사람들 union시킨다.
        }
    }

    int ans = liarParty(parties); //과장된 이야기 할 수 있는 파티의 최댓값

    //출력
    cout << ans;
}