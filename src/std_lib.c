#include "std_lib.h"

// int div(int a, int b)
// {
//   int quotient;
//   if (b == 0) return 0; //ngehindar pembagian dengan nol
//   quotient = a / b;
//   //Penyesuaian untuk pembagian integer yang sesuai dengan aturan C
//   if (a < 0 && b > 0 && a % b != 0) {
//     quotient--;
//   } else if (a > 0 && b < 0 && a % b != 0) {
//     quotient--;
//   }
//   return quotient;
// }

// int mod(int a, int b)
// {
//   int remainder;
//   if (b == 0) return 0; //ngehindar modulus dengan nol
//   remainder = a % b;
//   if (remainder < 0) {
//     remainder += b < 0 ? -b : b; // Penyesuaian untuk mod negatif
//   }
//   return remainder;
// }

bool strcmp(char *str1, char *str2)
{
  while (*str1 && *str2 && *str1 == *str2) {
    str1++;
    str2++;
  }
  return *str1 == *str2;
}

void strcpy(char *dst, char *src)
{
  while (*src) {
    *dst = *src;
    dst++;
    src++;
  }
  *dst = '\0';
}

void clear(byte *buf, unsigned int size)
{
  unsigned int i;
  for (i = 0; i < size; i++) {
    buf[i] = 0;
  }
}

// void atoi(char *str, int *num)
// {
//   int sign;
//   int i;
//   *num = 0;
//   sign = 1;
//   i = 0;
//   if (str[0] == '-') {
//     sign = -1;
//     i++;
//   }
//   while (str[i] >= '0' && str[i] <= '9') {
//     *num = *num * 10 + (str[i] - '0');
//     i++;
//   }
//   *num *= sign;
// }

// void itoa(int num, char *str)
// {
//  int i;
//  int temp;
//  i = 0;
//   if (num == 0) {
//     str[i++] = '0';
//     str[i] = '\0';
//     return;
//   }
//   if (num < 0) {
//     str[i++] = '-';
//     num = -num;
//   }
//   int temp;
//   temp = num;
//   int digits;
//   digits = 0;
//   while (temp > 0) {
//     temp /= 10;
//     digits++;
//   }
//   int j;
//   for (j = digits - 1; j >= 0; j--) {
//     str[i + j] = (num % 10) + '0';
//     num /= 10;
//   }
//   str[i + digits] = '\0';
// }

