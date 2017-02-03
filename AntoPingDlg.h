// AntoPingDlg.h : header file
//

#if !defined(AFX_ANTOPINGDLG_H__7E965A13_95C3_488B_BBDD_FDB8CC4A83E1__INCLUDED_)
#define AFX_ANTOPINGDLG_H__7E965A13_95C3_488B_BBDD_FDB8CC4A83E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAntoPingDlg dialog

class CAntoPingDlg : public CDialog
{
// Construction
public:
	CAntoPingDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAntoPingDlg)
	enum { IDD = IDD_ANTOPING_DIALOG };
	UINT	m_nEnd1;
	UINT	m_nEnd2;
	UINT	m_nEnd3;
	UINT	m_nEnd4;
	UINT	m_nStart1;
	UINT	m_nStart2;
	UINT	m_nStart3;
	UINT	m_nStart4;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAntoPingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	BOOL WriteToBatFile();
	// Generated message map functions
	//{{AFX_MSG(CAntoPingDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonStart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANTOPINGDLG_H__7E965A13_95C3_488B_BBDD_FDB8CC4A83E1__INCLUDED_)
