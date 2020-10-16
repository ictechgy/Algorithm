#include <string>
#include <vector>

using namespace std;

int stu1[5] = {1, 2, 3, 4, 5}, p1, score1;
int stu2[8] = {2, 1, 2, 3, 2, 4, 2, 5}, p2, score2;
int stu3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}, p3, score3;

vector<int> solution(vector<int> answers) {
    for(auto answer : answers){
        if(answer == stu1[p1++]) score1++;
        if(answer == stu2[p2++]) score2++;
        if(answer == stu3[p3++]) score3++;
        
        if(p1 >= 5) p1 = 0;
        if(p2 >= 8) p2 = 0;
        if(p3 >= 10) p3 = 0;
    }
    int max_score = max(score1, max(score2, score3));
    vector<int> scores;
    
    if(max_score == score1) scores.push_back(1);
    if(max_score == score2) scores.push_back(2);
    if(max_score == score3) scores.push_back(3);
    
    return scores;
}