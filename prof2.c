#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static unsigned t1, t2, t3, t4;


void func(int a1, int a2, int a3, int a4)
{
	int i,j,k;

	if(a1){
		i++;
		if(a2){
			j++;
		} else {
			i++;
			goto b1;
		}

		k++;
		goto b2;
	} else {
		if(a3){
			j++;
		} else {
			k++;
			goto b1;
		}

		k++;
		goto b2;
	}

b1: if(a4){
		j++;
	}

b2: k++;
}

/* Input set 1 */
void input1()
{
	t1 = 0.5 * RAND_MAX;
	t2 = 0.5 * RAND_MAX;
	t3 = 0.5 * RAND_MAX;
	t4 = 0.5 * RAND_MAX;
}
/* End input set 1*/

/* Input set 2 */
void input2()
{
	t1 = 0.2 * RAND_MAX;
	t2 = 0.6 * RAND_MAX;
	t3 = 0.8 * RAND_MAX;
	t4 = 0.3 * RAND_MAX;
}
/* End input set 2*/


int main()
{
	int i;
	unsigned a1, a2, a3, a4;

	input1();
	/* input2(); */

	srand(time(NULL));

	for(i=0; i<10000; i++){
		a1 = (rand() > t1);
		a2 = (rand() > t2);
		a3 = (rand() > t3);
		a4 = (rand() > t4);

		func(a1, a2, a3, a4);
	}

	/* Print out your profiling results here */
	
	return EXIT_SUCCESS;
}

