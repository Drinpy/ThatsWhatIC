#include <stdio.h>

int main(void)
{

 double time, speed;

    scanf("%lf %lf", &time, &speed);
    printf("%.3lf\n", time * speed/12 );
  
    return 0;
}
