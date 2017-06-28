#include "rectangle.h"

int is_rect(rectangle rect, int *matrix, int N, int M)
{
	int x, y;
	for (y = rect.y1, x = rect.x1-1; y <= rect.y2 && x > 0;  y++)
		if (*(matrix+y*M+x) != 0)
			return 0;
	for (y = rect.y2, x = rect.x2+1; y >= rect.y1 && x < M; y--)
		if(*(matrix+y*M+x) != 0)
			return 0;
	for (y = rect.y1-1, x = rect.x1; x <= rect.x2 && y >= 0; x++)
		if(*(matrix+y*M+x) != 0)
			return 0;
	for (y = rect.y2+1, x = rect.x2+1; x >= rect.x1 && y < N; x--)
		if(*(matrix+y*M+x) != 0)
			return 0;
	return 1;
}

rectangle rect_search(int *matrix, int N, int  M )
{
	rectangle result;
	result.square = 0;
	int b[M], r[M], l[M];
	for (int i = 0; i < M; i++) 
	{
		b[i] = l[i] = -1;
		r[i] = M;
	}
	int st[M], sz = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
			if (*(matrix+y*M+x) == 0)
				b[x] = y;
		while (sz > 0) sz--;
		for (int x = 0; x < M; x++)
		{
			while(sz > 0 && (b[st[sz]] <= b[x])) sz--;
			l[x] = (sz) ? st[sz] : -1;
			st[++sz] = x;
		}
		while (sz >= 0) sz--;
		for (int x = M-1; x >= 0; x--)
		{
			while (sz > 0 && (b[st[sz]] <= b[x])) sz--; 
			r[x] = (sz >= 0) ? st[sz] : M;
			st[++sz] = x;
			
		}
		for (int x = 0; x < M; x++)
		{
			rectangle t_rect;
			t_rect.x1 = l[x]+1;
			t_rect.x2 = r[x]-1;
			t_rect.y1 = b[x]+1;
			t_rect.y2 = y;
			t_rect.square = (r[x]-l[x]-1)*(y-b[x]);
			if (t_rect.square > result.square)
				result = (is_rect(t_rect, matrix, N, M)) ? t_rect : result; 
			//result = (t_rect.square > result.square) ? t_rect : result; 
		}
	}
	return result;
}