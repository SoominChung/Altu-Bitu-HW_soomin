//
// Created by kirin on 2021-09-28.
//

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 45; // T 45까지만 구하면 됨

/*
 * [유레카 이론]
 * 삼각수 T(n) = n * (n+1) /2
 * 어떤 자연수가 정확히 3개의 삼각수의 합으로 표현 가능한지 검사해라
 *
 * [풀이]
 * 어떤 자연수(k)가 주어졌을 떄, n=1부터 모든 삼각수의 합을 3개씩 조합해보자
 * 이때, n = 45일 때 T(45) = 1,035이고, k 최대값 1000이므로 45의 삼각수까지만 계산하면 됨
 * 모두 해도 45*45*45 < 1억이므로 브루트 포스 가능
 */

vector<int> tri_num(SIZE); // 각 tri num 담을 vector
bool ans_recursion; // 재귀함수 풀이 시 사용할 정답

//유레카인지 검사하는 재귀함수
void eurekaRecur(int k, int cnt, int sum){ //cnt, sum은 0부터 시작
    if(cnt == 3){ // 정확히 3개의 삼각수
        if(sum == k) // 자연수와 같다면
            ans_recursion = true;
        return;
    }

    for(int i=1; i<=45; i++) // tri_num 크기인 45동안 sum에 더하며 돈다
        eurekaRecur(k, cnt+1, sum+tri_num[i]);
}

//유레카인지 검사하는 반복문 함수
bool eureka(int num){ // 삼중 반복문으로 45*45*45 경우 다 돌아봄
    for(int i=1; i<=45; i++){
        for(int j=1; j<=45; j++){
            for(int k=1; k<=45; k++){
                if(tri_num[i]+tri_num[j]+tri_num[k] == num)
                    return true; // 만약 표현이 된다면 true
            }
        }
    }
    return false; //불가능 했다면 false return
}
int main(){
    int t, k; // t: test case#, k: 입력 숫자

    //입력
    cin >> t;

    //삼각수 SIZE까지 미리 구하기
    for(int i=1; i<=45; i++){
        tri_num[i] = i*(i+1)/2; // 삼각수 공식에 맞추어 tri_num array에 넣는다
    }

    //입력 + 연산 + 출력
    while(t--){
        cin>> k;

        //반복문 풀이
        cout << eureka(k)<< '\n'; // true/false return

        //재귀함수 풀이
        //ans_recursion = false;
        //eurekaRecur(k,0,0); // 입력 int=k, cnt,sum=0으로 시작해야함
        //cout << ans_recursion << '\n'; // 3개의 삼각수로 sum=k된다면 ans_recursion = ture
    }

    return 0;
}