void CMFCDraw4Dlg::cut(CPoint l, CPoint h)
{
	CClientDC dc(this);
	CPen Rpen(PS_SOLID, 1, RGB(255, 0, 0));
	dc.SelectObject(&Rpen);
	//bool if_in=false;
	Line line;
	if_cut = false;
	if (l.x > h.x) {
		xmax = l.x;
		xmin = h.x;
	}
	else {
		xmax = h.x;
		xmin = l.x;
	}
	if (l.y > h.y) {
		ymax = l.y;
		ymin = h.y;
	}
	else {
		ymax = h.y;
		ymin = l.y;
	}
	line=judge(A, B, xmin, xmax, ymin, ymax);
	if (line.xo > 0) {
		dc.MoveTo(line.xo,line.yo);
		dc.LineTo(line.xx, line.yy);
	}
	line = judge(C, D, xmin, xmax, ymin, ymax);
	if (line.xo > 0) {
		dc.MoveTo(line.xo, line.yo);
		dc.LineTo(line.xx, line.yy);
	}
	line = judge(E, F, xmin, xmax, ymin, ymax);
	if (line.xo > 0) {
		dc.MoveTo(line.xo, line.yo);
		dc.LineTo(line.xx, line.yy);
	}
	line = judge(M, N, xmin, xmax, ymin, ymax);
	if (line.xo > 0) {
		dc.MoveTo(line.xo, line.yo);
		dc.LineTo(line.xx, line.yy);
	}
	line = judge(U, V, xmin, xmax, ymin, ymax);
	if (line.xo > 0) {
		dc.MoveTo(line.xo, line.yo);
		dc.LineTo(line.xx, line.yy);
		if (abs(line.yy - ymax) <= 3) {
			dc.LineTo(xmax, ymax);
		}
		else if (abs(line.yo - ymax) <= 3) {
			dc.MoveTo(line.xo, line.yo);
			dc.LineTo(xmax, ymax);
		}
	}
	line = judge(V, W, xmin, xmax, ymin, ymax);
	if (line.xo > 0) {
		dc.MoveTo(line.xo, line.yo);
		dc.LineTo(line.xx, line.yy);
		if (abs(line.yy - ymax) <= 3) {
			dc.LineTo(xmax, ymax);
		}
		else if (abs(line.yo - ymax) <= 3) {
			dc.MoveTo(line.xo, line.yo);
			dc.LineTo(xmax, ymax);
		}
	}
	line = judge(W, X, xmin, xmax, ymin, ymax);
	if (line.xo > 0) {
		dc.MoveTo(line.xo, line.yo);
		dc.LineTo(line.xx, line.yy);
		if (abs(line.yy - ymax) <= 3) {
			dc.LineTo(xmax, ymax);
		}
		else if (abs(line.yo - ymax) <= 3) {
			dc.MoveTo(line.xo, line.yo);
			dc.LineTo(xmax, ymax);
		}
	}
	line = judge(X, Y, xmin, xmax, ymin, ymax);
	if (line.xo > 0) {
		dc.MoveTo(line.xo, line.yo);
		dc.LineTo(line.xx, line.yy);
		if (abs(line.yy - ymax) <= 3) {
			dc.LineTo(xmax, ymax);
		}
		else if (abs(line.yo - ymax) <= 3) {
			dc.MoveTo(line.xo, line.yo);
			dc.LineTo(xmax, ymax);
		}
	}
	line = judge(Y, Z, xmin, xmax, ymin, ymax);
	if (line.xo > 0) {
		dc.MoveTo(line.xo, line.yo);
		dc.LineTo(line.xx, line.yy);
		if (line.xx == xmax) {
			dc.LineTo(xmax, ymax);
		}
	}
	line = judge(U, Z, xmin, xmax, ymin, ymax);
	if (line.xo > 0) {
		dc.MoveTo(line.xo, line.yo);
		dc.LineTo(line.xx, line.yy);
		if (abs(line.xx - xmax)<=3) {
			dc.LineTo(xmax, ymax);
		}
		else if (abs(line.xo - xmax) <= 3) {
			dc.MoveTo(line.xo, line.yo);
			dc.LineTo(xmax, ymax);
		}
	}
}

Line CMFCDraw4Dlg::judge(CPoint Head, CPoint End, int x1, int x2, int y1, int y2)
{
	Line line{-1,0,0,0};
	int head = 0;
	int end = 0;
	head = area(Head, x1, x2, y1, y2);
	end = area(End, x1, x2, y1, y2);
	if (head == 0 && end == 0) {
		line.xo = Head.x;
		line.yo = Head.y;
		line.xx = End.x;
		line.yy = End.y;
		return line;
	}
	
	int in = head & end;
	if ( in== 0) {
		line.xo = midjudgeh(Head, End, x1, x2, y1, y2).x;
		line.yo = midjudgeh(Head, End, x1, x2, y1, y2).y;
		line.xx = midjudged(Head, End, x1, x2, y1, y2).x;
		line.yy = midjudged(Head, End, x1, x2, y1, y2).y;
		return line;
	}
	else {
		return line;
	}
	
}

int CMFCDraw4Dlg::area(CPoint O, int x1, int x2, int y1, int y2)
{
	int	i = -1;
	if (O.y < y1) {
		if (O.x < x1) {
			 i= 9;
		}
		else if (O.x > x2) {
			i = 10;
		}
		else {
			i = 8;
		}
	}
	else if (O.y >= y1 && O.y <= y2) {
		if (O.x < x1) {
			i = 1;
		}
		else if (O.x > x2) {
			i = 2;
		}
		else {
			i = 0;
		}
	}
	else if (O.y > y2) {
		if (O.x < x1) {
			i = 5;
		}
		else if (O.x > x2) {
			i = 6;
		}
		else {
			i = 4;
		}
	}
	return i;
}

CPoint CMFCDraw4Dlg::midjudgeh(CPoint Head, CPoint End, int x1, int x2, int y1, int y2)
{
	int xm = (Head.x+End.x) / 2;
	int ym = (Head.y + End.y) / 2;
	CPoint mid=CPoint(xm, ym);
	if (abs(xm - Head.x) * abs(ym - Head.y) <= 1) {
		return mid;
	}
	int ha = area(Head, x1, x2, y1, y2);
	int ma = area(mid, x1, x2, y1, y2);
	int i = ha & ma;
	if (i == 0) {
		midjudgeh(Head, mid, x1, x2, y1, y2);
	}
	else {
		midjudgeh(mid, End, x1, x2, y1, y2);
	}
}

CPoint CMFCDraw4Dlg::midjudged(CPoint Head, CPoint End, int x1, int x2, int y1, int y2)
{
	int xm = (Head.x + End.x) / 2;
	int ym = (Head.y + End.y) / 2;
	CPoint mid = CPoint(xm, ym);
	if (abs(xm - Head.x) * abs(ym - Head.y) <= 1) {
		return mid;
	}
	int ea = area(End, x1, x2, y1, y2);
	int ma = area(mid, x1, x2, y1, y2);
	mid = CPoint(xm, ym);
	ma= area(mid, x1, x2, y1, y2);
	int i = ea & ma;
	if (i != 0) {
		midjudged(Head, mid, x1, x2, y1, y2);
	}
	else {
		midjudged(mid, End, x1, x2, y1, y2);
	}
}
