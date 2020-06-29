/*
	Given a sorted array A of size N. 
	The function remove_duplicate takes two arguments. 
	The first argument is the sorted array A[] and the second argument is 'N' the size of the array 
	and returns the size of the new converted array A[] with no duplicate element.
*/

int remove_duplicate(int A[],int N)
{
	// i - used to traverse the array
	// j - denotes the index at which a new unique element can be inserted
	int i, j;
	
	for(i=1, j=1; i<N; ++i) {
		if(A[i] == A[i-1]) continue;
		A[j++] = A[i];
	}

	return j;
}