typedef struct {
	int x;
	int y;
}Seed;  //自定义种子坐标数据类型(x,y)

void CMFCDraw3Dlg::ScanLineFill(HDC dc, int x, int y)
{
	std::stack<Seed> sstk;  //递归栈
	int xl, xr, i;
	bool spanNeedFill;
	Seed pt;
	pt.x = x;
	pt.y = y;
	sstk.push(pt);
	COLORREF color=GetPixel(dc,x,y);
	while (!sstk.empty())
	{
		pt = sstk.top();
		sstk.pop();
		x = pt.x;
		y = pt.y;
		while (GetGValue(GetPixel(dc, x, y))==255) {
			SetPixel(dc, x, y, RGB(0, 0, 255));
			x=x+1;
		}
		xr = x-1 ;
		x = pt.x - 1;
		while (GetGValue(GetPixel(dc, x, y)) == 255) {
			SetPixel(dc, x, y, RGB(0, 0, 255));
			x--;
		}
		xl = x + 1;
		x = xl;
		y = y + 1;
		while (x <= xr) {
			spanNeedFill = FALSE;
			while (GetGValue(GetPixel(dc, x, y)) == 255) {
				spanNeedFill = TRUE;
				x++;
			}
			if (spanNeedFill) {
				pt.x = x - 1;
				pt.y = y;
				sstk.push(pt);
				spanNeedFill = FALSE;
			}
			while (GetGValue(GetPixel(dc, x, y)) != 255 && x <= xr) {
				x++;
			}
		}
		x = xl;
		y = y - 2;
		while (x <= xr) {
			spanNeedFill = FALSE;
			while (GetGValue(GetPixel(dc, x, y)) == 255) {
				spanNeedFill = TRUE;
				x++;
			}
			if (spanNeedFill) {
				pt.x = x - 1;
				pt.y = y;
				sstk.push(pt);
				spanNeedFill = FALSE;
			}
			while (GetGValue(GetPixel(dc, x, y)) != 255 && x <= xr) {
				x++;
			}
		}
	}
}
