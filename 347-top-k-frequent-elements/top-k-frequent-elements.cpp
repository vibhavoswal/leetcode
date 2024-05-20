class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;

        for(auto num: nums) {
            freq[num]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 

        int count = 0;
        for(auto& [key,value]: freq) {
            if(count < k) {
                pq.push({value, key});
                count++;
            }
            else {
                auto temp = pq.top();
                if(value > temp.first) {
                    pq.pop();
                    pq.push({value, key});
                }
            }
        }

        vector<int> ans;
        while(!pq.empty()) {
            auto temp = pq.top();
            ans.push_back(temp.second);
            pq.pop();
        }

        return ans;
    }
};