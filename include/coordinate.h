#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>
//#include "map.h"
using namespace std;
class Coordinate{
    public:
	    /*Coordinate()
	    {
	    	x=y=-1;
	    }*/
        Coordinate():x(0),y(0){}

        Coordinate(int xpos, int ypos):x(xpos),y(ypos){}
        ~Coordinate(){}
        int getX() const{
            return x;
        }
        int getY() const{
            return y;
        }
        void show(){
            cout<<x<<','<<y<<endl;
        }
    	bool operator==(const Coordinate& cor) const{
            if(this->x==cor.x&&this->y==cor.y)
                return true;
            return false;
    	}
        bool operator<(const Coordinate& coord) const{
            if(x<coord.x)
                return true;
            else if(x==coord.x){
                if(y<coord.y)
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
        
        
    protected:
        int x;
        int y;
};

#endif
