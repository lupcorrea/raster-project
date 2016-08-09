#ifndef _COLOR_H_
#define _COLOR_H_

class Color {
    int r;
    int g;
    int b;
    int a;
    
    public:
        Color (int red, int green, int blue, int alpha) :
            r (red), g (green), b (blue), a (alpha) { }
    
        int getR() { return r; }
        int getG() { return g; }
        int getB() { return b; }
        int getA() { return a; }
        void setR (int red) { r = red; }
        void setG (int green) { g = green; }
        void setB (int blue) { b = blue; }
        void setA (int alpha) { a = alpha; }
};

#endif