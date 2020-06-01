#include<iostream>
#include<graphics.h>
#include<math.h>
#include<conio.h>
using namespace std;

void DDA(int x1, int y1, int x2, int y2) {
	int i, steps, dx, dy;
	int x0 = 300, y0 = 200;
	float x, y, delta_x, delta_y;
	dx = x2 - x1;
	dy = y2 - y1;
	if (abs(dx) >= abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	delta_x = float(1.0*dx / steps);                  
	delta_y = float(1.0*dy / steps);
	x = x1;
	y = y1;
	putpixel((x + x0), (y0 - y), RED);                      
	Sleep(50);
	for (i = 1; i <= steps; i++) {
		x = x + delta_x;
		y = y + delta_y;
		putpixel((x + x0), (y0 - int(y + 0.5)), WHITE);                                    
	}
}
int main() {
	int x1, x2, y1, y2;
	int x0 = 300, y0 = 200;
	cout << "请输入两个整数点的坐标(x1,y1),(x2,y2)" << endl;
	cin >> x1 >> y1 >> x2 >> y2;
	initgraph(x0 * 2, y0 * 2);		      
	line(0, y0, x0 * 2, y0);			
	line(x0, 0, x0, y0 * 2);			
	DDA(x1, y1, x2, y2);                   
	_getch();         
	closegraph();    
	return 0;
}

