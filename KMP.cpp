#include <iostream>
#include <vector>
#include <string>
using namespace std;

int BF(string T, string P)
{
    cout << "Locate the Pattern string with the BF method." << endl;
    int count = 0;
    int i = 0;
    while (i <= T.length() - P.length())
    {
        int j = 0;
        while (j < P.length())
        {
            count++;
            if (T[i] == P[j])
            {
                i++;
                j++;
            }
            else
            {
                i = i - j + 1;
                break;
            }
        }
        if (j == P.length())
        {
            cout << "Compare time is " << count << "." << endl;
            return (i - j);
        }
    }
    return -1;
}

vector<int> getnext(string n)
{
    vector<int> next(n.length());
    next[0] = 0;
    for (int i = 1; i < n.length(); i++)
    {
        int j = next[i - 1];
        while (j > 0 && n[j] != n[i])
        {
            j = next[j - 1];
        }
        if (n[j] == n[i])
            next[i] = j + 1;
        else
            next[i] = 0;
    }
    return next;
}

int KMP(string T, string P)
{
    cout << "Locate the Pattern string with the KMP method." << endl;
    int count = 0;
    int i = 0;
    int j = 0;
    vector<int> next = getnext(P);

    cout << "The next array is: ";
    for (int k = 0; k < next.size(); k++)
    {
        cout << next[k] << " ";
    }
    cout << endl;

    while (i < T.length())
    {
        count++;
        if (T[i] == P[j])
        {
            i++;
            j++;
        }
        else if (j > 0)
        {
            j = next[j - 1];
        }
        else
        {
            i++;
        }

        if (j == P.length())
        {
            cout << "Compare time is " << count << "." << endl;
            return i - j;
        }
    }
    return -1;
}

int KMP2(string T, string P)
{
    cout << "Locate the Pattern string with the KMP method by constructing a new string." << endl;
    int count = 0;
    string s = P + '#' + T;
    vector<int> n(s.length());
    n[0] = 0;
    for (int i = 1; i < s.length(); i++)
    {
        int j = n[i - 1];
        while (j > 0)
        {
            count++;
            if (s[j] != s[i])
            {
                j = n[j - 1];
            }
            else
            {
                break;
            }
        }
        count++;
        if (s[j] == s[i])
        {
            n[i] = j + 1;
            if (n[i] == P.length())
            {
                cout << "Compare time is " << count << "." << endl;
                return i - 2 * P.length();
            }
        }
        else
        {
            n[i] = 0;
        }
    }
    cout << "The Pattern string cannot be found in Main string." << endl;
    return -1;
}

void print_result(int pos)
{
    if (pos != -1)
    {
        cout << "The Pattern string can be found at the " << pos << "'s position in Main string." << endl;
    }
    else
    {
        cout << "The Pattern string cannot be found in Main string." << endl;
    }
}

int main()
{
    string text = "ssssssssussu";
    string pattern = "ussu";

    int pos = BF(text, pattern);
    print_result(pos);
    cout << "*****************************************************************" << endl;

    pos = KMP(text, pattern);
    print_result(pos);
    cout << "*****************************************************************" << endl;

    pos = KMP2(text, pattern);
    print_result(pos);
    cout << "*****************************************************************" << endl;

    return 0;
}