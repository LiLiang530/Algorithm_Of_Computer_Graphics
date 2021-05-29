void CMFCDraw2Dlg::OnBnClickedButtonDraw()  //按下绘制圆得的按钮
{
	// TODO: 
	CClientDC dc(this);
	CString str;
	GetDlgItemText(IDC_EDIT1, str);  //获取输入框中圆的半径
	r = _ttoi(str);  //CString转int
	int dx = Opoint.x;
	int dy = Opoint.y;
	int x=0;
	int y=r;
	float d=1.25-r;
	SetPixel(dc, x + dx, y + dy, RGB(255, 0, 0));
	SetPixel(dc, x + dx, -y + dy, RGB(255, 0, 0));
	SetPixel(dc, -y + dy,x + dx,  RGB(255, 0, 0));
	SetPixel(dc, y + dy,x + dx,  RGB(255, 0, 0));
	while (x <= y ) {
		if (d < 0) {
			d += 2 * x + 3;
		}
		else {
			d += 2 * (x - y) + 5;
			y--;
		}
		x++;
		SetPixel(dc,x+dx,y+dy,RGB(255,0,0));
		SetPixel(dc, y + dx, x + dy, RGB(255, 0, 0));
		SetPixel(dc, -x + dx, y + dy, RGB(255, 0, 0));
		SetPixel(dc, y + dx, -x + dy, RGB(255, 0, 0));
		SetPixel(dc, x + dx, -y + dy, RGB(255, 0, 0));
		SetPixel(dc, -y + dx, x + dy, RGB(255, 0, 0));
		SetPixel(dc, -x + dx, -y + dy, RGB(255, 0, 0));
		SetPixel(dc, -y + dx, -x + dy, RGB(255, 0, 0));
	}
}
