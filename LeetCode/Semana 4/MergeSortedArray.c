// https://leetcode.com/problems/merge-sorted-array/

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int pos1 = m - 1, pos2 = n - 1;

    for(int i = nums1Size - 1; i >= 0; i--){
        if(pos1 >= 0 && pos2 >= 0){
            if(nums1[pos1] >= nums2[pos2]){
                nums1[i] = nums1[pos1];
                pos1--;
            }
            else{
                nums1[i] = nums2[pos2];
                pos2--;
            }
        }
        else if(pos1 < 0){
            nums1[i] = nums2[pos2];
            pos2--;
        }
        else if(pos2 < 0){
            nums1[i] = nums1[pos1];
            pos1--;
        }
    }

    return;
    
}