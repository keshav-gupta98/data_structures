import java.util.Scanner;
public class HeapSort {
    public static void main(String[] args) {
        int arr[] = {4,7,1,6,9,10,32,12};
        heapSort(arr);
        for(int i =0 ;i< arr.length ; i++)
        System.out.print(arr[i] + " ");
    }
    public static void heapSort(int []arr)
    {
        int n = arr.length;
        int start = n/2 -1;
        int i;
        for(i=start;i>=0;i--)
        {
            heapify(arr,i,arr.length);
        }
        for(i=n-1;i>=0;i--)
        {
            swap(arr,0,i);
            heapify(arr,0,i);
        }
    }
    public static void heapify(int arr[], int i , int n)
    {
        int l = i*2 + 1;
        int r = i*2 + 2;
        int largest = i;
        if(l<n && arr[largest] < arr[l] )
        largest = l;
        if(r<n && arr[largest] < arr[r] )
        largest = r;
        if(largest!=i)
        {
            swap(arr,largest,i);
            heapify(arr, largest, n);
        }
    }
    public static void swap(int arr[] , int i , int j)
    {
        int c = arr[i] + arr[j];
        arr[i] = c - arr[i];
        arr[j] = c - arr[j];
    }    
}