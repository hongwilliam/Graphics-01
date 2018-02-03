#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  int fd = open("sample.ppm", O_CREAT | O_WRONLY, 0644);
  int R = 150, G = 0, B = 175; //color values
  char buffer[256];

  //write the header, dimensions, and max color value
  write(fd, "P3\n700 700\n175\n", strlen("P3\n700 700\n175\n"));

  //looping thru the "2D" pixel grid
  int x = 0, y = 0;
  while (y < 700){
    x = 0;
    while (x < 700){
      if (G == 255){
        G = 0; }
      else{
        G += 1; }
      //now we input the pixel data RGB triplets
      sprintf(buffer, "%d %d %d\n", R, G, B); //this formats the buffer string
      //so writing to the file gets much easier
      write(fd, buffer, strlen(buffer));
      x++;
    }
    y++;
  }

  close(fd);
}
