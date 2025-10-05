class Solution {
  private:
    void merge(vector<int>& arr, int l, int mid, int r){
        int left = mid - l +1;
        int right = r - mid;
        int L[left],R[right];
        int k = l;
        
        for(int i = 0;i<left;i++){
            L[i] = arr[k];
            k++;
        }
        for(int i = 0;i < right;i++){
            R[i] = arr[k];
            k++;
        }
        int i = 0;
        int j = 0;
        k = l;
        while(i<left && j < right){
            if(L[i] <= R[j]){
                arr[k] = L[i++];
            }else{
                arr[k] = R[j++];
            }
            k++;
        }
        while(i<left){
            arr[k++] = L[i++];
        }
        while(j < right){
            arr[k++] = R[j++];
        }
    }
  public:
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        
        if(l<r){
            int mid = l + (r-l)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
        
    }
};