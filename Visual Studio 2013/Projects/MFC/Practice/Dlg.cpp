// Dlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Practice.h"
#include "Dlg.h"
#include "afxdialogex.h"


// CDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlg, CDialog)

CDlg::CDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg::IDD, pParent)
{

}

CDlg::~CDlg()
{
}

void CDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SHOW, m_Title);
}


BEGIN_MESSAGE_MAP(CDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDlg �޽��� ó�����Դϴ�.


void CDlg::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_Title.ShowWindow(SW_HIDE);
}


void CDlg::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_Title.ShowWindow(SW_SHOW);
}
