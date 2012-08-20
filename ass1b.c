#include<stdio.h>

long long int a[100000];


long long int fact(int n)
{
	if(n==0||n==1)
		return 1;
	else
		return n*fact(n-1);
}
	
long long int array(long long int fac,long long int n)
{
	long long int temp,count=0,i,j,k,count1=0,flag=0;
	temp=fac;

	while(temp>0)
	{
		count=count+1;
		temp=temp/10;
	}
	
	for(i=count-1;i>=0;i--)
	{
		a[i]=fac%10;
		fac=fac/10;
	
	}
	for(k=20;k<=n;k++)
	{
		for(i=0;i<count;i++)
		{
			a[i]=a[i]*k;
		}
		

	
		for(i=count-1;i>0;i--)	
		{
			a[i-1]=a[i-1]+(a[i]/10);
			a[i]=a[i]%10;
		
			
		}

        
		temp=a[0];
	
		while(temp>0)
        	{
                	count1=count1+1;
                	temp=temp/10;
        	}
		
		
		j=count;
	
		for(i=count+count1-2;i>=count1;i--)
		{
			a[i]=a[j-1];
			j=j-1;
		}
		
		temp=a[0];
		for(i=count1-1;i>=0;i--)
        	{
                	a[i]=temp%10;
                	temp=temp/10;
        	}	
		count=count+count1-1;
	}
	

	printf("\n");
	for(i=0;i<count;i++)
	{
	if(a[i]!=0 && flag==0)
	flag=1;
	if(flag==1)
	printf("%lld",a[i]);}
	
}

main()
{
	long long int n,fac;

	printf("Enter n:");
	scanf("%lld",&n);
	if(n<20)	
	{fac=fact(n);
	printf("%lld\n",fac);}
	else
	{
		fac=fact(19);
		array(fac,n);
	}	
	
}
