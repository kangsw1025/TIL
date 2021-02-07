#include <iostream>
#include <algorithm>
using namespace std;

int N, L;
int pipe[1001];
bool taped[1001];

int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0); //cin 실행속도 향상

        cin >> N >> L;

        int result = 0;
        for (int i = 0; i < N; i++)
                 cin >> pipe[i];
        sort(pipe, pipe + N);
        for(int i=0; i<N; i++)
                 if (!taped[pipe[i]])
                 {
                         for (int j = pipe[i]; j < min(pipe[i] + L, 1001); j++)
                                 taped[j] = true;
                         result++;
                 }
        cout << result;
        return 0;
}
