
// VsProjectCleanerDlg.h : 头文件
//

#pragma once
#include "MfcStrFile.h"
#include "Configure.h"
#include "Defines.h"
#include "GetDirFiles.h"
#include "tag.h"
#include "fileref.h"

// CVsProjectCleanerDlg 对话框
class CRenameByTxtDlg : public CDialogEx
{
// 构造
public:
	CRenameByTxtDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_VSPROJECTCLEANER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	config_s _conf;
	bool ShowPreviewInList(const CString& strDir, const CString& strTxt);
	bool ChangeTitleInfo(const std::string strFilePath);
	std::string GetIniPath();
public:
	afx_msg void OnBnClickedButtonOpenitem();
	afx_msg void OnBnClickedOk();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnBnClickedCheckRestore();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButtonOpentxt();
};
