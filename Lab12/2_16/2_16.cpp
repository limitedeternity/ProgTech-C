#include <algorithm> // transform
#include <iostream>  // streams
#include <string>    // string
#include <vector>    // vector
#include <regex>     // wsaq_re, sregex_token_iterator

using namespace std;

string removeDuplicates(string s)
{
    if (s.begin() == s.end())
    {
        return s;
    }

    auto no_duplicates = s.begin();
    for (auto current = no_duplicates; current != s.end();)
    {
        current = find_if(next(current), s.end(), [no_duplicates](const char c) -> bool { return c != *no_duplicates; });
        *++no_duplicates = move(*current);
    }

    s.erase(++no_duplicates, s.end());
    return s;
}

int main(int argc, char **argv)
{
    string str;
    cout << "Enter line: ";
    getline(cin, str);
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    regex wsaq_re("\\s+");
    sregex_token_iterator iter(str.begin(), str.end(), wsaq_re, -1);
    sregex_token_iterator zero;

    vector<string> split_arr;
    while (iter != zero)
    {
        split_arr.push_back(*iter++);
    }

    for (int i = 0; i < (int)split_arr.size(); i++)
    {
        if (split_arr[i] == split_arr.back())
        {
            split_arr.erase(split_arr.begin() + i);
        }
    }

    for (int i = 0; i < (int)split_arr.size(); i++)
    {
        char firstletter = *(split_arr[i].begin());

        split_arr[i].erase(split_arr[i].begin());
        split_arr[i].erase(split_arr[i].end() - 1);
        remove_if(split_arr[i].begin(), split_arr[i].end(), [firstletter](const char c) -> bool { return c == firstletter; });
        split_arr[i] = removeDuplicates(split_arr[i]);

        if ((split_arr[i].size() - 1) & 1)
        {
            split_arr[i].erase(((int)split_arr[i].size() - 2) / 2, 1);
        }

        cout << split_arr[i] << " ";
    }

    cout << endl; // Qqqqquikkkkkk brown    fox jumps over another fox
    return 0;
}
