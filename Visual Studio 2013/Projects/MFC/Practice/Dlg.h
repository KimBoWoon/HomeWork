#pragma once
#include "afxwin.h"


// CDlg ��ȭ �����Դϴ�.

class CDlg : public CDialog
{
	DECLARE_DYNAMIC(CDlg)

public:
	CDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_Title;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
