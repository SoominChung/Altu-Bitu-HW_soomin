//
// Created by kirin on 2021-10-03.
//

#include <iostream>
#include <vector>

using namespace std;

// 쉬운 계단 수
/*
 * N : 1~100까지의 숫자
 * 계단 수 = 인접한 모든 차리의 차이가 1
 * 길이 N인 계단 수 몇 개인지!
 *
 * 수가 0~9밖에 없으니 인덱스로 접근하기 .
 *
 * 정답을 1,000,000,000으로 나눈 나머지 출력하기
 */

struct available_num{
    int prev, aft;
};

int main(){
    int n;
    vector<available_num> number(10,{0,0});
    for(int i=1; i<10; i++){
        number[i].prev = i-1;
        number[i].aft = i+1;
    }
    number[0].aft = 1;
    number[9].aft = 0;

    //입력
    cin>>n;
    int num[n];

    //연산
    for(int i=0; i<n; i++){
        for(int j=0; j<10; j++){
            num[i] = number[j];
            num[i+1] = number[j].aft; // 뒤에 숫자는 number의 aft/prev만 올 수 있음
       }
    }

}