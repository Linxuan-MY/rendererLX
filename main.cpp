#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

void line(int x1, int x2, int y1, int y2, TGAImage &image, TGAColor color);

int main(int argc, char** argv) {
	TGAImage image(100, 100, TGAImage::RGB);
	image.set(52, 41, red);
    line(0,35,50,35,image,white);
	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	image.write_tga_file("output.tga");
	return 0;
}

void line(int x1, int x2, int y1, int y2, TGAImage &image, TGAColor color)
{
    for(float i=0.;i<1.;i+=.01)
    {
        int x = x1 + (x2 - x1) * i;
        int y = y1 + (y2 - y1) * i;
        image.set(x, y, color);
    }
}