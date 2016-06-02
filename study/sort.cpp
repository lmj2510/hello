#include<stdio.h>
#include<string>

/*

void selectsort(int a[10]){	// ��������

	int i,j;
	int max = 0;
	int mIndex;
	int last = 9;
	int temp;

	for(i=0;i<9;i++){			// �迭 ���� ���� ��ŭ �ݺ�
		for(j=0;j<last;j++){	// ���ĵ��� ���� �͵� �߿��� �ִ� �� �˻�
			if(a[j] > max){		// ���ο� �ִ밪�̸�
				max = a[j];		// �ִ밪 �ٽ� �Ҵ�
				mIndex = j;		
			}
		}
		if(last > 1){			// �� ���ĉ�µ� 
								// 13 9 23 34 55 66 78 90 �̷������� ù��° �ι�° �ٲ�� �� ����
			temp = a[mIndex];
			a[mIndex] = a[last];
			a[last] = temp;		// �ִ밪�� ���ʳ����� ����
			last--;				// ���ĵ��� ���� ���� �ϳ� ����
			max = 0;			// max �� �ʱ�ȭ

			for(int i=0;i<10;i++){	// ���ĵǴ� ���� ���
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

void insertsort(int a[10]){	// ��������

	int i,j,k;
	int temp;
	//int x = 0;

	for(i=1;i<10;i++){		// �ݺ�Ƚ��
		for(j=0;j<i;j++){	// ���� ��Һ��� �տ� �ִ� �͵��ϰ� ���ϵ���
			//if((a[i] < a[j]) && (x != 1)){
			if(a[i] < a[j]){
				//x = 1;				// �ѹ� ���������� �̹� ȸ���� ������ �ٽ� ���� �ʵ���
										// �̰� ��� 59���� break ���� ��!
				temp = a[i];		// ������ �� �����ϰ� (������ ������ ���)
				
				//for(k=0;k<(i-j);k++){	// �ڷ� �ϳ��� �̷��
				//	a[j+(k+1)] = a[j+k];
				//}

				for(k=(i-j-1);k>=0;k--){// ���� �ͺ��� �̷����
										// �ȱ׷��� ��� ���� ������ �ڷ� �� ĭ�� �̵��ϴ� ��
					a[j+(k+1)] = a[j+k];
				}
				a[j] = temp;	// ����
				break;
			}
		}
		//x = 0;
		for(int i=0;i<10;i++){	// ���ĵǴ� ���� ���
			printf("%d ",a[i]);
		}
		printf("\n");
	}
}
void insertsort(int a[10]){ // insert �Լ� ����

	int i,j,k;
	int temp;

	for(i=1;i<10;i++){		
		for(j=0;j<i;j++){	
			if(a[i] < a[j]){
				temp = a[i];		

				//for(k=(i-j-1);k>=0;k--){
										
				//	a[j+(k+1)] = a[j+k];
				//}

				for(k=i;k>j;k--){	// �� ����!
					a[k] = a[k-1];
				}
				a[j] = temp;	
				break;
			}
		}
	}
}
*/

void Merge(int a[10], int F, int mid, int L){	// ��������

	int temp[10];	// �ӽù迭

	int First1 = F; int Last1 = mid;
	int First2 = mid+1;  int Last2 = L;
	int index;

	for(index = First1; (First1 <= Last1) && (First2 <= Last2) ; index++){		// => while�� �ٲ㵵��
	
		if(a[First1] < a[First2]){
			temp[index] = a[First1];
			First1++;
		
		}else{
			temp[index]= a[First2];
			First2++;
		}
	}

	for(; First1 <= Last1 ; First1++, index++){		// => ������ ��ũ��
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
		int Middle = (First + Last) / 2; // -> ��, ������
		MergeSort(a, First, Middle);
		MergeSort(a, Middle+1, Last);
		Merge(a,First, Middle, Last);		// ������ ���߿�
	}
}

int partition(int a[10], int F, int L)	// first�� last�� �迭 ��ü�� ó���� ��
{
	int low, high, p; // ���ҵ� �迭 �������� ó��, ��, �ǹ�
	int temp;

	p = a[L];
	low = F;
	high = L-1;

	while(low <= high){
		while(p > a[low]){
			low++; // ���ؿ� �´� ��
		}
		
		while(p < a[high]){	
			high--;
		}

		// a[low]�� �ǹ����� ũ�ų�, a[high]�� �ǹ����� ���� ��
		if( low <= high ){
			temp = a[high];
			a[high] = a[low];
			a[low] = temp;
		}
	}

	temp = a[high];
	a[high] = a[L];
	a[L] = temp;

	return high; // ���� �ǹ� index�� ����;

}
void QuickSort(int a[10], int first, int last){

	if(first < last){
		int PivotIndex = partition(a, first, last);		// �ǹ� �������� ������ ����
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