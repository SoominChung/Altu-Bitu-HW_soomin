//
// Created by kirin on 2021-11-02.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 * <회전초밥>
 * 초밥의 종류를 번호로 표현. 벨트 위에 같은 종류의 초밥 둘 이상 있을 수 있음
 * 프로모션
 * 1. 한 위치부터 k개 접시 연속해서 먹으면 할인된 가격으로 제공
 * 2. 각 고객에게 한 초밥 종류의 쿠폰 발행하고, 1번 행사 참여하면 해당 초밥 꽁짜
 * 만약에 벨트에 없으면 요리사가 만들어 줌.
 *
 * 위의 행사 참여하며 최대한 다양한 초밥 먹는 것이 목표임
 *
 * [in]
 * 벨트 상태(접시 수 N), 초밥 가짓수(d), 연속해서 먹는 접시 개수(k), 쿠폰 번호(c)
 *  2 ≤ N ≤ 30,000, 2 ≤ d ≤ 3,000, 2 ≤ k ≤ 3,000 (k ≤ N), 1 ≤ c ≤ d
 * */

/*
 * 1. 연속해서 먹어야 할 접시가 k로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산 통해 윈도우의 양 끝 위치 조절하기
 * 3. 쿠폰으로 먹은 초밥을 먼저 고려해놓기
 * 4. 초밥의 종류가 최대 3000개로 많지 않음. 각 종류별 먹은 초밥 개수 세어주기
 */

int chooseSushi(vector<int> &belt, int n, int d, int k, int c){
    vector<int> sushi(d+1,0); // d개의 초밥 종류, 먹은 개수 세어줄 vector

    //쿠폰으로 먹은 초밥
    int section_sushi =1; //스시 종류를 나타내는 변수
    sushi[c]++; //c종류의 스시 하나 먹음

    //윈도우 초기화
    for(int i=0; i<k; i++){
        sushi[belt[i]]++; //벨트에서 0번째부터 k번째까지의 스시 먹음
        if(sushi[belt[i]] ==1)
            section_sushi++; //2이상의 숫자가 아니라 1이라면 처음 그 종류의 스시 먹은거니까 +1
    }

    int ans = section_sushi; //지금까지 먹은 종류 나타내는 section_sushi
    int left =0, right = k-1;
    do{ //원 형태로 윈도우를 옮기기 때문에 종료조건은 left가 초기값(=0) 됐을 때
        sushi[belt[left]]--; //제일 left에 있는 건 오른쪽으로 옮기며 안 먹게 되는거니까
        if(!sushi[belt[left]]) // 그 스시 종류 지금까지 먹은 개수가 0이상이라면 (--했을 때 음수가 나오지 않는다면)
            section_sushi--; // section에서 하나 빼야지 이제 안먹는거니까

        //윈도우의 양 끝 이동
        left = (left + 1) %n; //한 칸씩 이동하되, 원이니까 %n 사용
        right = (right + 1) %n;

        sushi[belt[right]]++; //right에 있는 거 새로이 먹었으니 ++해주고
        if(sushi[belt[right]] == 1) //만약 right 초밥 처음 먹은거였다면
            section_sushi++; //종류 ++ 해줘야지

        ans = max(ans, section_sushi); //윈도우 크기만큼 돌면서 최댓값 업데이트 해줌
    }while(left); //left가 처음으로 돌아올 때 까지 반복한다.

    return ans;

}

int main(){
    int n,d,k,c;

    //입력
    cin>>n>>d>>k>>c;
    vector<int> belt(n,0);
    for(int i=0; i<n; i++){
        cin>>belt[i];
    }

    //연산 & 출력
    cout<<chooseSushi(belt,n,d,k,c);
}