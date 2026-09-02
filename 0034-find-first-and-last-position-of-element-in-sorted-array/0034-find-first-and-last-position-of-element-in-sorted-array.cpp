class Solution {
public:
    int firstPos(vector<int>&arr, int tar,int n){
        int l=0,h=n-1;
        int first =-1;
        while(l<=h){
            int mid=l + (h-l)/2;
            if(arr[mid]==tar){
                first = mid;
                h=mid-1;
            }
            else if(arr[mid]<tar) l = mid + 1;
            else h = mid-1;
        }
        return first;
    }

    int lastPos(vector<int>&arr, int tar,int n){
        int l=0,h=n-1;
        int last =-1;
        while(l<=h){
            int mid=l + (h-l)/2;
            if(arr[mid]==tar){
                last = mid;
                l=mid+1;
            }
            else if(arr[mid]<tar) l = mid + 1;
            else h = mid-1;
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first = firstPos(nums,target,n);
        if(first == -1) return {-1,-1};
        int last = lastPos(nums,target,n);
        return {first,last};
    }
};