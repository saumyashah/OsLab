#include<stdio.h>

void main()
{
int p,r,i,j;

printf("Enter the number of processes");
scanf("%d",&p);
printf("Enter the number or resources");
scanf("%d",&r);
//Current Allocation Matrix
int curr[p][r];

printf("Enter the current allocation matrix\n");
for (i=0; i<p; i++)
{
	for (j=0; j<r; j++)
	{
	scanf("\n %d",&curr[i][j]);
	}
}

printf("\nthe current allocation matrix\n");
for ( i=0; i<p; i++)
{
	for (j=0; j<r; j++)
	{
	printf("%d \t" ,curr[i][j]);
	}
	printf("\n");
}

//Maximum Allocation Matrix
int max[p][r];

printf("Enter the maximum allocation matrix\n");
for (i=0; i<p; i++)
{
	for (j=0; j<r; j++)
	{
	scanf("\n %d",&max[i][j]);
	}
}

printf("\nthe maximum allocation matrix \n");
for ( i=0; i<p; i++)
{
	for (j=0; j<r; j++)
	{
	printf("%d \t" ,max[i][j]);
	}
	printf("\n");
}
//Need matrix
int need[p][r];
for ( i=0; i<p; i++)
{

	for (j=0; j<r; j++)
	{

	need[i][j]= max[i][j]-curr[i][j];
	}
	printf("\n");
}
printf("The need matrix is \n ");
for ( i=0; i<p; i++)
{
	for (j=0; j<r; j++)
	{

	printf("%d \t",need[i][j]);
	}
	printf("\n");
}
//Total reources
int total[r];
printf("\nEnter the total available resources\n");
for(i=0; i<r; i++)
{
	scanf("%d",&total[i]);
}

printf("\nThe total available resources\n");
for(i=0; i<r; i++)
{
	printf("%d \n",total[i]);
} 
//Available resources 
int avail[r];

printf("\nEnter the available resources\n");
for(i=0; i<r; i++)
{
	scanf("%d",&avail[i]);
}

printf("\nThe available resources\n");
for(i=0; i<r; i++)
{
	printf("%d \n",avail[i]);
}

int cnt=0;
int a=0;
int k,b;
int safe[p];
int dead[p];
for(i=0;i<p;i++)
{
	dead[i] = 0;
}

for(i=0;i<p;i++)
{
	cnt=0;
	for(j=0;j<r;j++)
	{ 
		//printf("\n j in %d",i);
		if(need[i][j]<=avail[j]);
		cnt++;
	}
	//printf("after j for");
	if(cnt==r)
	{
	//printf(" in if");
	safe[a]=i+1;	
	a++;
	//printf(" before available print");
	for(k =0; k<r; k++)
	{
		avail[k] = avail[k] + curr[i][k];
		need[i][k] = 0;
	//	printf("avail matrix : %d " , avail[k]);
	}
	for(k =0; k<r; k++)
	{
		printf("\n avail matrix :%d",avail[k]);
	}
	}
	else
	{
	dead[b]=i+1;
	b++;
	}	
	//printf (" \n in : %d",i);
}
//printf("  \n out : %d",i);
/*int cnt1;
for(i=0 ; i<(p-a); i++)
{
	for(j=0;j<p;j++)
	{
		for(k=0;k<r;k++)
		{
			if(need[j][k] != 0)
			cnt1++;
		}
		if(cnt1 == r)
		{
		
		
		
}*/
if(dead[0] == 0)
{
	for(k =0; k<p; k++)
	{
	printf("\nSafe state order %d \t",safe[k]);
	}
}
else
{
	for(i=0;i<b;i++)
	{
		for(j=dead[i];j<b;j++)
		{
			for(k=0;k<r;k++)
			{
			if(need[j][k]<=avail[j])
			cnt1++;
			}
			
			if(cnt1==r)
			{
	
}
}
