void CMFCDraw3Dlg::BoundaryFill4(HDC dc,int x, int y)  //4连通  种子(x,y)填充
{
	COLORREF color = GetPixel(dc,x, y);
	if (GetGValue(color)!= 0)
	{
		SetPixel(dc, x, y, RGB(255, 0, 0));
		BoundaryFill4(dc,x,y+1);
		BoundaryFill4(dc,x, y - 1);
		BoundaryFill4(dc,x + 1, y);
		BoundaryFill4(dc,x-1, y);
	}
}
