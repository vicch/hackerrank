// Problem:
// Given two strings a and b, that may or may not be of the same length,
// determine the minimum number of character deletions required to make a and b
// anagrams. Any characters can be deleted from either of the strings.
// - Assume that a and b only contain lowercase letters.
// 
// Example:
// Input: "abc", "cde"
// Output: 4
// 
// Solution:
// Count the number of each letter in 2 strings, the sum of all differences of
// each letter's count is the number of letters to remove. Use one array to
// calculate the diffs, first plus 1 for each letter in a, then minus 1 for
// each letter in b, then add up abs value of all diffs.

int make_anagram(string a, string b)
{
    int diff, i;
    int count[26] = {0};
    
    for (i = 0; i < a.size(); i++)
        count[a[i] - 'a']++;
    
    for (i = 0; i < b.size(); i++)
        count[b[i] - 'a']--;
    
    for (diff = 0, i = 0; i < 26; i++)
        diff += abs(count[i]);
    
    return diff;
}