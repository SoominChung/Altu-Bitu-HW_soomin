//
// Created by kirin on 2021-10-12.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> w; //구슬
int ans; //모든 경우에 대해 반복하며 찾은 max 값

void backtracking(int sum){
    if(w.size()==2){ //에너지 구슬 2개 남으면 -> 더 이상 고를 수 없음
        ans = max(ans,sum); //기존 max값이랑 현재 sum값이랑 비교
        return;
    }
    for(int i=1; i<w.size(); i++){ //처음과 마지막 선택 불가 이므로
        int temp_w = w[i];
        int sum_w = w[i-1] * w[i+1]; //i번째 구슬의 에너지는 w(i-1)*w(i+1)
        w.erase(w.begin()+i); //i번째 구슬 더했으면 지운다
        backtracking(sum+sum_w); //sum=0부터 시작해서 현재 구슬에 대한 sum_w값 더해서 보냄
        w.insert(w.begin()+i, temp_w); //지금 turn에 대한 연산 완료했으면 다시 원상복귀 시켜야지
    }
}

/**
* 가능한 모든 경우를 구해서 계산하자.
 * 이때, 사용한 에너지는 따로 저장해 둔 후에 배열에서 지우고, 다시 돌아왔을 때 저장한 값을 배열에 넣는다.
*/

int main(){
    int n; //구슬의 개수

    //입력
    cin>>n;
    w.assign(n,0);
    for(int i=0; i<n; i++){
        cin>>w[i]; //index=0부터 구슬 넣는다
    }

    //연산
    backtraking(0);

    //출력
    cout<< ans << '\n';

    return 0;
}