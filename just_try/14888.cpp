#include <iostream>
using namespace std;

int N;
int operands[11];
int operators[4];
int mmin = 1000000001;
int mmax = -1000000001;
void ope(int result, int idx)
{
    if (idx == N)
    {
        if (result > mmax)
            mmax = result;
        if (result < mmin)
            mmin = result;
    }
    for (int i = 0; i < 4; i++)
    {
        if (operators[i] > 0)
        {
            operators[i]--;
            if (i == 0)
                ope(result + operands[idx], idx + 1);
            else if (i == 1)
                ope(result - operands[idx], idx + 1);
            else if (i == 2)
                ope(result * operands[idx], idx + 1);
            else
                ope(result / operands[idx], idx + 1);
            operators[i]++;
        }
    }
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> operands[i];
    for (int i = 0; i < 4; i++)
        cin >> operators[i];
    ope(operands[0], 1);
    cout << mmax << '\n' << mmin;
}