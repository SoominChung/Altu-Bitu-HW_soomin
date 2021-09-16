//
// Created by kirin on 2021-09-16.
//

// 후위 표기식 2

#include <iostream>
#include <stack>
#include <map>

using namespace std;

int main(){
    int n;
    double a,b; // 연산을 위한 변수
    string input;
    map<char, int> alphabet; //n개의 피연산자에 대한 정보 담음
    //vector<char> calc; //연산자들 담은 벡터
    stack<double> s; //연산을 위한 스택

    //calc.assign(4,{'+','-','*','/'});

    //입력
    cin>>n;
    cin>>input;
    char last_alphabet = 'A'+n; // 각 피연산자에 값 할당 위해서 마지막 알파벳 파악하기

    for(char a='A'; a<last_alphabet; a++){
        cin>>alphabet[a];
    }

    //연산
    for(int i=0; i<input.size(); i++){
        if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){//연산자이면 그에 상응하는 연산 수행
            b= s.top();
            s.pop();
            a= s.top();
            s.pop();

            switch(input[i]){
                case '+':
                    s.push(a+b);
                    break;
                case '-':
                    s.push(a-b);
                    break;
                case '*':
                    s.push(a*b);
                    break;
                case '/':
                    s.push(a/b);
                    break;
            }
        }
        else{ //알파벳이면 push
            s.push(alphabet[input[i]]);

        }
    }
    cout<<fixed;
    cout.precision(2); //출력되는 double 자리수 고정시키기 위해!
    cout<<s.top();
}