#include <iostream>
using namespace std;

void swap(int *first, int *sec){
	int temp = *first;
	*first = *sec;
	*sec = temp;
}

class sorting{
	public:
		int array[6] = {3,7,9,2,1,8};
		int size = sizeof(array)/sizeof(array[0]);
		int curr, minIndex;
		int last = size-1;
		int first = 0;
		
		
		//Selection Sort
		void s_sorting(){
			for(curr = 0; curr<size-1; curr++){
				minIndex = curr;
				for(int j = curr+1; j<size; j++){
					if(array[j] < array[curr]){
						minIndex = j;
						swap(array[curr], array[minIndex]);
					}
				}
			}
		}
		
		//Bubble sort
		void bubbleSort(){
			for(curr = 0; curr<size-1; curr++){
				for(last = size-1; last>curr; last--){
					if(array[last] < array[last-1]){
						swap(array[last], array[last-1]);
					}
				}
			}
		}
		
		//Printing List
		void print(){
			for(int i = 0; i<size; i++){
				cout<<array[i]<<" ";
			}
		}
		
		//Merge Method
		void Merge(int value[], int leftstart, int leftlast, int rightstart, int rightlast){
			int temp_array[10];
			int index = leftstart;
			
			
			int saveIndex = leftstart;
			
			while((leftstart <= leftlast) && (rightstart <= rightlast)){
				if(value[leftstart] < value[rightstart]){
				//	cout<<"first while loop\n if run!\n";
					temp_array[index] = value[leftstart];
					leftstart++;
				} else {
				//	cout<<"first while loop\n else run!\n";
					temp_array[index] = value[rightstart];
					rightstart++;
				}
				index++;
			}
				
				while(leftstart <= leftlast){
				//	cout<<"second while loop\n";
					temp_array[index] = value[leftstart];
					leftstart++;
					index++;
				}
				
				while(rightstart <= rightlast){
				//	cout<<"third while loop\n";
					temp_array[index] = value[rightstart];
					rightstart++;
					index++;
				}
				
				for(index = saveIndex; index <= rightlast; index++){
					value[index] = temp_array[index];
				//	cout<<"For loop\n";
				}
				
			}
		
		
		//Merge Sort
		void MergeSort(int value[], int start, int last){
			if(start < last){
				int mid = (start + last) / 2;
				MergeSort(value, start, mid);
				MergeSort(value, mid+1, last);
				Merge(value, start, mid, mid+1, last);	
			}
		}
};

int main(){
	cout<<"\t\tWelcome jee!\n\n";
	
//	int array[] = {3,2,5,1,8,6,4,9,7};
	int first = 0;
//	int len = sizeof(array)/sizeof(array[0]);
	//int last = len-1;
	
	sorting *ss = new sorting();
	ss->s_sorting();
	
	//ss->bubbleSort();
	/*cout<<"Original List ==> ";
	for(int i = 0; i<=last; i++){
		cout<<array[i]<<" ";
	}
	ss->MergeSort(array, first, last);
	cout<<"\nMerge Sorted List ==> ";*/
	for(int i = 0; i<=5; i++){
		cout<<ss->array[i]<<" ";
	}
}
