#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_multiset<string> sets;
    //int count;
    for(auto person : participant){
        sets.insert(person);
    }
    
    for(auto person : completion){
        sets.erase(sets.find(person));  //이 코드가 가장 간결한 듯
        /*
        count = sets.count(person);
        if(count == 1) sets.erase(person);
        else sets.erase(sets.find(person));
        */
        /*
        int res = sets.erase(person);
        if(res != 1){
            for(int i = 1; i <= res-1; i++) sets.insert(person);
        }
        */
    }
    unordered_multiset<string>::iterator it = sets.begin();
    
    return *it;     //or *sets.begin();
}