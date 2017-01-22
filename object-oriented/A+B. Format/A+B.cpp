#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,p,q,t,C;
	scanf("%d %d",&a,&b);
	c=a+b;
	C=abs(c);
	if(C<1000&&C>=0)
		printf("%d",c);
	else if(C>=1000&&C<1000000)
	{
		p=abs(c%1000);
		q=c/1000;
		printf("%d,%03d",q,p);
	}
	else if(C>=1000000&&C<=2000000)
	{
		p=abs(c%1000);
		q=abs(c/1000)%1000;
		t=c/1000000;
		printf("%d,%03d,%03d",t,q,p);
	}
	return 0;
}