void bubbleSort(int arr[],int n){
	int i,j;
	bool swapped;
	for(i=0;i<n-1;i++){
		swapped=false;
	    for(j=0;j<n-i-1;j++){
		if(arr[j]>arr[i]){
		     swap(&arr[j],&arr[i]);
		     swapped=true;
		}
	    }
	
	if(swapped==false){
		break;
	}
}


