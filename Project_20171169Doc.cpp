
// Project_20171169Doc.cpp: CProject20171169Doc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Project_20171169.h"
#endif

#include "Project_20171169Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CProject20171169Doc

IMPLEMENT_DYNCREATE(CProject20171169Doc, CDocument)

BEGIN_MESSAGE_MAP(CProject20171169Doc, CDocument)
END_MESSAGE_MAP()


// CProject20171169Doc 생성/소멸

CProject20171169Doc::CProject20171169Doc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.
	InputImg = NULL;
	InputImg2 = NULL;
	ResultImg = NULL;
	gResultImg = NULL;

}

CProject20171169Doc::~CProject20171169Doc()
{
	if (InputImg != NULL)
	{
		for (int i = 0; i < ImageHeight; i++)
			free(InputImg[i]);

		free(InputImg);
	}
	if (InputImg2 != NULL)
	{
		for (int i = 0; i < ImageHeight; i++)
			free(InputImg2[i]);

		free(InputImg2);
	}
	if (ResultImg != NULL)
	{
		for (int i = 0; i < ImageHeight; i++)
			free(ResultImg[i]);

		free(ResultImg);
	}
	if (gResultImg != NULL)
	{
		for (int i = 0; i < gImageHeight; i++)
			free(gResultImg[i]);

		free(gResultImg);
	}
}

BOOL CProject20171169Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CProject20171169Doc serialization

void CProject20171169Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
		LoadImgFile(ar);
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CProject20171169Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CProject20171169Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CProject20171169Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CProject20171169Doc 진단

#ifdef _DEBUG
void CProject20171169Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CProject20171169Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CProject20171169Doc 명령


void CProject20171169Doc::LoadImgFile(CArchive& ar)
{
	// TODO: 여기에 구현 코드 추가.
	CFile* fp = ar.GetFile();
	CString fname = fp->GetFilePath();

	char type[16], buf[256];
	int maxValue;
	bool isbmp = false;

	if (strcmp(strchr(fname, '.'), ".ppm") == 0 || strcmp(strchr(fname, '.'), ".PPM") == 0||
		strcmp(strchr(fname, '.'), ".pgm") == 0 || strcmp(strchr(fname, '.'), ".PGM") == 0)
	{
		ar.ReadString(type, 15);

		do {
			ar.ReadString(buf, 255);
		} while (buf[0] == '#');
		sscanf_s(buf,"%d %d", &ImageWidth, &ImageHeight);

		do {
			ar.ReadString(buf, 255);
		} while (buf[0] == '#');
		scanf_s(buf, "%d", &maxValue);

		if (strcmp(type, "P5") == 0) depth = 1;
		else depth = 3;
	}
	else if (strcmp(strchr(fname, '.'), ".bmp") == 0 || strcmp(strchr(fname, '.'), ".BMP") == 0)
	{
		//bitmapfile header 읽기
		BITMAPFILEHEADER bmfh;
		ar.Read((LPSTR)&bmfh, sizeof(bmfh));
		if (bmfh.bfType != (WORD)('B' | ('M' << 8))) return;

		//bitmap info header 읽기
		BITMAPINFOHEADER bih;
		ar.Read((LPSTR)&bih, sizeof(bih));
		ImageWidth = bih.biWidth;
		ImageHeight = bih.biHeight;
		depth = bih.biBitCount / 8;

		if (depth == 1)
		{
			//palette 존재
			BYTE pallette[256 * 4];
			ar.Read(pallette, 256 * 4);
		}

		isbmp = true;
	}
	else if (strcmp(strchr(fname, '.'), ".raw") == 0 || strcmp(strchr(fname, '.'), ".RAW") == 0)
	{
		if (fp->GetLength() != 256 * 256)
		{
			AfxMessageBox("256*256 크기의 raw파일만 사용가능");
			return;
		}

		ImageWidth = 256;
		ImageHeight = 256;
		depth = 1;
	}

	//메모리 할당
	InputImg = (unsigned char **)malloc(ImageHeight * sizeof(unsigned char*));
	ResultImg = (unsigned char**)malloc(ImageHeight * sizeof(unsigned char*));
	for (int i = 0; i < ImageHeight; i++)
	{
		InputImg[i] = (unsigned char*)malloc(ImageWidth * depth);
		ResultImg[i] = (unsigned char*)malloc(ImageWidth * depth);
	}
	//영상데이터 읽기
	if (!isbmp)
	{
		for (int i = 0; i < ImageHeight; i++)
			ar.Read(InputImg[i], ImageWidth * depth);
	}
	else
	{
		//파일에서 읽어서 저장
		BYTE nu[4*3];
		int widthfile;
		widthfile = (ImageWidth * 8 + 32) / 32 * 4;
		for (int j = 0; j < ImageHeight; j++)
		{
			if(depth == 1)
				ar.Read(InputImg[ImageHeight-1-j], ImageWidth * depth);
			else
			{
				for (int i = 0; i < ImageWidth; i++)
				{
					BYTE r, g, b;
					ar.Read(&b, 1);
					ar.Read(&g, 1);
					ar.Read(&r, 1);

					InputImg[ImageHeight - 1 - j][3 * i + 0] = r;
					InputImg[ImageHeight - 1 - j][3 * i + 1] = g;
					InputImg[ImageHeight - 1 - j][3 * i + 2] = b;
				}
			}

			if ((widthfile - ImageWidth) != 0)
			{
				ar.Read(nu, (widthfile - ImageWidth) * depth);
			}
		}
	}
}


void CProject20171169Doc::LoadSecondImageFile(CArchive& ar)
{
	// TODO: 여기에 구현 코드 추가.
	CFile* fp = ar.GetFile();
	CString fname = fp->GetFilePath();

	char type[16], buf[256];
	int maxValue;
	int imgw, imgh, imgd;
	bool isbmp = false;

	if (strcmp(strchr(fname, '.'), ".ppm") == 0 || strcmp(strchr(fname, '.'), ".PPM") == 0 ||
		strcmp(strchr(fname, '.'), ".pgm") == 0 || strcmp(strchr(fname, '.'), ".PGM") == 0)
	{
		ar.ReadString(type, 15);

		do {
			ar.ReadString(buf, 256);
		} while (buf[0] == '#');
		sscanf_s(buf, "%d %d", &imgw, &imgh);

		do {
			ar.ReadString(buf, 256);
		} while (buf[0] == '#');
		scanf_s(buf, "%d", &maxValue);

		if (strcmp(type, "P5") == 0) imgd = 1;
		else imgd = 3;
	}
	else if (strcmp(strchr(fname, '.'), ".bmp") == 0 || strcmp(strchr(fname, '.'), ".BMP") == 0)
	{
		//bitmapfile header 읽기
		BITMAPFILEHEADER bmfh;
		ar.Read((LPSTR)&bmfh, sizeof(bmfh));
		if (bmfh.bfType != (WORD)('B' | ('M' << 8))) return;

		//bitmap info header 읽기
		BITMAPINFOHEADER bih;
		ar.Read((LPSTR)&bih, sizeof(bih));
		imgw = bih.biWidth;
		imgh = bih.biHeight;
		imgd = bih.biBitCount / 8;

		if (depth == 1)
		{
			//palette 존재
			BYTE pallette[256 * 4];
			ar.Read(pallette, 256 * 4);
		}

		isbmp = true;
	}
	else if (strcmp(strchr(fname, '.'), ".raw") == 0 || strcmp(strchr(fname, '.'), ".RAW") == 0)
	{
		if (fp->GetLength() != 256 * 256)
		{
			AfxMessageBox("256*256 크기의 raw파일만 사용가능");
			return;
		}

		imgw = 256;
		imgh = 256;
		imgd = 1;
	}

	if (imgw != ImageWidth || imgh != ImageHeight || imgd != depth)
	{
		AfxMessageBox("동일한 크기의 파일만 읽어들일 수 있습니다.");
		return;
	}

	//메모리 할당
	InputImg2 = (unsigned char**)malloc(ImageHeight * sizeof(unsigned char*));
	for (int i = 0; i < ImageHeight; i++)
	{
		InputImg2[i] = (unsigned char*)malloc(ImageWidth * depth);
	}
	//영상데이터 읽기
	if (!isbmp)
	{
		for (int i = 0; i < ImageHeight; i++)
			ar.Read(InputImg2[i], ImageWidth * depth);
	}
	else
	{
		//파일에서 읽어서 저장
		BYTE nu[4 * 3];
		int widthfile;
		widthfile = (ImageWidth * 8 + 32) / 32 * 4;
		for (int j = 0; j < ImageHeight; j++)
		{
			if (depth == 1)
				ar.Read(InputImg2[ImageHeight - 1 - j], ImageWidth * depth);
			else
			{
				for (int i = 0; i < ImageWidth; i++)
				{
					BYTE r, g, b;
					ar.Read(&b, 1);
					ar.Read(&g, 1);
					ar.Read(&r, 1);

					InputImg2[ImageHeight - 1 - j][3 * i + 0] = r;
					InputImg2[ImageHeight - 1 - j][3 * i + 1] = g;
					InputImg2[ImageHeight - 1 - j][3 * i + 2] = b;
				}
			}

			if ((widthfile - ImageWidth) != 0)
			{
				ar.Read(nu, (widthfile - ImageWidth) * depth);
			}
		}
	}
}
