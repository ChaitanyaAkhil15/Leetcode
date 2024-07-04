#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
using namespace std;

string stringFormat(string s)
{
    string res = "";
    for(auto ch : s)
    {
        if(isalnum(ch))
            res+=tolower(ch);
    }

    return res;
}

bool PalindromeCheck(string &s, int ind, int len)
{ 
    if(ind >= len/2)
        return true;
    if(s[ind] != s[len-ind-1])
        return false;
    return PalindromeCheck(s, ind+1, len);
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    string res = stringFormat(s);

    int ind = 0;
    int len = res.length();
    bool isPalindrome =  PalindromeCheck(res, ind, len);

    if(isPalindrome)
        cout << "String is a Palindrome" << "\n";
    else
        cout << "String is not a Palindrome" << "\n";
}

// string stringFormat(string s)
//     {
//         string res = "";
//         for(auto ch : s)
//         {
//             if(isalnum(ch))
//                 res+=tolower(ch);
//         }

//         return res;
//     }

//     bool PalindromeCheck(string &s, int start, int end)
//     { 
//         if(start < end)
//         {
//             if(s[start] != s[end])
//                 return false;
//             return PalindromeCheck(s, start + 1, end - 1);
//         }

//         return true;
//     }
