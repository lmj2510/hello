/*#include<iostream>
10797��
int main(void){

	int date = 0;
	int x[5] = {0,0,0,0,0};
	int count = 0;

	std::cin>>date;
	std::cout<<"\n";

	for(int i=0;i<5;i++){
		std::cin>>x[i];
		if(x[i] == date){
			count++;
		}
	}

	std::cout<<count<<"\n";
}*/

/*#include<iostream>
//10798��
int main(void){

	int i,j;
	char x[5][15];

	for(i=0;i<5;i++){
		for(j=0;j<15;j++){
			x[i][j] = NULL;
		}
	}

	i=0;
	j=0;

	while(i<5){
		if(std::cin.peek() != '\n'){
			std::cin>>x[i][j];
			j++;
		}else{
			std::cin.ignore();
			i++;
			j=0;
		}
	}

	//������ for������ ������ �ٲٷ��ؼ� �ڲ� ������?

	for(j=0;j<15;j++){
		for(i=0;i<5;i++){
			if(x[i][j] != NULL){
				std::cout<<x[i][j];
			}
		}
	}
	return 0 ;
}*/

//���ڵ�
/*#include<iostream>
char a[5][15];
int i,j;

void main(){
	for(i;i<5;i++)
		std::cin>>a[i];
	for(i=0;i<15;i++)
		for(j=0;j<5;j++)
			if(a[j][i])
				std::cout<<a[j][i];
}*/



