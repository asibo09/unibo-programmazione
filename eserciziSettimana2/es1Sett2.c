#include <stdio.h>
#include <math.h>

int main() 
{
    //operatori aritmetici
    int a = 10, b = 3, c = 0;
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    printf("a %% b = %d\n\n", a % b);

    //forma compatta
    printf("a + b = %d\n", a += b); //a è 10 prima dell'operazione
    printf("a - b = %d\n", a -= b); //ora a sarà 13 prima dell'operazione
    printf("a * b = %d\n", a *= b); //ora a sarà di nuovo 10 prima dell'operazione
    printf("a / b = %d\n", a /= b); //ora a sarà 30 prima dell'operazione
    printf("a %% b = %d\n\n", a %= b); //ora a sarà 10 prima dell'operazione

    //operatori unari
    int d = 10;
    int e = 10;
    printf("%d  %d\n", d++, ++e);
    printf("%d  %d\n", d--, --e);

    //side effect
    int x = 5;
    int y = 2;
    x += (y = 4);
    printf("\nx += (y = 4) -> x = %d, y = %d\n", x, y);

    //conversione implicita
    int numero = 10;
    double risultato = numero / 3;
    printf("\nnum / 3 = %lf\n", risultato);

    //superamento del range
    char overrange = 127;
    overrange++;
    printf("\nOver range: %d\n", overrange);


    //funzioni libreria math.h
    float valore = 2.0;
    printf("\nsqrt(%.1f) = %lf\n", valore, sqrt(valore));
    printf("cbrt(%.1f) = %lf\n", valore, cbrt(valore));
    printf("exp(%.1f) = %lf\n", valore, exp(valore));
    printf("log(%.1f) = %lf\n", valore, log(valore));
    printf("log10(%.1f) = %lf\n", valore, log10(valore));
    printf("fabs(%.1f) = %lf\n", valore, fabs(valore));
    printf("ceil(%.1f) = %lf\n", valore, ceil(valore));
    printf("floor(%.1f) = %lf\n", valore, floor(valore));
    printf("sin(%.1f) = %lf\n", valore, sin(valore));
    printf("cos(%.1f) = %lf\n", valore, cos(valore));
    printf("tan(%.1f) = %lf\n", valore, tan(valore));
    printf("asin(%.1f) = %lf\n", valore, asin(valore));
    printf("acos(%.1f) = %lf\n", valore, acos(valore));
    printf("atan(%.1f) = %lf\n", valore, atan(valore));
    printf("sinh(%.1f) = %lf\n", valore, sinh(valore));
    printf("cosh(%.1f) = %lf\n", valore, cosh(valore));
    printf("tanh(%.1f) = %lf\n", valore, tanh(valore));

    //comportamento scorretto con tipi non appropriati
    int Int = 1000;
    char Char = (char)Int; 
    printf("\nint = %d, char = %d\n", Int, Char);

    //operatori logici
    if (a > 0 && b > 0) {
        printf("a e b sono entrambi maggiori di zero\n");
    }
    if (a > 0 || b > 0) {
        printf("Almeno uno tra a e b è maggiore di zero\n");
    }
    if (!(a == b)) {
        printf("a non è uguale a b\n");
    }
    if ((a > 0) ^ (c > 0)) {
        printf("a è maggiore di zero XOR c è maggiore di zero\n");
    }
    if (a > 0 && b > 0 && c > 0) {
        printf("a, b e c sono tutti maggiori di zero\n");
    }

    //operatori bitwise
    unsigned int val = 60;  
    unsigned int val2 = 13;
    
    unsigned int risultatoAND = val & val2;
    printf("valore1 & valore2 = %u\n", risultatoAND);  
    
    unsigned int risultatoOR = val | val2;
    printf("valore1 | valore2 = %u\n", risultatoOR);  

    unsigned int risultatoXOR = val ^ val2;
    printf("valore1 ^ valore2 = %u\n", risultatoXOR);  

    unsigned int risultatoNOTval = ~val;
    unsigned int risultatoNOTval2 = ~val2;
    printf("~valore1 = %u\n", risultatoNOTval);  
    printf("~valore2 = %u\n", risultatoNOTval2);  

    unsigned int risultatoShiftSinistra = val << 2;
    printf("valore << 2 = %u\n", risultatoShiftSinistra);  

    unsigned int risultatoShiftDestra = val >> 2;
    printf("valore1 >> 2 = %u\n", risultatoShiftDestra);

    //operatori relazionali
    if (a == b) {
        printf("a è uguale a b\n");
    }
    if (a != b) {
        printf("a è diverso da b\n");
    }
    if (a > b) {
        printf("a è maggiore di b\n");
    }
    if (a < b) {
        printf("a è minore di b\n");
    }
    if (a >= b) {
        printf("a è maggiore o uguale a b\n");
    }
    if (a <= b) {
        printf("a è minore o uguale a b\n");
    }


    return 0;
}