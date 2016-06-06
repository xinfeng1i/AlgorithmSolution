bool increasingTriplet(vector<int>& nums) {
    int first_min = INT_MAX;
    int second_min = INT_MAX;
    for (int x : nums) {
        if (x <= first_min) {
            first_min = x;
        } else if (x <= second_min) {
            second_min = x;
        } else {
            return true;
        }
    }
    return false;
}
