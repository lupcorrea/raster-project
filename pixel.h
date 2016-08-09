#ifndef _PIXEL_H_
#define _PIXEL_H_

#include "Position.h"
#include "Color.h"

class Pixel {
    Position pos;
    Color col;
    
    public:
        Pixel (int x, int y, int r, int g, int b, int a = 255) :
            pos (x, y), col (r, g, b, a) { }
    
        Position getPosition () { return pos; }
        Color getCol () { return col; }
        void setPosition (Position newPos) { pos = newPos; }
        void setColor (Color newCol) { col = newCol; }
};

#endif