#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static unsigned t1, t2, t3;

           //0,1,2,3,4,5,6
           //A,B,C,D,E,F,G
int nf[7] = {0,0,0,0,0,0,0};
void func(int a1, int a2, int a3)
{
	int i,j,k;
                //nodes
	if(a1){       nf[0]++; 
		i++;        nf[1]++;
		if(a2){     nf[3]++;
			j++;      nf[4]++;
		}         
	} else {
		k++;        nf[2]++;
	}

	if(a3){       nf[5]++;
		k++;        nf[6]++;
	}
 
}
 
/* No profiling for code below*/

/* Input set 1 */
void input1()
{
	t1 = 0.5 * RAND_MAX;
	t2 = 0.5 * RAND_MAX;
	t3 = 0.5 * RAND_MAX;
}
/* End input set 1*/

/* Input set 2 */
void input2()
{
	t1 = 0.2 * RAND_MAX;
	t2 = 0.6 * RAND_MAX;
	t3 = 0.8 * RAND_MAX;
}
/* End input set 2*/


int main()
{
	int i;
	unsigned a1, a2, a3;

	input1();
	/* input2(); */

	srand(time(NULL));

	for(i=0; i<10000; i++){
		a1 = (rand() > t1);
		a2 = (rand() > t2);
		a3 = (rand() > t3);

		func(a1, a2, a3);
  }

	/* Print out your profiling results here */
	for (i=0; i<7; i++){
    char c = (char)65+i;
    printf("%c: %d ",c,nf[i]); 
  }
  printf("\n");
 
	return EXIT_SUCCESS;
}

