//
// Created by kirin on 2021-09-28.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n, ans =0; // n : test case, ans : 맞은 개수
    string input;
    map<string, int> seq; // 각 입력과 입력의 인덱스

    //입력
    cin>>n;
    vector<string> answer(n); //현우가 적은 정답
    for(int i=0; i<n; i++){
        cin>>input; //string input을 받아서
        seq[input] = i; // 각 입력을 string으로 갖고있으면 복잡하니 int로 변형하여 생각
    }
    for(int i=0; i<n; i++){
        cin >> answer[i]; // answer 입력 받는다
    }

    //연산
    //모든 n(n-1)/2개의 쌍에서 올바른 순서로 적힌 답안 찾기
    for(int i=0; i<n-1; i++){
        for(int j= i+1; j<n; j++){
            if(seq[answer[i]] < seq[answer[j]]){ // 두 답안의 상대적인 관계가 맞음
                ans++; // 정답 값 높인다
            }
        }
    }

    //출력
    cout << ans << '/' << n*(n-1)/2;
}