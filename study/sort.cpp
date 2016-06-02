#include<stdio.h>
#include<string>

/*

void selectsort(int a[10]){	// 선택정렬

	int i,j;
	int max = 0;
	int mIndex;
	int last = 9;
	int temp;

	for(i=0;i<9;i++){			// 배열 원소 갯수 만큼 반복
		for(j=0;j<last;j++){	// 정렬되지 않은 것들 중에서 최대 값 검색
			if(a[j] > max){		// 새로운 최대값이면
				max = a[j];		// 최대값 다시 할당
				mIndex = j;		
			}
		}
		if(last > 1){			// 다 정렬됬는데 
								// 13 9 23 34 55 66 78 90 이런식으로 첫번째 두번째 바뀌는 것 방지
			temp = a[mIndex];
			a[mIndex] = a[last];
			a[last] = temp;		// 최대값을 한쪽끝으로 보냄
			last--;				// 정렬되지 않은 갯수 하나 줄임
			max = 0;			// max 값 초기화

			for(int i=0;i<10;i++){	// 정렬되는 과정 출력
				printf("%d ",a[i]);
			}
			printf("\n");
		}
	}
}
void selectsort(int a[10]){

	int i,j;
	int max = 0;
	int maxIndex = 0;
	int temp;
	int last = 9;

	for(i=0;i<10;i++){
		for(j=0;j<last;j++){
			if(a[j] > max){
				max = a[j];
				maxIndex = j;
			}
		}

		if(last>1){
			temp = a[last];
			a[last] = a[maxIndex];
			a[maxIndex] = temp;

			last--;
			max = 0;
		}
	}
}

void insertsort(int a[10]){	// 삽입정렬

	int i,j,k;
	int temp;
	//int x = 0;

	for(i=1;i<10;i++){		// 반복횟수
		for(j=0;j<i;j++){	// 비교할 요소보다 앞에 있는 것들하고만 비교하도록
			//if((a[i] < a[j]) && (x != 1)){
			if(a[i] < a[j]){
				//x = 1;				// 한번 삽입했으면 이번 회차엔 삽입을 다시 하지 않도록
										// 이거 대신 59줄의 break 쓰면 됨!
				temp = a[i];		// 삽입할 값 저장하고 (정렬할 데이터 백업)
				
				//for(k=0;k<(i-j);k++){	// 뒤로 하나씩 미루고
				//	a[j+(k+1)] = a[j+k];
				//}

				for(k=(i-j-1);k>=0;k--){// 뒤의 것부터 미뤄야함
										// 안그러면 계속 같은 값으로 뒤로 한 칸씩 이동하는 것
					a[j+(k+1)] = a[j+k];
				}
				a[j] = temp;	// 삽입
				break;
			}
		}
		//x = 0;
		for(int i=0;i<10;i++){	// 정렬되는 과정 출력
			printf("%d ",a[i]);
		}
		printf("\n");
	}
}
void insertsort(int a[10]){ // insert 함수 최종

	int i,j,k;
	int temp;

	for(i=1;i<10;i++){		
		for(j=0;j<i;j++){	
			if(a[i] < a[j]){
				temp = a[i];		

				//for(k=(i-j-1);k>=0;k--){
										
				//	a[j+(k+1)] = a[j+k];
				//}

				for(k=i;k>j;k--){	// 더 간단!
					a[k] = a[k-1];
				}
				a[j] = temp;	
				break;
			}
		}
	}
}
*/

void Merge(int a[10], int F, int mid, int L){	// 병합정렬

	int temp[10];	// 임시배열

	int First1 = F; int Last1 = mid;
	int First2 = mid+1;  int Last2 = L;
	int index;

	for(index = First1; (First1 <= Last1) && (First2 <= Last2) ; index++){		// => while로 바꿔도됨
	
		if(a[First1] < a[First2]){
			temp[index] = a[First1];
			First1++;
		
		}else{
			temp[index]= a[First2];
			First2++;
		}
	}

	for(; First1 <= Last1 ; First1++, index++){		// => 은정씨 매크로
		temp[index] = a[First1];
	}
	for(; First2 <= Last2 ; First2++, index++){
		temp[index] = a[First2];
	}
	for(index = F; index <= L; index++){
		a[index] = temp[index];
	}

}
void MergeSort(int a[10], int First, int Last){

	if(First < Last){
		int Middle = (First + Last) / 2; // -> 몫, 나머지
		MergeSort(a, First, Middle);
		MergeSort(a, Middle+1, Last);
		Merge(a,First, Middle, Last);		// 정렬을 나중에
	}
}

int partition(int a[10], int F, int L)	// first와 last는 배열 자체의 처음과 끝
{
	int low, high, p; // 분할된 배열 내에서의 처음, 끝, 피벗
	int temp;

	p = a[L];
	low = F;
	high = L-1;

	while(low <= high){
		while(p > a[low]){
			low++; // 기준에 맞는 것
		}
		
		while(p < a[high]){	
			high--;
		}

		// a[low]가 피벗보다 크거나, a[high]가 피벗보다 작을 때
		if( low <= high ){
			temp = a[high];
			a[high] = a[low];
			a[low] = temp;
		}
	}

	temp = a[high];
	a[high] = a[L];
	a[L] = temp;

	return high; // 현재 피벗 index를 리턴;

}
void QuickSort(int a[10], int first, int last){

	if(first < last){
		int PivotIndex = partition(a, first, last);		// 피벗 기준으로 정렬을 먼저
		QuickSort(a, first, PivotIndex);
		QuickSort(a, PivotIndex+1, last);
	}
}

void main(){

	int a[10] = {481, 241, 454, 325, 452, 685, 498, 890, 281, 121};

	//selectsort(a);
	//insertsort(a);
	//MergeSort(a,0,9);
	QuickSort(a,0,9);

	for(int i =0; i <10 ; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}