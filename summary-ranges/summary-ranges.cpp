class Solution {
public:
   vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans;

    if (nums.empty()) {
        return ans;  // Return an empty vector if nums is empty
    }

    int start = nums[0], end = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i - 1] != (nums[i] - 1)) {
            string range = to_string(start);
            if (start != end) {
                range += "->" + to_string(end);
            }
            ans.push_back(range);

            start = nums[i];
            end = nums[i];
        } else {
            end = nums[i];
        }
    }

    string range = to_string(start);
    if (start != end) {
        range += "->" + to_string(end);
    }
    ans.push_back(range);

    return ans;
}

};