#include <bits/stdc++.h>
using namespace std;
int L, C;
vector<char> alphabets;
char answer[20];

void DFS(int l, int i, int vowel, int consonant){  //answer의 l레벨(인덱스)에 들어갈 값(alpha 인덱스 i)을 결정, vowel(모음)과 consonant(자음)수 추적
    if(l >= L){
        if(vowel >= 1 && consonant >= 2){
            for(int i = 0; i < L; i++) cout << answer[i];
            cout << "\n";
        }
    }else if(i >= alphabets.size()) return;
    else{
        for(int index = i; index < C; index++){
            char word = alphabets[index];
            answer[l] = word;
            if(word == 'a' || word == 'e' || word == 'i' || word == 'o' || word == 'u') DFS(l+1, index+1, vowel+1, consonant);
            else DFS(l+1, index+1, vowel, consonant+1);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char tmp;
    cin >> L >> C;
    for(int i = 0; i < C; i++){
        cin >> tmp;
        alphabets.push_back(tmp);
    }
    sort(alphabets.begin(), alphabets.end());
    //모든 경우의 수를 탐색하면서 마지막에 해당 결과가 조건을 만족하는지 셈 하는게 나을까..
    //아니면 최소조건을 만족하도록 먼저 어떤 조치를 취한 뒤에 최소 가지로만 뻗어나가는게 좋을까.. <- 이게 낫겠지만 어떤 방식으로?
    DFS(0, 0, 0, 0);

    return 0;
}