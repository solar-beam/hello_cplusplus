#include <iostream>
#include <string>
#include <vector>
#define SWAP_INT(x, y) {int t = x; x = y; y = t;}

using namespace std;

int decimal_digit_counter(int n) {
    if (n == 0) return 1;

    int cnt = 0;
    while (n > 0) {
        n /= 10;
        cnt++;
    }
    
    return cnt;
}

string solution(vector<int> numbers) {
    string answer = "";


    return answer;
}

int main() {
    vector<int> tc1 = { 6,10,2 }; solution(tc1);
    vector<int> tc2 = { 3,30,34,5,9 }; solution(tc2);

    return 0;
}