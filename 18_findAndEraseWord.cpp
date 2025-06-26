#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// here will be using .find() and .erase() inbuilt functions

string removeOccurrences(string s, string part)
{
    while ((s.find(part)) != -1)
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main()
{
    string s = "daabcbaabcbc", part = "abc";
    string output = removeOccurrences(s, part);
    cout << output << endl;
    return 0;
}