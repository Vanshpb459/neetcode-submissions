class Solution {
public:
    string frequency(string str)
    {
        sort(str.begin(), str.end());

        string s = "";

        for (int i = 0; i < str.length(); )
        {
            int count = 1;
            int j = i + 1;

            while (j < str.length() && str[j] == str[i])
            {
                count++;
                j++;
            }

            s += str[i];
            s += to_string(count);

            i = j;
        }

        return s;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        map<string, vector<string>> freqMap;

        for (string str : strs)
        {
            string freqString = frequency(str);
            freqMap[freqString].push_back(str);
        }

        vector<vector<string>> ans;

        for (auto &p : freqMap)
            ans.push_back(p.second);

        return ans;
    }
};