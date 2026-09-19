class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int ansx = -1;
        int ansy = -1;
        if(xCenter < x1) ansx = x1;
        else if(xCenter > x2) ansx = x2;
        else ansx = xCenter;

        if(yCenter < y1) ansy = y1;
        else if(yCenter > y2) ansy = y2;
        else ansy = yCenter;
        int dis = sqrt(pow((ansx-xCenter), 2) + pow((ansy-yCenter), 2));
        if(dis > radius) return false;
        return true;
    } 
};