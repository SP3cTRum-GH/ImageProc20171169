﻿
// Project_20171169Doc.h: CProject20171169Doc 클래스의 인터페이스
//


#pragma once


class CProject20171169Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CProject20171169Doc() noexcept;
	DECLARE_DYNCREATE(CProject20171169Doc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CProject20171169Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS

public:
	unsigned char** InputImg;
	unsigned char** InputImg2;
	unsigned char** ResultImg;
	int ImageWidth;
	int ImageHeight;
	int depth; //흑백값

	int gImageWidth;
	int gImageHeight;

	unsigned char** gResultImg;

//	unsigned char InputImg[256][256];
//	unsigned char InputImg2[256][256];
//	unsigned char ResultImg[256][256];
	void LoadImgFile(CArchive& ar);
	void LoadSecondImageFile(CArchive& ar);
};
