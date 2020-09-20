#include <iostream>
#include <string>
#include <vector>
#define SWAP_INT(x, y) {int t = x; x = y; y = t;}

using namespace std;

//dec in 0..1000 
//depth in 1..4
int ndepth_decimal_getter(int dec, int depth) {
    return 0;
}

//dec in 0..1000 
int decimal_digit_counter(int dec) {
    if (dec == 0) return 1;
    int cnt = 0; 
    while (dec > 0) {
        dec /= 10;
        cnt++;
    }
    return cnt;
}


string solution(vector<int> numbers) {
    string answer = "";


    return answer;
}

int main42746() {
    vector<int> tc1 = { 6,10,2 }; solution(tc1);
    vector<int> tc2 = { 3,30,34,5,9 }; solution(tc2);

    return 0;
}