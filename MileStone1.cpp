// MileStone1
//CURRENTLY THIS CODE IS VALID FOR ONLY FIRST INPUT
#include <bits/stdc++.h>
using namespace std;
void print(vector<bool> &x)
{
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i] << " ";
    }
    cout << "\n";
}
vector<string> splitByDelimeter(string s, char ch)
{
    vector<string> ans;
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            ans.push_back(temp);
            temp = "";
        }
        else
        {
            temp += s[i];
        }
    }
    ans.push_back(temp);
    return ans;
}
int main()
{
    unsigned long long ticketNumber = 100000001;
    int n;
    cin >> n;
    cin.get();
    int x = 2 * n;
    vector<string> trainDetails(x);
    for (int i = 0; i < x; i++)
    {
        getline(cin, trainDetails[i]);
    }
    // for(int i=0;i<x;i++)
    // {
    //     cout<<trainDetails[i]<<" ";
    // }
    for(int i=1;i<x;i+=2)
    {
        vector<string>noOfCoaches=splitByDelimeter(trainDetails[i],' ');
        
    }
    // coach c[n];
    // int q=0;
    // for(int i=0;i<x;i++)
    // {
    //     if(i%2==1)
    //     {
    //         vector<string>individualStr=splitByDelimeter(trainDetails[i],' ');
    //         // for(int i=0;i<individualStr.size();i++)
    //         // {
    //         //     cout<<individualStr[i]<<"\n";
    //         // }
    //         int coachSize1=stoi(individualStr[1].substr(3));
    //         int coachSize2=stoi(individualStr[2].substr(3));
    //         int coachSize3=stoi(individualStr[3].substr(3));
    //         int coachSize4=stoi(individualStr[4].substr(3));
    //         int coachSize5=stoi(individualStr[5].substr(3));

    //     }
    // }
    while (true)
    {
        string input;
        getline(cin, input);
        vector<string> inp = splitByDelimeter(input, ' ');
        for (int i = 0; i < trainDetails.size(); i += 2)
        {
            vector<string> split = splitByDelimeter(trainDetails[i], ' ');
            for(int i=0;i<split.size();i++)
            {
                cout<<split[i]<<"       ";
            }
            string temp1, temp2;
            int dist;
            for (int i = 0; i < split[1].size(); i++)
            {
                if (split[1][i] == '-')
                {
                    break;
                }
                else
                {
                    temp1 += split[1][i];
                }
            }
            for (int i = 0; i < split[2].size(); i++)
            {
                if (split[2][i] == '-')
                {
                    dist = stoi(split[2].substr(i + 1));
                    break;
                }
                else
                {
                    temp2 += split[2][i];
                }
            }
            cout<<temp1<<"      "<<temp2<<"\n";
            if (inp[0] != temp1 || inp[1] != temp2)
            {
                cout << "No Trains Available\n";
            }
            else
            {
                if (inp[3] == "SL")
                {
                    int tickets = stoi(inp[4]);
                    int fair = tickets * dist;
                    cout << ticketNumber << " " << fair << "\n";
                    ticketNumber++;
                    cin.get();
                }
                else if (inp[3] == "1A")
                {
                    int tickets = stoi(inp[4]);
                    int fair = tickets * dist * 4;
                    cout << ticketNumber << " " << fair << "\n";
                    ticketNumber++;
                    cin.get();
                }
                else if (inp[3] == "2A")
                {
                    int tickets = stoi(inp[4]);
                    int fair = tickets * dist * 3;
                    cout << ticketNumber << " " << fair << "\n";
                    ticketNumber++;
                    cin.get();
                }
                else if (inp[3] == "3A")
                {
                    int tickets = stoi(inp[4]);
                    int fair = tickets * dist * 2;
                    cout << ticketNumber << " " << fair << "\n";
                    ticketNumber++;
                    cin.get();
                }
            }
        }
    }

    return 0;
}