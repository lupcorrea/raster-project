#ifndef _POSITION_H_
#define _POSITION_H_

class Position {
    int x;
    int y;
    
    public:
        Position (int posX, int posY) :
            x (posX), y (posY) { }
    
        int getX() { return x; }
        int getY() { return y; }
        void setX (int posX) { x = posX; }
        void setY (int posY) { x = posY; }
        void incX () { x++; }
        void incY () { y++; }
};

#endif