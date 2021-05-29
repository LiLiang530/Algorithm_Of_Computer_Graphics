void CMFCDraw1Dlg::MidpointLine(int x1, int y1, int x2, int y2)
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
	int a, b, d1, d2, d, x, y;
	int lc = 0;
//	float k;
	a = y1 - y2;
	b = x2 - x1;
//	k = -a / b;
	if (abs(b)>=abs(a)) {
		if (a <= 0) {
			lc = 1;
		}
		else {
			lc = 3;
		}
	}
	else {
		if (a <= 0) {
			lc = 2;
		}
		else {
			lc = 4;
		}
	}

	if (lc==1) {
		d = 2 * a + b;
		d1 = 2 * a;
		d2 = 2 * (a + b);
		x= x1;
		y = y1;
		SetPixel(dc, x, y, RGB(0, 255, 0));
		while (x < x2) {
			if (d < 0) {
				d += d2;
				x += 1;
				y += 1;
			}
			else {
				d += d1;
				x += 1;
			}
			SetPixel(dc, x, y, RGB(0, 255, 0));
		}
	}
	else if (lc==2) {
		d = a + 2 * b;
		d1 = 2 * b;
		d2 = 2 * (a + b);
		x = x1;
		y = y1;
		SetPixel(dc, x, y, RGB(0, 255, 0));
		while (y < y2) {
			if (d >= 0) {
				d += d2;
				x += 1;
				y += 1;
			}
			else {
				d += d1;
				y += 1;
			}
			SetPixel(dc, x, y, RGB(0, 255, 0));
		}
	}
	else if (lc==3) {
		d = 2 * a - b;
		d1 = 2 * a;
		d2 = 2 * (a-b);
		x = x1;
		y = y1;
		SetPixel(dc, x, y, RGB(0, 255, 0));
		while (x < x2) {
			if (d >= 0) {
				d += d2;
				x += 1;
				y -= 1;
			}
			else {
				d += d1;
				x += 1;
			}
			SetPixel(dc, x, y, RGB(0, 255, 0));
		}
	}
	else if (lc==4){
		d = a - 2*b;
		d1 = -2 * b;
		d2 = 2 * (a - b);
		x = x1;
		y = y1;
		SetPixel(dc, x, y, RGB(0, 255, 0));
		while (y > y2) {
			if (d < 0) {
				d += d2;
				x += 1;
				y -= 1;
			}
			else {
				d += d1;
				y -= 1;
			}
			SetPixel(dc, x, y, RGB(0, 255, 0));
		}
	}
}
