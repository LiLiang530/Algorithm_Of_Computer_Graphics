void CMFCDraw1Dlg::BresenhamLine(int x1, int y1, int x2, int y2)
{
	if (x2 < x1) {
		int x0 = x1;
		int y0 = y1;
		x1 = x2;
		y1 = y2;
		x2 = x0;
		y2 = y0;
	}
	CClientDC dc(this);
	int x, y, dx, dy,e;
	int lc = 0;
	//float k, e;
	dx = x2 - x1;
	dy = y2 - y1;
	//k = dy / dx;
	//e = -0.5;
	if (abs(dx) >= abs(dy)) {
		e = -dx;
		if (dy >= 0) {
			lc = 1;

		}
		else {
			lc = 3;

		}
	}
	else {
		e = -dy;
		if (dy >= 0) {
			lc = 2;
			
		}
		else {
			lc = 4;
		}
	}

	x = x1;
	y = y1;
	if (lc == 1) {
		for (int j = 0; j <= dx;j++) {
			SetPixel(dc, x, y, RGB(0,0, 255));
			x ++;
			e = e + 2 * dy;
			//e += k;
			if (e >= 0) {
				y++;
				//e -= 1;
				e = e - 2 * dx;
			}
		}
	}
	else if (lc == 2) {
		for (int j = 0; j <= dy; j++) {
			SetPixel(dc, x, y, RGB(0, 0, 255));
			y++;
			e = e + 2 * dx;
			if (e >= 0) {
				x++;
				e = e - 2 * dy;
			}
		}
	}
	else if (lc == 3) {
		for (int j = 0; j <= dx; j++) {
			SetPixel(dc, x, y, RGB(0, 0, 255));
			x++;
			e = e - 2 * dy;
			if (e >= 0) {
				y--;;
				e = e - 2 * dx;
			}
		}
	}
	else if (lc == 4) {
		for (int j = 0; j <= -dy; j++) {
			SetPixel(dc, x, y, RGB(0, 0, 255));
			y--;
			e = e + 2 * dx;
			if (e >= 0) {
				x++;
				e = e + 2 * dy;
			}
		}
	}
}
