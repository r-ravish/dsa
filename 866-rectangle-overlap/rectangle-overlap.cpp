class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int a = max(rec1[0], rec2[0]);
        int b = min(rec1[2], rec2[2]);

        int c = max(rec1[1], rec2[1]);
        int d = min(rec1[3], rec2[3]);

        return a<b && c<d;
    }
};