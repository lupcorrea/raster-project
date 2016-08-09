#include "mygl.h"
#include "definitions.h"

/* ---------- Pixel operations ---------- */
void drawPixel (Pixel p1) {
    // Find the position in the FB
    int curr_pos = 4*p1.getPosition().getY() + 4*IMAGE_WIDTH*p1.getPosition().getX();
    
    // Color the FB position
    FBptr[curr_pos] = p1.getCol().getR();
    FBptr[curr_pos + 1] = p1.getCol().getG();
    FBptr[curr_pos + 2] = p1.getCol().getB();
    FBptr[curr_pos + 3] = p1.getCol().getA();
}

/* ---------- Line operations ---------- */
void drawLine (Pixel p1, Pixel p2) {
    // Calculate dx and dy
    int dx = p2.getPosition().getX() - p1.getPosition().getX();
    int dy = p2.getPosition().getY() - p1.getPosition().getY();
    
    // Get the module for dx and dy
    int mod_dx = dx; int mod_dy = dy;
    if (mod_dx < 0) mod_dx *= -1; if (mod_dy) mod_dy *= -1;
    
    // Navigation pixel;
    Pixel p = p1;
    
    // Determine which octant the line belongs to
    if (dx >= 0 && dy >= 0 && mod_dx >= mod_dy) {
        // First octant
        // First midpoint
        int d = (2 * dy) - dx;
        
        // Calculate the increment
        int e = 2 * dy;
        int ne = 2 * (dy - dx);
        
        // Main loop
        drawPixel (p);
        while (p.getPosition().getX() < p2.getPosition.getX()) {
            if (d <= 0) {
                // If line is below midpoint
                d += e;
                p.getPosition().incX();
            } else {
                // If line is above midpoint
                d += ne;
                p.getPosition().incX();
                p.getPosition().incY();
            }
            drawPixel (p);
        }  
    } else if (dx >= 0 && dy >= 0 && mod_dx < mod_dy) {
        // Second octant
        // First midpoint
        int d = dy - (2 * dx);
        
        // Calculate the increment
        int ne = 2 * (dy - dx);
        int n = -2 * dx;
        
        // Main loop
        drawPixel (p);
        while (p.getPosition().getY() < p2.getPosition.getY()) {
            if (d <= 0) {
                // If line is at midpoint's left
                d += n;
                p.getPosition().incY();
            } else {
                // If line is at midpoint's right
                d += ne;
                p.getPosition().incX();
                p.getPosition().incY();
            }
            drawPixel (p);
        }  
    } else if (dx < 0 && dy >= 0 && mod_dx < mod_dy) {
        // Third octant
        // First midpoint
        int d = (2 * dy) - dx;
        
        // Calculate the increment
        int n = -2 * dx;
        int nw = -2 * (dy + dx);
        
        // Main loop
        
    } else if (dx < 0 && dy >= 0 && mod_dx >= mod_dy) {
        // Fourth octant
        // First midpoint
        int d = (2 * dy) - dx;
        
        // Calculate the increment
        int nw = -2 * (dy + dx);
        int w = -2 * dy;
        
        // Main loop
        
    } else if (dx < 0 && dy < 0 && mod_dx >= mod_dy) {
        // Fifth octant
        // First midpoint
        int d = (2 * dy) - dx;
        
        // Calculate the increment
        int w = -2 * dy;
        int sw = -2 * (dx - dy);
        
        // Main loop
        
    } else if (dx < 0 && dy < 0 && mod_dx < mod_dy) {
        // Sixth octant
        // First midpoint
        int d = (2 * dy) - dx;
        
        // Calculate the increment
        int sw = -2 * (dx - dy);
        int s = 2 * dx;
        
        // Main loop
        
    } else if (dx >= 0 && dy < 0 && mod_dx < mod_dy) {
        // Seventh octant
        // First midpoint
        int d = (2 * dy) - dx;
        
        // Calculate the increment
        int s = 2 * dx;
        int se = 2 * (dy + dx);
        
        // Main loop
        
    } else if (dx >= 0 && dy < 0 && mod_dx >= mod_dy) {
        // Eighth octant
        // First midpoint
        int d = (2 * dy) - dx;
        
        // Calculate the increment
        int se = 2 * (dy + dx);
        int e = 2 * dy;
        
        // Main loop
        
    }
}