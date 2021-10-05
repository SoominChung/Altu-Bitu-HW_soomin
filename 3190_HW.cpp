//
// Created by kirin on 2021-10-02.
//

#include <iostream>
#include <vector>

using namespace std;

/* 뱀 : 사과 먹으면 뱀 길이 늘어남
 * 벽, 자기자신 몸과 부딪히면 게임 끝
 * NxN 정사각 보드 위에서 진행. 보드 상하좌우 끝에 벽 존재
 * 게임 시작할 때 뱀은 맨위 맨좌측에 위치, 길이 1
 * 처음에 오른쪽을 향함.
 * 매 초마다 이동: 몸길이 늘려서 머리를 다음칸에 위치 시킨다.
 * if 이동한 칸에 사과 있다면 칸에 있던 사과 없어지고 꼬리 움직이지 않는다
 * else 몸길이 줄여서 꼬리가 위치한 칸을 비운다. 즉, 몸길이는 변하지 않는다
 *
 * 사과의 위치, 뱀 이동경로 주어질 때 게임이 몇 초에 끝나는지 계산해라.
 *
 * [IN]
 * 보드 크기 N(2~100) /n 사과 개수 K(0~100)
 * K개의 줄에 사과의 위치 주어진다. (행,열)
 * 다음 줄에 뱀 방향 변환 횟수 L (1~100)
 * 정수 X, 문자 C : 게임 시작 X 후에 L/D로 회전
 * */

struct apple_location{
    int row, col;
};
struct change_direction{
    int sec;
    char direction;
};

int main(){
    int n,k; //보드 크기, 사과 개수
    vector<apple_location> apple; //사과 위치 (행,열)
    vector<change_direction> change_info; // 방향 변환 정보 (초,방향)
    int l; //방향 변환 횟수

    //입력
    cin>>n;
    cin>>k;

    apple.assign(n, {0,0});
    for(int i=0; i<n; i++){
        cin>>apple[i].row>>apple[i].col;
    }

    cin>> l;
    change_info.assign(l,{0,D});
    for(int i=0; i<l; i++){
        cin>>change_info[i].sec>>change_info[i].direction;
    }




}