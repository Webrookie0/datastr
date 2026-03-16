
class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            // the core idea was to find a perfect split in the smaller array so that 
            // lets say if that array is split at k th elemnts , the total arrays have y elements 
            // then we have the second larger array split at y/2 -k 

            // if bigger array is 1st then swap both so that 1st array is smaller and it is easy to find 
            if(size(nums1)>size(nums2)){
                return findMedianSortedArrays(nums2, nums1);
            }

    
            int high = size(nums1);
            // the maxm we can get is max size of nums1
            int low=0;
            int mid=0;
            int sizee= (nums1.size() + nums2.size() +1)/2;
    
            while(low<=high){
                mid = low + (high-low )/2;
                // mid
                int maxleftA= (mid==0)?INT_MIN: nums1[mid-1];
                // left part of the split of nums1 has the last elemnt or the maxm elemnt that is maxleftA which is at mid-1
                int minrightA= (mid == nums1.size()) ? INT_MAX : nums1[mid];
                // right part is at nums1[mid] as 
                // 1 2 4 5 | 6 8 11 14 ;
                //  here this | is the split and behind this is left suabrray and after this starts the right subarray
                int maxleftB = (sizee - mid ==0) ? INT_MIN : nums2[sizee-mid-1] ;
                // left of tha nums2 is at half- mid-1;
                int minrightB = (sizee -mid  == nums2.size()) ?INT_MAX: nums2[sizee-mid]; 
                // and min right of nums2 is at hald -mid;
    
    
                if(maxleftA<=minrightB && maxleftB<=minrightA ){
                    if((size(nums1)+ size(nums2))%2==0){
                        return (min(minrightA , minrightB) + max(maxleftA , maxleftB))/2.0;
                        // if the size is even then half of the max( leftpart last of both the nums1 and nums2)
                        // + half part of min(right part of both nums1 and nums2)
    
                    }else{
                        // else max of leftA , leftB as we took half = both size +1 that will round off to half in case of even or 
                        // exactly mid in case of odd 
                        return max(maxleftA, maxleftB);
                    }
                }else if(maxleftB>minrightA){
                    // agar leftB bada hai rightA se to hmne median se pehle hi maar diya split right side chalo 
                    low = mid+1;
                }else{
                    // warna left side chalo median ke aage aa gaye hai hum log 
                    high = mid-1;
                }
            }
            return 0.0;
    
        }
    };