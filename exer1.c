#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* function(const char* input) {
    if (input == NULL) {
        return NULL;
    }

    size_t input_length = strlen(input);
    char* result = (char*)malloc((input_length + 1) * sizeof(char));

 

    char symbols[10] = { '!', '#', '/', '~', '=', '\'', '\\', '>', '.', ',' }; /// popravka na switch case 

    for (size_t i = 0; i < input_length; i++) {
        char digit = input[i];

        if (i % 2 == 0) { // proveka za chetno i zamenyane s bukva
            result[i] = 'A' + (digit - '0');
        } else { //nechetno...
            if (digit >= '0' && digit <= '9') {
                result[i] = symbols[digit - '0']; // popravka na switch case(po indexa na simvolite v masiva)
            } else {
                result[i] = digit; // ako ne e cifra zap simvol 
            }
        }
    }

    result[input_length] = '\0'; // tapa
    return result;
}

int main() {
    char input[501];
    printf("Въведете цяло положително число (максимум 500 цифри): ");
    scanf("%500s", input);

    char* coded = function(input);
    if (coded == NULL) {
        printf("Грешка при заделянето на памет.\n");
        return 1;
    }

    printf("Кодиран резултат: %s\n", coded);

    free(coded); // freedoom 

    return 0;
}
