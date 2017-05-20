#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifdef WIN32
#define SSIZET_FMT "%lu"
#else
#define SSIZET_FMT "%zu"
#endif

char* MaxSubString(char* str1, char* str2);

int main(int argc, char *argv[]) {
    char *MaxSubStringResult = MaxSubString("abractyeyt", "dgdsaeactyey");
    printf("MaxSubString(\"abractyeyt\", \"dgdsaeactyey\")=%s\n", MaxSubStringResult);
    free(MaxSubStringResult);
  
    return 0;
}

char *MaxSubString(char *str1, char *str2) {
    printf("-----reverseString_Advanced-----\n");
    const size_t  str1Len = strlen(str1);
    const size_t  str2Len = strlen(str2);
    
    int i, j;
    
    printf("str1Len="SSIZET_FMT" str2Len="SSIZET_FMT"\n", str1Len, str2Len);    

    int longest[str1Len][str2Len];
    for (i = 0; i < str1Len; i++) {
        for (j = 0; j < str2Len; j++) {
            printf("%d ", longest[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Initializing entire 2D array with one value
    memset(longest, 0, sizeof(longest));
    
    for (i = 0; i < str1Len; i++) {
        for (j = 0; j < str2Len; j++) {
            printf("%d ", longest[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int i_max = 0, j_max = 0, length_max = 0;

    for (i = 0; i < str1Len; i++) {
        for (j = 0; j < str2Len; j++) {
            if (str1[i] == str2[j]) {
                if (i > 0 && j > 0 && longest[i - 1][j - 1] > 0) {
                    longest[i][j] = longest[i - 1][j - 1] + 1;
                } else {
                    longest[i][j] = 1;
                }
                if (longest[i][j] > length_max) {
                    i_max = i;
                    j_max = j;
                    length_max = longest[i][j];
                }
            }
        }
    }
    
    for (i = 0; i < str1Len; i++) {
        for (j = 0; j < str2Len; j++) {
            printf("%d ", longest[i][j]);
        }
        printf("\n");
    }
    printf("\n");
        
    char *ret = (char*)malloc(length_max); 
    
    for (i = i_max - length_max + 1, j = j_max - length_max + 1; i <= i_max && j <= j_max; i++, j++) {
        *ret++ = str1[i];
    }
    *ret = '\0';
    ret = ret - length_max;

    printf("--------------------\n");
    return ret;
}
