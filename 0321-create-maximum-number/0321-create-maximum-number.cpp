class Solution {
public:
    // Get maximum subsequence of length k
    vector<int> getMaxSubsequence(vector<int>& nums, int k) {

        int remove = nums.size() - k;
        vector<int> st;

        for (int x : nums) {

            while (!st.empty() && st.back() < x && remove > 0) {

                st.pop_back();
                remove--;
            }

            st.push_back(x);
        }

        // If removals are still remaining
        while (remove > 0) {
            st.pop_back();
            remove--;
        }

        return st;
    }

    // Is A[i...] lexicographically greater than B[j...]?
    bool greater(vector<int>& A, int i, vector<int>& B, int j) {

        while (i < A.size() && j < B.size()) {

            if (A[i] > B[j])
                return true;

            if (A[i] < B[j])
                return false;

            i++;
            j++;
        }

        // If B finished first, A is greater
        return j == B.size();
    }

    // Merge two subsequences to get maximum sequence
    vector<int> merge(vector<int>& A, vector<int>& B) {

        vector<int> result;

        int i = 0;
        int j = 0;

        while (i < A.size() || j < B.size()) {

            if (greater(A, i, B, j)) {
                result.push_back(A[i]);
                i++;
            } else {
                result.push_back(B[j]);
                j++;
            }
        }

        return result;
    }

    // Compare two complete answers
    bool isGreater(vector<int>& A, vector<int>& B) {

        for (int i = 0; i < A.size(); i++) {

            if (A[i] > B[i])
                return true;

            if (A[i] < B[i])
                return false;
        }

        return false;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<int> answer;

        int n1 = nums1.size();
        int n2 = nums2.size();

        // Try every possible split
        for (int take1 = 0; take1 <= k; take1++) {

            int take2 = k - take1;

            // Split must be possible
            if (take1 > n1 || take2 > n2)
                continue;

            // Best subsequence from each array
            vector<int> A = getMaxSubsequence(nums1, take1);

            vector<int> B = getMaxSubsequence(nums2, take2);

            // Merge them
            vector<int> candidate = merge(A, B);

            // Keep maximum candidate
            if (answer.empty() || isGreater(candidate, answer)) {

                answer = candidate;
            }
        }

        return answer;
    }
};