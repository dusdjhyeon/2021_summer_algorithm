#include <iostream>
#include <string>
#include <stack>
using namespace std;

//stack을 써 문제에 활용하기
/*
(의 수 만큼 스택을 쌓고 )의 수 만큼 제거, 비어 있을 경우도 고려
*/

bool vps(string in) {
    stack<char> v;
    bool flag = true;
    for (int i = 0; i < in.size(); i++) {
        if (in[i] == '(')
            v.push(in[i]);
        else if (!v.empty() && in[i] == ')')
            v.pop();
        else if (v.empty() && in[i] == ')') {
            flag = false;
            break;
        }

    }
    if (v.empty() && flag) return true;
    else return false;
}
int main() {
    int num;
    string in;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> in;
        if (vps(in)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}