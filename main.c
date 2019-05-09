#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void pixelMean(float *r, float *g, float *b);
int main() 
{
    float image[5][5][3];
    int x, y;
// Don’t change this srand() line!
    srand(0);
    for(y = 0; y < 5; y++) 
    {
        for(x = 0; x < 5; x++) 
        {
            image[x][y][0] = (float)rand()/(float)INT_MAX;
            image[x][y][1] = (float)rand()/(float)INT_MAX;
            image[x][y][2] = (float)rand()/(float)INT_MAX;
        }
    }

    for (y=0; y < 2; y++)
    {
        for (x=0; x < 5; x++)
        {
           pixelMean(&image[x][y][0], &image[x][y][1], &image[x][y][2]);
            
          printf ( "%d %d: %f %f %f\n", x+1, y+1, image[x][y][0], image[x][y][1], image[x][y][2])
          ;
        }
    }
   
    

    return 0;
    }
void pixelMean(float *r, float *g, float *b)
{
    *r= *r + *g + *b;
    *r= *r/3.0;
    *g= *r;
    *b= *g;
            
}