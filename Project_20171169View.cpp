
// Project_20171169View.cpp: CProject20171169View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Project_20171169.h"
#endif

#include "Project_20171169Doc.h"
#include "Project_20171169View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProject20171169View

IMPLEMENT_DYNCREATE(CProject20171169View, CScrollView)

BEGIN_MESSAGE_MAP(CProject20171169View, CScrollView)
	ON_COMMAND(PIXEL_add, &CProject20171169View::Onadd)
	ON_COMMAND(PIXEL_sub, &CProject20171169View::Onsub)
	ON_COMMAND(PIXEL_mul, &CProject20171169View::Onmul)
	ON_COMMAND(PIXEL_div, &CProject20171169View::Ondiv)
	ON_COMMAND(PIXEL_HISTOGRAM, &CProject20171169View::OnHistogram)
	ON_COMMAND(PIXEL_CONTRASTSTR, &CProject20171169View::OnContraststr)
	ON_COMMAND(PIXEL_BINARZATION, &CProject20171169View::OnBinarzation)
	ON_COMMAND(PIXEL_twoimgadd, &CProject20171169View::Ontwoimgadd)
	ON_COMMAND(PIXEL_twoimgsub, &CProject20171169View::Ontwoimgsub)
	ON_COMMAND(ID_REGION_SMOOTHING, &CProject20171169View::OnRegionSmoothing)
	ON_COMMAND(ID_REGION_SHARPENING, &CProject20171169View::OnRegionSharpening)
	ON_COMMAND(ID_REGION_EMBOSSING, &CProject20171169View::OnRegionEmbossing)
	ON_COMMAND(ID_REGION_PREWITT, &CProject20171169View::OnRegionPrewitt)
	ON_COMMAND(ID_REGION_ROVERT, &CProject20171169View::OnRegionRovert)
	ON_COMMAND(ID_REGION_SOBEL, &CProject20171169View::OnRegionSobel)
	ON_COMMAND(ID_REGION_AVERAGEFILTERING, &CProject20171169View::OnRegionAveragefiltering)
	ON_COMMAND(ID_REGION_MEDIANFILTERING, &CProject20171169View::OnRegionMedianfiltering)
	ON_COMMAND(ID_MOPOLOGY_COLOR_GRAY, &CProject20171169View::OnMopologyColorGray)
	ON_COMMAND(ID_MOPOLOGY_BINARZATION, &CProject20171169View::OnMopologyBinarzation)
	ON_COMMAND(ID_MOPLOGY_EROSION, &CProject20171169View::OnMoplogyErosion)
	ON_COMMAND(ID_MOPLOGY_OPENING, &CProject20171169View::OnMoplogyOpening)
	ON_COMMAND(ID_MOPLOGY_DILATION, &CProject20171169View::OnMoplogyDilation)
	ON_COMMAND(ID_MOPLOGY_CLOSING, &CProject20171169View::OnMoplogyClosing)
	ON_COMMAND(ID_GEOMETRY_ZOOMIN_PIXELCOPY, &CProject20171169View::OnGeometryZoominPixelcopy)
	ON_COMMAND(ID_GEOMETRY_ZOOMIN_BILINARINTERPOLATION, &CProject20171169View::OnGeometryZoominBilinarinterpolation)
	ON_COMMAND(ID_GEOMETRY_ZOOMOUT_SUBSAMPLING, &CProject20171169View::OnGeometryZoomoutSubsampling)
	ON_COMMAND(ID_GEOMETRY_ZOOMIN_AVG, &CProject20171169View::OnGeometryZoominAvg)
	ON_COMMAND(ID_GEOMETRY_ROTATE, &CProject20171169View::OnGeometryRotate)
	ON_COMMAND(ID_GEOMETRY_HORIZONTAL_FLIP, &CProject20171169View::OnGeometryHorizontalFlip)
	ON_COMMAND(ID_GEOMETRY_VERTICAL_FLIP, &CProject20171169View::OnGeometryVerticalFlip)
	ON_COMMAND(ID_GEOMETRY_ZOOMOUT_MEANSUB, &CProject20171169View::OnGeometryZoomoutMeansub)
END_MESSAGE_MAP()


// CProject20171169View 생성/소멸

CProject20171169View::CProject20171169View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CProject20171169View::~CProject20171169View()
{
}

BOOL CProject20171169View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CScrollView::PreCreateWindow(cs);
}

// CProject20171169View 그리기

void CProject20171169View::OnDraw(CDC* pDC)
{
	CProject20171169Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	int x, y;

	if (pDoc->InputImg != NULL)
	{
		if (pDoc->depth == 1)
		{
			for (y = 0; y < pDoc->ImageHeight; y++) {
				for (x = 0; x < pDoc->ImageWidth; x++) {
					pDC->SetPixel(x, y, RGB(pDoc->InputImg[y][x], pDoc->InputImg[y][x], pDoc->InputImg[y][x]));
				}
			}
		}
		else
		{
			for (y = 0; y < pDoc->ImageHeight; y++) {
				for (x = 0; x < pDoc->ImageWidth; x++) {
					pDC->SetPixel(x, y, RGB(pDoc->InputImg[y][3 * x + 0], pDoc->InputImg[y][3 * x + 1], pDoc->InputImg[y][3 * x + 2]));
				}
			}
		}
	}
	if (pDoc->ResultImg != NULL)
	{
		if (pDoc->depth == 1) {
			for (y = 0; y < pDoc->ImageHeight; y++) {
				for (x = 0; x < pDoc->ImageWidth; x++) {
					pDC->SetPixel(x + pDoc->ImageWidth + 20, y, RGB(pDoc->ResultImg[y][x], pDoc->ResultImg[y][x], pDoc->ResultImg[y][x]));
				}
			}
		}
		else
		{
			for (y = 0; y < pDoc->ImageHeight; y++) {
				for (x = 0; x < pDoc->ImageWidth; x++) {
					pDC->SetPixel(x + pDoc->ImageWidth + 20, y, RGB(pDoc->ResultImg[y][3*x+0], pDoc->ResultImg[y][3*x+1], pDoc->ResultImg[y][3*x+2]));
				}
			}
		}
	}

	if (pDoc->InputImg2 != NULL)
	{
		if (pDoc->depth == 1) 
		{
			for (y = 0; y < pDoc->ImageHeight; y++) {
				for (x = 0; x < pDoc->ImageWidth; x++) {
					pDC->SetPixel(x + (pDoc->ImageWidth + 20) * 2, y, RGB(pDoc->InputImg2[y][x], pDoc->InputImg2[y][x], pDoc->InputImg2[y][x]));
				}
			}
		}
		else
		{
			for (y = 0; y < pDoc->ImageHeight; y++) {
				for (x = 0; x < pDoc->ImageWidth; x++) {
					pDC->SetPixel(x + (pDoc->ImageWidth + 20) * 2, y, RGB(pDoc->InputImg2[y][3*x+0], pDoc->InputImg2[y][3*x+1], pDoc->InputImg2[y][3*x+2]));
				}
			}
		}
	}
	if (pDoc->gResultImg != NULL)
	{
		if (pDoc->depth == 1) {
			for (y = 0; y < pDoc->gImageHeight; y++) {
				for (x = 0; x < pDoc->gImageWidth; x++) {
					pDC->SetPixel(x, pDoc->ImageHeight+20+y, RGB(pDoc->gResultImg[y][x], pDoc->gResultImg[y][x], pDoc->gResultImg[y][x]));
				}
			}
		}
		else
		{
			for (y = 0; y < pDoc->gImageHeight; y++) {
				for (x = 0; x < pDoc->gImageWidth; x++) {
					pDC->SetPixel(x, pDoc->ImageHeight + 20 + y, RGB(pDoc->gResultImg[y][3 * x + 0], pDoc->gResultImg[y][3 * x + 1], pDoc->gResultImg[y][3 * x + 2]));
				}
			}
		}
	}
}

void CProject20171169View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 이 뷰의 전체 크기를 계산합니다.
	sizeTotal.cx = sizeTotal.cy = 2048;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CProject20171169View 진단

#ifdef _DEBUG
void CProject20171169View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CProject20171169View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CProject20171169Doc* CProject20171169View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProject20171169Doc)));
	return (CProject20171169Doc*)m_pDocument;
}
#endif //_DEBUG


// CProject20171169View 메시지 처리기


void CProject20171169View::Onadd()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CProject20171169Doc* pDoc = GetDocument();

	if (pDoc->InputImg == NULL) return;

	int x, y, value;

	for (y = 0; y < pDoc->ImageHeight; y++) {
		for (x = 0; x < pDoc->ImageWidth*pDoc->depth; x++) {
			value = pDoc->InputImg[y][x] + 50;
			
			if (value > 255) value = 255;
			else if (value < 0) value = 0;

			pDoc->ResultImg[y][x] = value;
		}
	}
	Invalidate();
}


void CProject20171169View::Onsub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CProject20171169Doc* pDoc = GetDocument();
	if (pDoc->InputImg == NULL) return;

	int x, y, value;

	for (y = 0; y < pDoc->ImageHeight; y++) {
		for (x = 0; x < pDoc->ImageWidth*pDoc->depth; x++) {
			value = pDoc->InputImg[y][x] - 50;

			if (value > 255) value = 255;
			else if (value < 0) value = 0;

			pDoc->ResultImg[y][x] = value;
		}
	}
	Invalidate();
}


void CProject20171169View::Onmul()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CProject20171169Doc* pDoc = GetDocument();
	if (pDoc->InputImg == NULL) return;

	int x, y, value;

	for (y = 0; y < pDoc->ImageHeight; y++) {
		for (x = 0; x < pDoc->ImageWidth*pDoc->depth; x++) {
			value = pDoc->InputImg[y][x] * 1.5;
			if (value > 255) value = 255;
			else if (value < 0) value = 0;

			pDoc->ResultImg[y][x] = value;
		}
	}
	Invalidate();
}


void CProject20171169View::Ondiv()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CProject20171169Doc* pDoc = GetDocument();
	if (pDoc->InputImg == NULL) return;

	int x, y, value;

	for (y = 0; y < pDoc->ImageHeight; y++) {
		for (x = 0; x < pDoc->ImageWidth * pDoc->depth; x++) {
			value = pDoc->InputImg[y][x] / 1.5;

			if (value > 255) value = 255;
			else if (value < 0) value = 0;

			pDoc->ResultImg[y][x] = value;
		}
	}
	Invalidate();
}


void CProject20171169View::OnHistogram()
{
	CProject20171169Doc* pDoc = GetDocument();
	if (pDoc->InputImg == NULL) return;

	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int hist[256], sum[256];
	int k;

	for (int i = 0; i < 256; i++) {
		hist[i] = 0;
	}
	//히스토그램 구하기
	for (int y = 0; y < pDoc->ImageHeight; y++) {
		for (int x = 0; x < pDoc->ImageWidth; x++) {
			k = pDoc->InputImg[y][x];
			hist[k]++;
		}
	}

	//누적분포 구하기
	int aoc_hist = 0;
	for (int i = 0; i < 256; i++) {
		aoc_hist += hist[i];
		sum[i] = aoc_hist;
	}

	//화소값계산(정규화)
	int N = pDoc->ImageHeight * pDoc->ImageWidth;
	for (int y = 0; y < pDoc->ImageHeight; y++) {
		for (int x = 0; x < pDoc->ImageWidth*pDoc->depth; x++) {
			k = pDoc->InputImg[y][x];
			pDoc->ResultImg[y][x] = (double)sum[k] / N * 255;
		}
	}

	Invalidate();
}


void CProject20171169View::OnContraststr()
{
	CProject20171169Doc* pDoc = GetDocument();
	if (pDoc->InputImg == NULL) return;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int max = 0;
	int min = 256;

	//최대값,최소값 설정
	for (int y = 0; y < pDoc->ImageHeight; y++) {
		for (int x = 0; x < pDoc->ImageWidth*pDoc->depth; x++) {
			if (pDoc->InputImg[y][x] > max) max = pDoc->InputImg[y][x];
			if (pDoc->InputImg[y][x] < min) min = pDoc->InputImg[y][x];
		}
	}

	double value;
	for (int y = 0; y < pDoc->ImageHeight; y++) {
		for (int x = 0; x < pDoc->ImageWidth*pDoc->depth; x++) {
			value = ((pDoc->InputImg[y][x] - min) / (double)(max - min)) *255;
			if (value > 255) value = 255;
			else if (value < 0) value = 0;
			pDoc->ResultImg[y][x] = value;
		}
	}
	Invalidate();
}


void CProject20171169View::OnBinarzation()
{
	CProject20171169Doc* pDoc = GetDocument();
	if (pDoc->InputImg == NULL) return;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	int t = 120;
	int value;

	if (pDoc->depth == 1) {
		for (int y = 0; y < pDoc->ImageHeight; y++) {
			for (int x = 0; x < pDoc->ImageWidth; x++) {
				value = pDoc->InputImg[y][x];
				if (value > t) pDoc->ResultImg[y][x] = 255;
				else pDoc->ResultImg[y][x] = 0;
			}
		}
	}
	else
	{
		for (int y = 0; y < pDoc->ImageHeight; y++) {
			for (int x = 0; x < pDoc->ImageWidth*pDoc->depth; x=x+3) {
				value = (pDoc->InputImg[y][x]+ pDoc->InputImg[y][x]+ pDoc->InputImg[y][x])/3;
				if (value > t)
				{
					pDoc->ResultImg[y][x] = 255;
					pDoc->ResultImg[y][x+1] = 255;
					pDoc->ResultImg[y][x+2] = 255;
				}
				else
				{
					pDoc->ResultImg[y][x] = 0;
					pDoc->ResultImg[y][x+1] = 0;
					pDoc->ResultImg[y][x+2] = 0;
				}
			}
		}
	}

	Invalidate();
}


void CProject20171169View::Ontwoimgadd()
{
	CProject20171169Doc* pDoc = GetDocument();
	if (pDoc->InputImg == NULL) return;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CFileDialog dlg(true);
	if (dlg.DoModal() == IDOK) {
		CFile file;
		file.Open(dlg.GetPathName(), CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		pDoc->LoadSecondImageFile(ar);
		file.Close();
	}
	else return;
	/*
	//LoadTwoImage();
	//파일열기
	if (dlg.DoModal() == IDOK) {
		CFile file;
		file.Open(dlg.GetPathName(), CFile::modeRead);
		file.Read(pDoc->InputImg2, 256 * 256);
		file.Close();
	}
	Invalidate();
	*/
	int x, y, value;
	for (int y = 0; y < pDoc->ImageHeight; y++) {
		for (int x = 0; x < pDoc->ImageWidth; x++) {
			value = 0.5*pDoc->InputImg[y][x] + 0.5*pDoc->InputImg2[y][x];
			if (value > 255) value = 255;
			else if (value < 0) value = 0;
			pDoc->ResultImg[y][x] = value;
		}
	}
	Invalidate();
}


void CProject20171169View::Ontwoimgsub()
{
	CProject20171169Doc* pDoc = GetDocument();
	if (pDoc->InputImg == NULL) return;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CFileDialog dlg(true);
	if (dlg.DoModal() == IDOK) {
		CFile file;
		file.Open(dlg.GetPathName(), CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		pDoc->LoadSecondImageFile(ar);
		file.Close();
	}
	else return;
	/*
	//LoadTwoImage();
	//파일열기
	if (dlg.DoModal() == IDOK) {
		CFile file;
		file.Open(dlg.GetPathName(), CFile::modeRead);
		file.Read(pDoc->InputImg2, 256 * 256);
		file.Close();
	}
	Invalidate();
	*/
	int x, y, value;
	for (int y = 0; y < pDoc->ImageHeight; y++) {
		for (int x = 0; x < pDoc->ImageWidth; x++) {
			value = abs(pDoc->InputImg[y][x] - pDoc->InputImg2[y][x]);
			
			if (value > 255) value = 255;
			else if (value < 0) value = 0;
			pDoc->ResultImg[y][x] = value;
		}
	}
	Invalidate();
}


void CProject20171169View::OnRegionSmoothing()
{
	CProject20171169Doc* pDoc = GetDocument();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	float kernel[3][3] = {	{1.0/9.0,1.0/9.0,1.0/9.0},
							{1.0/9.0,1.0/9.0,1.0/9.0},
							{1.0/9.0,1.0/9.0,1.0/9.0} };

	Convolve(pDoc->InputImg, pDoc->ResultImg, pDoc->ImageWidth, pDoc->ImageHeight, kernel, 0, pDoc->depth);

	Invalidate();
}


void CProject20171169View::Convolve(unsigned char** InImg, unsigned char** OutImg, int cols, int rows, float mask[][3], int bias, int depth)
{
	// TODO: 여기에 구현 코드 추가.
	float sum, rsum,gsum,bsum;

	for (int y = 1; y < rows-1; y++) {
		for (int x = 1; x < cols-1; x++) {
			if (depth == 1)
			{
				sum = 0;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						sum += mask[i][j] * InImg[y - 1 + i][x - 1 + j];
					}
				}
				sum += bias;
				if (sum > 255) sum = 255;
				else if (sum < 0) sum = 0;
				OutImg[y][x] = sum;
			}
			else
			{
				rsum = 0;
				gsum = 0;
				bsum = 0;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						rsum += mask[i][j] * InImg[y - 1 + i][3 * (x - 1 + j)+0];
						gsum += mask[i][j] * InImg[y - 1 + i][3 * (x - 1 + j)+1];
						bsum += mask[i][j] * InImg[y - 1 + i][3 * (x - 1 + j)+2];
					}
				}
				rsum += bias;
				gsum += bias;
				bsum += bias;

				if (rsum > 255) rsum = 255;
				else if (rsum < 0) rsum = 0;
				if (gsum > 255) gsum = 255;
				else if (gsum < 0) gsum = 0;
				if (bsum > 255) bsum = 255;
				else if (bsum < 0) bsum = 0;

				OutImg[y][3 * x + 0] = rsum;
				OutImg[y][3 * x + 1] = gsum;
				OutImg[y][3 * x + 2] = bsum;
			}
		}
	}
}


void CProject20171169View::OnRegionSharpening()
{
	CProject20171169Doc* pDoc = GetDocument();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	float kernel[3][3] = {	{0, -1, 0},
							{-1, 5, -1},
							{0, -1, 0} };

	Convolve(pDoc->InputImg, pDoc->ResultImg, pDoc->ImageWidth, pDoc->ImageHeight, kernel, 0, pDoc->depth);

	Invalidate();
}


void CProject20171169View::OnRegionEmbossing()
{
	CProject20171169Doc* pDoc = GetDocument();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	float kernel[3][3] = {	{-1, 0, 0},
							{0, 0, 0},
							{0, 0, 1} };

	Convolve(pDoc->InputImg, pDoc->ResultImg, pDoc->ImageWidth, pDoc->ImageHeight, kernel, 0, pDoc->depth);

	Invalidate();
}


void CProject20171169View::OnRegionPrewitt()
{
	CProject20171169Doc* pDoc = GetDocument();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	float Hmask[3][3] = {	{-1, -1, -1},
							{0, 0, 0},
							{1, 1, 1} };
	float Vmask[3][3] = {	{1, 0, -1},
							{1, 0, -1},
							{1, 0, -1} };

	unsigned char** Er, ** Ec;
	int value;

	//메모리할당
	Er = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));
	Ec = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));
	for (int i = 0; i < pDoc->ImageHeight; i++)
	{
		Er[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
		Ec[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
	}

	Convolve(pDoc->InputImg, Er, pDoc->ImageWidth, pDoc->ImageHeight, Hmask, 0, pDoc->depth);
	Convolve(pDoc->InputImg, Ec, pDoc->ImageWidth, pDoc->ImageHeight, Vmask, 0, pDoc->depth);
	
	for (int y = 0; y < pDoc->ImageHeight; y++) {
		for (int x = 0; x < pDoc->ImageWidth*pDoc->depth; x++) {
			value = sqrt(Er[y][x] * Er[y][x] + Ec[y][x] * Ec[y][x]);
			if (value > 255) value = 255;
			else if (value < 0) value = 0;

			pDoc->ResultImg[y][x] = value;
		}
	}

	//메모리 해제
	for (int i = 0; i < pDoc->ImageHeight; i++) {
		free(Er[i]);
		free(Ec[i]);
	}
	free(Er);
	free(Ec);

	Invalidate();
}


void CProject20171169View::OnRegionRovert()
{
	CProject20171169Doc* pDoc = GetDocument();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	float Hmask[3][3] = { {0, 0, -1},
							{0, 1, 0},
							{0, 0, 0} };
	float Vmask[3][3] = { {-1, 0, 0},
							{0, 1, 0},
							{0, 0, 0} };

	unsigned char** Er, ** Ec;
	int value;

	//메모리할당
	Er = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));
	Ec = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));
	for (int i = 0; i < pDoc->ImageHeight; i++)
	{
		Er[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
		Ec[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
	}

	Convolve(pDoc->InputImg, Er, pDoc->ImageWidth, pDoc->ImageHeight, Hmask, 0, pDoc->depth);
	Convolve(pDoc->InputImg, Ec, pDoc->ImageWidth, pDoc->ImageHeight, Vmask, 0, pDoc->depth);

	for (int y = 0; y < pDoc->ImageHeight; y++) {
		for (int x = 0; x < pDoc->ImageWidth * pDoc->depth; x++) {
			value = sqrt(Er[y][x] * Er[y][x] + Ec[y][x] * Ec[y][x]);
			if (value > 255) value = 255;
			else if (value < 0) value = 0;

			pDoc->ResultImg[y][x] = value;
		}
	}

	//메모리 해제
	for (int i = 0; i < pDoc->ImageHeight; i++) {
		free(Er[i]);
		free(Ec[i]);
	}
	free(Er);
	free(Ec);

	Invalidate();
}


void CProject20171169View::OnRegionSobel()
{
	CProject20171169Doc* pDoc = GetDocument();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	float Hmask[3][3] = { {-1, -2, -1},
							{0, 0, 0},
							{1, 2, 1} };
	float Vmask[3][3] = { {1, 0, -1},
							{2, 0, -2},
							{1, 0, -1} };

	unsigned char** Er, ** Ec;
	int value;

	//메모리할당
	Er = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));
	Ec = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));
	for (int i = 0; i < pDoc->ImageHeight; i++)
	{
		Er[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
		Ec[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
	}

	Convolve(pDoc->InputImg, Er, pDoc->ImageWidth, pDoc->ImageHeight, Hmask, 0, pDoc->depth);
	Convolve(pDoc->InputImg, Ec, pDoc->ImageWidth, pDoc->ImageHeight, Vmask, 0, pDoc->depth);

	for (int y = 0; y < pDoc->ImageHeight; y++) {
		for (int x = 0; x < pDoc->ImageWidth * pDoc->depth; x++) {
			value = sqrt(Er[y][x] * Er[y][x] + Ec[y][x] * Ec[y][x]);
			if (value > 255) value = 255;
			else if (value < 0) value = 0;

			pDoc->ResultImg[y][x] = value;
		}
	}

	//메모리 해제
	for (int i = 0; i < pDoc->ImageHeight; i++) {
		free(Er[i]);
		free(Ec[i]);
	}
	free(Er);
	free(Ec);

	Invalidate();
}


void CProject20171169View::OnRegionAveragefiltering()
{
	CProject20171169Doc* pDoc = GetDocument();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int xcor,ycor;
	int sum, count, rsum, gsum, bsum;

	for (int y = 0; y < pDoc->ImageHeight; y++) {
		for (int x = 0; x < pDoc->ImageWidth; x++) {
			if (pDoc->depth == 1)
			{
				sum = 0;
				count = 0;
				for (int j = -3; j <= 3; j++) {
					for (int i = -3; i <= 3; i++) {
						ycor = y + j;
						xcor = x + i;

						if (ycor >= 0 && ycor < pDoc->ImageHeight - 1 && xcor >= 0 && xcor <= pDoc->ImageHeight - 1)
						{
							sum += pDoc->InputImg[ycor][xcor];
							count++;
						}
					}
				}
				pDoc->ResultImg[y][x] = sum / count;
			}
			else
			{
				rsum = gsum = bsum = 0;
				count = 0;
				for (int j = -3; j <= 3; j++) {
					for (int i = -3; i <= 3; i++) {
						ycor = y + j;
						xcor = x + i;

						if (ycor >= 0 && ycor <= pDoc->ImageHeight - 1 && xcor >= 0 && xcor <= pDoc->ImageWidth - 1)
						{
							rsum += pDoc->InputImg[ycor][3 * xcor + 0];
							gsum += pDoc->InputImg[ycor][3 * xcor + 1];
							bsum += pDoc->InputImg[ycor][3 * xcor + 2];
							count++;
						}
					}
				}
				pDoc->ResultImg[y][3 * x + 0] = rsum / count;
				pDoc->ResultImg[y][3 * x + 1] = gsum / count;
				pDoc->ResultImg[y][3 * x + 2] = bsum / count;
			}
		}
	}
	Invalidate();
}


void CProject20171169View::OnRegionMedianfiltering()
{
	CProject20171169Doc* pDoc = GetDocument();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int n[9];
	int temp;
	for (int y = 1; y < pDoc->ImageHeight-1; y++) {
		for (int x = 1; x < pDoc->ImageWidth-1; x++) {
			if (pDoc->depth == 1)
			{
				n[0] = pDoc->InputImg[y - 1][x - 1];
				n[1] = pDoc->InputImg[y - 1][x - 0];
				n[2] = pDoc->InputImg[y - 1][x + 1];
				n[3] = pDoc->InputImg[y - 1][x - 1];
				n[4] = pDoc->InputImg[y - 1][x - 1];
				n[5] = pDoc->InputImg[y - 1][x + 1];
				n[6] = pDoc->InputImg[y + 1][x - 1];
				n[7] = pDoc->InputImg[y + 1][x - 0];
				n[8] = pDoc->InputImg[y + 1][x + 1];

				//sort
				for (int i = 8; i > 0; i--) {
					for (int j = 0; j < i; j++) {
						if (n[j] > n[j + 1]) {
							temp = n[j + 1];
							n[j + 1] = n[j];
							n[j] = temp;
						}
					}
				}
				pDoc->ResultImg[y][x] = n[4];
			}
			else
			{
				//r
				n[0] = pDoc->InputImg[y - 1][3 * (x - 1) + 0];
				n[1] = pDoc->InputImg[y - 1][3 * (x - 0) + 0];
				n[2] = pDoc->InputImg[y - 1][3 * (x + 1) + 0];
				n[3] = pDoc->InputImg[y - 1][3 * (x - 1) + 0];
				n[4] = pDoc->InputImg[y - 1][3 * (x - 0) + 0];
				n[5] = pDoc->InputImg[y - 1][3 * (x + 1) + 0];
				n[6] = pDoc->InputImg[y + 1][3 * (x - 1) + 0];
				n[7] = pDoc->InputImg[y + 1][3 * (x - 0) + 0];
				n[8] = pDoc->InputImg[y + 1][3 * (x + 1) + 0];

				//sort
				for (int i = 8; i > 0; i--) {
					for (int j = 0; j < i; j++) {
						if (n[j] > n[j + 1]) {
							temp = n[j + 1];
							n[j + 1] = n[j];
							n[j] = temp;
						}
					}
				}
				pDoc->ResultImg[y][3 * x + 0] = n[4];
				//g
				n[0] = pDoc->InputImg[y - 1][3 * (x - 1) + 1];
				n[1] = pDoc->InputImg[y - 1][3 * (x - 0) + 1];
				n[2] = pDoc->InputImg[y - 1][3 * (x + 1) + 1];
				n[3] = pDoc->InputImg[y - 1][3 * (x - 1) + 1];
				n[4] = pDoc->InputImg[y - 1][3 * (x - 0) + 1];
				n[5] = pDoc->InputImg[y - 1][3 * (x + 1) + 1];
				n[6] = pDoc->InputImg[y + 1][3 * (x - 1) + 1];
				n[7] = pDoc->InputImg[y + 1][3 * (x - 0) + 1];
				n[8] = pDoc->InputImg[y + 1][3 * (x + 1) + 1];

				//sort
				for (int i = 8; i > 0; i--) {
					for (int j = 0; j < i; j++) {
						if (n[j] > n[j + 1]) {
							temp = n[j + 1];
							n[j + 1] = n[j];
							n[j] = temp;
						}
					}
				}
				pDoc->ResultImg[y][3 * x + 1] = n[4];
				//b
				n[0] = pDoc->InputImg[y - 1][3 * (x - 1) + 2];
				n[1] = pDoc->InputImg[y - 1][3 * (x - 0) + 2];
				n[2] = pDoc->InputImg[y - 1][3 * (x + 1) + 2];
				n[3] = pDoc->InputImg[y - 1][3 * (x - 1) + 2];
				n[4] = pDoc->InputImg[y - 1][3 * (x - 0) + 2];
				n[5] = pDoc->InputImg[y - 1][3 * (x + 1) + 2];
				n[6] = pDoc->InputImg[y + 1][3 * (x - 1) + 2];
				n[7] = pDoc->InputImg[y + 1][3 * (x - 0) + 2];
				n[8] = pDoc->InputImg[y + 1][3 * (x + 1) + 2];

				//sort
				for (int i = 8; i > 0; i--) {
					for (int j = 0; j < i; j++) {
						if (n[j] > n[j + 1]) {
							temp = n[j + 1];
							n[j + 1] = n[j];
							n[j] = temp;
						}
					}
				}
				pDoc->ResultImg[y][3 * x + 2] = n[4];
			}
		}
	}
	Invalidate();
}


void CProject20171169View::OnMopologyColorGray()
{
	CProject20171169Doc* pDoc = GetDocument();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (pDoc->depth == 1) return;

	int gray;

	for (int y = 0; y < pDoc->ImageHeight; y++) {
		for (int x = 0; x < pDoc->ImageWidth; x++) {
			gray = (pDoc->InputImg[y][3 * x + 0] + pDoc->InputImg[y][3 * x + 1] + pDoc->InputImg[y][3 * x + 2]) / 3;
			pDoc->InputImg[y][3 * x + 0] = gray;
			pDoc->InputImg[y][3 * x + 1] = gray;
			pDoc->InputImg[y][3 * x + 2] = gray;
		}
	}
	Invalidate();
}


void CProject20171169View::OnMopologyBinarzation()
{
	CProject20171169Doc* pDoc = GetDocument();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int thresh = 128;

	for (int y = 0; y < pDoc->ImageHeight; y++) {
		for (int x = 0; x < pDoc->ImageWidth; x++) {
			if (pDoc->depth == 1)
			{
				if (pDoc->InputImg[y][x] > thresh) pDoc->InputImg[y][x] = 255;
				else pDoc->InputImg[y][x] = 0;
			}
			else
			{
				if ((pDoc->InputImg[y][3 * x + 0] + pDoc->InputImg[y][3 * x + 1] + pDoc->InputImg[y][3 * x + 2]) / 3 > thresh)
				{
					pDoc->InputImg[y][3 * x + 0] = 255;
					pDoc->InputImg[y][3 * x + 1] = 255;
					pDoc->InputImg[y][3 * x + 2] = 255;
				}
				else
				{
					pDoc->InputImg[y][3 * x + 0] = 0;
					pDoc->InputImg[y][3 * x + 1] = 0;
					pDoc->InputImg[y][3 * x + 2] = 0;
				}
			}
		}
	}
	Invalidate();
}


void CProject20171169View::OnMoplogyErosion()
{
	CProject20171169Doc* pDoc = GetDocument();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int min,rmin,gmin,bmin;

	for (int y = 1; y < pDoc->ImageHeight-1; y++) {
		for (int x = 1; x < pDoc->ImageWidth-1; x++) {
			if (pDoc->depth == 1)
			{
				min = 255;
				for (int j = -1; j <= 1; j++) {
					for (int i = -1; i <= 1; i++)
					{
						if (pDoc->InputImg[y + j][x + i] < min) min = pDoc->InputImg[y + j][x + i];
					}
				}
				pDoc->ResultImg[y][x] = min;
			}
			else
			{
				rmin = 255;
				gmin = 255;
				bmin = 255;
				for (int j = -1; j <= 1; j++) {
					for (int i = -1; i <= 1; i++)
					{
						if (pDoc->InputImg[y + j][3 * (x + i) + 0] < rmin)
							rmin = pDoc->InputImg[y + j][3 * (x + i) + 0];
						if (pDoc->InputImg[y + j][3 * (x + i) + 1] < gmin)
							gmin = pDoc->InputImg[y + j][3 * (x + i) + 1];
						if (pDoc->InputImg[y + j][3 * (x + i) + 2] < bmin)
							bmin = pDoc->InputImg[y + j][3 * (x + i) + 2];
						
					}
				}
				pDoc->ResultImg[y][3 * x + 0] = rmin;
				pDoc->ResultImg[y][3 * x + 1] = gmin;
				pDoc->ResultImg[y][3 * x + 2] = bmin;
			}
		}
	}
	Invalidate();
}

void CProject20171169View::OnMoplogyDilation()
{
	CProject20171169Doc* pDoc = GetDocument();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int max, rmax, gmax, bmax;

	for (int y = 1; y < pDoc->ImageHeight - 1; y++) {
		for (int x = 1; x < pDoc->ImageWidth - 1; x++) {
			if (pDoc->depth == 1)
			{
				max = 0;
				for (int j = -1; j <= 1; j++) {
					for (int i = -1; i <= 1; i++)
					{
						if (pDoc->InputImg[y + j][x + i] > max) max = pDoc->InputImg[y + j][x + i];
					}
				}
				pDoc->ResultImg[y][x] = max;
			}
			else
			{
				rmax = 0;
				gmax = 0;
				bmax = 0;
				for (int j = -1; j <= 1; j++) {
					for (int i = -1; i <= 1; i++)
					{
						if (pDoc->InputImg[y + j][3 * (x + i) + 0] > rmax)
							rmax = pDoc->InputImg[y + j][3 * (x + i) + 0];
						if (pDoc->InputImg[y + j][3 * (x + i) + 1] > gmax)
							gmax = pDoc->InputImg[y + j][3 * (x + i) + 1];
						if (pDoc->InputImg[y + j][3 * (x + i) + 2] > bmax)
							bmax = pDoc->InputImg[y + j][3 * (x + i) + 2];

					}
				}
				pDoc->ResultImg[y][3 * x + 0] = rmax;
				pDoc->ResultImg[y][3 * x + 1] = gmax;
				pDoc->ResultImg[y][3 * x + 2] = bmax;
			}
		}
	}
	Invalidate();
}


void CProject20171169View::OnMoplogyOpening()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnMoplogyErosion();
	CopyResultToInput();
	OnMoplogyErosion();
	CopyResultToInput();
	OnMoplogyErosion();

	CopyResultToInput();
	OnMoplogyDilation();
	CopyResultToInput();
	OnMoplogyDilation();
	CopyResultToInput();
	OnMoplogyDilation();
}

void CProject20171169View::CopyResultToInput()
{
	CProject20171169Doc* pDoc = GetDocument();
	// TODO: 여기에 구현 코드 추가.
	for (int y = 0; y < pDoc->ImageHeight; y++) {
		for (int x = 0; x < pDoc->ImageWidth*pDoc->depth; x++) {
			pDoc->InputImg[y][x] = pDoc->ResultImg[y][x];
		}
	}
}


void CProject20171169View::OnMoplogyClosing()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnMoplogyDilation();
	CopyResultToInput();
	OnMoplogyDilation();
	CopyResultToInput();
	OnMoplogyDilation();

	CopyResultToInput();
	OnMoplogyErosion();
	CopyResultToInput();
	OnMoplogyErosion();
	CopyResultToInput();
	OnMoplogyErosion();
}


void CProject20171169View::OnGeometryZoominPixelcopy()
{
	CProject20171169Doc* pDoc = GetDocument();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	int xscale = 3;
	int yscale = 2;

	if (pDoc->gResultImg != NULL) {
		for (int i = 0; i < pDoc->gImageHeight; i++) {
			free(pDoc->gResultImg[i]);
		}
		free(pDoc->gResultImg);
	}

	pDoc->gImageWidth = pDoc->ImageWidth * xscale;
	pDoc->gImageHeight = pDoc->ImageHeight * yscale;

	//메모리 할당
	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
	for (int i = 0; i < pDoc->gImageHeight; i++)
	{
		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);
	}
	
	for (int y = 0; y < pDoc->gImageHeight; y++) {
		for (int x = 0; x < pDoc->gImageWidth; x++) {
			if(pDoc->depth ==1)
				pDoc->gResultImg[y][x] = pDoc->InputImg[y/yscale][x/xscale];
			else {
				pDoc->gResultImg[y][3 * x + 0] = pDoc->InputImg[y / yscale][3 * (x / xscale) + 0];
				pDoc->gResultImg[y][3 * x + 1] = pDoc->InputImg[y / yscale][3 * (x / xscale) + 1];
				pDoc->gResultImg[y][3 * x + 2] = pDoc->InputImg[y / yscale][3 * (x / xscale) + 2];
			}
		}
	}

	/*
	//전방향사상
	for (int y = 0; y < pDoc->ImageHeight; y++) {
		for (int x = 0; x < pDoc->ImageWidth; x++) {
			pDoc->gResultImg[y * yscale][x * xscale]=pDoc->InputImg[y][x];
		}
	}
	*/
	Invalidate();
}


void CProject20171169View::OnGeometryZoominBilinarinterpolation()
{
	CProject20171169Doc* pDoc = GetDocument();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	float xscale = 2.3;
	float yscale = 1.5;

	float src_x, src_y;
	float alpha, beta;
	int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
	int E,F;

	if (pDoc->gResultImg != NULL) {
		for (int i = 0; i < pDoc->gImageHeight; i++) {
			free(pDoc->gResultImg[i]);
		}
		free(pDoc->gResultImg);
	}

	pDoc->gImageWidth = pDoc->ImageWidth * xscale + 0.5;//실수보다 큰정수로 변환?
	pDoc->gImageHeight = pDoc->ImageHeight * yscale + 0.5;

	//메모리 할당
	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
	for (int i = 0; i < pDoc->gImageHeight; i++)
	{
		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);
	}

	//역방향사상
	for (int y = 0; y < pDoc->gImageHeight; y++) {
		for (int x = 0; x < pDoc->gImageWidth; x++) {
			src_x = x / xscale;
			src_y = y / yscale;

			alpha = src_x - (int)src_x;
			beta = src_y - (int)src_y;

			Ax = (int)src_x;
			Ay = (int)src_y;
			Bx = Ax + 1;
			By = Ay;
			Cx = Ax;
			Cy = Ay + 1;
			Dx = Ax + 1;
			Dy = Ay + 1;

			if (Bx > pDoc->ImageWidth - 1) Bx = pDoc->ImageWidth - 1;
			if (Cy > pDoc->ImageHeight - 1) Cy = pDoc->ImageHeight - 1;
			if (Dx > pDoc->ImageWidth - 1) Dx = pDoc->ImageWidth - 1;
			if (Dy > pDoc->ImageHeight - 1) Dy = pDoc->ImageHeight - 1;

			if (pDoc->depth == 1) {
				E = (1 - alpha) * pDoc->InputImg[Ay][Ax] + alpha * pDoc->InputImg[By][Bx];
				F = (1 - alpha) * pDoc->InputImg[Cy][Cx] + alpha * pDoc->InputImg[Dy][Dx];

				pDoc->gResultImg[y][x] = (1 - beta) * E + beta * F;
			}
			else {
				E = (1 - alpha) * pDoc->InputImg[Ay][3*Ax+0] + alpha * pDoc->InputImg[By][3*Bx+0];
				F = (1 - alpha) * pDoc->InputImg[Cy][3*Cx+0] + alpha * pDoc->InputImg[Dy][3*Dx+0];

				pDoc->gResultImg[y][3*x+0] = (1 - beta) * E + beta * F;

				E = (1 - alpha) * pDoc->InputImg[Ay][3 * Ax + 1] + alpha * pDoc->InputImg[By][3 * Bx + 1];
				F = (1 - alpha) * pDoc->InputImg[Cy][3 * Cx + 1] + alpha * pDoc->InputImg[Dy][3 * Dx + 1];

				pDoc->gResultImg[y][3 * x + 1] = (1 - beta) * E + beta * F;

				E = (1 - alpha) * pDoc->InputImg[Ay][3 * Ax + 2] + alpha * pDoc->InputImg[By][3 * Bx + 2];
				F = (1 - alpha) * pDoc->InputImg[Cy][3 * Cx + 2] + alpha * pDoc->InputImg[Dy][3 * Dx + 2];

				pDoc->gResultImg[y][3 * x + 2] = (1 - beta) * E + beta * F;
			}
		}
	}

	Invalidate(); 
}


void CProject20171169View::OnGeometryZoomoutSubsampling()
{
	CProject20171169Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	int x, y, i;
	int xscale = 3;
	int yscale = 2;


	//기존메모리 삭제
	if (pDoc->gResultImg != NULL) {
		for (i = 0; i < pDoc->gImageHeight; i++) free(pDoc->gResultImg[i]);
		free(pDoc->gResultImg);
		pDoc->gResultImg = NULL;
	}

	pDoc->gImageWidth = pDoc->ImageWidth / xscale;
	pDoc->gImageHeight = pDoc->ImageHeight / yscale;


	// 메모리할당	
	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
	for (i = 0; i < pDoc->gImageHeight; i++) {
		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);
	}


	//역방향사상
	for (y = 0; y < pDoc->gImageHeight; y++)
		for (x = 0; x < pDoc->gImageWidth; x++) {
			if (pDoc->depth == 1)
				pDoc->gResultImg[y][x] = pDoc->InputImg[y * yscale][x * xscale];
			else {
				pDoc->gResultImg[y][3 * x + 0] = pDoc->InputImg[y * yscale][3 * (x * xscale) + 0];
				pDoc->gResultImg[y][3 * x + 1] = pDoc->InputImg[y * yscale][3 * (x * xscale) + 1];
				pDoc->gResultImg[y][3 * x + 2] = pDoc->InputImg[y * yscale][3 * (x * xscale) + 2];
			}
		}
	Invalidate();

}


void CProject20171169View::OnGeometryZoomoutMeansub()
{
	OnRegionSmoothing();
	CopyResultToInput();
	OnGeometryZoomoutSubsampling();
}


void CProject20171169View::OnGeometryZoominAvg()
{
	CProject20171169Doc* pDoc = GetDocument();
	int xscale = 3;		// 1/3
	int yscale = 2;		// 1/2
	int x, y, i, j;
	int sum, rsum, gsum, bsum;
	int src_x, src_y;

	if (pDoc->gResultImg != NULL)
	{
		for (int i = 0; i < pDoc->gImageHeight; i++)
			free(pDoc->gResultImg[i]);
		free(pDoc->gResultImg);
	}

	pDoc->gImageWidth = pDoc->ImageWidth / xscale;
	pDoc->gImageHeight = pDoc->ImageHeight / yscale;
	// 메모리할당
	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
	for (int i = 0; i < pDoc->gImageHeight; i++)
	{
		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);
	}

	//전방향사상
	for (y = 0; y < pDoc->ImageHeight; y += yscale)
		for (x = 0; x < pDoc->ImageWidth; x += xscale)
		{
			if (pDoc->depth == 1)
			{
				sum = 0;
				for (j = 0; j < yscale; j++)
					for (i = 0; i < xscale; i++)
					{
						src_x = x + i;
						src_y = y + j;

						sum += pDoc->InputImg[src_y][src_x];
					}
				pDoc->gResultImg[y / yscale][x / xscale] = sum / (yscale * xscale);
			}
			else
			{
				rsum = 0;	gsum = 0;	bsum = 0;
				for (j = 0; j < yscale; j++)
					for (i = 0; i < xscale; i++)
					{
						src_x = x + i;
						src_y = y + j;

						rsum += pDoc->InputImg[src_y][3 * src_x + 0];
						gsum += pDoc->InputImg[src_y][3 * src_x + 1];
						bsum += pDoc->InputImg[src_y][3 * src_x + 2];
					}
				pDoc->gResultImg[y / yscale][3 * (x / xscale) + 0] = rsum / (yscale * xscale);
				pDoc->gResultImg[y / yscale][3 * (x / xscale) + 1] = gsum / (yscale * xscale);
				pDoc->gResultImg[y / yscale][3 * (x / xscale) + 2] = bsum / (yscale * xscale);
			}
		}
	Invalidate();
}

#include <math.h>
#define PI 3.1416926521
void CProject20171169View::OnGeometryRotate()
{
	CProject20171169Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	int i, x, y;
	int angle = -120;	// degree 시계방향 -120 도   // 만일 반시계방향시 120 도
	float radian;
	int Cx, Cy, Oy;
	int x_source, y_source;
	int xdiff, ydiff;

	if (pDoc->gResultImg != NULL) {
		for (i = 0; i < pDoc->gImageHeight; i++) free(pDoc->gResultImg[i]);
		free(pDoc->gResultImg);
	}

	radian = 2 * PI / 360 * angle;
	pDoc->gImageWidth = pDoc->ImageHeight * fabs(cos(PI / 2 - radian)) + pDoc->ImageWidth * fabs(cos(radian));
	pDoc->gImageHeight = pDoc->ImageHeight * fabs(cos(radian)) + pDoc->ImageWidth * fabs(cos(PI / 2 - radian));

	// 메모리 할당
	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
	for (i = 0; i < pDoc->gImageHeight; i++) {
		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);
	}

	// 중심점
	Cx = pDoc->ImageWidth / 2;	Cy = pDoc->ImageHeight / 2;
	//y의 마지막
	Oy = pDoc->ImageHeight - 1;
	xdiff = (pDoc->gImageWidth - pDoc->ImageWidth) / 2;
	ydiff = (pDoc->gImageHeight - pDoc->ImageHeight) / 2;

	for (y = -ydiff; y < pDoc->gImageHeight - ydiff; y++)
		for (x = -xdiff; x < pDoc->gImageWidth - xdiff; x++) {
			x_source = ((Oy - y) - Cy) * sin(radian) - (x - Cx) * cos(radian) + Cx;		//시계 방향
			y_source = Oy - (((Oy - y) - Cy) * cos(radian) + (x - Cx) * sin(radian) + Cy);

			/*
			x_source = ((Oy - y) - Cy)*sin(radian) + (x - Cx)*cos(radian) + Cx;		//반시계 방향
			y_source = Oy - (((Oy - y) - Cy)*cos(radian) - (x - Cx)*sin(radian) + Cy);
			*/
			if (pDoc->depth == 1) {
				if (x_source<0 || x_source>pDoc->ImageWidth - 1 ||
					y_source<0 || y_source>pDoc->ImageHeight - 1)
					pDoc->gResultImg[y + ydiff][x + xdiff] = 255;
				else
					pDoc->gResultImg[y + ydiff][x + xdiff] = pDoc->InputImg[y_source][x_source];
			}
			else {
				if (x_source<0 || x_source>pDoc->ImageWidth - 1 || y_source<0 || y_source>pDoc->ImageHeight - 1) {
					pDoc->gResultImg[y + ydiff][3 * (x + xdiff) + 0] = 255;
					pDoc->gResultImg[y + ydiff][3 * (x + xdiff) + 1] = 255;
					pDoc->gResultImg[y + ydiff][3 * (x + xdiff) + 2] = 255;
				}
				else {
					pDoc->gResultImg[y + ydiff][3 * (x + xdiff) + 0] = pDoc->InputImg[y_source][3 * (x_source)+0];
					pDoc->gResultImg[y + ydiff][3 * (x + xdiff) + 1] = pDoc->InputImg[y_source][3 * (x_source)+1];
					pDoc->gResultImg[y + ydiff][3 * (x + xdiff) + 2] = pDoc->InputImg[y_source][3 * (x_source)+2];
				}
			}
		}
	Invalidate();
}


void CProject20171169View::OnGeometryHorizontalFlip()
{
	CProject20171169Doc* pDoc = GetDocument();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	for (int y = 0; y < pDoc->ImageHeight; y++) {
		for (int x = 0; x < pDoc->ImageWidth; x++) {
			if (pDoc->depth == 1) {
				pDoc->ResultImg[y][x] = pDoc->InputImg[y][pDoc->ImageWidth - 1 - x];
			}
			else {
				pDoc->ResultImg[y][3 * x + 0] = pDoc->InputImg[y][3 * (pDoc->ImageWidth - 1 - x) + 0];
				pDoc->ResultImg[y][3 * x + 1] = pDoc->InputImg[y][3 * (pDoc->ImageWidth - 1 - x) + 1];
				pDoc->ResultImg[y][3 * x + 2] = pDoc->InputImg[y][3 * (pDoc->ImageWidth - 1 - x) + 2];
			}
		}
	}
	Invalidate();
}


void CProject20171169View::OnGeometryVerticalFlip()
{
	CProject20171169Doc* pDoc = GetDocument();
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	for (int y = 0; y < pDoc->ImageHeight; y++) {
		for (int x = 0; x < pDoc->ImageWidth; x++) {
			if (pDoc->depth == 1) {
				pDoc->ResultImg[y][x] = pDoc->InputImg[pDoc->ImageHeight - 1 - y][x];
			}
			else {
				pDoc->ResultImg[y][3 * x + 0] = pDoc->InputImg[pDoc->ImageHeight - 1 - y][3 * x + 0];
				pDoc->ResultImg[y][3 * x + 1] = pDoc->InputImg[pDoc->ImageHeight - 1 - y][3 * x + 1];
				pDoc->ResultImg[y][3 * x + 2] = pDoc->InputImg[pDoc->ImageHeight - 1 - y][3 * x + 2];
			}
		}
	}
	Invalidate();
}

