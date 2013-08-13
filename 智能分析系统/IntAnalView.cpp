// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// (“Fluent UI”)。该示例仅供参考，
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问  
// http://msdn.microsoft.com/officeui。
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。

// IntAnalView.cpp : CIntAnalView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
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

// CIntAnalView 构造/析构

CIntAnalView::CIntAnalView()
{
	// TODO: 在此处添加构造代码

}

CIntAnalView::~CIntAnalView()
{
}

BOOL CIntAnalView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CIntAnalView 绘制

void CIntAnalView::OnDraw(CDC* /*pDC*/)
{
	CIntAnalDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CIntAnalView 打印


void CIntAnalView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CIntAnalView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CIntAnalView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CIntAnalView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CIntAnalView 诊断

#ifdef _DEBUG
void CIntAnalView::AssertValid() const
{
	CView::AssertValid();
}

void CIntAnalView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CIntAnalDoc* CIntAnalView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CIntAnalDoc)));
	return (CIntAnalDoc*)m_pDocument;
}
#endif //_DEBUG


// CIntAnalView 消息处理程序


void CIntAnalView::OnBtnOpen()
{
	CString strPathName;
	//创建一个打开文件对话框，并返回完整的文件路径
	const TCHAR BASED_CODE szFilter[] = _T("256色位图文件(*.bmp)|");
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter,NULL);
    if(dlg.DoModal() == IDOK)
	{
	   strPathName = dlg.GetPathName();
	}
	else 
	{
		return;
	}

	//创建一个文件对象
   	CFile file;

	//以只读模式打开文件
	file.Open (strPathName,CFile::modeRead);

	/*
	//读取文件到HDIB句柄中. 注意:此时只是读取位图文件中文件头之后的部分,不含文件头
	m_hDIB = ::ReadDIBFile (file);

	//HDIB句柄: 就是一块存储位图数据的内存区域的地址
	//HDIB句柄包含:位图信息头、调色板(如果有的话)、DIB图像数据
	//关闭文件
	file.Close ();
	//指向DIB的指针(指向位图信息头)
	BYTE* lpDIB=(BYTE*)::GlobalLock ((HGLOBAL)m_hDIB);
	// 获取DIB中颜色表中的颜色数目
	WORD wNumColors;	
	wNumColors = ::DIBNumColors((char*)lpDIB);

	// 判断是否是256色位图
	if (wNumColors != 256)
	{
		// 提示用户
		MessageBox("非256色位图！", "系统提示" , MB_ICONINFORMATION | MB_OK);

		// 解除锁定
		::GlobalUnlock((HGLOBAL)m_hDIB);

		// 返回
		return;
	}

	//在屏幕上显示位图
	CDC* pDC=GetDC();
	DisplayDIB(pDC,m_hDIB);

	//更改位图文件是否已加载的标志
	fileloaded=true;

	gyhfinished=false;
	*/
}


void CIntAnalView::OnBtnCheck()
{
	// TODO: 在此添加命令处理程序代码
}


void CIntAnalView::OnBtnDeal()
{
	// TODO: 在此添加命令处理程序代码
}


void CIntAnalView::OnBtnRecog()
{
	// TODO: 在此添加命令处理程序代码
}
