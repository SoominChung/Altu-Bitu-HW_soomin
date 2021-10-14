//
// Created by kirin on 2021-10-12.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

// if문 좀 대신 써줘
/**
 * 전투력 기준으로 칭호를 붙임.
 *
 * [in]
 * 칭호의 개수 N(~10^5), 캐릭터 개수 (~10^5) -> 순차탐색 하면 10^10
 * N개의 줄에 칭호 이름, 전투력 상한값 (~10^9) -> 상한값의 비내림차순(오름차순)으로 주어진다.
 * N+2번째 줄부터 M개의 각 줄에는 캐릭터 전투력 주어지지.
 *
 * [out]
 * M개의 캐릭터 전투력에 맞는 칭호 출력. 여러개이라면 가장 먼저 입력된 칭호 하나만 출력
 *
 * [sol] M개의 입력에 대해서 각 숫자가 names의 어디 범위에 있는지 알아야함
 * lower bound: 찾고자 하는 값인 X이상의 수가 처음으로 나오는 위치
 * upper bound: 찾고자 하는 값인 X를 초과하는 수가 처음으로 나오는 위치
 *
 * if m_iter == names.lower_bound == names.upper_bound 이면
 * m은 names[m_iter-1]에 속한 캐릭터임.
 *
 * if m_iter == lower_bound = upper_bound-1이면
 * m은 names[m_iter]에 속한 캐릭터임. (상한선이랑 동일한 경우)
 *
 * if 두 캐릭터의 상한선이 동일하다면?
 * 맨 왼쪽에 있는 값 return해줄 것이므로 잘 나올 거 같긴 한데 일단 봐야지
 *
 * <map의 lower_bound 어케 쓰는지>
 * https://www.cplusplus.com/reference/map/map/lower_bound/
 * <iterator를 int로 바꿔서 쓰는 법>
 * https://stackoverflow.com/questions/26995725/how-to-convert-vector-iterator-to-int-in-c/26995815
 * <map에서 key 값 find>
 * https://www.cplusplus.com/reference/map/map/find/
 *
 */
map<int, string> names; // names.first = 해당 칭호 상한선, second = 칭호

string findCharacters(int power){
    std::map<int,string>::iterator itlow;
    //,itup;

    itlow = names.lower_bound(power);
    //itup = names.upper_bound(power);

    return (*itlow).second;
    /*
    if(std::distance(itlow,itup) ==0){ //low, up 동일한 곳 가리킨다면
        //itlow--;
        return (*itlow).second; //iterator로 map 어떻게 가리키는지 알아봐야겠다..
    }
    else{ // up이 low의 한 칸 다음 가리켰을 때
        return (*itlow).second;
    } */

}


int main(){
    int n,m;
    string name; int upper;
    vector<int> characters; // m명의 칭호 정해줘야하는 캐릭터들

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //입력
    cin>>n>>m;
    characters.assign(m,0);
    for(int i=0; i<n; i++){
        cin>>name>> upper;
        // 동일한 key값을 가진 map에 들어왔을 경우? -> 나중에 들어온 게 먼저거를 밀어냄
        // 따라서 키 값 겹치는 input이 들어왔을 경우 continue해야 함
        std::map<int,string>::iterator it=names.find(upper);
        if(it != names.end()){
            continue;
        }
        names[upper] = name; // names.first는 상한값 뜻하고 오름차순 정렬 되어있음

    }

    for(int i=0; i<m; i++){
        cin>>characters[i];
    }


    //연산+출력
    for(int i=0; i<m; i++){ //m명의 캐릭터에 대해서 판별 함.
        cout<<findCharacters(characters[i])<<'\n'; //각 캐릭터의 힘 input으로 넣음
    }

   return 0;
}