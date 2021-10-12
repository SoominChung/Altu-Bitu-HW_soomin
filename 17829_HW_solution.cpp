//
// Created by kirin on 2021-10-12.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 222-풀링
/**
 * 1. 행렬 4등분 하기
 * 2. 행렬의 크기가 1이라면 원소 리턴
 * 3. 리턴된 원소 4개 모아서 두번째로 큰 수만 리턴
 */
 vector<vector<int>> matrix;

int divide(int row, int col, int size){
    //Conquer : n의 크기가 1
    if(size ==1){
        return matrix[row][col]; //마지막 남은 원소 return
    }

    //Divide : 행렬 4등분 하기
    int next_size = size/2; // sub_matrix는 (기존size/2) x (기존size/2)
    vector<int> sub_problem;
    for(int i=0; i<=next_size; i+= next_size){ //각 sub_problem matrix에 대한 for문
        for(int j=0; j<=next_size; j+= next_size){
            sub_problem.push_back(divide(row+i, col+j,next_size)); //sub_problem에 더 작은 sub_problem에서 max값으로 선정된 애들 채움
        }
    }

    //Combine : 두 번째로 큰 수만 남기기
    sort(sub_problem.begin(), sub_problem.end(), greater<>()); //오름차순으로 정렬한 후
    return sub_problem[1]; //두 번째 원소 return
}
int main(){
    int n;

    //입력
    cin>>n;
    matrix.assign(n, vector<int>(n)); //nxn 행렬
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }

    //연산 + 출력
    cout<<divide(0,0,n); // (0,0)부터 시작함

    return 0;
}