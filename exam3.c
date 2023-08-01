#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    float sum = 0;


    for (int i = 1; i < argc; i++) {
        char *argument = argv[i];

        
        if (argument[0] == '0' && (argument[1] == 'x' || argument[1] == 'X')) {
            int hex;
            
            sscanf(argument, "%x", &hex);
            sum += hex;
        }
    
        else if (strchr(argument, '.') != NULL) {
            float floatValue = strtof(argument, NULL);
            sum += floatValue;
        }
    
        else {
            int intValue = atoi(argument);
            sum += intValue;
        }
    }

    
    printf("Сумата е %.2f\n", sum);
    return 0;
}
