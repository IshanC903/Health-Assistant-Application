// Health Assistant ApplicationDlg.h : header file
//

#pragma once


// CHealthAssistantApplicationDlg dialog
class CHealthAssistantApplicationDlg : public CDialogEx
{
// Construction
public:
	CHealthAssistantApplicationDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HEALTHASSISTANTAPPLICATION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedButton1();
	CEdit bx_FinalOutput;
	CEdit bx_Height;
	CEdit bx_Weight;
	CDateTimeCtrl bx_FullDate;
	int storedGender;
	CComboBox bx_WaterCon;
	CComboBox bx_calIn;
	bool print;
	afx_msg void OnBnClickedCheck1();
};
