//
// Created by kirin on 2021-11-30.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//여행 가기
/**
 * 입력으로 주어지는 i, j 도시의 연결정보를 통해 서로소 집합을 만든 후,
 * 여행 계획으로 세운 도시들이 모두 같은 집합에 속하는지 확인하는 문제
 */

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //루트 정점
        return node; //정점 노드 return
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x); //두 점의 정점 찾기
    int yp = findParent(y);

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return;
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else { //새로운 루트 yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}


int main() {
    int n, m, a, b, input;

    //입력
    cin >> n >> m; //n: 도시의 수, m: 여행 계획에 속한 도시 수
    parent.assign(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> input; //두 도시의 연결 관계
            if (input) //두 정점이 연결되어 있다면
                unionInput(i, j);
        }
    }
    cin >> a; //시작 정점
    while (--m) {
        cin >> b; //여행 계획
        if (findParent(a) != findParent(b)) { //서로 다른 집합이라면 -> 해당 경로 불가능
            cout << "NO";
            return 0;
        }
    }
    cout << "YES"; //가능하면 YES
}