#include <stdio.h>
#define MAX 10

void yolYazdir(int path[],int length){
	int i;
	for(i=0;i<length;i+=2){
		printf("(%d,%d)",path[i],path[i+1]);
	}
	printf("\n");
}
int countPaths(int i,int j,int n,int matris[][MAX],int path[],int pathLength){
	int rightpaths;
	int downpaths;
	if(i==n-1 && j==n-1){
		path[pathLength++]=i;
		path[pathLength++]=j;
		yolYazdir(path,pathLength);
		return 1;//1yol tamamlandi
	}	
	if(i>=n || j>=n || matris[i][j]==0){
		return 0;//geçersiz yol
	}
	path[pathLength++]=i;
	path[pathLength++]=j;
	
	rightpaths=countPaths(i+1,j,n,matris,path,pathLength);//saga gitme yol sayisi
	downpaths=countPaths(i,j+1,n,matris,path,pathLength);//asagi gitme yol sayisi
	return rightpaths+downpaths;
}
void matrisAlma(int n,int matris[][MAX]){
	int i,j;
	printf("Matris giriniz.\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&matris[i][j]);
		}
	}
}
void matrisYazdir(int n,int matris[][MAX]){
	int i,j;
	printf("Matris;\n");
	for(i=0;i<n;i++){
		printf("\n");
		for(j=0;j<n;j++){
			printf("%d",matris[i][j]);
		}
	}
	printf("\n");
}
int main(){
	int n;
	int matris[MAX][MAX];
	int path[2*MAX]={0};
	printf("Matris boyutu giriniz.\n");
	scanf("%d",&n);
	do{
		matrisAlma(n,matris);
		matrisYazdir(n,matris);
		printf("Toplam yol sayisi=%d\n",countPaths(0,0,n,matris,path,0));
		printf("Yeniden denemek icin matris boyutu giriniz n<=0 cikis\n");
		scanf("%d",&n);
	}while(n>0);
	return 0;
}
