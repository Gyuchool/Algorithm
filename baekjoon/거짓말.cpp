#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

bool truee[51] = {
    false,
};

bool party[51] = {
    false,
};

int main()
{
    int answer = 0;

    int n, m;
    cin >> n >> m;

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int x;
        cin >> x;
        truee[x] = true; // know true people
    }

    map<int, vector<int>> mp;

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        vector<int> v;
        bool know = false;
        for (int j = 0; j < num; j++)
        {
            int people;
            cin >> people;
            if (truee[people])
            {
                know = true;
            }
            v.push_back(people);
        }
        if (know)
        {
            party[i] = true;
            answer++;

            for (int k = 0; k < v.size(); k++)
            {
                truee[v[k]] = true;
            }
        }
        mp[i] = v;
    }
    
    bool change = true;
    while(change){
        change = false;
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            if(party[it->first] == true){
                continue;
            }
            vector<int> values = it->second;
            for (int i = 0; i < values.size(); i++)
            {
                if (truee[values[i]])
                {
                    party[it->first] = true;
                    break;
                }
            }
            if (party[it->first])
            {
                answer++;
                change= true;
                for (int i = 0; i < values.size(); i++)
                {
                    truee[values[i]] = true;
                }
            }
        }
    }

    cout << m - answer;
}
