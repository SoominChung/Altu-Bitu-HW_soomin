//
// Created by kirin on 2021-10-06.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * [삼각형 만들기]
 * N개의 빨대 중 3개를 선택해서 삼각형 만들 수 있다면, 세 변의 길이의 합의 최댓값을 구하고 싶다.
 *
 * [in]
 * 빨대 개수 N이 주어짐. (3~1,000,000) -> 10^6C3하면 거의 10^18됨.브루트포스는 불가능 -> 만약 아예 가능한 쌍이 없다면 시간초과나나
 * N개의 빨대 길이 각 줄마다 주어짐 <= 1,000,000
 *
 * [out]
 * 세 변의 길이의 합의 최댓값. 만약 삼각형 만들기 불가능하면 -1
 */

int maxTriangle(int n, vector<int> straw){
    // 삼각형 : 가장 긴 변의 길이 a, 다른 두 변의 길이 b,c일 때 a < b+c
    // 제일 큰거부터 뽑아서 삼각형 되는지 확인? -> n이 최대인데 삼각형 조건 만족하는 쌍 없으면 시간초과 날듯
    int flag = 0;
    //int max_sum = -1;
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                if(straw[i] < straw[j]+straw[k]){ //삼각형 조건 만족시키면 max 값 업데이트
                    //cout<<"triangle:"<<straw[i]<<' '<<straw[j]<<' '<<straw[k]<<'\n';

                    return straw[i]+straw[j]+straw[k];
                }
                if(straw[i] >= straw[j]+straw[k]){ // 큰 수 부터 뽑으므로 뽑는 숫자들이 갈수록 작아짐. 따라서 제일 긴 것이 나머지 두 변보다 크다면 나머지 두 변에 대한 거 볼 필요 없음
                    //cout<<"pass:"<<straw[i]<<' '<<straw[j]<<' '<<straw[k]<<'\n';
                    flag=1;
                    break; // k에 대한 for문 벗어남
                }
            }
            if(flag==1){
                break; // j에 대한 for문 벗어남
            }
        }

    }

    return -1;

}


int main(){
    int n;
    ios::sync_with_stdio(false);
    cin.tie(NULL); //입출력 속도 향상
    //입력
    cin>>n;
    vector<int> straw(n,0);
    for(int i=0; i<n; i++){
        cin>>straw[i];
    }

    sort(straw.begin(),straw.end(),greater<>()); // 길이 큰 거 부터 뽑기 위해 내림차순 정렬시킨다.

    //연산+출력
    cout<<maxTriangle(n,straw);


}