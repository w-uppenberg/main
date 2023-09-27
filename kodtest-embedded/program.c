#include "./pd9982_driver.h"
#include <stdio.h>
#include <inttypes.h>
#include "libs/libcrc/include/checksum.h"
#include <string.h>
#include<unistd.h>
#include <stdlib.h>

void cleanup(volatile void * init){
	uint8_t* ctrl = (uint8_t *)init;
	uint8_t* sts = ((uint8_t *)init)+1;
	uint8_t * buf = ((uint8_t *)init)+2;
	uint8_t* crc = ((uint8_t *)init)+9;

	*ctrl = (uint8_t) 0;
	//*sts = (uint8_t) 0;
	*buf = (uint8_t) 0;
	*(buf + 1) = (uint8_t) 0;
	*(buf + 2) = (uint8_t) 0;
	*(buf + 3) = (uint8_t) 0;
	*(buf + 4) = (uint8_t) 0;
	*(buf + 5) = (uint8_t) 0;
	*(buf + 6) = (uint8_t) 0;
	*crc = (uint8_t) 0;
}

uint8_t runCycle(volatile void * init, uint8_t checksum) {

	uint8_t* ctrl = (uint8_t *)init;
	uint8_t* sts = ((uint8_t *)init)+1;
	uint8_t * buf = ((uint8_t *)init)+2;
	uint8_t* crc = ((uint8_t *)init)+9;
	cleanup(init);
			
	uint8_t set = 6;
	set = set << 1;

	sleep(1);
	if((*sts) & ((uint8_t)4)) {
		printf( "started\n");
	}
	void *tmpBuf = malloc(6);
	*((uint16_t * ) tmpBuf) = (uint16_t) 26624;
	*((uint16_t * ) tmpBuf+2) = (uint16_t) 25856;
	*((uint16_t * ) tmpBuf+4) = (uint16_t) 27136;
	*((uint16_t * ) tmpBuf+6) = (uint16_t) 0;
	memcpy(buf, tmpBuf, 6);
	
	// strncpy(buf, "hejsan", 6);
	printf("attempted checksum %" PRIu8 "\n", crc_8("hej", 3) );
	*crc = checksum;

	*ctrl = set;
	while (!((*sts) & 1)){
		//printf("OP_STS Bit not set - wait 10ms");
		sleep(0.01);		
	}
	while ((*sts) & 1) {
		//printf("OP_STS Bit set - wait 10ms");
		sleep(0.01);		
	}
	set = set << 3;

	if((*sts) & 128){
		printf("failed  - faulty crc: ");
		printf("%" PRIu8 "\n", *crc);

		cleanup(init);
		*ctrl = (uint8_t) 128;
		while ((*ctrl) & 128){
			if(!((*sts) & 128)) {
			//	printf("shouldn't be sleeping\n");
				*ctrl = 0;
				break;
			}
			//printf("sleeping\n");
			sleep(0.001);
		}
		return 0;
	}

	if(((*sts) & 4) && ((*sts) & (set))) {
		printf( "success! ");
		printf("%" PRIu8 "\n", *crc);
		return *crc;
	}

}


int main(int argc, char** argv) {
	FILE *fptr;
	fptr = fopen("./tmpoutput.txt", "w+");

	volatile void* init = initModule((char *)fptr);
	startModule();
	for(uint8_t i = 255; i>0; i--) {
		if(runCycle(init, 49) > 0)
			break;
	}
	
	uint8_t* ctrl = (uint8_t *)init;
	uint8_t* sts = ((uint8_t *)init)+1;

	*ctrl = 241;
	while (!((*sts) & 1)){
		//printf("OP_STS Bit not set - wait 10ms");
		sleep(0.01);		
	}
	while ((*sts) & 1) {
		//printf("OP_STS Bit set - wait 10ms");
		sleep(0.01);
		
	}
	
		
	stopModule();
	return 0;
}
