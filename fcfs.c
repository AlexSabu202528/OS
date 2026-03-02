#include<stdio.h>
int n;
int main(){
printf("Enter the number of processors:");
scanf("%d",&n);
int p[n],b[n],a[n],tat[n],ct[n],wt[n];
for(int i=0;i<n;i++){
	printf("Enter the processor ID :");
	scanf("%d",&p[i]);
	printf("Enter the Arrival Time :");
	scanf("%d",&a[i]);
	printf("Enter the Burst Time :");
	scanf("%d",&b[i]);
	printf("processor %d values has been taken succesfully..\n",i+1);
}

int time=0;
for(int j=0;j<n;j++){

if(time<a[j]){
	time=a[j];
}

	ct[j]=time+b[j];
	time=ct[j];
	tat[j]=ct[j]-a[j];
	wt[j]=tat[j]-b[j];
}

printf("Enter the FCFS of the process are..\n");
printf("\tPID\tAT\tBT\tCT\tTAT\tWT\t\n");
for(int k=0;k<n;k++){
printf("\t%d\t%d\t%d\t%d\t%d\t%d\n",p[k],a[k],b[k],ct[k],tat[k],wt[k]);
}
return 0;
}
