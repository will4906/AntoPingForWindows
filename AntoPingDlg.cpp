// AntoPingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AntoPing.h"
#include "AntoPingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAntoPingDlg dialog

CAntoPingDlg::CAntoPingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAntoPingDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAntoPingDlg)
	m_nEnd1 = 0;
	m_nEnd2 = 0;
	m_nEnd3 = 0;
	m_nEnd4 = 0;
	m_nStart1 = 0;
	m_nStart2 = 0;
	m_nStart3 = 0;
	m_nStart4 = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAntoPingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAntoPingDlg)
	DDX_Control(pDX, IDC_CHECK_RANGE, m_checkRange);
	DDX_Text(pDX, IDC_EDIT_END_IP1, m_nEnd1);
	DDV_MinMaxUInt(pDX, m_nEnd1, 0, 255);
	DDX_Text(pDX, IDC_EDIT_END_IP2, m_nEnd2);
	DDV_MinMaxUInt(pDX, m_nEnd2, 0, 255);
	DDX_Text(pDX, IDC_EDIT_END_IP3, m_nEnd3);
	DDV_MinMaxUInt(pDX, m_nEnd3, 0, 255);
	DDX_Text(pDX, IDC_EDIT_END_IP4, m_nEnd4);
	DDV_MinMaxUInt(pDX, m_nEnd4, 0, 255);
	DDX_Text(pDX, IDC_EDIT_START_IP1, m_nStart1);
	DDV_MinMaxUInt(pDX, m_nStart1, 0, 255);
	DDX_Text(pDX, IDC_EDIT_START_IP2, m_nStart2);
	DDV_MinMaxUInt(pDX, m_nStart2, 0, 255);
	DDX_Text(pDX, IDC_EDIT_START_IP3, m_nStart3);
	DDV_MinMaxUInt(pDX, m_nStart3, 0, 255);
	DDX_Text(pDX, IDC_EDIT_START_IP4, m_nStart4);
	DDV_MinMaxUInt(pDX, m_nStart4, 0, 255);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAntoPingDlg, CDialog)
	//{{AFX_MSG_MAP(CAntoPingDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_START, OnButtonStart)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_CHECK_RANGE, OnCheckRange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAntoPingDlg message handlers

BOOL CAntoPingDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	GetDlgItem(IDC_EDIT_START_IP1)->SetWindowText("192");
	GetDlgItem(IDC_EDIT_START_IP2)->SetWindowText("168");
	GetDlgItem(IDC_EDIT_END_IP1)->SetWindowText("192");
	GetDlgItem(IDC_EDIT_END_IP2)->SetWindowText("168");
	GetDlgItem(IDC_EDIT_END_IP1)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_END_IP2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_END_IP3)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_END_IP4)->EnableWindow(FALSE);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAntoPingDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAntoPingDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAntoPingDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAntoPingDlg::OnButtonStart() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	
	if (ChoosePlaceToSave("log.txt") == IDOK)
	{
		if (WriteToBatFile())
		{
			CString strFile = _T("autoping.bat");
			ShellExecute(NULL, _T("open"), strFile, _T(""), NULL, SW_SHOWMINIMIZED);
			AfxMessageBox("启动成功，文件将输出到\"log.txt\"");
		}
		else
		{
			AfxMessageBox("启动失败");
		}
	}
	
	
}

BOOL CAntoPingDlg::WriteToBatFile()
{
	CStdioFile stFile;
	if (stFile.Open("autoping.bat", CFile::modeCreate|CFile::modeReadWrite))
	{
		unsigned int startIp = 0,endIp = 0;
		startIp |= m_nStart1 << 24;
		startIp |= m_nStart2 << 16;
		startIp |= m_nStart3 << 8;
		startIp |= m_nStart4;

		if (m_checkRange.GetCheck() == 1)
		{
			endIp |= m_nEnd1 << 24;
			endIp |= m_nEnd2 << 16;
			endIp |= m_nEnd3 << 8;
			endIp |= m_nEnd4;
		}
		else
		{
			endIp = startIp;
		}
		
		stFile.WriteString("@echo 请不要关闭cmd，否则ping将终止\n");
		stFile.WriteString("@echo off\n");
		unsigned int i = 0;
		for (i = startIp; i < endIp + 1; i++)
		{
			CString strIp1,strIp2,strIp3,strIp4,strIp;
			strIp1.Format("%03d", (i & 0xff000000) >> 24);
			strIp2.Format("%03d", (i & 0x00ff0000) >> 16);
			strIp3.Format("%03d", (i & 0x0000ff00) >> 8);
			strIp4.Format("%03d", i & 0x000000ff);
			if (i == startIp)
			{
				strIp = "ping " + strIp1 + "." + strIp2 + "." + strIp3 + "." + strIp4 + " > " + customFilePath;
			}
			else
			{
				strIp = "ping " + strIp1 + "." + strIp2 + "." + strIp3 + "." + strIp4 + " >> " + customFilePath;
			}
			stFile.WriteString(strIp + "\n");
		}
		stFile.Close();
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int CAntoPingDlg::ChoosePlaceToSave(CString strFile)
{
	const char pszFilter[] = _T("Text File (*.txt)|*.txt||");
	CFileDialog dlgSave(FALSE, //FALSE为保存
		_T(".txt"), //自动加上的扩展名
		_T(strFile), //默认保存的文件名
		OFN_NOCHANGEDIR,
		pszFilter, this);
	BOOL flag = dlgSave.DoModal();
	if (flag == TRUE)
	{
		customFilePath = dlgSave.GetPathName();
	}

	return flag;
}

void CAntoPingDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
}

void CAntoPingDlg::OnCheckRange() 
{
	// TODO: Add your control notification handler code here
	if (m_checkRange.GetCheck())
	{
		m_checkRange.SetWindowText("多个");
		GetDlgItem(IDC_EDIT_END_IP1)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_END_IP2)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_END_IP3)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_END_IP4)->EnableWindow(TRUE);
	}
	else
	{
		m_checkRange.SetWindowText("单个");
		GetDlgItem(IDC_EDIT_END_IP1)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_END_IP2)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_END_IP3)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_END_IP4)->EnableWindow(FALSE);
	}
}
