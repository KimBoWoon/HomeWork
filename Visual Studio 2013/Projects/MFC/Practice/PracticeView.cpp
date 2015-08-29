
// PracticeView.cpp : CPracticeView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Practice.h"
#endif

#include "PracticeDoc.h"
#include "PracticeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPracticeView

IMPLEMENT_DYNCREATE(CPracticeView, CView)

BEGIN_MESSAGE_MAP(CPracticeView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPracticeView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_SHOW_DIALOG, &CPracticeView::OnShowDialog)
END_MESSAGE_MAP()

// CPracticeView ����/�Ҹ�

CPracticeView::CPracticeView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CPracticeView::~CPracticeView()
{
}

BOOL CPracticeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CPracticeView �׸���

void CPracticeView::OnDraw(CDC* /*pDC*/)
{
	CPracticeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CPracticeView �μ�


void CPracticeView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPracticeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CPracticeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CPracticeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CPracticeView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPracticeView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPracticeView ����

#ifdef _DEBUG
void CPracticeView::AssertValid() const
{
	CView::AssertValid();
}

void CPracticeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPracticeDoc* CPracticeView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPracticeDoc)));
	return (CPracticeDoc*)m_pDocument;
}
#endif //_DEBUG


// CPracticeView �޽��� ó����

#include "Dlg.h"
void CPracticeView::OnShowDialog()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CDlg dlg;
	dlg.DoModal();
}