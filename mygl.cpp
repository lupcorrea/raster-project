#include "mygl.h"
#include "definitions.h"
#include <stdio.h>

/* ---------- Pixel operations ---------- */
void drawPixel (Pixel p1) {
    // Find the position in the FB
    int curr_pos = 4*p1.getX() + 4*IMAGE_WIDTH*p1.getY();
    
    // Color the FB position
    if (p1.getX() < IMAGE_WIDTH && p1.getY() < IMAGE_HEIGHT) {
        FBptr[curr_pos] = p1.getR();
        FBptr[curr_pos + 1] = p1.getG();
        FBptr[curr_pos + 2] = p1.getB();
        FBptr[curr_pos + 3] = p1.getA();    
    }    
}

/* ---------- Line operations ---------- */
void drawLine (Pixel p1, Pixel p2) {
    int dx = p2.getX() - p1.getX();
    int dy = p1.getY() - p2.getY();
    
    int d = 2 * dy - dx;
    
    int e = 2 * dy;
    int ne = 2 * (dy - dx);
    
    Pixel p = p1;
    
    drawPixel (p);
    int i = 0;
    while (p.getX() < p2.getX()) {
        if (d <= 0) {
            d += e;
            p.incX();
        } else {
            d += ne;
            p.incX();
            p.decY();
        }
        drawPixel (p);
    }
}