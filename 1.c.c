  #include <stdio.h>
 #include <stdlib.h>
  #include <string.h>
  int main()
{

 FILE *fp = fopen("cpu_burst.txt", "r");
  int bt[20],p[20],wt[20],tat[20],i=0,j,n=5,total=0,pos,temp;
     float avg_wt,avg_tat;
  printf("\nReading CPU_BURST.txt File\n");
     //for(i=0;i<5;i++)
     while((getc(fp))!=EOF)
     {

         fscanf(fp, "%d", &bt[i]);
           if(bt[i]>0){
         p[i]=i+1;  i++;}         //contains process number
}
n=i;
for(i=0;i<n;i++)

{
    pos=i;
    for(j=i+1;j<n;j++)
    {
        if(bt[j]<bt[pos])
            pos=j;
    }
    
    temp=bt[i];
    bt[i]=bt[pos];
    bt[pos]=temp;
    temp=p[i];
    p[i]=p[pos];
    p[pos]=temp;
}
wt[0]=0;            //waiting time for first process will be zero
//calculate waiting time
for(i=1;i<n;i++)
{
    wt[i]=0;
    for(j=0;j<i;j++)
        wt[i]+=bt[j];
    total+=wt[i];
}
avg_wt=(float)total/n;      //average waiting time
total=0;
printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
   for(i=0;i<n;i++)
   {
       tat[i]=bt[i]+wt[i];     //calculate turnaround time
       total+=tat[i];
       printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
   }
   avg_tat=(float)total/n;     //average turnaround time
   printf("\n\nAverage Waiting Time=%f",avg_wt);
   printf("\nAverage Turnaround Time=%f\n",avg_tat);
   fclose(fp);
   return 0;
}
