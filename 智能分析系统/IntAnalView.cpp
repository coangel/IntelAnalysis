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
#include "IntAnalApp.h"
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
	CString strPathName;
	//����һ�����ļ��Ի��򣬲������������ļ�·��
	const TCHAR BASED_CODE szFilter[] = _T("256ɫλͼ�ļ�(*.bmp)|");
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter,NULL);
    if(dlg.DoModal() == IDOK)
	{
	   strPathName = dlg.GetPathName();
	}
	else 
	{
		return;
	}

	//����һ���ļ�����
   	CFile file;

	//��ֻ��ģʽ���ļ�
	file.Open (strPathName,CFile::modeRead);

	/*
	//��ȡ�ļ���HDIB�����. ע��:��ʱֻ�Ƕ�ȡλͼ�ļ����ļ�ͷ֮��Ĳ���,�����ļ�ͷ
	m_hDIB = ::ReadDIBFile (file);

	//HDIB���: ����һ��洢λͼ���ݵ��ڴ�����ĵ�ַ
	//HDIB�������:λͼ��Ϣͷ����ɫ��(����еĻ�)��DIBͼ������
	//�ر��ļ�
	file.Close ();
	//ָ��DIB��ָ��(ָ��λͼ��Ϣͷ)
	BYTE* lpDIB=(BYTE*)::GlobalLock ((HGLOBAL)m_hDIB);
	// ��ȡDIB����ɫ���е���ɫ��Ŀ
	WORD wNumColors;	
	wNumColors = ::DIBNumColors((char*)lpDIB);

	// �ж��Ƿ���256ɫλͼ
	if (wNumColors != 256)
	{
		// ��ʾ�û�
		MessageBox("��256ɫλͼ��", "ϵͳ��ʾ" , MB_ICONINFORMATION | MB_OK);

		// �������
		::GlobalUnlock((HGLOBAL)m_hDIB);

		// ����
		return;
	}

	//����Ļ����ʾλͼ
	CDC* pDC=GetDC();
	DisplayDIB(pDC,m_hDIB);

	//����λͼ�ļ��Ƿ��Ѽ��صı�־
	fileloaded=true;

	gyhfinished=false;
	*/
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
