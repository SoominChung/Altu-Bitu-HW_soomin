//
// Created by kirin on 2021-09-22.
//

#include <iostream>

using namespace std;

int constructor(int n){
    //n까지 분해합 모두 구해보며 분해합이 n인 경우 찾음
    for(int i=1; i<n; i++){
        int k=1; // i는 가공하면 안되므로 k에 저장
        int sum = i; //분해합 -> 해당 수
        while(k >0){ //분해합 -> 각 자리수의 합
            sum += (k%10);
            k /= 10;
        }
    }
    if(sum == n)//분해합이 n이면 바로 생성자 (i)리턴
        return 1;
    return 0; //생성자 없는 경우
}

int main(){
    int n;

    //입력
    cin>> n;

    //연산 + 출력
    cout<<constructor(n)<<'\n';
    return 0;
}