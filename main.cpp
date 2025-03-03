#include<vector>
#include "tgaimage.h"
#include<cmath>
#include"model.h"
#include"geometry.h"
const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);
const TGAColor green = TGAColor(0,   255, 0,   255);
Model *model = NULL;
const int width  = 200;
const int height = 200;

void line(int x1, int x2, int y1, int y2, TGAImage &image, TGAColor color);
void triangle(Vec2i t0, Vec2i t1, Vec2i t2, TGAImage &image, TGAColor color);

int main(int argc, char** argv) {
    TGAImage image(width, height, TGAImage::RGB);
    Vec2i t0[3] = {Vec2i(10, 70),   Vec2i(50, 160),  Vec2i(70, 80)};
    Vec2i t1[3] = {Vec2i(180, 50),  Vec2i(150, 1),   Vec2i(70, 180)};
    Vec2i t2[3] = {Vec2i(180, 150), Vec2i(120, 160), Vec2i(130, 180)};

    triangle(t0[0], t0[1], t0[2], image, red);
    triangle(t1[0], t1[1], t1[2], image, white);
    triangle(t2[0], t2[1], t2[2], image, green);


    /*
	if(2==argc)
    {
        model = new Model(argv[1]);
    }
    else{
        model = new Model("obj/nigger_head.obj");
    }

    TGAImage image(width, height, TGAImage::RGB);
    for(int i=0; i<model->nfaces(); i++)
    {
        std::vector<int> face = model->face(i);
        for(int j=0; j<3; j++)
        {
            Vec3f v0 = model->vert(face[j]);
            Vec3f v1 = model->vert(face[(j+1)%3]);
            int x0 = (v0.x+1.)*width/2.;
            int y0 = (v0.y+1.)*height/2.;
            int x1 = (v1.x+1.)*width/2.;
            int y1 = (v1.y+1.)*height/2.;
            line(x0, x1, y0, y1, image, white);
        }
    }
    */

	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	image.write_tga_file("output.tga");
	return 0;
}

void line(int x1, int x2, int y1, int y2, TGAImage &image, TGAColor color)
{
    bool steep = false;
    if(std::abs(x1-x2)<std::abs(y1-y2)) // to transform the line to a less steep one when it's steep
    {
        std::swap(x1,y1);
        std::swap(x2,y2);
        steep = true;
    }
    if(x1>x2)
    {
        std::swap(x1,x2);
        std::swap(y1,y2);
    }
    int dx = x2-x1;
    int dy = y2-y1;
    int derror2 = std::abs(dy)*2;
    int error2 = 0;
    int y = y1;
    for(int x = x1; x <= x2; x++)
    {
        if(steep)
        {
            image.set(y,x,color); // if trnaspsoed, then we need to swap x and y
        }
        else
        {
            image.set(x,y,color);
        }
        error2 += derror2;
        if(error2 > dx)
        {
            y += (y2>y1?1:-1);
            error2 -= dx*2;
        }
    }
}

void triangle(Vec2i t0, Vec2i t1, Vec2i t2, TGAImage &image, TGAColor color)
{
    line(t0.x, t1.x, t0.y, t1.y, image, color);
    line(t1.x, t2.x, t1.y, t2.y, image, color);
    line(t2.x, t0.x, t2.y, t0.y, image, color);
}