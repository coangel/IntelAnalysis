// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// (��Fluent UI��)����ʾ�������ο���
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ�������  
// http://msdn.microsoft.com/officeui��
//
// ��Ȩ����(C) Microsoft Corporation
// ��������Ȩ����

// IntAnalView.cpp : CIntAnalView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "���ܷ���ϵͳ.h"
#endif

#include "IntAnalDoc.h"
#include "IntAnalView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIntAnalView

IMPLEMENT_DYNCREATE(CIntAnalView, CView)

BEGIN_MESSAGE_MAP(CIntAnalView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CIntAnalView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_BTN_OPEN, &CIntAnalView::OnBtnOpen)
	ON_COMMAND(ID_BTN_CHECK, &CIntAnalView::OnBtnCheck)
	ON_COMMAND(ID_BTN_DEAL, &CIntAnalView::OnBtnDeal)
	ON_COMMAND(ID_BTN_RECOG, &CIntAnalView::OnBtnRecog)
END_MESSAGE_MAP()

// CIntAnalView ����/����

CIntAnalView::CIntAnalView()
{
	// TODO: �ڴ˴���ӹ������

}

CIntAnalView::~CIntAnalView()
{
}

BOOL CIntAnalView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CIntAnalView ����

void CIntAnalView::OnDraw(CDC* /*pDC*/)
{
	CIntAnalDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CIntAnalView ��ӡ


void CIntAnalView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CIntAnalView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CIntAnalView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CIntAnalView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CIntAnalView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CIntAnalView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CIntAnalView ���

#ifdef _DEBUG
void CIntAnalView::AssertValid() const
{
	CView::AssertValid();
}

void CIntAnalView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CIntAnalDoc* CIntAnalView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIntAnalDoc)));
	return (CIntAnalDoc*)m_pDocument;
}
#endif //_DEBUG


// CIntAnalView ��Ϣ�������


void CIntAnalView::OnBtnOpen()
{
	// TODO: �ڴ���������������
}


void CIntAnalView::OnBtnCheck()
{
	// TODO: �ڴ���������������
}


void CIntAnalView::OnBtnDeal()
{
	// TODO: �ڴ���������������
}


void CIntAnalView::OnBtnRecog()
{
	// TODO: �ڴ���������������
}
