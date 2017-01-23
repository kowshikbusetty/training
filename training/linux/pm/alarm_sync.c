#include "errors.h"

int main( void )
{
	int seconds;
	char line[120];
	char message[64];
	
	while(1) {
		printf("Alarm> ");
		if(fgets(line, sizeof(line), stdin) == NULL) exit(0);
		
		if(strlen(line) <= 1) continue;

		/*
         * Parse input in to seconds (%d) and a message
         * (%64[^\n]), consisting of up to 64 characters
         * seperated from seconds by whitespaces
         */
		
		if(sscanf(line, "%d %64[^\n]", &seconds, message) < 2) {
			fprintf(stderr, "Bad command \n");
		} else {
			sleep(seconds);
			printf("(%d) %s \n", seconds, message);
		}

	}

}
		
