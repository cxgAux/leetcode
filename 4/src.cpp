#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int> & nums1, vector<int> & nums2) {
		int sz1 = nums1.size(), sz2 = nums2.size();
		if(sz1 > sz2) {
			swap(nums1, nums2);
			swap(sz1, sz2);
		}
		if(sz1 == 0) {
		    if(sz2 == 0) {
		        return 0;
		    }
		    else {
		        return sz2 % 2 == 0 ? (nums2[sz2 / 2] - nums2[sz2 / 2 - 1]) / 2.0 + nums2[sz2 / 2 - 1] : double(nums2[sz2 / 2]);// to avoid overflow, but there are still no cases to challenge this
		    }
		}
		return findMedianSortedArrays(nums1, 0, sz1 - 1, nums2, 0, sz2 - 1);
	}

	double findMedianSortedArrays(vector<int> & nums1, int s1, int e1, vector<int> & nums2, int s2, int e2) {
		if((e1 - s1) < 2) {
			return merge_and_search(nums1, s1, e1, nums2, s2, e2);
		}
		else {
			int m1 = (e1 - s1) / 2 + s1, m2 = (e2 - s2) / 2 + s2;
			if(nums1[m1] <= nums2[m2]) {
				return findMedianSortedArrays(nums1, m1, e1, nums2, s2, e2 - m1 + s1);
			}
			else {
				return findMedianSortedArrays(nums1, s1, e1 - m1 + s1, nums2, s2 + m1 - s1, e2);
			}
		}
	}

	double merge_and_search(vector<int> & nums1, int s1, int e1, vector<int> & nums2, int s2, int e2) {
		int sz = e2 - s2 + 1, p = (sz - 1) / 2 + s2;
		vector<int> cur(nums1.begin() + s1, nums1.begin() + e1 + 1);
		if(p - 1 >= s2) {
		    cur.push_back(nums2[p - 1]);
		}
		cur.push_back(nums2[p]);
		if(p + 1 <= e2) {
		    cur.push_back(nums2[p + 1]);
		    if(sz % 2 == 0 && p + 2 <= e2) {
		        cur.push_back(nums2[p + 2]);
		    }
		}
		sort(cur.begin(), cur.end());
		sz = cur.size();
		return sz % 2 == 0 ? (cur[sz / 2] - cur[sz / 2 - 1]) / 2.0 + cur[sz / 2 - 1]: double(cur[sz / 2]);
	}
};

int main(int argc, char * const argv[]) {
	vector<int> v1{1, 2, 3, 7, 8, 9}, v2{4, 5, 6, 10, 11, 12};
	Solution s;
	cout << s.findMedianSortedArrays(v1, v2) << endl;
	return 0;
}
