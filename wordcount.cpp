#include<stdio.h>
#include<string.h>
int *getcharnum(char *filename,int *totalnum);
int main(){
	char filename[30];
	int totalnum[3]={1,1,1};//�С��ַ�������
	char control[5];
	char a[5]="-c";
	scanf("%s",control);
	printf("Input file name:");
	scanf("%s",filename);
	if(getcharnum(filename,totalnum)){
		if(strcmp(control,a)==0)
			printf("�ַ���%d",totalnum[1]);
		else
			printf("������%d",totalnum[2]);
	}
	else
		printf("Error!");
	return 0;
} 
int *getcharnum(char *filename,int *totalnum){
	FILE *fp;
	char buffer[1003];//�洢���������� 
	int bufferlen;//���ʵ�ʳ���
	int i;
	char c;
	int islastblank=0;//�ж���һ���ַ��Ƿ�Ϊ�ո�
	int charnum=0;
	int wordnum=0;
	if((fp=fopen(filename,"rb"))==NULL){
		perror(filename);
		return NULL;
	} 
	while(fgets(buffer,1003,fp)!=NULL){
		bufferlen=strlen(buffer);
		for(i=0;i<buffer[i];i++){
			c=buffer[i];
			if(c==' '||c=='\t'){
				!islastblank && wordnum++;
				islastblank=1;
			}
			else if(c!='\n'&&c!='\r'){
				charnum++;
				islastblank=0;
			}
		}
		!islastblank && wordnum++;
		islastblank=1;
		totalnum[0]++;
		totalnum[1]+=charnum;
		totalnum[2]+=wordnum;
	}
	return totalnum; 
}

