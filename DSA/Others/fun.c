#include<stdio.h>

int main()
{
    printf("Program compilation data: %s\n",__DATE__);
    printf("Program compilation time: %s\n",__TIME__);

    printf("File name of this program is: %s\n",__FILE__);
    printf("Compiler standard no: %d\n",__STDC__); // 1 means the compiler conforms to ISO Standard C
    printf("STDC_HOSTDED Number: %d\n",__STDC_HOSTED__); // This macro holds the value 1 if the compiler’s target is a hosted environment. 
    //A hosted environment is a facility in which a third-party holds the compilation data and runs the programs on its own computers. Generally, the value is set to 1.
    printf("Compiler Standard VERSION Number: %ld\n",__STDC_VERSION__); 



    printf("\nLine is: %d",__LINE__);
}