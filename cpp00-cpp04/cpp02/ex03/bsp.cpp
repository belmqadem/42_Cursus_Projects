#include "Point.hpp"

Fixed area(Point const p1, Point const p2, Point const p3) {
    Fixed x1 = p1.getX();
    Fixed y1 = p1.getY();
    Fixed x2 = p2.getX();
    Fixed y2 = p2.getY();
    Fixed x3 = p3.getX();
    Fixed y3 = p3.getY();
    Fixed areaValue = (x1 * (y2 - y3) + 
                       x2 * (y3 - y1) + 
                       x3 * (y1 - y2)) / Fixed(2);
                
    if (areaValue < Fixed(0)) {
        areaValue = areaValue * -1;
    }

    return areaValue;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed area_abc = area(a, b, c);
	Fixed area_pab = area(point, a, b);
	Fixed area_pbc = area(point, b, c);
	Fixed area_pac = area(point, a, c);
    if (area_pab + area_pbc + area_pac == area_abc) {
        if (area_pab == 0 || area_pbc == 0 || area_pac == 0)
            return false;
        return true;
    }
    return false;
}