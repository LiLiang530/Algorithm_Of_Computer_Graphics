void CMFCDraw1Dlg::DDALine(int x1, int y1, int x2, int y2)
{
	if (x2<x1) {
		int x0 = x1;
		int y0 = y1;
		x1 = x2;
		y1 = y2;
		x2 = x0;
		y2 = y0;
	}
	CClientDC dc(this);
	float dx, dy, k;
	dx = x2 - x1;
	dy = y2 - y1;
	
	
	if (abs(dx) >= abs(dy)) {
		int x;
		float y = y1;
		k = dy / dx;
		for (x = x1; x <= x2; x++) {
			SetPixel(dc, x, int(y + 0.5), RGB(255, 0, 0));
			y = y + k;
		}
	}
	else {
		int y;
		float x = x1;
		k = dx / dy;
		if (y1 <= y2) {
			for (y = y1; y <= y2; y++) {
				SetPixel(dc, int(x + 0.5), y, RGB(255, 0, 0));
				x = x + k;
			}
		}
		else {
			for (y = y1; y >= y2; y--) {
				SetPixel(dc, int(x + 0.5), y, RGB(255, 0, 0));
				x = x - k;
			}
		}
	}
