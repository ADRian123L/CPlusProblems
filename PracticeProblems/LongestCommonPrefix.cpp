#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	return 0;
}

class Solution {
public:

    // The function compares two strings and returns how many characters are equal.
    int numEqualChar (string& first, string& second)
    {
        // The length of the smallest string:
        int length = min(first.size(), second.size());
        // Declare and initialize the counter variable:
        int count {0};
        // Iterate trough the strings and count the number of equal char:
        for (int i = 0; (length != 0) && first[i] == second[i]; ++i, ++count, --length)
            ;
        cout << count << endl;
        return count;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if (strs[0].empty())
            return strs[0];

        unsigned long length {strs[0].size()};
        for (int i {1}, temp; i < (int) strs.size(); ++i)
        {
            temp = numEqualChar(strs[0], strs[i]);
            (temp < length) ? (length = temp): (length);
            if (length == 0)
                return string();
        }	
        
        strs[0].resize(length); 
        return strs[0];
    }
};
