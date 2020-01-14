//------10--------20--------30--------40--------50--------60--------70--------//
//-------|---------|---------|---------|---------|---------|---------|--------//
//----------------------------------------------------------------------------//
// x23RFPCDlg.h : ヘッダー ファイル
#pragma once
//----------------------------------data--------------------------------------//
#include "MyData.h"
//----------------------------------------------------------------------------//

using namespace std;

// Cx23RFPCDlg ダイアログ
class Cx23RFPCDlg : public CDialogEx
{
	// コンストラクション
public:
	Cx23RFPCDlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_X23RFPC_DIALOG };
	//#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CEdit msgED;
	CButton graphPICT;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();

	LRESULT OnMessageRCV(WPARAM wParam, LPARAM lParam);
	afx_msg void OnBnClickedButton4();
	afx_msg void OnDestroy();

	//----------------------------------Data----------------------------------//
public:
	bool dataFlag = false;
	void dataCallback();
	void updateData();
private:
	Data data_container;
	//------------------------------------------------------------------------//
	//---------------------------------OpenGL---------------------------------//
public:
	bool glFlag = false;						// OpenGL Thread Flag
	void glCallback();					// OpenGL Callback Function
	BOOL SetUpPixelFormat(HDC hdc);		// Setup Pixel Format in Picture Control
	void glSetup(); 					// Setup OpenGL & OpenGL Context
private:
	CStatic m_glView;
	CDC* m_pDC;							// Picture Control's Device Context
	HGLRC m_GLRC;						// OpenGL's Device Context
	//------------------------------------------------------------------------//
	//--------------------------------Graph-----------------------------------//
public:
	bool graphFlag = false;
	void graphCallback();
	void drawGraph();
	//------------------------------------------------------------------------//
	//-------------------------------Text-------------------------------------//
public:
	bool textFlag = false;
	void textCallback();
	void drawText();
	void setTextStyle();
private:
	CFont* m_newFont;
	int fontTime;
	CEdit msgED2;
	CEdit msgED3;	
	CEdit msgED4;
	CEdit msgED5;
	CEdit msgED6;
	//------------------------------------------------------------------------//
};
