
// CTabControlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CTabControl.h"
#include "CTabControlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCTabControlDlg dialog



CCTabControlDlg::CCTabControlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CTABCONTROL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCTabControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TABCONTROL, m_tabcontrol);
}

BEGIN_MESSAGE_MAP(CCTabControlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, AFX_ID_PREVIEW_PREV, &CCTabControlDlg::OnTcnSelchangeIdPreviewPrev)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TABCONTROL, &CCTabControlDlg::OnSelchangeTabcontrol)
END_MESSAGE_MAP()


// CCTabControlDlg message handlers

BOOL CCTabControlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

	CTabCtrl* pTabCtrl = (CTabCtrl*)GetDlgItem(IDC_TABCONTROL);
	m_tab1.Create(IDD_TAB1, pTabCtrl);

	CTabCtrl* pTabCtrl2 = (CTabCtrl*)GetDlgItem(IDC_TABCONTROL);
	m_tab2.Create(IDD_TAB2, pTabCtrl2);



	TCITEM item1,item2;
	item1.mask = TCIF_TEXT | TCIF_PARAM;
	item1.lParam = (LPARAM)& m_tab1;
	item1.pszText = _T("Section 1");
	pTabCtrl->InsertItem(0, &item1);

	

	item2.mask = TCIF_TEXT | TCIF_PARAM;
	item2.lParam = (LPARAM)& m_tab2;
	item2.pszText = _T("Section 2");
	pTabCtrl2->InsertItem(1, &item2);


	CRect rcItem;
	pTabCtrl->GetItemRect(0, &rcItem);
	m_tab1.SetWindowPos(NULL, rcItem.left, rcItem.bottom + 1, 0, 0, SWP_NOSIZE | SWP_NOZORDER);


	CRect rcItem2;
	pTabCtrl2->GetItemRect(0, &rcItem2);
	m_tab2.SetWindowPos(NULL, rcItem2.left, rcItem2.bottom + 1, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	m_tab1.ShowWindow(SW_SHOW);
	m_tab2.ShowWindow(SW_HIDE);

	

	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCTabControlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCTabControlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCTabControlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCTabControlDlg::OnTcnSelchangeIdPreviewPrev(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CCTabControlDlg::OnSelchangeTabcontrol(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;

	int iSel = m_tabcontrol.GetCurSel();

	if (iSel == 0)
	{
		m_tab1.ShowWindow(SW_SHOW);
		m_tab2.ShowWindow(SW_HIDE);
	}
	else if (iSel == 1)
	{
		m_tab2.ShowWindow(SW_SHOW);
		m_tab1.ShowWindow(SW_HIDE);
	}
	else
	{
		m_tab1.ShowWindow(SW_SHOW);
		m_tab2.ShowWindow(SW_HIDE);
	}
}
