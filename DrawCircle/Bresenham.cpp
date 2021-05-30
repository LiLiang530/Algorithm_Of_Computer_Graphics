void CMFCDraw2Dlg::OnBnClickedButtonDraw()  //按下按钮开始绘制圆
{
	// TODO: 
	CClientDC dc(this);
	CString str;
	GetDlgItemText(IDC_EDIT1, str);  //获取输入的半径r
	r = _ttoi(str);
	int dx = Opoint.x;
	int dy = Opoint.y;
	int x, y, delta, delta1, delta2, direction;
	x = 0; y = r;
	delta = 2 * (1 - r);
	while (y >= 0)
	{
		SetPixel(dc, x + dx, y + dy, RGB(0, 0, 255));
		SetPixel(dc, -x + dx, y + dy, RGB(0, 0, 255));
		SetPixel(dc, x + dx, -y + dy, RGB(0, 0, 255));
		SetPixel(dc, -x + dx, -y + dy, RGB(0, 0, 255));
		if (delta < 0)
		{
			delta1 = 2 * (delta + y) - 1;
			if (delta1 <= 0) {
				direction = 1;
			}
			else {
				direction = 2;
			}
		}
		else if (delta > 0)
		{
			delta2 = 2 * (delta - x) - 1;
			if (delta2 < 0) direction = 2;
			else direction = 3;
		}
		else {
			direction = 2;
		}
		switch(direction)
		{
		case 1:   
				x++;
				delta += 2 * x + 1;
				break;
		case 2:   
			x++;
			y--;
			delta += 2 * (x - y + 1);
			break;
		case 3:   
			y--;
			delta += (-2 * y + 1);
			break;
		}
	}
}
