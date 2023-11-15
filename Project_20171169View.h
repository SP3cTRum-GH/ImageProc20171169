
// Project_20171169View.h: CProject20171169View 클래스의 인터페이스
//

#pragma once


class CProject20171169View : public CScrollView
{
protected: // serialization에서만 만들어집니다.
	CProject20171169View() noexcept;
	DECLARE_DYNCREATE(CProject20171169View)

// 특성입니다.
public:
	CProject20171169Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CProject20171169View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onadd();
	afx_msg void Onsub();
	afx_msg void Onmul();
	afx_msg void Ondiv();
	afx_msg void OnHistogram();
	afx_msg void OnContraststr();
	afx_msg void OnBinarzation();
	afx_msg void Ontwoimgadd();
	afx_msg void Ontwoimgsub();
	afx_msg void OnRegionSmoothing();
	void Convolve(unsigned char** InImg, unsigned char** OutImg, int cols, int rows, float mask[][3], int bias, int depth);
	afx_msg void OnRegionSharpening();
	afx_msg void OnRegionEmbossing();
	afx_msg void OnRegionPrewitt();
	afx_msg void OnRegionRovert();
	afx_msg void OnRegionSobel();
	afx_msg void OnRegionAveragefiltering();
	afx_msg void OnRegionMedianfiltering();
	afx_msg void OnMopologyColorGray();
	afx_msg void OnMopologyBinarzation();
	afx_msg void OnMoplogyErosion();
	afx_msg void OnMoplogyOpening();
	afx_msg void OnMoplogyDilation();
	void CopyResultToInput();
	afx_msg void OnMoplogyClosing();
	afx_msg void OnGeometryZoominPixelcopy();
	afx_msg void OnGeometryZoominBilinarinterpolation();
	afx_msg void OnGeometryZoomoutSubsampling();
	afx_msg void OnGeometryZoominAvg();
	afx_msg void OnGeometryRotate();
	afx_msg void OnGeometryHorizontalFlip();
	afx_msg void OnGeometryVerticalFlip();
	afx_msg void OnGeometryZoomoutMeansub();
};

#ifndef _DEBUG  // Project_20171169View.cpp의 디버그 버전
inline CProject20171169Doc* CProject20171169View::GetDocument() const
   { return reinterpret_cast<CProject20171169Doc*>(m_pDocument); }
#endif

