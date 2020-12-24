
// VsProjectCleanerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RenameByTxt.h"
#include "RenameByTxtDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	// ʵ��
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


// CVsProjectCleanerDlg �Ի���




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

// CVsProjectCleanerDlg ��Ϣ�������

BOOL CRenameByTxtDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	std::string strIniPath = GetIniPath();
	if (CStdFile::IfAccessFile(strIniPath))
	{
		ReadIniFromFile(strIniPath, _conf);
	}
	else
	{
		WriteIniToFile(strIniPath, _conf);
	}

	//����ǽ��ļ�����ק��Ӧ�ó���ͼ����߿�ݷ�ʽ
	int argc = 0;
	LPWSTR *argv=::CommandLineToArgvW(::GetCommandLine(),&argc);
	CStringArray arrCmds;
	//ȥ����һ����������Ĳ���
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

	//��ʼ��ListControl
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST_NAME);
	CRect rListRect;
	pList->GetClientRect(rListRect);
	pList->InsertColumn( 0, TEXT("���ļ���"), LVCFMT_LEFT, rListRect.Width() / 2);
	pList->InsertColumn( 1, TEXT("���ļ���"), LVCFMT_LEFT, rListRect.Width() / 2);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻�TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CRenameByTxtDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CRenameByTxtDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CRenameByTxtDlg::OnBnClickedButtonOpenitem()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strDirPath = CMfcStrFile::BrowseDir();
	{
		SetDlgItemText(IDC_EDIT_ITEM, strDirPath);

		//�����ʱ�ļ��Ѿ����أ������ļ��������ı�����һ�£���չʾԤ��
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strTxtPath = CMfcStrFile::OpenSuffixFile(".txt");
	if (strTxtPath.GetLength() > 0)
	{
		SetDlgItemText(IDC_EDIT_TXT, strTxtPath);
		//�����ʱ�ļ����Ѿ����أ������ļ��������ı�����һ�£���չʾԤ��
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

	//��ʼ�������
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

	//����ʱ��
	clock_t start, finish;
	double duration;
	start = clock();

	if (!bRestore)
	{
		for (int m = 0; m < nDirNum; ++m)
		{
			//�������ļ���
			std::string sCurDir = vDirs[m];
			std::string sCurFile = vFiles[m];
			if (_access(sCurDir.c_str(), 0) != 0)
			{
				//�ļ��в����������
				continue;
			}

			//��ʼ��ʾ����
			if (NULL == m_pTaskbarList)
			{
				CoCreateInstance(CLSID_TaskbarList, NULL, CLSCTX_ALL, IID_ITaskbarList3, (void**)&m_pTaskbarList);
			}

			std::map<std::string, std::string> mLogs;

			//��ʼ���ն�Ӧ��txt���������ļ����е��ļ�
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
					//������ֲ�������׺������Ӻ�׺
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

			//����log����ǰʱ���Լ���ʱ
			std::string strLogFile = CStdStr::AddSlashIfNeeded(sCurDir.c_str()) + "log.log";
			std::vector<std::string> vLogContent;
			for (std::map<std::string, std::string>::iterator it = mLogs.begin(); it != mLogs.end(); ++it)
			{
				vLogContent.push_back(it->first + "->" + it->second + '\n');
			}

			CStdFile::SaveTXTFile(strLogFile, vLogContent);
		}
	}
	//����ǻָ�
	else
	{
		for (int m = 0; m < nDirNum; ++m)
		{
			//�ָ�����ļ���
			std::string sCurDir = vDirs[m];
			if (_access(sCurDir.c_str(), 0) != 0)
			{
				//�ļ��в����������
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

			//��ʼ��ʾ����
			if (NULL == m_pTaskbarList)
			{
				CoCreateInstance(CLSID_TaskbarList, NULL, CLSCTX_ALL, IID_ITaskbarList3, (void**)&m_pTaskbarList);
			}
			m_pTaskbarList->SetProgressState(m_hWnd, TBPF_INDETERMINATE);

			//��ʼ�ָ�
			for (std::map<std::string, std::string>::iterator it = mLogs.begin(); it != mLogs.end(); ++it)
			{
				rename(it->first.c_str(), it->second.c_str());
			}

			FlashWindow(TRUE);
			m_pTaskbarList->SetProgressState(m_hWnd, TBPF_NOPROGRESS);

			//������
			DeleteFile(CString(strLogFile.c_str()));
		}
	}

	finish = clock();
	duration = double(finish - start) / CLOCKS_PER_SEC;
	int nMinutes = int(duration / 60);
	int nSeconds = (int)duration % 60;
	CString strTips;
	strTips.Format(_T("%d��%d��"), nMinutes, nSeconds);

	CString strTime, strDate; //��ȡϵͳʱ�� ����
	CTime tm;
	tm = CTime::GetCurrentTime();
	strTime = tm.Format("%Y��%m��%d�� %X");
	strDate = tm.Format("%Y��%m��%d��");

	CString strSaveLine = strTips + "\t\t" + strTime + "\t\t" + strItems + '\n';

	TCHAR exeFullPath[MAX_PATH];
	CString strPath;
	GetModuleFileName(NULL, exeFullPath, MAX_PATH);
	strPath = (CString)exeFullPath;
	int position = strPath.ReverseFind('\\');
	strPath = strPath.Left(position);

	CStdioFile sFile(strPath + "\\" + strDate + ".log", CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
	sFile.SeekToEnd();
	setlocale(LC_CTYPE, "chs");//�趨f
	sFile.WriteString(strSaveLine);
	setlocale(LC_ALL, "C"); //��ԭ�����趨
	sFile.Close();

	MessageBox(_T("��ʱ:") + strTips + '\n' + _T("������ɣ�"), _T("�K��꣡"));
	SetFocus();

	//����ÿһ��Ŀ¼��Ѱ�Ҷ�Ӧ���ļ������������Ҽ�¼��log�ļ�

	WriteIniToFile(GetIniPath(), _conf);

	//CDialogEx::OnOK();
}


void CRenameByTxtDlg::OnDropFiles(HDROP hDropInfo)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	// ����һ������������Ŷ�ȡ���ļ�����Ϣ
	wchar_t szItemPath[MAX_PATH + 1] = { 0 };
	// ͨ������iFiles����Ϊ0xFFFFFFFF,����ȡ�õ�ǰ�϶����ļ�������
	// ������Ϊ0xFFFFFFFF,��������Ժ�������������
	UINT nNum = DragQueryFile(hDropInfo, 0xFFFFFFFF, NULL, 0);
	// ͨ��ѭ������ȡ���϶��ļ���File Name��Ϣ����������ӵ�ListBox��
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

	//�����ʱ�ļ����ļ����Ѿ����أ������ļ��������ı�����һ�£���չʾԤ��
	if (nItemNum == 1 && nFileNum == 1)
	{
		ShowPreviewInList(strItems, strFiles);
	}

	// �����˴���ק���������ͷŷ������Դ
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDialog::OnEraseBkgnd(pDC);
	HBITMAP   hBitmap;
	HDC           m_hBkDC;
	hBitmap   =   ::LoadBitmap(::GetModuleHandle(NULL),MAKEINTRESOURCE(IDB_BITMAP1));
	BITMAP bitmap;
	GetObject(hBitmap, sizeof (BITMAP), &bitmap) ;//��ȡλͼ�ߴ�  
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
		pDC->SetBkMode(TRANSPARENT);//���ñ���͸��
		//pDC->SetTextColor(RGB(0,0,0));//����������ɫ
		return (HBRUSH)::GetStockObject(NULL_BRUSH);
	}

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
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

	//����ļ�����ͳһ����ʾԤ�������򷵻�false
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
			//������ֲ�������׺������Ӻ�׺
			strNewName += strOldSuffix;
		}

		//����ļ�����list����
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
