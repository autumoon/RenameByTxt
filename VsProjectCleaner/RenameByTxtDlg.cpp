
// VsProjectCleanerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "RenameByTxt.h"
#include "RenameByTxtDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CVsProjectCleanerDlg 对话框




CRenameByTxtDlg::CRenameByTxtDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRenameByTxtDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRenameByTxtDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRenameByTxtDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_OPENITEM, &CRenameByTxtDlg::OnBnClickedButtonOpenitem)
	ON_BN_CLICKED(IDOK, &CRenameByTxtDlg::OnBnClickedOk)
	ON_WM_DROPFILES()
	ON_BN_CLICKED(IDC_CHECK_RESTORE, &CRenameByTxtDlg::OnBnClickedCheckRestore)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_OPENTXT, &CRenameByTxtDlg::OnBnClickedButtonOpentxt)
END_MESSAGE_MAP()

// CVsProjectCleanerDlg 消息处理程序

BOOL CRenameByTxtDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	std::string strIniPath = GetIniPath();
	if (CStdFile::IfAccessFile(strIniPath))
	{
		ReadIniFromFile(strIniPath, _conf);
	}
	else
	{
		WriteIniToFile(strIniPath, _conf);
	}

	//如果是将文件夹拖拽到应用程序图标或者快捷方式
	int argc = 0;
	LPWSTR *argv=::CommandLineToArgvW(::GetCommandLine(),&argc);
	CStringArray arrCmds;
	//去掉第一个程序自身的参数
	for (int i = 1; i < argc; ++i)
	{
		arrCmds.Add(argv[i]);
	}
	LocalFree(argv);

	if (arrCmds.GetCount() >= 1)
	{
		int nItems = (int)arrCmds.GetCount();
		CString strItems, strFiles;
		int nItemNum = 0, nFileNum = 0;
		for (int i = 0; i < nItems; ++i)
		{
			CString strDirOrFile = arrCmds[i];
			std::string sItems = CMfcStrFile::CString2string(strDirOrFile);
			if (_access(sItems.c_str(), 0) == 0)
			{
				if (CStdFile::IfAccessFile(sItems))
				{
					strFiles += strDirOrFile + '|';
					++nFileNum;
				}
				else
				{
					strItems += strDirOrFile + '|';
					++nItemNum;
				}
			}
		}
		CString strTmp[2];
		strTmp[0].LoadString(IDS_PROCESS_NOW);
		strTmp[1].LoadString(IDS_TIPS);
		if (strItems.GetLength() && MessageBox(strTmp[0], strTmp[1], MB_YESNO) == IDYES)
		{
			if (nItemNum == 1)
			{
				strItems.Trim('|');
				SetDlgItemText(IDC_EDIT_ITEM, strItems);
			}
			else
			{
				SetDlgItemText(IDC_EDIT_ITEM, strItems);
			}

			if (nFileNum == 1)
			{
				strFiles.Trim('|');
				SetDlgItemText(IDC_EDIT_TXT, strFiles);
			}
			else
			{
				SetDlgItemText(IDC_EDIT_TXT, strFiles);
			}
			OnBnClickedOk();
		}
	}

	//初始化ListControl
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST_NAME);
	CRect rListRect;
	pList->GetClientRect(rListRect);
	pList->InsertColumn( 0, TEXT("旧文件名"), LVCFMT_LEFT, rListRect.Width() / 2);
	pList->InsertColumn( 1, TEXT("新文件名"), LVCFMT_LEFT, rListRect.Width() / 2);

	return TRUE;  // 除非将焦点设置到控件，否则返回TRUE
}

void CRenameByTxtDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRenameByTxtDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CRenameByTxtDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CRenameByTxtDlg::OnBnClickedButtonOpenitem()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strDirPath = CMfcStrFile::BrowseDir();
	{
		SetDlgItemText(IDC_EDIT_ITEM, strDirPath);

		//如果此时文件已经加载，并且文件个数与文本个数一致，则展示预览
		CString strTxtPath;
		GetDlgItemText(IDC_EDIT_TXT, strTxtPath);
		CString strTmp[2];
		strTmp[0].LoadString(IDS_PROCESS_NOW);
		strTmp[1].LoadString(IDS_TIPS);
		if (ShowPreviewInList(strDirPath, strTxtPath) && MessageBox(strTmp[0], strTmp[1], MB_YESNO) == IDYES)
		{
			OnBnClickedOk();
		}
	}
}

void CRenameByTxtDlg::OnBnClickedButtonOpentxt()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strTxtPath = CMfcStrFile::OpenSuffixFile(".txt");
	if (strTxtPath.GetLength() > 0)
	{
		SetDlgItemText(IDC_EDIT_TXT, strTxtPath);
		//如果此时文件夹已经加载，并且文件个数与文本个数一致，则展示预览
		CString strDirPath;
		GetDlgItemText(IDC_EDIT_ITEM, strDirPath);
		CString strTmp[2];
		strTmp[0].LoadString(IDS_PROCESS_NOW);
		strTmp[1].LoadString(IDS_TIPS);
		if (ShowPreviewInList(strDirPath, strTxtPath) && MessageBox(strTmp[0], strTmp[1], MB_YESNO) == IDYES)
		{
			OnBnClickedOk();
		}
	}
}

static ITaskbarList3* m_pTaskbarList = nullptr;

void CRenameByTxtDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	bool bRestore = ((CButton*)GetDlgItem(IDC_CHECK_RESTORE))->GetCheck() == TRUE;

	CString strItems, strFiles;
	GetDlgItemText(IDC_EDIT_ITEM, strItems);
	if (!bRestore)
	{
		GetDlgItemText(IDC_EDIT_TXT, strFiles);
	}
	if (strItems.GetLength() == 0)
	{
		strItems = CMfcStrFile::BrowseDir();
		if (strItems.GetLength() > 0)
		{
			SetDlgItemText(IDC_EDIT_ITEM, strItems);
		}
		else
		{
			return;
		}
	}

	if (!bRestore && strFiles.GetLength() == 0)
	{
		strFiles = CMfcStrFile::OpenSuffixFile(".txt");
		if (strItems.GetLength() > 0)
		{
			SetDlgItemText(IDC_EDIT_TXT, strItems);
		}
		else
		{
			return;
		}
	}

	//开始逐个处理
	std::string sItems = CMfcStrFile::CString2string(strItems);
	std::string sFiles = CMfcStrFile::CString2string(strFiles);
	std::vector<std::string> vDirs = CStdStr::Split(sItems, "|");
	std::vector<std::string> vFiles = CStdStr::Split(sFiles, "|");

	size_t nDirNum = vDirs.size();
	size_t nFileNum = vFiles.size();

	if (nDirNum != nFileNum)
	{
		CString strTmp[2];
		strTmp[0].LoadString(IDS_NOT_PAIR);
		strTmp[1].LoadString(IDS_TIPS);
		MessageBox(strTmp[0], strTmp[1], MB_ICONINFORMATION);

		return;
	}

	_conf.vDirPaths = vDirs;
	_conf.vFilePaths = vFiles;

	//测试时间
	clock_t start, finish;
	double duration;
	start = clock();

	if (!bRestore)
	{
		for (int m = 0; m < nDirNum; ++m)
		{
			//处理多个文件夹
			std::string sCurDir = vDirs[m];
			std::string sCurFile = vFiles[m];
			if (_access(sCurDir.c_str(), 0) != 0)
			{
				//文件夹不存在则继续
				continue;
			}

			//开始显示进度
			if (NULL == m_pTaskbarList)
			{
				CoCreateInstance(CLSID_TaskbarList, NULL, CLSCTX_ALL, IID_ITaskbarList3, (void**)&m_pTaskbarList);
			}

			std::map<std::string, std::string> mLogs;

			//开始按照对应的txt，重命名文件夹中的文件
			std::vector<std::string> vCurDirFiles;
			std::string strFileSuffix = CStdStr::ws2s(_conf.strSuffix);
			getFiles(sCurDir, vCurDirFiles, ("*" + strFileSuffix).c_str() , false);
			std::vector<std::string> vNewNames;
			CStdFile::ParseTXTFile(sCurFile, vNewNames);

			const size_t nCurFileNum = vCurDirFiles.size();
			const size_t nNewNames = vNewNames.size();
			if (nCurFileNum != nNewNames)
			{
				continue;
			}

			for (int i = 0; i < nCurFileNum; ++i)
			{
				std::string strFileDir = CStdStr::GetDirOfFile(vCurDirFiles[i]);
				std::string strNewFilePath = CStdStr::AddSlashIfNeeded(strFileDir) + vNewNames[i];
				std::string strOldSuffix = CStdStr::GetSuffixOfFile(vCurDirFiles[i]);
				std::string strNewSuffix = CStdStr::GetSuffixOfFile(strNewFilePath);
				if (CStdStr::ToUpperLower(strOldSuffix) != CStdStr::ToUpperLower(strNewSuffix))
				{
					//如果名字不包含后缀，则添加后缀
					strNewFilePath += strOldSuffix;
				}

				if (rename(vCurDirFiles[i].c_str(), strNewFilePath.c_str()) != -1)
				{
					ChangeTitleInfo(strNewFilePath);
					mLogs.insert(std::make_pair(vCurDirFiles[i], strNewFilePath));
				}
			}

			FlashWindow(TRUE);
			m_pTaskbarList->SetProgressState(m_hWnd, TBPF_NOPROGRESS);

			//保存log，当前时间以及耗时
			std::string strLogFile = CStdStr::AddSlashIfNeeded(sCurDir.c_str()) + "log.log";
			std::vector<std::string> vLogContent;
			for (std::map<std::string, std::string>::iterator it = mLogs.begin(); it != mLogs.end(); ++it)
			{
				vLogContent.push_back(it->first + "->" + it->second + '\n');
			}

			CStdFile::SaveTXTFile(strLogFile, vLogContent);
		}
	}
	//如果是恢复
	else
	{
		for (int m = 0; m < nDirNum; ++m)
		{
			//恢复多个文件夹
			std::string sCurDir = vDirs[m];
			if (_access(sCurDir.c_str(), 0) != 0)
			{
				//文件夹不存在则继续
				continue;
			}

			std::string strLogFile = CStdStr::AddSlashIfNeeded(sCurDir) + "log.log";
			if (!CStdFile::IfAccessFile(strLogFile))
			{
				continue;
			}
			std::vector<std::string> vLogContent;
			CStdFile::ParseTXTFile(strLogFile, vLogContent);
			std::map<std::string, std::string> mLogs;
			for (int i = 0; i < vLogContent.size(); ++i)
			{
				std::vector<std::string> vLines = CStdStr::Split(vLogContent[i], "->");
				if (vLines.size() >= 2)
				{
					mLogs.insert(std::make_pair(vLines[1].c_str(), vLines[0].c_str()));
				}
			}

			//开始显示进度
			if (NULL == m_pTaskbarList)
			{
				CoCreateInstance(CLSID_TaskbarList, NULL, CLSCTX_ALL, IID_ITaskbarList3, (void**)&m_pTaskbarList);
			}
			m_pTaskbarList->SetProgressState(m_hWnd, TBPF_INDETERMINATE);

			//开始恢复
			for (std::map<std::string, std::string>::iterator it = mLogs.begin(); it != mLogs.end(); ++it)
			{
				rename(it->first.c_str(), it->second.c_str());
			}

			FlashWindow(TRUE);
			m_pTaskbarList->SetProgressState(m_hWnd, TBPF_NOPROGRESS);

			//清理工作
			DeleteFile(CString(strLogFile.c_str()));
		}
	}

	finish = clock();
	duration = double(finish - start) / CLOCKS_PER_SEC;
	int nMinutes = int(duration / 60);
	int nSeconds = (int)duration % 60;
	CString strTips;
	strTips.Format(_T("%d分%d秒"), nMinutes, nSeconds);

	CString strTime, strDate; //获取系统时间 　　
	CTime tm;
	tm = CTime::GetCurrentTime();
	strTime = tm.Format("%Y年%m月%d日 %X");
	strDate = tm.Format("%Y年%m月%d日");

	CString strSaveLine = strTips + "\t\t" + strTime + "\t\t" + strItems + '\n';

	TCHAR exeFullPath[MAX_PATH];
	CString strPath;
	GetModuleFileName(NULL, exeFullPath, MAX_PATH);
	strPath = (CString)exeFullPath;
	int position = strPath.ReverseFind('\\');
	strPath = strPath.Left(position);

	CStdioFile sFile(strPath + "\\" + strDate + ".log", CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
	sFile.SeekToEnd();
	setlocale(LC_CTYPE, "chs");//设定f
	sFile.WriteString(strSaveLine);
	setlocale(LC_ALL, "C"); //还原区域设定
	sFile.Close();

	MessageBox(_T("耗时:") + strTips + '\n' + _T("处理完成！"), _T("終わり！"));
	SetFocus();

	//对于每一个目录，寻找对应的文件，重命名并且记录到log文件

	WriteIniToFile(GetIniPath(), _conf);

	//CDialogEx::OnOK();
}


void CRenameByTxtDlg::OnDropFiles(HDROP hDropInfo)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	// 定义一个缓冲区来存放读取的文件名信息
	wchar_t szItemPath[MAX_PATH + 1] = { 0 };
	// 通过设置iFiles参数为0xFFFFFFFF,可以取得当前拖动的文件数量，
	// 当设置为0xFFFFFFFF,函数间忽略后面两个参数。
	UINT nNum = DragQueryFile(hDropInfo, 0xFFFFFFFF, NULL, 0);
	// 通过循环依次取得拖动文件的File Name信息，并把它添加到ListBox中
	CString strItems, strFiles;
	int nItemNum = 0, nFileNum = 0;
	for (UINT i = 0; i < nNum; ++i)
	{
		DragQueryFile(hDropInfo, i, szItemPath, MAX_PATH);
		if (_access(CStdStr::ws2s(szItemPath).c_str(), 0) == 0)
		{
			if (CStdFile::IfAccessFile(CStdStr::ws2s(szItemPath)))
			{
				strFiles += CString(szItemPath) + '|';
				++nFileNum;
			}
			else
			{
				strItems += CString(szItemPath) + '|';
				++nItemNum;
			}
		}
	}

	if (nItemNum == 1)
	{
		strItems.Trim('|');
		SetDlgItemText(IDC_EDIT_ITEM, strItems);
	}
	else
	{
		SetDlgItemText(IDC_EDIT_ITEM, strItems);
	}

	if (nFileNum == 1)
	{
		strFiles.Trim('|');
		SetDlgItemText(IDC_EDIT_TXT, strFiles);
	}
	else
	{
		SetDlgItemText(IDC_EDIT_TXT, strFiles);
	}

	//如果此时文件和文件夹已经加载，并且文件个数与文本个数一致，则展示预览
	if (nItemNum == 1 && nFileNum == 1)
	{
		ShowPreviewInList(strItems, strFiles);
	}

	// 结束此次拖拽操作，并释放分配的资源
	DragFinish(hDropInfo);
	CDialog::OnDropFiles(hDropInfo);

	CDialogEx::OnDropFiles(hDropInfo);
}

std::string CRenameByTxtDlg::GetIniPath()
{
	TCHAR chpath[MAX_PATH];
	GetModuleFileName(NULL, chpath, sizeof(chpath));

	std::string strModulePath = CMfcStrFile::CString2string(chpath);
	std::string strIniPath = CStdStr::ReplaceSuffix(strModulePath, ".ini");

	return strIniPath;
}


void CRenameByTxtDlg::OnBnClickedCheckRestore()
{
	// TODO: 在此添加控件通知处理程序代码
	BOOL bRes = ((CButton*)GetDlgItem(IDC_CHECK_RESTORE))->GetCheck();

	if (bRes == TRUE)
	{
		((CButton*)(GetDlgItem(IDC_EDIT_TXT)))->EnableWindow(FALSE);
		((CButton*)(GetDlgItem(IDC_BUTTON_OPENTXT)))->EnableWindow(FALSE);
	}
	else
	{
		((CButton*)(GetDlgItem(IDC_EDIT_TXT)))->EnableWindow(TRUE);
		((CButton*)(GetDlgItem(IDC_BUTTON_OPENTXT)))->EnableWindow(TRUE);
	}
}


BOOL CRenameByTxtDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDialog::OnEraseBkgnd(pDC);
	HBITMAP   hBitmap;
	HDC           m_hBkDC;
	hBitmap   =   ::LoadBitmap(::GetModuleHandle(NULL),MAKEINTRESOURCE(IDB_BITMAP1));
	BITMAP bitmap;
	GetObject(hBitmap, sizeof (BITMAP), &bitmap) ;//获取位图尺寸  
	m_hBkDC     =   ::CreateCompatibleDC(pDC-> m_hDC);
	if(hBitmap   &&   m_hBkDC)
	{
		::SelectObject(m_hBkDC,hBitmap);
		::StretchBlt(pDC->m_hDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight,m_hBkDC,0,0, bitmap.bmWidth, bitmap.bmHeight,SRCCOPY);
		::DeleteObject(hBitmap);
		::DeleteDC(m_hBkDC);
	}

	return TRUE;
}

HBRUSH CRenameByTxtDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	if(nCtlColor == CTLCOLOR_STATIC )
	{
		pDC->SetBkMode(TRANSPARENT);//设置背景透明
		//pDC->SetTextColor(RGB(0,0,0));//设置字体颜色
		return (HBRUSH)::GetStockObject(NULL_BRUSH);
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

bool CRenameByTxtDlg::ShowPreviewInList(const CString& strDir, const CString& strTxt)
{
	if (strDir.GetLength() <= 0 || strTxt.GetLength() <= 0)
	{
		return false;
	}


	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST_NAME);

	if (pList == nullptr)
	{
		return false;
	}
	else
	{
		pList->DeleteAllItems();
	}

	//如果文件个数统一则显示预览，否则返回false
	std::vector<std::string> vFiles;
	getFiles(CMfcStrFile::CString2string(strDir), vFiles, ('*' + CStdStr::ws2s(_conf.strSuffix)).c_str(), false);

	std::vector<std::string> vNewNames;
	CStdFile::ParseTXTFile(CMfcStrFile::CString2string(strTxt), vNewNames);

	size_t nFileNum = vFiles.size();
	size_t nNameNum = vNewNames.size();

	if (nFileNum != nNameNum)
	{
		return false;
	}

	for (size_t i = 0; i < nFileNum; ++i)
	{
		std::string strFilePath = vFiles[i];
		std::string strOldName = CStdStr::GetNameOfFile(strFilePath);
		std::string strNewName = vNewNames[i];

		std::string strOldSuffix = CStdStr::GetSuffixOfFile(strOldName);
		std::string strNewSuffix = CStdStr::GetSuffixOfFile(strNewName);
		if (CStdStr::ToUpperLower(strOldSuffix) != CStdStr::ToUpperLower(strNewSuffix))
		{
			//如果名字不包含后缀，则添加后缀
			strNewName += strOldSuffix;
		}

		//添加文件名到list当中
		int nCount = pList->GetItemCount();
		pList->InsertItem(nCount, CStdStr::s2ws(strOldName).c_str());
		pList->SetItemText(nCount, 1, CStdStr::s2ws(strNewName).c_str());
	}

	return true;
}

bool CRenameByTxtDlg::ChangeTitleInfo(const std::string strFilePath)
{
	TagLib::FileRef f(strFilePath.c_str());

	if (f.tag() != nullptr)
	{
		TagLib::String artist = f.tag()->title();
		f.tag()->setTitle(CStdStr::GetNameOfFile(strFilePath, false));
		f.save();
	}

	return 0;
}
