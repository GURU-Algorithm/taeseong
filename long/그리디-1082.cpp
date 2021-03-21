#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<pair<int,int>> v;
int cost[50];
int total;
int rest;
string ans;
int max_selected;
bool isOK;

void f(int budget, vector<int> selected)
{
    if(budget > total) return;
    if(isOK) return;

    if(selected.size() == max_selected) isOK = 1;

    auto temp = selected;
    sort(begin(temp), end(temp), greater<int>());
    string tempAns;
    for(int i = 0; i < temp.size(); i++)
        tempAns += to_string(temp[i]);

    //cout << tempAns << endl;

    ans = tempAns;

    for(int i = 0; i < v.size(); i++)
    {
        selected.push_back(v[i].second);
        f(budget + v[i].first, selected);
        selected.pop_back();
    }
}

bool compare1(pair<int, int> rv, pair<int, int> lv)
{
    if (rv.first < lv.first)
    {
        return true;
    }
    else if(rv.first == lv.first)
    {
        if(rv.second > lv.second)
            return true;
        else
            return false;
    }

    return false;
}

bool compare2(pair<int, int> rv, pair<int, int> lv)
{
    if (rv.second > lv.second)
    {
        return true;
    }

    return false;
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        cost[i] = temp;
        v.push_back({temp, i});
    }

    cin >> total;
    
    vector<int> selected;
    // if(N == 1 || total < v[1])
    // {
    //     cout << 0 << endl;
    //     return 0;
    // }else
    // {
    //     max_selected += 1;
    //     max_selected += (total - v[1]) / v[0]; 
    //     rest = (total - v[1]) % v[0];
    // }

    //f(0, selected);

    sort(begin(v), end(v), compare1);

    // for_each(begin(v), end(v), [](auto e){cout << e.first << " " << e.second << endl;});

    if(N == 1 || total < v[0].first || (v[0].second == 0 && total < v[1].first))
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {   
        if(v[0].second == 0)
        {
            ans += char(v[1].second + '0');
            for (int i = 0; i < (total - v[1].first)/v[0].first; i++)
            {
                ans += char(v[0].second + '0');
            }

            rest = (total - v[1].first) % v[0].first;
        }
        else
        {
            for (int i = 0; i < total/v[0].first; i++)
            {
                ans += char(v[0].second + '0');
            }

            rest = (total) % v[0].first;
        }
    }

    sort(begin(v), end(v), compare2);

    // for_each(begin(v), end(v), [](auto e){cout << e.first << " " << e.second << endl;});


    // for(int j = 0; j < ans.size(); j++)
    // {
    //     for (int i = 0; i < v.size(); i++)
    //     {
    //         if(rest < (v[i].first - cost[ans[j] - '0']) || ans[j] >=  (v[i].second + '0')) continue;

    //         rest -= (v[i].first - cost[ans[j] - '0']);
    //         ans[j] = char(v[i].second + '0');
            
    //         break;
    //     }
    // }

    max_selected = ans.length();
    f(0, selected);

    cout << ans << endl;

    return 0;
}