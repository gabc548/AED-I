// https://leetcode.com/problems/median-of-two-sorted-arrays/

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0, nums1Pos = 0, nums2Pos = 0, *finalArray;
    finalArray = (int*)malloc((nums1Size + nums2Size) * sizeof(int));

    while(i < nums1Size + nums2Size){
        if(nums1Pos < nums1Size && nums2Pos < nums2Size){
            if(nums1[nums1Pos] <= nums2[nums2Pos]){
                finalArray[i] = nums1[nums1Pos];
                nums1Pos++;
            }
            else{
                finalArray[i] = nums2[nums2Pos];
                nums2Pos++;
            }
        }
        else if(nums1Pos < nums1Size){
            finalArray[i] = nums1[nums1Pos];
            nums1Pos++;
        }
        else if(nums2Pos < nums2Size){
            finalArray[i] = nums2[nums2Pos];
            nums2Pos++;
        }
        i++;
    }

    double median;
    if((nums1Size + nums2Size) % 2 == 1){
        median = finalArray[(nums1Size + nums2Size) / 2];
    }
    else{
        median = finalArray[(nums1Size + nums2Size) / 2 - 1] + finalArray[(nums1Size + nums2Size) / 2];
        median = median / 2;
    }

    free(finalArray);

    return median;
    
}