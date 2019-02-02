#pragma once


// CTAB1 dialog

class CTAB1 : public CDialogEx
{
	DECLARE_DYNAMIC(CTAB1)

public:
	CTAB1(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CTAB1();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
