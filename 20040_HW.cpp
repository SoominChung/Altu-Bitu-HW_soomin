//
// Created by kirin on 2021-11-30.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//사이클 게임

/**
 * 사이클이 발생한 순간 = 같은 집합에 있는 원소 두 개를 유니온하려 할 때
 * unionInput 함수의 반환형을 bool로 선언하여 cycle이 생성되는 순간 발견하기
 */

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //루트 정점
        return node;
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
bool unionInput(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return false;
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else { //새로운 루트 yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
    return true;
}

int main() {
    int n, m, x, y;

    //입력
    cin >> n >> m; //점의 개수, 진행된 차례
    parent.assign(n, -1);
    for (int i = 0; i < m; i++) {
        cin >> x >> y; //i번째 차례에 해당 플레이어가 선택한 두 점의 번호가 주어짐

        //연산 & 출력
        if (!unionInput(x, y)) { //유니온 할 수 없음 = 사이클이 생성됨
            cout << i + 1; //사이클 처음 만들어진 차례의 번호 출력
            return 0;
        }
    }
    cout << 0; //사이클 안만들어지고 끝나면 0 출력
}