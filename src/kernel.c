#include "shell.h"
#include "kernel.h"

int main() {
  clearScreen();
  shell();
}

void printString(char *str)
{
  int i = 0;
  while (str[i] != '\0') {
    putInMemory(0xB800, i * 2, str[i]); //Write character to VGA
    putInMemory(0xB800, i * 2 + 1, 0x0F); //White text on black
    i++;
  }
}

void readString(char *buf)
{
  int i = 0;
  char c;
  do {
    //BIOS interrupt 0x16, AH=0: Read key press
    c = (char)interrupt(0x16, 0, 0, 0, 0);
    if (c == '\r') { //Enter key
      buf[i] = '\0';
      putInMemory(0xB800, i * 2, '\r'); //Carriage return
      putInMemory(0xB800, i * 2 + 1, 0x0F);
      putInMemory(0xB800, (i + 1) * 2, '\n'); //Line feed
      putInMemory(0xB800, (i + 1) * 2 + 1, 0x0F);
      break;
    } else if (c == '\b' && i > 0) { //Backspace
      i--;
      putInMemory(0xB800, i * 2, ' '); //Erase character
      putInMemory(0xB800, i * 2 + 1, 0x0F);
    } else if (c >= 32 && c <= 126) { //Printable ASCII
      buf[i] = c;
      putInMemory(0xB800, i * 2, c); //Display character
      putInMemory(0xB800, i * 2 + 1, 0x0F);
      i++;
    }
  } while (i < 127); // Buffer limit
  buf[i] = '\0';
}

void clearScreen()
{
  int i;
 for (i = 0; i < 80 * 25 * 2; i += 2) { // 80x25 VGA text mode
    putInMemory(0xB800, i, ' '); // Clear to space
    putInMemory(0xB800, i + 1, 0x0F); // White on black
  }
}