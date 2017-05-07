#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifdef __WIN32__ // or whatever
#define SSIZET_FMT "%lu"
#else
#define SSIZET_FMT "%zu"
#endif

bool reverseString_Basic(char* pcInput, char* pcOutput);

int main(int argc, char *argv[]) {
	char InputString[] = "1 2 3 4 5 6 7 8 9";
	// char *OutputString = malloc(0);
	char OutputString[100];
	reverseString_Basic(InputString, OutputString);
	printf("OutputString=%s\n", OutputString);
	return 0;
}

bool reverseString_Basic(char* pcInput, char* pcOutput) {
	printf("-----reverseString_Basic-----\n");
	const size_t len = strlen(pcInput); 
	printf("InputString=%s, Len="SSIZET_FMT"\n", pcInput, len);
	// pcOutput = malloc(pcOutput, len);
	char* p = pcOutput; 
	int i;
	for (i = len - 1 ; i >= 0 ; i--) {
		*(p++) = pcInput[i];
	} 
	*p = '\0';
	printf("OutputString=%s\n", pcOutput);
	printf("--------------------\n");
	return true;
}
