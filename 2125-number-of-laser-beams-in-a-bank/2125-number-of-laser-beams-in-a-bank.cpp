class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int beams = 0;
        map<int, int> mp;
        for (int i = 0; i < bank.size(); i++)
            for (auto cell : bank[i])
                if (cell == '1')
                    mp[i]++;

        if(mp.size()<=1)  return 0;
        auto it = mp.begin();
        int prev = it->second;
        it++;
        while (it != mp.end()) {
            beams += prev * it->second;
            prev = it->second;
            it++;
        }
        
        return beams;
    }
};