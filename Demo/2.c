#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1
/*�Ӽ���������10��ѧ�����й����ݣ�Ȼ�������ת�浽�����ļ���ȥ*/
typedef struct STU_INFO{
	char name[2];
	int age;
	int stu_num;
	char addr[15];
}student_info;

void save(student_info stu[]);
int main(){
	student_info stu[N];
	int i; 
	printf("please enter name,age,stu_num,addr:\n");
	for(i=0;i<N;i++){
		scanf("%s %d %d %s",stu[i].name,&stu[i].age,&stu[i].stu_num,stu[i].addr);
	}
	save(stu);
	return 0;
} 

void save(student_info stu[]){
	FILE *fp;
	int i;
    fp = fopen(".\\note.txt","wb");
	if(fp == NULL){
		printf("error file\n");
		exit(0);
	}
	// fflush(fp);
	for(i=0;i<N;i++){
		printf("%s %d %d %s\n",stu[i].name,stu[i].age,stu[i].stu_num,stu[i].addr);
		if(fwrite(&stu[i],sizeof(struct STU_INFO),1,fp)!=1){
			printf("write error\n");
		}
	}	
	fclose(fp);	
}
