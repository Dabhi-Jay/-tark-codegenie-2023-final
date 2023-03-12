// MileStone1
#include <bits/stdc++.h>
using namespace std;
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
    while (true)
    {
        string input;
        getline(cin, input);
        // cout<<"INPUT="<<input<<"\n";
        vector<string> inp = splitByDelimeter(input, ' ');
        // cout<<"INPUT SPLIT\n";
        // for(int i=0;i<inp.size();i++)
        // {
        //     cout<<inp[i]<<"     ";
        // }
        // cout<<endl;
        int count=0;
        for (int i = 0; i < trainDetails.size(); i += 2)
        {
            vector<string> split = splitByDelimeter(trainDetails[i], ' ');
            // cout<<"SPLIT TRAIN DETAILS\n";
            // for(int i=0;i<split.size();i++)
            // {
            //     cout<<split[i]<<"               ";
            // }
            // cout<<endl;
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
            // cout<<"temp1="<<temp1<<"temp2="<<temp2<<"inp[0]="<<inp[0]<<"inp[1]=="<<inp[1]<<"\n";
            if (inp[0] != temp1 || inp[1] != temp2)
            {
                count++;
            }
            else
            {
                if (inp[3] == "SL")
                {
                    int tickets = stoi(inp[4]);
                    int fair = tickets * dist;
                    cout << ticketNumber << " " << fair << "\n";
                    ticketNumber++;
                    break;
                }
                else if (inp[3] == "1A")
                {
                    int tickets = stoi(inp[4]);
                    int fair = tickets * dist * 4;
                    cout << ticketNumber << " " << fair << "\n";
                    ticketNumber++;
                    break;
                }
                else if (inp[3] == "2A")
                {
                    int tickets = stoi(inp[4]);
                    int fair = tickets * dist * 3;
                    cout << ticketNumber << " " << fair << "\n";
                    ticketNumber++;
                    break;
                }
                else if (inp[3] == "3A")
                {
                    int tickets = stoi(inp[4]);
                    int fair = tickets * dist * 2;
                    cout << ticketNumber << " " << fair << "\n";
                    ticketNumber++;
                    break;
                }
            }
        }
        if (count == (trainDetails.size()/2))
        {
            cout << "No Trains Available\n";
        }
    }
    return 0;
}