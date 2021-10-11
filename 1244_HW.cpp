//
// Created by kirin on 2021-10-08.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> switches;
vector<pair<int,int>> students;
//스위치
/**
 * 남: 스위치 번호가 자기 받은 수 배수면 스위치 상태 바꿈. ex. 3받으면 3,6 바꿈
 * 여: 자기 받은 수와 같은 번호가 붙은 스위치 중심으로 좌우가 대칭이면서 가장 많은 스위치 포함하는 구간 찾아서
 * 그 구간의 스위치 모두 바꾼다. 스위치 개수는 항상 홀수. ex. 3받고 2=4, 1=5이면 1~5 바꿈. 4받고 3 !=5면 4만 바꿈
 *
 * [in] : 스위치들의 처음 상태, 각 학생의 성별과 받은 수
 *
 * [out] : 스위치 마지막 상태. 단 한 줄에 20개씩. 스위치 상태 사이에는 빈 칸 하나씩.
 */

void turnSwitch(int n, int students_n){
    for(int i=1; i<students_n+1; i++){ //각 학생에 대한 스위치 조정 돌아가면서 하기
        int number = students[i].second; // 학생의 스위치 넘버
        if(students[i].first == 1){ //남학생 : 자기 수의 배수들 상태 변환
            while(number <= n){ // 자기 수의 배수 중 n보다 작은 값들 찾기
                switches[number] = !switches[number]; // 스위치 상태 바꿈
                number += students[i].second;
            }
        }
        else{ //여학생 : 자기 스위치 중심으로 상태가 좌우 대칭인 스위치들 상태 변환
            switches[number] = !switches[number]; // 우선 자기 수는 스위치 상태 바꿈
            int pre = number-1;
            int aft = number+1;
            while(switches[pre] == switches[aft] && pre>=1 && aft<=n){ //number가 양 끝 숫자였거나, pre와 aft가 양끝에 갔을 때 대비
                switches[pre] = !switches[pre];
                switches[aft] = !switches[aft];
                pre--; aft++;
            }
        }
    }
}

int main(){
    int n, students_n;
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //입력
    cin>>n;
    switches.assign(n+1,0); //출력 편하게 [1]부터 구현하기
    for(int i=1; i<n+1; i++){
        cin>>switches[i];
    }
    cin>>students_n;
    students.assign(students_n+1,{0,0});
    for(int i=1; i<students_n+1; i++){
        cin>>students[i].first>> students[i].second; //first: 성별, second: 스위치 번호
    }

    //연산
    turnSwitch(n, students_n);

    //출력
    int i=1;
    if(n<=20){ //n이 20보다 작을 경우 출력 줄 넘어가는거 신경쓸 필요 없음
        while(i<=n) {
            cout << switches[i];
            if (i == n) { //맨 마지막 원소는 띄어쓰기 없음
                i++;
                continue;
            }
            cout << ' ';
            i++;
        }
    }
    else{ //n이 20보다 크다면
        while(i<=n) {
            if(i%20 ==0){
                cout << switches[i] << '\n';
                i++;
                continue;
            }

            cout << switches[i]<<' ';
            i++;

        }
    }

    return 0;
}