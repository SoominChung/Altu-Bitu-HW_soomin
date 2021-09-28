//
// Created by kirin on 2021-09-28.
//

#include <iostream>

using namespace std;
/*
 * 기숙사 타일
 * 방 크기 LxW -> 가장자리 빨간색, 나머지 갈색으로 채움
 * 빨간, 갈색 타일 개수 주어졌을 떄 방 크기 구하기 (l,w 출력)
 * 빨간 : 8~5000, 갈색 : 1~2,000,000
 *
 * [풀이]
 * 기숙사 바닥의 넓이는 타일 개수의 총합인 r+b
 * l(높이)이 r+b인 사각형부터 검사 ( w= (r+b)/l) -> 테두리 타일 개수가 r과 같다면 정답
 * 테두리 개수 = (l+w)*2 -4 (겹치는 부분)
 * 입력 범위는 최대 r+b = 2,005,000이므로 접근 가능함
 */

// 기숙사 바닥의 l(높이), w(넓이) 구해서 리턴하는 함수
pair<int,int> length(int r, int b){
    int area = r+b; //넓이는 빨간 타일+갈색 타일 더한 수
    for(int i= area; i>0; i--){ // i = l (높이)의 값
        if(area %i != 0){ // w가 정수가 아니라면 넘어감
            continue;
        }
        int w = area/i; // area = ixw이므로 w는 area/l
        if(r == ((i+w)*2 - 4)){ // 테두리 개수가 r과 같다면
            return make_pair(i,w); // pair 제작하는 make_pair 이용해서 return
        }

    }
}
 int main(){
     int r,b; // r: 빨간 타일, b: 갈색 타일

     //입력
     cin>>r>>b;

     //연산
     pair<int, int> result = length(r,b);

     //출력
     cout<<result.first <<' '<<result.second<<'\n'; // l과 w 출력

     return 0;
 }



