#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

class Matrix
{
    public :

    vector<vector<int>> v;

    Matrix(int N = 50)
    {
        v.resize(N);
        for (int i = 0; i < N; i++)
        {
            v[i].resize(N);
        }
    }

    void Put(int i, int j, int elem)
    {
        v[i][j] = elem;
    }

    Matrix operator*(Matrix l)
    {
        Matrix ret(v.size());
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int subSum = 0;
                for (int k = 0; k < N; k++)
                {
                    subSum += v[i][k] * l.v[k][j];   
                }
                ret.Put(i, j, subSum);   
            }
            
        } 

        return ret;
    }

    Matrix operator+(Matrix l)
    {
        Matrix ret(v.size());
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                ret.Put(i, j, v[i][j] + l.v[i][j]);   
            }
            
        } 

        return ret;
    }
};

int main()
{
    cin >> N;

    Matrix m(N);

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < N; j++)
        {
            if(s[j] == 'N')
            {
                m.Put(i, j, 0);
                m.Put(j, i, 0);
            }
            else
            {
                m.Put(i, j, 1); 
                m.Put(j, i, 1); 
            }
        }  
    }

    Matrix ret = m * m;
    ret = ret + m;

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int count = 0;
        for (int j = 0; j < N; j++)
        {
            if(i == j) continue;
            if(ret.v[i][j] != 0) count++;
        }

        ans = max(ans, count);
    }
    
    cout << ans;
}