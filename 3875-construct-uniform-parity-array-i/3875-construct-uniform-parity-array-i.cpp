class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        bool canOdd = true;
        bool canEven = true;

        for (int i = 0; i < n; i++) {
            bool oddPossible = (nums1[i] % 2 != 0);
            bool evenPossible = (nums1[i] % 2 == 0);

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int x = nums1[i] - nums1[j];

                if (x % 2 != 0)
                    oddPossible = true;

                if (x % 2 == 0)
                    evenPossible = true;
            }

            if (!oddPossible)
                canOdd = false;

            if (!evenPossible)
                canEven = false;
        }

        return canOdd || canEven;
    }
};