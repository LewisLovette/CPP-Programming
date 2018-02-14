#include <iostream>

void increment(int *v) {	//As we pass the pointer it means we are able to change the variable
    (*v)++;					//even though it's not in the scope of it's functions
}							//Sendin non-pointer would mutate a copy of it, as the original wouldn't be in it's scope.

int main() {
    int a;
    scanf("%d", &a);
    increment(&a);
    printf("%d", a);
    return 0;
} 