void CMFCDraw3Dlg::ScanLineFill(HDC dc, CPoint a, CPoint b, CPoint c)  //基于三角形的几何填充,顶点为A,B,C
{    //由几何数学可知:所有多边形均可切分成多个三角形。故用三角形填充作为关键代码,N边形只需切成N-2个三角形即可。
	int xa, ya, xb, yb, xc, yc,ymax,ymin,y1,y2;
	float kab, kac, kbc;
	if (a.x <= b.x) {
		if (a.x <= c.x) {
			xa = a.x;
			ya = a.y;
			if (b.x <= c.x) {
				//tric = 1;
				xb = b.x;
				yb = b.y;
				xc = c.x;
				yc = c.y;
			}
			else {
				xb = c.x;
				yb = c.y;
				xc = b.x;
				yc = b.y;
			}
		}
		else {
			xa = c.x;
			ya = c.y;
			xb = a.x;
			yb = a.y;
			xc = b.x;
			yc = b.y;
			//tric = 6;
		}
	}
	else {
		if (b.x <= c.x) {
			xa = b.x;
			ya = b.y;

			if (a.x <= c.x) {
				xb = a.x;
				yb = a.y;
				xc = c.x;
				yc = c.y;
				//tric=4;
			}
			else {
				xb = c.x;
				yb = c.y;
				xc = a.x;
				yc = a.y;
				//tric = 3;
			}
		}
		else {
			xa = c.x;
			ya = c.y;
			xb = b.x;
			yb = b.y;
			xc = a.x;
			yc = a.y;
			//tric = 5;
		}
	}
	kab = 1.0 * (yb - ya) / (xb - xa);
	kac = 1.0 * (yc - ya) / (xc - xa);
	kbc = 1.0 * (yc - yb) / (xc - xb);
	
		for (int i = 1; i < xb-xa; i++) {
			y1 = ya + int(i * kab);
			y2 = ya + int(i * kac);
			if (y1 >= y2) {
				ymax = y1;
				ymin = y2;
			}
			else {
				ymax = y2;
				ymin = y1;
			}
			for (int j = ymin; j <= ymax; j++) {
				SetPixel(dc, xa + i, j, RGB(0, 0, 255));
			}
		}
		for (int i = 0; i < xc - xb; i++) {
			y1 = yb + int(i * kbc);
			y2 = ya + int((i+xb-xa) * kac);
			if (y1 >= y2) {
				ymax = y1;
				ymin = y2;
			}
			else {
				ymax = y2;
				ymin = y1;
			}
			for (int j = ymin; j <= ymax; j++) {
				SetPixel(dc, xb + i, j, RGB(0, 0, 255));
			}
		}
}
