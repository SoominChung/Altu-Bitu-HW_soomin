//
// Created by kirin on 2021-09-06.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long int B,C;

int countPeople(int students){
    long int sum_superviser=0;
    long int main_superviser, sub_superviser,left_students;

    left_students = students-B;
    main_superviser=1;
    sum_superviser += main_superviser;
    if(left_students <0){
        return sum_superviser;
    }
    if(left_students%C == 0){
        sub_superviser = left_students/C;
        sum_superviser +=sub_superviser;

    }
    else{
        sub_superviser = int(floor(left_students/C))+1;
        sum_superviser += sub_superviser;
    }
    return sum_superviser;
}

int main(){
    long int n;
    long long int sum_supervisors=0;

    vector<long int> A; //각 반의 학생 수가 담긴 array

    //입력
    cin >> n;
    A.assign(n,0);
    for(int i=0; i<n; i++){
        cin >>A[i];
    }
    cin >> B >> C;


    //연산

    for(int i=0; i<n;i++){
        sum_supervisors += countPeople(A[i]);
    }

    //출력
    cout<< sum_supervisors;
}