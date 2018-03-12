//
// Created by Ahmed Alkabir on 3/12/2018.
//
#include <ustring.h>

int main(void){
    uString *test = uString_new("Ahmed Alkabir");
    printf("%s\n", test->value);
    test->free(test);
    return 0;
}
