#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool reverseString_Basic(char* pcInput, char* pcOutput);

int main(int argc, char *argv[]) {
  char InputString[] = "123456789";
  char *OutputString = malloc(0);
	reverseString_Basic(InputString, OutputString);
	printf("OutputString=%s\n", OutputString);
	return 0;
}

bool reverseString_Basic(char* pcInput, char* pcOutput) {
	printf("-----reverseString_Basic-----\n");
	int len = strlen(pcInput); 
	printf("InputString=%s, Len=%d\n", pcInput, len);
	pcOutput = realloc(pcOutput, len);
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
