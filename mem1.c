#include <papi.h>
#include <stdio.h>
#include <stdlib.h>

static unsigned len = 16*(1 << 20);

void func(int * a)
{
	int i;

	for(i=0; i<len; i++){
		a[i]++;
	}
}

void funcStride(int * a)
{
	int i,j;
	int stride = 500;
	for (j = 0; j < stride; j++) {
		for (i = 0; i < len; i+=stride) {
			a[i+j]++;
		}
	}

}

void funcUnroll(int * a)
{
	int i;
	int step = 10;
	for (i = 0; i< len; i++){
		a[i]++;
		a[i+2]++;
		a[i+4]++;
		a[i+6]++;
		a[i+8]++;
		a[i+12]++;
		a[i+14]++;
		a[i+16]++;
		a[i+18]++;
		
		a[i+1]++;
		a[i+3]++;
		a[i+5]++;
		a[i+7]++;
		a[i+9]++;
		a[i+11]++;
		a[i+13]++;
		a[i+15]++;
		a[i+17]++;
		a[i+19]++;
	}
}
 
/* Please add your events here */
int events[1] = {PAPI_TLB_DM}; /*PAPI_L1_DCM, PAPI_L2_DCM, PAPI_TLB_DM*/
int eventnum = 1;

void curFunc(int * a) {
	func(a);
}

int main()
{
	/* Record TLB values */
	long long values[1];
	int eventset;
	int * a;

	if(PAPI_VER_CURRENT != PAPI_library_init(PAPI_VER_CURRENT)){
		printf("Can't initiate PAPI library!\n");
		exit(-1);
	}

	eventset = PAPI_NULL;
	if(PAPI_create_eventset(&eventset) != PAPI_OK){
		printf("Can't create eventset!\n");
		exit(-3);
	}
	if(PAPI_OK != PAPI_add_events(eventset, events, eventnum)){
		printf("Can't add events!\n");
		exit(-4);
	}

	a = (int *) malloc(len*sizeof(int));
	PAPI_start(eventset);
	curFunc(a);
	PAPI_stop(eventset, values);
	free(a);

	/*Print out PAPI reading*/
	char event_name[PAPI_MAX_STR_LEN];
	if (PAPI_event_code_to_name( events[0], event_name ) == PAPI_OK)
		printf("%s: %lld\n", event_name, values[0]);


	/* Record L1 and L2 */	
	int l_events[2] = {PAPI_L1_DCM,PAPI_L2_DCM};
	long long l_values[1];
	int l_eventset;	
	l_eventset = PAPI_NULL;
	
	PAPI_create_eventset(&l_eventset);
	PAPI_add_events(l_eventset, l_events, 2);

	int * b;
	b = (int *) malloc(len*sizeof(int));
	PAPI_start(l_eventset);
	curFunc(b);
	PAPI_stop(l_eventset, l_values);
	free(b);

	int i;
	for (i = 0; i < 2; ++i) {	
		if (PAPI_event_code_to_name(l_events[0], event_name) == PAPI_OK)
			printf("%s: %lld\n", event_name, l_values[0]);
	} 	
	return EXIT_SUCCESS;
}
