/****************************************************************************

    ������ bmp.c

    ������ �������� �������� �������, ����������� ��� ������
    � bmp-������� � bmp-�������������.

    ������ ���� �������������           06.11.2013

****************************************************************************/


#include <windows.h>
#include <malloc.h>
#include "bmp.h"


//----------------------------------------

//
// ������� ����������� �������� �� ��������� ����������
//
void DrawBitmap (HDC hdc, HBITMAP hBitmap, int xStart, int yStart) { 

BITMAP bm; 
HDC hdcMem; 
POINT ptSize;
POINT ptOrg;

    // ������� ������� ������ (�������� ����������, ������������ ������ � ������),
    // ����������� � ������������ ��������� ���������� hdc
    // ����� �������� �������� ������ 1 ����������� �������
	hdcMem = CreateCompatibleDC (hdc);

    // �������� �������� � �������� ����������
    // ����� ����� ������ ����������� ��������� ������
    // ����� ����� ������� ��������
	SelectObject (hdcMem, hBitmap);

    // �������� ����� �����������
	SetMapMode(hdcMem, GetMapMode(hdc)); 

    // ��������� ��������� ����������� ��������
	GetObject (hBitmap, sizeof(BITMAP), (LPVOID) &bm); 

    // ����������� ���������� ���������� � ����������
	ptSize.x = bm.bmWidth; 
	ptSize.y = bm.bmHeight;
	DPtoLP (hdc, &ptSize, 1); 
	ptOrg.x = 0; 
	ptOrg.y = 0; 
	DPtoLP (hdcMem, &ptOrg, 1);

    // ������� ����� �������� �� ��������� ������ �� �������� ����������
	BitBlt (hdc, xStart, yStart, ptSize.x, ptSize.y, 
			hdcMem, ptOrg.x, ptOrg.y, SRCCOPY);

    // �������� ��������� ������
	DeleteDC (hdcMem);
	return;
} 

//--------------------

//
// ��������� �������� �� ����� � ������
//
HBITMAP LoadBmpFile (HWND MainWindow, HINSTANCE ins) {

OPENFILENAMEA ofn;
char szFile[MAX_PATH] = "";
HBITMAP bm = NULL;

	ZeroMemory (&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = MainWindow;
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = "bmp-�����\0*.bmp\0��� �����\0*.*\0";
	ofn.nFilterIndex = 0;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	if (GetOpenFileNameA (&ofn)) {
		bm = (HBITMAP)LoadImage (ins, szFile, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		}

	return bm;
}

//--------------------

//
// ������ bmp-���� � ���������� ���������
//
void CreateBMPFile (LPTSTR pszFile, HBITMAP hBitmap, HWND MainWindow) { 

BITMAP bitmap; 
HANDLE hf;                  // ��������� �����
BITMAPFILEHEADER hdr;       // ��������� �� �������� ��������� ����� 
BITMAPINFOHEADER bmih;      // ��������� �� ��������� �������
unsigned char *bits;
unsigned int size_bitmap;
LPDWORD tmp;
HDC hdc;
 
    if (!GetObject(hBitmap, sizeof(BITMAP), (LPSTR)&bitmap)) 
        return; 

	if (bitmap.bmBitsPixel != 32)
		return;

	bmih.biSize = sizeof(BITMAPINFOHEADER); 
	bmih.biWidth = bitmap.bmWidth; 
	bmih.biHeight = bitmap.bmHeight; 
	bmih.biPlanes = bitmap.bmPlanes; 
	bmih.biBitCount = bitmap.bmBitsPixel;  
	bmih.biClrUsed = 0;
	bmih.biCompression = BI_RGB; 
	bmih.biSizeImage = 0;
	bmih.biClrImportant = 0; 

	size_bitmap = 4 * bitmap.bmHeight * bitmap.bmWidth;
    bits = (unsigned char*) malloc (size_bitmap);

    if(!bits) 
         return;

	hdc = GetDC(MainWindow);
	if (!GetDIBits (hdc, hBitmap, 0, (WORD) bmih.biHeight, bits, (LPBITMAPINFO) &bmih, DIB_RGB_COLORS))
		return;

    hf = CreateFile (pszFile, 
                   GENERIC_READ | GENERIC_WRITE, 
                   (DWORD) 0, 
                    NULL, 
                   CREATE_ALWAYS, 
                   FILE_ATTRIBUTE_NORMAL, 
                   (HANDLE) NULL); 
    if (hf == INVALID_HANDLE_VALUE) {
        return;
        }
	
	hdr.bfType = 0x4d42;        // 0x42 = "B" 0x4d = "M" 
	hdr.bfSize = (DWORD) (sizeof(BITMAPFILEHEADER) + bmih.biSize + size_bitmap); 
	hdr.bfReserved1 = 0; 
	hdr.bfReserved2 = 0; 

	hdr.bfOffBits = (DWORD) (sizeof(BITMAPFILEHEADER) + bmih.biSize); 

	if (WriteFile (hf, (LPVOID) &hdr, sizeof(BITMAPFILEHEADER), (LPDWORD) &tmp, NULL) &&
	    WriteFile (hf, (LPVOID) &bmih, sizeof(BITMAPINFOHEADER), (LPDWORD) &tmp, NULL) &&
	    WriteFile(hf, (LPSTR) bits, size_bitmap, (LPDWORD) &tmp, NULL));

	CloseHandle(hf);

    free (bits);

	return; 
}


//--------------------

//
// ��������� �������� � ����
//
void SaveBMPFile (HBITMAP hBitmap, HWND MainWindow){

OPENFILENAMEA ofn;
char szFile[MAX_PATH]="";

	ZeroMemory(&ofn,sizeof(ofn));
	ofn.lStructSize=sizeof(ofn);
	ofn.hwndOwner = MainWindow;
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = "bmp-�����\0*.bmp\0��� �����\0*.*\0";
	ofn.nFilterIndex = 0;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	if (GetSaveFileNameA (&ofn))
		CreateBMPFile (szFile, hBitmap, MainWindow);
		
	return;
}

//--------------------

//
// ���������� �������� � �������, ����������������
// ������������ ���������
//
HBITMAP InvertBitmap (HBITMAP srcBitmap) {


BITMAP bitmap;
HBITMAP dstBitmap;
unsigned char *bits;
unsigned char *pBits;
unsigned int pixelCount;
int i, j;
unsigned int bytesPixel;


    if (!GetObject(srcBitmap,sizeof(BITMAP),&bitmap))
		return NULL;

    if( (bitmap.bmBitsPixel != 24) && (bitmap.bmBitsPixel != 32) ){
        //MessageBox (NULL, "", "����������� ������ ��������� 32 ��� 24 ���� �� �������", MB_OK);
        return NULL;
        }

    pixelCount = bitmap.bmHeight * bitmap.bmWidth;

    bytesPixel = bitmap.bmBitsPixel / 8;

    //bits = (unsigned char*) malloc (bytesPixel * pixelCount);
    bits = (unsigned char*) malloc (bitmap.bmWidthBytes * bitmap.bmHeight);
    if (!bits) {
        //MessageBox(HwndMainWindow,"","������ ��������� ������",MB_OK);
        return NULL;
        }

    //GetBitmapBits (srcBitmap, bitmap.bmBitsPixel * pixelCount, (void*)bits);
    GetBitmapBits (srcBitmap, bitmap.bmWidthBytes * bitmap.bmHeight, (void*)bits);

    pBits = bits;

    for (i = 0; i < bitmap.bmHeight; ++i) {
        pBits = bits + i * bitmap.bmWidthBytes;
        for (j = 0; j < bitmap.bmWidth; ++j) {
            unsigned int pixel = 0;
            memcpy (&pixel, pBits, bytesPixel);
            pixel = ~pixel & 0x00FFFFFF;
            memcpy (pBits, &pixel, bytesPixel);
            pBits += bytesPixel;
            }
        }

    dstBitmap = CreateBitmap (bitmap.bmWidth, bitmap.bmHeight, 1, bitmap.bmBitsPixel, bits);

    free (bits);

    return dstBitmap;
}

//--------------------

//
// ���������� �������� �������� � �������� ������
//
HBITMAP GetGraystyleBitmap (HBITMAP srcBitmap) {


BITMAP bitmap;
HBITMAP dstBitmap;
unsigned char *bits;
unsigned char *pBits;
unsigned int pixelCount;
unsigned int bytesPixel;
int i, j;


    if (!GetObject(srcBitmap,sizeof(BITMAP),&bitmap)) {
		return NULL;
        }

    if( (bitmap.bmBitsPixel != 24) && (bitmap.bmBitsPixel != 32) ){
        //MessageBox (NULL, "", "����������� ������ ��������� 32 ��� 24 ���� �� �������", MB_OK);
        return NULL;
        }

    pixelCount = bitmap.bmHeight * bitmap.bmWidth;

    bytesPixel = bitmap.bmBitsPixel / 8;

    bits = (unsigned char*) malloc (bitmap.bmWidthBytes * bitmap.bmHeight);
    if (!bits) {
        //MessageBox(HwndMainWindow,"","������ ��������� ������",MB_OK);
        return NULL;
        }

    GetBitmapBits (srcBitmap, bitmap.bmBitsPixel * pixelCount, (void*)bits);

    pBits = bits;

    for (i = 0; i < bitmap.bmHeight; ++i) {
        pBits = bits + i * bitmap.bmWidthBytes;
        for (j = 0; j < bitmap.bmWidth; ++j) {
            unsigned int pixel = 0;
            unsigned int r, g, b;
            unsigned int gray;
            memcpy (&pixel, pBits, bytesPixel);
            r = pixel & 0xFF;
            g = (pixel >> 8) & 0xFF;
            b = (pixel >> 16) & 0xFF;
            gray = (r + g + b) / 3;
            pixel = gray | (gray << 8) | (gray << 16);
            memcpy (pBits, &pixel, bytesPixel);
            pBits += bytesPixel;
            }
        }

    dstBitmap = CreateBitmap (bitmap.bmWidth, bitmap.bmHeight, 1, bitmap.bmBitsPixel, bits);

    free (bits);

    return dstBitmap;
}

HBITMAP GetLightPlusBitmap(HBITMAP srcBitmap) {


	BITMAP bitmap;
	HBITMAP dstBitmap;
	unsigned char *bits;
	unsigned char *pBits;
	unsigned int pixelCount;
	unsigned int bytesPixel;
	int i, j;


	if (!GetObject(srcBitmap, sizeof(BITMAP), &bitmap)) {
		return NULL;
	}

	if ((bitmap.bmBitsPixel != 24) && (bitmap.bmBitsPixel != 32)) {
		return NULL;
	}

	pixelCount = bitmap.bmHeight * bitmap.bmWidth;

	bytesPixel = bitmap.bmBitsPixel / 8;

	bits = (unsigned char*)malloc(bitmap.bmWidthBytes * bitmap.bmHeight);
	if (!bits) {
		return NULL;
	}

	GetBitmapBits(srcBitmap, bitmap.bmBitsPixel * pixelCount, (void*)bits);

	pBits = bits;

	for (i = 0; i < bitmap.bmHeight; ++i) {
		pBits = bits + i * bitmap.bmWidthBytes;
		for (j = 0; j < bitmap.bmWidth; ++j) {
			unsigned int pixel = 0;
			unsigned int r, g, b;
			memcpy(&pixel, pBits, bytesPixel);
			r = pixel & 0xFF;
			g = (pixel >> 8) & 0xFF;
			b = (pixel >> 16) & 0xFF;
			if (r < 255 && g < 255 && b < 255) {
				++r; ++g; ++b;
			}
			pixel = r | g << 8  | b << 16 ;
			memcpy(pBits, &pixel, bytesPixel);
			pBits += bytesPixel;
		}
	}

	dstBitmap = CreateBitmap(bitmap.bmWidth, bitmap.bmHeight, 1, bitmap.bmBitsPixel, bits);

	free(bits);

	return dstBitmap;
}

HBITMAP GetLightMinusBitmap(HBITMAP srcBitmap) {


	BITMAP bitmap;
	HBITMAP dstBitmap;
	unsigned char *bits;
	unsigned char *pBits;
	unsigned int pixelCount;
	unsigned int bytesPixel;
	int i, j;


	if (!GetObject(srcBitmap, sizeof(BITMAP), &bitmap)) {
		return NULL;
	}

	if ((bitmap.bmBitsPixel != 24) && (bitmap.bmBitsPixel != 32)) {
		return NULL;
	}

	pixelCount = bitmap.bmHeight * bitmap.bmWidth;

	bytesPixel = bitmap.bmBitsPixel / 8;

	bits = (unsigned char*)malloc(bitmap.bmWidthBytes * bitmap.bmHeight);
	if (!bits) {
		return NULL;
	}

	GetBitmapBits(srcBitmap, bitmap.bmBitsPixel * pixelCount, (void*)bits);

	pBits = bits;

	for (i = 0; i < bitmap.bmHeight; ++i) {
		pBits = bits + i * bitmap.bmWidthBytes;
		for (j = 0; j < bitmap.bmWidth; ++j) {
			unsigned int pixel = 0;
			unsigned int r, g, b;
			const unsigned int lconst = 2;
			memcpy(&pixel, pBits, bytesPixel);
			r = pixel & 0xFF;
			g = (pixel >> 8) & 0xFF;
			b = (pixel >> 16) & 0xFF;
			if (r > 0 && g > 0 && b > 0) {
				--r; --g; --b;
			}
			pixel = r | g << 8 | b << 16;
			memcpy(pBits, &pixel, bytesPixel);
			pBits += bytesPixel;
		}
	}

	dstBitmap = CreateBitmap(bitmap.bmWidth, bitmap.bmHeight, 1, bitmap.bmBitsPixel, bits);

	free(bits);

	return dstBitmap;
}

HBITMAP InverseHorBitmap(HBITMAP srcBitmap) {


	BITMAP bitmap;
	HBITMAP dstBitmap;
	unsigned char *bits;
	unsigned char *pBits;
	unsigned char *invBits;
	unsigned char *pInvBits;
	unsigned int pixelCount;
	unsigned int bytesPixel;
	int i, j;


	if (!GetObject(srcBitmap, sizeof(BITMAP), &bitmap)) {
		return NULL;
	}

	if ((bitmap.bmBitsPixel != 24) && (bitmap.bmBitsPixel != 32)) {
		return NULL;
	}

	pixelCount = bitmap.bmHeight * bitmap.bmWidth;

	bytesPixel = bitmap.bmBitsPixel / 8;

	bits = (unsigned char*)malloc(bitmap.bmWidthBytes * bitmap.bmHeight);
	if (!bits) {
		return NULL;
	}

	invBits = (unsigned char*)malloc(bitmap.bmWidthBytes * bitmap.bmHeight);
	if (!invBits) {
		return NULL;
	}

	GetBitmapBits(srcBitmap, bitmap.bmBitsPixel * pixelCount, (void*)bits);

	pBits = bits;
	pInvBits = invBits;

	for (i = 0; i < bitmap.bmHeight; ++i) {
		pBits = bits + i * bitmap.bmWidthBytes;
		pInvBits = invBits + (bitmap.bmWidthBytes * (i + 1) - bytesPixel);
		for (j = 0; j < bitmap.bmWidth; ++j) {
			memcpy(pInvBits, pBits, bytesPixel);
			pBits += bytesPixel;
			pInvBits -= bytesPixel;
		}
	}

	dstBitmap = CreateBitmap(bitmap.bmWidth, bitmap.bmHeight, 1, bitmap.bmBitsPixel, invBits);

	free(bits);
	free(invBits);

	return dstBitmap;
}

HBITMAP InverseVerBitmap(HBITMAP srcBitmap) {


	BITMAP bitmap;
	HBITMAP dstBitmap;
	unsigned char *bits;
	unsigned char *pBits;
	unsigned char *invBits;
	unsigned char *pInvBits;
	unsigned int pixelCount;
	unsigned int bytesPixel;
	int i, j;


	if (!GetObject(srcBitmap, sizeof(BITMAP), &bitmap)) {
		return NULL;
	}

	if ((bitmap.bmBitsPixel != 24) && (bitmap.bmBitsPixel != 32)) {
		return NULL;
	}

	pixelCount = bitmap.bmHeight * bitmap.bmWidth;

	bytesPixel = bitmap.bmBitsPixel / 8;

	bits = (unsigned char*)malloc(bitmap.bmWidthBytes * bitmap.bmHeight);
	if (!bits) {
		return NULL;
	}

	invBits = (unsigned char*)malloc(bitmap.bmWidthBytes * bitmap.bmHeight);
	if (!invBits) {
		return NULL;
	}

	GetBitmapBits(srcBitmap, bitmap.bmBitsPixel * pixelCount, (void*)bits);

	pBits = bits;
	pInvBits = invBits;

	for (i = 0; i < bitmap.bmHeight; ++i) {
		pBits = bits + i * bitmap.bmWidthBytes;
		pInvBits = invBits + bitmap.bmWidthBytes * (bitmap.bmHeight - 1 - i);
		for (j = 0; j < bitmap.bmWidth; ++j) {
			memcpy(pInvBits, pBits, bytesPixel);
			pBits += bytesPixel;
			pInvBits += bytesPixel;
		}
	}

	dstBitmap = CreateBitmap(bitmap.bmWidth, bitmap.bmHeight, 1, bitmap.bmBitsPixel, invBits);

	free(bits);
	free(invBits);

	return dstBitmap;
}

HBITMAP RightRotateBitmap(HBITMAP srcBitmap) {


	BITMAP bitmap;
	HBITMAP dstBitmap;
	unsigned char *bits;
	unsigned char *pBits;
	unsigned char *newBits;
	unsigned char *pNewBits;
	unsigned int pixelCount;
	unsigned int bytesPixel;
	int i, j;


	if (!GetObject(srcBitmap, sizeof(BITMAP), &bitmap)) {
		return NULL;
	}

	if ((bitmap.bmBitsPixel != 24) && (bitmap.bmBitsPixel != 32)) {
		return NULL;
	}

	pixelCount = bitmap.bmHeight * bitmap.bmWidth;

	bytesPixel = bitmap.bmBitsPixel / 8;

	bits = (unsigned char*)malloc(bitmap.bmWidthBytes * bitmap.bmHeight);
	if (!bits) {
		return NULL;
	}

	newBits = (unsigned char*)malloc(bitmap.bmWidthBytes * bitmap.bmHeight);
	if (!newBits) {
		return NULL;
	}

	GetBitmapBits(srcBitmap, bitmap.bmBitsPixel * pixelCount, (void*)bits);
	
	pBits = bits;
	pNewBits = newBits;

	for (i = 0; i < bitmap.bmHeight; ++i) {
		pBits = bits + i * bitmap.bmWidthBytes;
		for (j = 0; j < bitmap.bmWidth; ++j) {
			pNewBits = newBits + (bitmap.bmHeight - i - 1) * bytesPixel + j * bitmap.bmHeight * bytesPixel;
			memcpy(pNewBits, pBits, bytesPixel);
			pBits += bytesPixel;
		}
	}

	dstBitmap = CreateBitmap(bitmap.bmHeight, bitmap.bmWidth, 1, bitmap.bmBitsPixel, newBits);

	free(bits);
	free(newBits);

	return dstBitmap;
}

HBITMAP LeftRotateBitmap(HBITMAP srcBitmap) {


	BITMAP bitmap;
	HBITMAP dstBitmap;
	unsigned char *bits;
	unsigned char *pBits;
	unsigned char *newBits;
	unsigned char *pNewBits;
	unsigned int pixelCount;
	unsigned int bytesPixel;
	int i, j;


	if (!GetObject(srcBitmap, sizeof(BITMAP), &bitmap)) {
		return NULL;
	}

	if ((bitmap.bmBitsPixel != 24) && (bitmap.bmBitsPixel != 32)) {
		return NULL;
	}

	pixelCount = bitmap.bmHeight * bitmap.bmWidth;

	bytesPixel = bitmap.bmBitsPixel / 8;

	bits = (unsigned char*)malloc(bitmap.bmWidthBytes * bitmap.bmHeight);
	if (!bits) {
		return NULL;
	}

	newBits = (unsigned char*)malloc(bitmap.bmWidthBytes * bitmap.bmHeight);
	if (!newBits) {
		return NULL;
	}

	GetBitmapBits(srcBitmap, bitmap.bmBitsPixel * pixelCount, (void*)bits);

	pBits = bits;
	pNewBits = newBits;

	for (i = 0; i < bitmap.bmHeight; ++i) {
		pBits = bits + i * bitmap.bmWidthBytes;
		for (j = 0; j < bitmap.bmWidth; ++j) {
			pNewBits = newBits + i * bytesPixel + (bitmap.bmWidth - 1 - j) * bitmap.bmHeight * bytesPixel;
			memcpy(pNewBits, pBits, bytesPixel);
			pBits += bytesPixel;
		}
	}

	dstBitmap = CreateBitmap(bitmap.bmHeight, bitmap.bmWidth, 1, bitmap.bmBitsPixel, newBits);

	free(bits);
	free(newBits);

	return dstBitmap;
}

HBITMAP SklBitmap(HBITMAP srcBitmap, HWND hwnd, HINSTANCE hIns) {

	HBITMAP dstBitmap;
	unsigned char *resBits;
	unsigned char *pResBits;
	unsigned char *addBits;
	unsigned char *pAddBits;
	unsigned int resWidth;
	unsigned int resHeight;
	unsigned int resBytesPixel;
	unsigned int minWidth, maxWidth;
	unsigned int minHeight, maxHeight;
	int i, j;

	BITMAP newBitmap;
	HBITMAP newHBitmap;
	unsigned char *newBits;
	unsigned int newPixelCount;
	unsigned int newBytesPixel;


	//��������� ����� ��������
	newHBitmap = LoadBmpFile(hwnd, hIns);

	if (!GetObject(newHBitmap, sizeof(BITMAP), &newBitmap)) {
		return NULL;
	}
	if ((newBitmap.bmBitsPixel != 24) && (newBitmap.bmBitsPixel != 32)) {
		return NULL;
	}

	newPixelCount = newBitmap.bmHeight * newBitmap.bmHeight;

	newBytesPixel = newBitmap.bmBitsPixel / 8;

	newBits = (unsigned char*)malloc(newBitmap.bmWidthBytes * newBitmap.bmHeight);
	if (!newBits) {
		return NULL;
	}

	GetBitmapBits(newHBitmap, newBitmap.bmBitsPixel * newPixelCount, (void*)newBits);


	BITMAP bitmap;
	unsigned char *bits;
	unsigned int pixelCount;
	unsigned int bytesPixel;


	//��������� ������� ��������
	if (!GetObject(srcBitmap, sizeof(BITMAP), &bitmap)) {
		return NULL;
	}
	if ((bitmap.bmBitsPixel != 24) && (bitmap.bmBitsPixel != 32)) {
		return NULL;
	}

	pixelCount = bitmap.bmHeight * bitmap.bmWidth;

	bytesPixel = bitmap.bmBitsPixel / 8;

	bits = (unsigned char*)malloc(bitmap.bmWidthBytes * bitmap.bmHeight);
	if (!bits) {
		return NULL;
	}

	GetBitmapBits(srcBitmap, bitmap.bmBitsPixel * pixelCount, (void*)bits);

	resHeight = newBitmap.bmHeight + bitmap.bmHeight;
	if (newBitmap.bmWidth > bitmap.bmWidth) {
		resBits = newBits;
		addBits = bits;
		resWidth = newBitmap.bmWidth;
		resBytesPixel = newBytesPixel;
		maxHeight = newBitmap.bmHeight;
		maxWidth = newBitmap.bmWidth;
		minWidth = bitmap.bmWidth;
		minHeight = bitmap.bmHeight;
	}
	else {
		resBits = bits;
		addBits = newBits;
		resWidth = bitmap.bmWidth;
		resBytesPixel = bytesPixel;
		maxHeight = bitmap.bmHeight;
		maxWidth = bitmap.bmWidth;
		minWidth = newBitmap.bmWidth;
		minHeight = newBitmap.bmHeight;
	}

	resBits = realloc(resBits, resWidth * resHeight * resBytesPixel);
	pResBits = resBits;
	pAddBits = addBits;

	for (i = maxHeight; i < resHeight; ++i) {
		int index = i - maxHeight;
		pResBits = resBits + i * resWidth * resBytesPixel;
		pAddBits = addBits + index * minWidth * resBytesPixel;
		for (j = 0; j < minWidth; ++j) {
			memcpy(pResBits, pAddBits, resBytesPixel);
			pResBits += newBytesPixel;
			pAddBits += newBytesPixel;
		}
	}

	dstBitmap = CreateBitmap(resWidth, resHeight, 1, bitmap.bmBitsPixel, resBits);

	free(resBits);
	free(addBits);

	return dstBitmap;
}

//--------------------


/*
HBITMAP ConvertTo24Bitmap (HBITMAP srcBitmap) {


BITMAP bitmap;
HBITMAP dstBitmap;
unsigned char *srcBits;
unsigned char *dstBits;
unsigned int dstBytesPixel;
unsigned int dstWidthBytes;
unsigned char *pSrcBits;
unsigned char *pDstBits;
unsigned int pixelCount;
unsigned int srcBytesPixel;
int i, j;


    if (!GetObject(srcBitmap,sizeof(BITMAP),&bitmap)) {
		return NULL;
        }

    if( (bitmap.bmBitsPixel != 24) && (bitmap.bmBitsPixel != 32) ){
        //MessageBox (NULL, "", "����������� ������ ��������� 32 ��� 24 ���� �� �������", MB_OK);
        return NULL;
        }

    pixelCount = bitmap.bmHeight * bitmap.bmWidth;

    srcBytesPixel = bitmap.bmBitsPixel / 8;

    srcBits = (unsigned char*) malloc (bitmap.bmWidthBytes * bitmap.bmHeight);
    if (!srcBits) {
        //MessageBox(HwndMainWindow,"","������ ��������� ������",MB_OK);
        return NULL;
        }

    GetBitmapBits (srcBitmap, bitmap.bmBitsPixel * pixelCount, (void*)srcBits);

    dstBytesPixel = 3;
    dstWidthBytes = dstBytesPixel * bitmap.bmWidth;
    if (dstWidthBytes % 4) {
        dstWidthBytes = 4 * (dstWidthBytes / 4) + 4;
    }

    dstBits = (unsigned char*) malloc (dstWidthBytes * bitmap.bmHeight);
    if (!dstBits) {
        free (srcBits);
        return NULL;
        }


    pSrcBits = srcBits;
    pDstBits = dstBits;

    for (i = 0; i < bitmap.bmHeight; ++i) {
        pSrcBits = srcBits + i * bitmap.bmWidthBytes;
        pDstBits = dstBits + i * dstWidthBytes;
        for (j = 0; j < bitmap.bmWidth; ++j) {
            memcpy (pDstBits, pSrcBits, dstBytesPixel);
            pSrcBits += srcBytesPixel;
            pDstBits += dstBytesPixel;
            }
        }

    dstBitmap = CreateBitmap (bitmap.bmWidth, bitmap.bmHeight, 1, 8 * dstBytesPixel, dstBits);

    free (srcBits);
    free (dstBits);

    return dstBitmap;
}
*/


//--------------------

