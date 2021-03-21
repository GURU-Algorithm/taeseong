#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        vector<int> v(N, 0);
        for (int i = 0; i < N; i++)
        {
            cin >> v[i];
        }

        vector<int> ans(N-1, 0);
        for (int i = 0; i < N-1; i++)
        {
            ans[i] = v[i+1] - v[i];
        }

        sort(begin(v), end(v), greater<int>());
    
        cout << ans[0] << ans[ans.size()-1]<< endl;    
    }
    
}