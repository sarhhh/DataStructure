#include <iostream>
#include <vector>
#include <string>
using namespace std;

int BF(string T, string P)
{
    int i = 0;
    while (i <= T.length() - P.length())
    {
        int j = 0;
        while (j < P.length())
        {
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
            return (i - j);
        }
    }
    return -1;
}

vector<int> getnext(string n)
{
    vector<int> next(n.length());
    next[0] = -1;
    for (int i = 1; i < n.length(); i++)
    {
        int j = next[i - 1];
        while (j >= 0)
        {
            if (n[j] == n[i])
            {
                next[i] = j + 1;
                break;
            }
            else
            {
                j--;
            }
        }
        if (j < 0)
        {
            next[i] = 0;
        }
    }
    return next;
}

int KMP(string T, string P)
{
    int i = 0;
    int j = 0;
    vector<int> next = getnext(P);

    cout << "模式串的next数组为：";
    for (int k = 0; k < next.size(); k++)
    {
        cout << next[k] << " ";
    }
    cout << endl;

    while (i < T.length())
    {
        if (j == -1 || T[i] == P[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }

        if (j == P.length())
        {
            return i - j;
        }
    }
    return -1;
}

int KMP2(string T, string P)
{
    string s = P + '#' + T;
    cout << "构造的字符串s为：" << s << endl;
    vector<int> n(s.length());
    n[0] = 0;
    for (int i = 1; i < s.length();i++)
    {
        cout << "计算n[" << i << "]，当前字符s[" << i << "]=" << s[i] << endl;
        int j = n[i - 1];
        cout << "当前j=" << j << endl;
        while (j>=0)
        {
            cout << "比较s[" << j << "]=" << s[j] << "和s[" << i << "]=" << s[i] << endl;
            if(s[j]==s[i])
            {
                n[i] = j + 1;
                cout << "匹配成功，n[" << i << "]=" << n[i] << endl;
                if(n[i]==P.length())
                {
                    cout << "模式串匹配成功，返回位置：" << i - P.length() - 1 << endl;
                    return i - P.length() - 1;
                }
                break;
            }
            else
            {
                j--;
                cout << "匹配失败，j减1，当前j=" << j << endl;
            }
        }
        if(j<0)
        {
            cout << "匹配失败，j<0，n[" << i << "]=" << 0 << endl;
            n[i] = 0;
        }
    }
    cout << "主串中未找到模式串，返回-1" << endl;
    return -1;
}

int main()
{
    string text = "ssssssssussu";
    string pattern = "ussu";
    int pos = KMP2(text, pattern);
    if (pos != -1)
    {
        cout << "匹配成功，模式串首次出现位置为：" << pos << endl;
    }
    else
    {
        cout << "匹配失败，主串中未找到模式串。" << endl;
    }
    return 0;
}