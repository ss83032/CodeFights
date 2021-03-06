#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifdef WIN32
#define SSIZET_FMT "%lu"
#else
#define SSIZET_FMT "%zu"
#endif

bool reverseString_Basic(char* pcInput, char* pcOutput);
bool reverseString_Advanced(char* pcInput, char* pcOutput);

int main(int argc, char *argv[]) {
	char InputString[] = "1 2 3 4 5 6 7 8 9";
	char OutputString[100];
	reverseString_Basic(InputString, OutputString);
	printf("OutputString=%s\n", OutputString);
	reverseString_Advanced(InputString, OutputString);
	printf("OutputString=%s\n", OutputString);
	return 0;
}

bool reverseString_Basic(char* pcInput, char* pcOutput) {
	printf("-----reverseString_Basic-----\n");
	const size_t len = strlen(pcInput); 
	printf("InputString=%s, Len="SSIZET_FMT"\n", pcInput, len);
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

bool reverseString_Advanced(char* pcInput, char* pcOutput) {
	printf("-----reverseString_Advanced-----\n");
	const size_t len = strlen(pcInput);
	printf("InputString=%s, Len="SSIZET_FMT"\n", pcInput, len);

	int i, j;

	for (i = 0, j = len - 1; i < j; i++ , j--) {
		*(pcOutput + i) = *(pcInput + j);
		*(pcOutput + j) = *(pcInput + i);
	}

	printf("OutputString=%s\n", pcOutput);
	printf("--------------------\n");
}
