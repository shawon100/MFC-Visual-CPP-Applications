// CTAB2.cpp : implementation file
//

#include "stdafx.h"
#include "CTabControl.h"
#include "CTAB2.h"
#include "afxdialogex.h"


// CTAB2 dialog

IMPLEMENT_DYNAMIC(CTAB2, CDialogEx)

CTAB2::CTAB2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB2, pParent)
{

}

CTAB2::~CTAB2()
{
}

void CTAB2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTAB2, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CTAB2::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CTAB2 message handlers


void CTAB2::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
