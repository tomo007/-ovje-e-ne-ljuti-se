
// �ovje�eNeLjutiSeDoc.cpp : implementation of the C�ovje�eNeLjutiSeDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "�ovje�eNeLjutiSe.h"
#endif

#include "�ovje�eNeLjutiSeDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C�ovje�eNeLjutiSeDoc

IMPLEMENT_DYNCREATE(C�ovje�eNeLjutiSeDoc, CDocument)

BEGIN_MESSAGE_MAP(C�ovje�eNeLjutiSeDoc, CDocument)
END_MESSAGE_MAP()


// C�ovje�eNeLjutiSeDoc construction/destruction

C�ovje�eNeLjutiSeDoc::C�ovje�eNeLjutiSeDoc()
{
	// TODO: add one-time construction code here

}

C�ovje�eNeLjutiSeDoc::~C�ovje�eNeLjutiSeDoc()
{
}

BOOL C�ovje�eNeLjutiSeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// C�ovje�eNeLjutiSeDoc serialization

void C�ovje�eNeLjutiSeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void C�ovje�eNeLjutiSeDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
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

// Support for Search Handlers
void C�ovje�eNeLjutiSeDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void C�ovje�eNeLjutiSeDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// C�ovje�eNeLjutiSeDoc diagnostics

#ifdef _DEBUG
void C�ovje�eNeLjutiSeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void C�ovje�eNeLjutiSeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C�ovje�eNeLjutiSeDoc commands
