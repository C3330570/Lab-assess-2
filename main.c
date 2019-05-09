#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void pixelMean(float *r, float *g, float *b);
int main() 
{
   int x=0, y=0;
   float image[x][y][3];
   
   FILE *input;
   input= fopen("RGB.txt", "r"); 

    for(y=0; y<2; y++)
    {
        for(x=0; x<5; x++)
        {
            fscanf(input, "%f %f %f\n", 
            &image[x][y][0], &image[x][y][1], &image[x][y][2]);
            printf("%d %d: %f %f %f\n", 
            x+1, y+1, image[x][y][0], image[x][y][1], image[x][y][2]);
        }
    }    
    printf("\n");
    for (y=0; y<2; y++)
    {
        for (x=0; x<5; x++)
        {
            pixelMean(&image[x][y][0], &image[x][y][1], &image[x][y][2]);
           printf("%d %d: %f %f %f\n", 
            x+1, y+1, image[x][y][0], image[x][y][1], image[x][y][2]);
        } 
    }
   
    fclose(input);
    return 0;
}
void pixelMean(float *r, float *g, float *b)
{
    *r= *r + *g + *b;
    *r= *r/3.0;
    *g= *r;
    *b= *g;
}