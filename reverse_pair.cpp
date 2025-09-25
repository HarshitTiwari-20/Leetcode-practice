//#include <bits/stdc++.h>

void merge(vector<int> &arr, int low, int mid, int high){
	vector<int> temp; 
	int left = low;
	int right = mid + 1;
	while(left <= mid && right <= high){
		if(arr[left] <= arr[right]){
			temp.push_back(arr[left]);
			left++;
		}
		else{
			temp.push_back(arr[right]);
			right++;
		}
	}
	while(right <= high){
		temp.push_back(arr[right]);
		right++;
	}
	for(int i =low; i<=high; i++){
		arr[i] = temp[ i - low];
	}
}
int countpairs(vector<int> &arr, int low, int mid, int high){
	int right = mid +1;
	cnt = 0;
	for(int i = low; i<= mid; i++){
		while(right <= high && arr[i] > 2 * arr[right]) right++;
		cnt += (right - (mid +1));
	}
	return cnt;
}

void mergeSort(vector<int> &arr, int low, int high){
	cnt = 0;
	if (low >= high) return cnt;
	int mid = (low + high) /2;
	cnt += mergeSort(arr, low, mid);
	cnt += mergeSort(arr, mid + 1; high);
	cnt += countpairs(arr, low, mid , high);
	merge(arr, low, mid, high);
	return cnt;
}

   int reversePairs(vector<int>& nums, int n) {
	   return mergeSort(nums, 0, n-1);
	  
        
};





//======================================================================================
class Solution {
public:
 //#include <bits/stdc++.h>

void merge(vector<int> &arr, int low, int mid, int high){
	vector<int> temp; 
	int left = low;
	int right = mid + 1;
	while(left <= mid && right <= high){
		if(arr[left] <= arr[right]){
			temp.push_back(arr[left]);
			left++;
		}
		else{
			temp.push_back(arr[right]);
			right++;
		}
	}
	while(right <= high){
		temp.push_back(arr[right]);
		right++;
	}
	for(int i =low; i<=high; i++){
		arr[i] = temp[ i - low];
	}
}
int countpairs(vector<int> &arr, int low, int mid, int high){
	int right = mid +1;
	int cnt = 0;
	for(int i = low; i<= mid; i++){
		while(right <= high && arr[i] > 2 * arr[right]) right++;
		cnt += (right - (mid +1));
	}
	return cnt;
}

void mergeSort(vector<int> &arr, int low, int high){
	int cnt = 0;
	if (low >= high) return cnt;
	int mid = (low + high) /2;
	cnt += mergeSort(arr, low, mid);
	cnt += mergeSort(arr, mid + 1; high);
	cnt += countpairs(arr, low, mid , high);
	merge(arr, low, mid, high);
	return cnt;
}

   int reversePairs(vector<int>& nums, int n) {
	   return mergeSort(nums, 0, n-1);
	  
        
};


};



//=======================================================================================


class Solution {
public:
    int count = 0;

    void merge(int low, int mid, int high, vector<int>& nums) {
        int n1 = mid - low + 1;
        int n2 = high - mid;

        vector<int> l(n1), r(n2);
        for (int i = 0; i < n1; i++)
            l[i] = nums[low + i];
        for (int i = 0; i < n2; i++)
            r[i] = nums[mid + 1 + i];

        // Count reverse pairs
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // Merge two sorted halves
        int i = 0;
        j = 0;
        int k = low;
        while (i < n1 && j < n2) {
            if (l[i] <= r[j]) {
                nums[k++] = l[i++];
            } else {
                nums[k++] = r[j++];
            }
        }
        while (i < n1) nums[k++] = l[i++];
        while (j < n2) nums[k++] = r[j++];
    }

    void merge_sort(int low, int high, vector<int>& nums) {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        merge_sort(low, mid, nums);
        merge_sort(mid + 1, high, nums);
        merge(low, mid, high, nums);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size() - 1;
        merge_sort(0, n, nums);
        return count;
    }
};
