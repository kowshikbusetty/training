#include "error.h"
#define LINE_LENGTH 80
#define MSG 64

int main(int argc, char *argv[])
{
	int seconds;
	char line[LINE_LENGTH];
	char message[MSG];

	while(1){
		printf("Alarm> ");
		if(fgets (line, sizeof(line), stdin) == NULL)exit(0);
		if(strlen(line) <= 1) continue;
	
		if(sscanf(line, "%d %s4["\n"]",seconds, message) < 2){
			fprintf(stderr, "Bad command \n");
		} else {
			sleep(seconds);
			printf("(%d) %s\n", seconds, message);
		}
	}

	return 0;
}
