void CMFCDraw2Dlg::OnBnClickedButtonDraw()  //按下绘制椭圆按钮
{
	// TODO: 
	CClientDC dc(this);
	CString stra;
	GetDlgItemText(IDC_EDIT2, stra);  //获取椭圆的长轴a
	a = _ttoi(stra);
	CString strb;
	GetDlgItemText(IDC_EDIT3, strb);  //获取椭圆的短轴b
	b = _ttoi(strb);
	int dx = Opoint.x;
	int dy = Opoint.y;

	int x = int(a + 0.5);
	int y = 0;
	int taa = a * a;
	int t2aa = 2 * taa;
	int t4aa = 2 * t2aa;
	int tx = x;
	int tbb = b * b;
	int t2bb = 2 * tbb;
	int t4bb = 2 * t2bb;
	int t2abb = a * t2bb;
	int t2bbx = t2bb * x;

	int d1 = t2bbx * (x - 1) + tbb / 2 + t2aa * (1 - tbb);
	while (t2bb * tx > t2aa * y) {
		SetPixel(dc, x + dx, y + dy, RGB( 0,255, 0));
		SetPixel(dc, x + dx, -y + dy, RGB( 0,255, 0));
		SetPixel(dc, -x + dx, y + dy, RGB( 0,255, 0));
		SetPixel(dc, -x + dx, -y + dy, RGB( 0,255, 0));
		if (d1 < 0) {
			y += 1;
			d1 = d1 + t4aa * y + t2aa;
			tx = x - 1;
		}
		else {
			x -= 1;
			y += 1;
			d1 = d1 - t4bb * x + t4aa * y + t2aa;
			tx = x;
		}
	}
	int d2 = t2bb * (x * x + 1) - t4bb * x + t2aa * (y * y + y - tbb) + taa / 2;
	while (x >= 0) {
		SetPixel(dc, x + dx, y + dy, RGB( 0,255, 0));
		SetPixel(dc, x + dx, -y + dy, RGB( 0,255, 0));
		SetPixel(dc, -x + dx, y + dy, RGB( 0,255, 0));
		SetPixel(dc, -x + dx, -y + dy, RGB( 0,255, 0));
		if (d2 < 0) {
			x -= 1;
			y += 1;
			d2 = d2 + t4aa * y - t4bb * x + t2bb;
		}
		else {
			x -= 1;
			d2 = d2 - t4bb * x + t2bb;
		}
	}
}
