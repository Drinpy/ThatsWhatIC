
int main(void)
{

  float far, cel;

  for(far = 32; far <= 212; far++)
  {

    cel = (float)5/9 * (far - 32);
    printf("Farenheit = %6.2f Celsius = %6.2f\n", far, cel);
    
  }
  
}
