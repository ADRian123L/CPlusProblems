#include <stdio.h>

#define Q .25f
#define D .10f
#define N .05f
#define P .01f

struct m {
	float q,
	    d,
	    n,
	    i,
	    f;

	float t;
} p;

void g(void);

int main(void) 
{
	g();
	return 0;

}

void g(void) {

	printf("Enter quarters: ");
	scanf("%f", &p.q);
	printf("Enter dimes ");
	scanf("%f", &p.d);
	printf("Enter nickels ");
	scanf("%f", &p.n);
	printf("Enter Penniess ");
        scanf("%f", &p.f);

	p.t = p.q*Q + p.d*D + p.n*N + p.f*P;
	printf("The total is $%.2f\n", p.t);
	
	
	
	}
