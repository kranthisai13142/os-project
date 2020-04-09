#include<stdio.h>
int main()
{
int v,n,pr[10]={1,2,3,4,5,6,7,8,9,10},least,k=1,tb=0;
int bt[10],dif,x,vt[10],wt[10],tt[10],tv=0,add=0;
float waverage=0,taverage=0,tadd=0,wadd=0;
printf("\n***SJF Scheduling*\n");
printf("\nEnter number of processes :");
scanf("%d",&n);
 
for(v=0;v<n;v++)
{
printf("\nEnter the arrival time of process %d :",v+1);
scanf(" %d",&vt[v]);
printf("\nEnter the burst time of process %d:",v+1);
scanf(" %d",&bt[v]);

}
 

 
for(v=0;v<n;v++)
{
for(x=0;x<n;x++)
{
if(vt[v]<vt[x])
{
dif=pr[x];
pr[x]=pr[v];
pr[v]=dif;
dif=vt[x];
vt[x]=vt[v];
vt[v]=dif;
dif=bt[x];
bt[x]=bt[v];
bt[v]=dif;
}
}
}
 

for(x=0;x<n;x++)
{
tb=tb+bt[x];
least=bt[k];
for(v=k;v<n;v++)
{
if (tb>=vt[v] && bt[v]<least
)
{
dif=pr[k];
pr[k]=pr[v];
pr[v]=dif;
dif=vt[k];
vt[k]=vt[v];
vt[v]=dif;
dif=bt[k];
bt[k]=bt[v];
bt[v]=dif;
}
}
k++;
}
wt[0]=0;
for(v=1;v<n;v++)
{
add=add+bt[v-1];
wt[v]=add-vt[v];
wadd=wadd+wt[v];
}
 
waverage=(wadd/n);
for(v=0;v<n;v++)
{
tv=tv+bt[v];
tt[v]=tv-vt[v];
tadd=tadd+tt[v];
}
 
taverage=(tadd/n);
 
printf("\n Output ::");
printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
for(v=0;v<n;v++)
{
printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",pr[v],bt[v],vt[v],wt[v],tt[v]);
}
 
printf("\n\nAverage waiting time of this is : %f",waverage);
printf("\nAverage turn around time of this is : %f",taverage);
return 0;
}

