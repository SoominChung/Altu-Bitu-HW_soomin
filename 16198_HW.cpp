//
// Created by kirin on 2021-10-08.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> marble;

//에너지 모으기
/**
 * N개의 에너지 구슬. (3~10) -> 10개라면, 2개 남을 때까지 8번 반복 -> 8! 브루트포스 가능
 * 에너지 모으기
 * 1. 고른 에너지 구슬 번호 x. 단, 첫 번쨰와 마지막은 선택 불가
 * 2. x번째 구슬 제거
 * 3. Wx-1 * Wx+1 의 에너지 모으기 가능
 * 4. N을 1 감소시키고 에너지 구슬 번호 다시 매긴다.
 * 모을 수 있는 에너지 양의 최댓값 구하기
 *
 */

// backtracking
int n;
int num[10]; //순서 인덱스 넣는
int max_energy=0;

// 가능한 모든 경우의 수를 구해볼까요? 이때, 사용한 에너지는 지우면서 탐색해야 할 것 같아요.
void backtracking(int cnt, int start){
    int sum_energy=0;
    vector<int> tmp_marble = marble; //브루트포스로 반복하기 위해서 tmp vector 생성

    if(cnt == n-2){ //기저 조건
        //기저조건 도착하면 그 순서대로 지우면서 sum 해볼까?
        for(int i=0; i<cnt; i++){
            //num array 안에는 index가 순서대로 들어있음.
            sum_energy += tmp_marble[num[i]-1]*tmp_marble[num[i]+1]; // w(i-1)*w(i+1)
            tmp_marble.erase(tmp_marble.begin()+num[i]); //에너지 구한 후에는 xi값 지운다.
        }
        if(max_energy<sum_energy){ //현재 sum한 값이 max_energy보다 크면 대체
            max_energy = sum_energy;
        }
    }
    for(int i=start; i<n-1; i++){ //index= n-2까지 사용할 수 있음. (index=n-1은 사용 불가)
        num[cnt] = i; //num에 index 저장하기
        backtracking(cnt+1,i+1);
    }
}

int main(){

    //입력
    cin>>n;
    marble.assign(n,0);
    for(int i=0; i<n; i++){
        cin>>marble[i];
    }

    //연산+출력
    backtracking(0,1); //start=1. 왜냐하면 0은 사용 불가.
    cout<<max_energy;

    return 0;
}