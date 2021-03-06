// Health Assistant ApplicationDlg.cpp : implementation file

#include "stdafx.h"
#include "Health Assistant Application.h"
#include "Health Assistant ApplicationDlg.h"
#include "afxdialogex.h"
#include <fstream>

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
public:
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


// CHealthAssistantApplicationDlg dialog



CHealthAssistantApplicationDlg::CHealthAssistantApplicationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HEALTHASSISTANTAPPLICATION_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHealthAssistantApplicationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, bx_Height);
	DDX_Control(pDX, IDC_EDIT2, bx_Weight);
	DDX_Control(pDX, IDC_EDIT3, bx_FinalOutput);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, bx_FullDate);
	DDX_Control(pDX, IDC_COMBO1, bx_WaterCon);
	DDX_Control(pDX, IDC_COMBO2, bx_calIn);
}

BEGIN_MESSAGE_MAP(CHealthAssistantApplicationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CHealthAssistantApplicationDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO1, &CHealthAssistantApplicationDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CHealthAssistantApplicationDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_CHECK1, &CHealthAssistantApplicationDlg::OnBnClickedCheck1)
END_MESSAGE_MAP()


// CHealthAssistantApplicationDlg message handlers

BOOL CHealthAssistantApplicationDlg::OnInitDialog()
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CHealthAssistantApplicationDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CHealthAssistantApplicationDlg::OnPaint()
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
HCURSOR CHealthAssistantApplicationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CHealthAssistantApplicationDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	storedGender = 0;
}

void CHealthAssistantApplicationDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	storedGender = 1;
}

void CHealthAssistantApplicationDlg::OnBnClickedButton1()
{
	//---------------------BMI CALCULATION-----------------------
	CString txt_Height;
	bx_Height.GetWindowText(txt_Height);
	double numHeight = _wtof(txt_Height);
	numHeight /= 100;

	CString txt_Weight;
	bx_Weight.GetWindowText(txt_Weight);
	double numWeight = _wtof(txt_Weight);

	CString txt_BMI;
	double bmi = ((numWeight / numHeight) / numHeight);
	txt_BMI.Format(_T("%f"), bmi);

	//------------------------DOB--------------------------------
	CTime dt_DOB;
	CString txt_Age;

	bx_FullDate.GetTime(dt_DOB);
	int enteredYr = dt_DOB.GetYear();
	int age = 2018 - enteredYr;
	txt_Age.Format(_T("%d"), age);

	//-----------------------WATER & CALORIE---------------------
	int waterCon = bx_WaterCon.GetCurSel();
	int calorieIn = bx_calIn.GetCurSel();
	
	//--------------------OUTPUT---------------------------------
	CString Result = _T("");

	Result += "Age: ";
	Result += txt_Age;
	Result += " Years\r\n";

	Result += "Gender: ";
	if (storedGender == 0) { Result += "Male\r\n"; }
	else if (storedGender == 1) { Result += "Female\r\n"; }

	Result += "BMI: ";
	Result += txt_BMI;
	Result += "\r\n";

	Result += "Water Consumption: ";
	if (waterCon == 0) { Result += "< 1"; }
	else if (waterCon == 1) { Result += "1 - 2"; }
	else if (waterCon == 2) { Result += "2 - 3"; }
	else { Result += "3+"; }
	Result += " Liters / Day\r\n";

	Result += "Calorie Intake: ";
	if (calorieIn == 0) { Result += "< 1000"; }
	else if (calorieIn == 1) { Result += "1000 - 1500"; }
	else if (calorieIn == 2) { Result += "1600 - 2000"; }
	else if (calorieIn == 3) { Result += "2100 - 2400"; }
	else { Result += "2500"; }
	Result += " / Day\r\n\r\n";

	Result += "Your evaluation, based on the provided information, states that you are ";
	
	if (bmi < 18.5) { Result += "UnderWeight."; }
	else if (bmi >= 18.5 && bmi <= 24.9) { Result += "Normal Weight."; }
	else if (bmi >= 25 && bmi <= 29.9) { Result += " OverWeight."; }
	else { Result += "Obese. "; }

	Result += " Your calorie intake ";
	if (storedGender == 0)
	{
		if (age >= 2 && age <= 5)
		{
			//1000-1500
			if (calorieIn == 1) { Result += "meets the recommended daily requirement. "; }
			else if (calorieIn > 1) { Result += "is above the recommended daily requirement. "; }
			else if (calorieIn < 1) { Result += "is below the recommended daily requirement. "; }
		}
		else if (age >= 6 && age <= 11)
		{
			//1600-2000
			if (calorieIn == 2) { Result += "meets the recommended daily requirement. "; }
			else if (calorieIn > 2) { Result += "is above the recommended daily requirement. "; }
			else if (calorieIn < 2) { Result += "is below the recommended daily requirement. "; }
		}
		else if (age >= 12 && age <= 14)
		{
			//2100-2400
			if (calorieIn == 3) { Result += "meets the recommended daily requirement. "; }
			else if (calorieIn > 3) { Result += "is above the recommended daily requirement"; }
			else if (calorieIn < 3) { Result += "is below the recommended daily requirement"; }
		}
		else if (age >= 15 && age <= 45)
		{
			//2500+
			if (calorieIn == 4) { Result += "meets the recommended daily requirement. "; }
			else if (calorieIn > 4) { Result += "is above the recommended daily requirement. "; }
			else if (calorieIn < 4) { Result += "is below the recommended daily requirement. "; }
		}
		else if (age > 2)
		{
			if (calorieIn == 0) { Result += "meets the recommended daily requirement. "; }
			else { Result += "is above the recommended daily requirement. "; }
		}
		else
		{
			//2100-2400
			if (calorieIn == 3) { Result += "meets the recommended daily requirement. "; }
			else if (calorieIn > 3) { Result += "is above the recommended daily requirement. "; }
			else if (calorieIn < 3) { Result += "is below the recommended daily requirement. "; }
		}

		Result += "Your water consumption ";
		if (age >= 4 && age <= 8)
		{
			//1
			if (waterCon == 1) { Result += "meets the recommended daily requirement. "; }
			else if (waterCon > 1) { Result += "is above the recommended daily requirement. "; }
			else if (waterCon < 1) { Result += "is below the recommended daily requirement. "; }
		}
		else if (age >= 9 && age <= 13)
		{
			//2
			if (waterCon == 2) { Result += "meets the recommended daily requirement. "; }
			else if (waterCon > 2) { Result += "is above the recommended daily requirement. "; }
			else if (waterCon < 2) { Result += "is below the recommended daily requirement. "; }
		}
		else if (age >= 14 && age <= 18)
		{
			//2
			if (waterCon == 2) { Result += "meets the recommended daily requirement. "; }
			else if (waterCon > 2) { Result += "is above the recommended daily requirement. "; }
			else if (waterCon < 2) { Result += "is below the recommended daily requirement. "; }
		}
		else if (age >= 19)
		{
			//3
			if (waterCon == 3) { Result += "meets the recommended daily requirement. "; }
			else if (waterCon < 3) { Result += "is below the recommended daily requirement. "; }
		}
	}
	else if (storedGender == 1)
	{
		if (age >= 2 && age <= 6)
		{
			//1000-1500
			if (calorieIn == 1) { Result += "meets the recommended daily requirement. "; }
			else if (calorieIn > 1) { Result += "is above the recommended daily requirement. "; }
			else if (calorieIn < 1) { Result += "is below the recommended daily requirement. "; }
		}
		else if (age >= 7 && age <= 18)
		{
			//1600-2000
			if (calorieIn == 2) { Result += "meets the recommended daily requirement. "; }
			else if (calorieIn > 2) { Result += "is above the recommended daily requirement. "; }
			else if (calorieIn < 2) { Result += "is below the recommended daily requirement. "; }
		}
		else if (age >= 19 && age <= 25)
		{
			//2100-2400
			if (calorieIn == 3) { Result += "meets the recommended daily requirement. "; }
			else if (calorieIn > 3) { Result += "is above the recommended daily requirement. "; }
			else if (calorieIn < 3) { Result += "is below the recommended daily requirement. "; }
		}
		else if (age >= 26)
		{
			//1600-2000
			if (calorieIn == 2) { Result += "meets the recommended daily requirement. "; }
			else if (calorieIn > 2) { Result += "is above the recommended daily requirement. "; }
			else if (calorieIn < 2) { Result += "is below the recommended daily requirement. "; }
		}

		Result += "Your water consumption ";
		Result += "Your water consumption ";
		if (age >= 4 && age <= 8)
		{
			//1
			if (waterCon == 1) { Result += "meets the recommended daily requirement. "; }
			else if (waterCon > 1) { Result += "is above the recommended daily requirement. "; }
			else if (waterCon < 1) { Result += "is below the recommended daily requirement. "; }
		}
		else if (age >= 9 && age <= 13)
		{
			//2
			if (waterCon == 2) { Result += "meets the recommended daily requirement. "; }
			else if (waterCon > 2) { Result += "is above the recommended daily requirement. "; }
			else if (waterCon < 2) { Result += "is below the recommended daily requirement. "; }
		}
		else if (age >= 14 && age <= 18)
		{
			//2
			if (waterCon == 2) { Result += "meets the recommended daily requirement. "; }
			else if (waterCon > 2) { Result += "is above the recommended daily requirement. "; }
			else if (waterCon < 2) { Result += "is below the recommended daily requirement. "; }
		}
		else if (age >= 19)
		{
			//2
			if (waterCon == 2) { Result += "meets the recommended daily requirement. "; }
			else if (waterCon < 2) { Result += "is below the recommended daily requirement. "; }
			else if (waterCon > 2) { Result += "is above the recommended daily requirement."; }
		}
	}

	bx_FinalOutput.SetWindowTextW(Result);

	if (print)
	{
		std::wofstream file;
		file.open(_T("Health_Evaluation.txt"));
		file << (LPCTSTR)Result;
	}
}

void CHealthAssistantApplicationDlg::OnBnClickedCheck1()
{
	// TODO: Add your control notification handler code here
	print = true;
}
