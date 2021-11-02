//
// Created by kirin on 2021-11-02.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * <좋다>
 * N개의 수 중에서 어떤 수가 다른 수 두 개의 합으로 나타낼 수 있다면 그 수=좋다
 * N개의 수가 주어지면 그 중에서 좋은 수의 개수는 몇 개인지 출력하라
 * 수의 위치가 다르면 값이 같아도 다른 수이다.
 *
 * [in]
 * 1. 수의 개수 (1~2000)
 * 2. 1,000,000,000 이하의 ai (음수 포함)
 */

//좋은 수인지 검사하는 함수 (투 포인터)
bool isGood(vector<int> &num, int left, int right, int idx){
    while(left < right){ //left가 right보다 커지기 전까지 반복 (같은 수 가리키는건 괜찮음)
        if(left == idx){ //left가 현재 수 위치와 같은 경우
            left ++;
            continue;
        }
        if(right == idx){ //right과 현재 수 위치와 같은 경우
            right--;
            continue;
        }

        if(num[left] + num[right] == num[idx]) {
            return true; //left와 right의 숫자 합으로 표현 된다면 true return
        }

        if(num[left] + num[right] > num[idx]){ //만드려는 수보다 크다면
            right--;
        }
        else{ //만드려는 수보다 작다면
            left++;
        }
    }
    return false;
}

int main(){
    int n, ans = 0;

    //입력
    cin>>n;
    vector<int> num(n,0);
    for(int i=0; i<n; i++)
        cin>>num[i];

    //연산
    sort(num.begin(), num.end()); //배열 순서 중요한 게 아니니 투 포인터 쓰기 위해 정렬해줌
    for(int i=0; i<n; i++){
        if(isGood(num,0,n-1,i)) //Good num이면 true return하니까
            ans++;
    }

    //출력
    cout<<ans<<'\n';

    return 0;
}