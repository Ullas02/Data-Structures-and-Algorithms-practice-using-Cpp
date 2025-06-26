#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string reverseWord(string str)
{
    string ans = "";
    reverse(str.begin(), str.end());
    for (int i = 0; i < str.length(); i++)
    {
        string word = "";
        while (i < str.length() && str[i] != ' ')
        {
            word += str[i];
            i++;
        }
        reverse(word.begin(), word.end());

        if (word.length() > 0)
        {
            ans += " " + word;
        }
    }
    return ans.substr(1); // because first character will space
}

int main()
{
    string str = "hello world";
    cout << "Before: " << str << endl;
    string str2 = reverseWord(str);
    cout << "After: " << str2 << endl;
    return 0;
}