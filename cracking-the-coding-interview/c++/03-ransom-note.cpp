// Problem:
// Given the words in the magazine and the words in the ransom note, print Yes
// if one can replicate a ransom note exactly using whole words from the
// magazine; otherwise, print No. Words are case-sensitive and can only be used
// as a whole (no substring or concatenation allowed).
// 
// Example:
// Input: "give me one grand today night", "give one grand today"
// Output: Yes
// 
// Solution:
// Use hash map to store string and count from the magazine, then check against
// the ransom note, minus 1 on each string, if any count < 0, return false.

bool ransom_note(vector<string> magazine, vector<string> ransom)
{
    map<string, int> dict;
    int ms, rs, i;
    
    ms = magazine.size();
    rs = ransom.size();
    
    if (ms < rs)
        return false;
    
    for (i = 0; i < magazine.size(); i++)
        dict[magazine[i]]++;
    
    for (i = 0; i < ransom.size(); i++)
        if (--dict[ransom[i]] < 0)
            return false;
    
    return true;
}