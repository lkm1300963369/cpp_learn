
// lainlainkanDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "lainlainkan.h"
#include "lainlainkanDlg.h"
#include "afxdialogex.h"
#include<windows.h>
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ClainlainkanDlg 对话框



ClainlainkanDlg::ClainlainkanDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAINLAINKAN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void ClainlainkanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, time);
}

BEGIN_MESSAGE_MAP(ClainlainkanDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_BEGIN, &ClainlainkanDlg::OnBnClickedButtonBegin)
	ON_EN_CHANGE(IDC_EDIT1, &ClainlainkanDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// ClainlainkanDlg 消息处理程序

BOOL ClainlainkanDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void ClainlainkanDlg::OnPaint()
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
HCURSOR ClainlainkanDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
byte arr[11][19] = { 0 };
int maxp(int i, int j)
{
	return i > j ? i : j;
}
int minp(int i, int j)
{
	return i < j ? i : j;
}
bool cheack2p(POINT a, POINT b)
{
	if (a.x == b.x && (a.y - b.y == 1 || b.y - a.y == 1))
		return true;
	if (a.y == b.y && (a.x - b.x == 1 || b.x - a.x == 1))
		return true;
	vector<POINT>q;
	vector<POINT>p;
	q.push_back(a);
	p.push_back(b);
	for (int i = a.x - 1; i >= 0; i--)
	{
		if (arr[i][a.y] == 0)
		{
			POINT temp;
			temp.x = i; temp.y = a.y;
			q.push_back(temp);
		}
		else
		{
			break;
		}
	}
	for (int i = b.x - 1; i >= 0; i--)
	{
		if (arr[i][b.y] == 0)
		{
			POINT temp;
			temp.x = i; temp.y = b.y;
			p.push_back(temp);
		}
		else
		{
			break;
		}
	}

	for (int i = a.x + 1; i <11; i++)
	{
		if (arr[i][a.y] == 0)
		{
			POINT temp;
			temp.x = i; temp.y = a.y;
			q.push_back(temp);
		}
		else
		{
			break;
		}
	}
	for (int i = b.x + 1; i < 11; i++)
	{
		if (arr[i][b.y] == 0)
		{
			POINT temp;
			temp.x = i; temp.y = b.y;
			p.push_back(temp);
		}
		else
		{
			break;
		}
	}

	for (int i = a.y - 1; i >= 0; i--)
	{
		if (arr[a.x][i] == 0)
		{
			POINT temp;
			temp.x = a.x; temp.y = i;
			q.push_back(temp);
		}
		else
		{
			break;
		}
	}
	for (int i = b.y - 1; i >= 0; i--)
	{
		if (arr[b.x][i] == 0)
		{
			POINT temp;
			temp.x = b.x; temp.y = i;
			p.push_back(temp);
		}
		else
		{
			break;
		}
	}

	for (int i = a.y + 1; i <19; i++)
	{
		if (arr[a.x][i] == 0)
		{
			POINT temp;
			temp.x = a.x; temp.y = i;
			q.push_back(temp);
		}
		else
		{
			break;
		}
	}
	for (int i = b.y + 1; i < 19; i++)
	{
		if (arr[b.x][i] == 0)
		{
			POINT temp;
			temp.x = b.x; temp.y = i;
			p.push_back(temp);
		}
		else
		{
			break;
		}
	}

	for (int i = 0; i < q.size(); i++)
	{
		for (int j = 0; j < p.size(); j++)
		{
			int flag = 0;
			if (q[i].x == p[j].x&&q[i].y == p[j].y)
				return true;
			if ((q[i].x == -1 && q[i].x == p[j].x) || (q[i].x == 11 && q[i].x == p[j].x))
				return true;
			if ((q[i].y == -1 && q[i].y == p[j].y) || q[i].y == 19 && q[i].y == p[j].y)
				return true;

			if (q[i].x == p[j].x)
			{
				for (int t = minp(q[i].y, p[j].y) + 1; t <= maxp(q[i].y, p[j].y); t++)
				{
					if (arr[q[i].x][t] != 0)
						break;
					if (t == maxp(q[i].y, p[j].y))
						return true;
				}
			}

			if (q[i].y == p[j].y)
			{
				for (int t = minp(q[i].x, p[j].x) + 1; t <= maxp(q[i].x, p[j].x); t++)
				{
					if (arr[t][q[i].y] != 0)
						break;
					if (t == maxp(q[i].x, p[j].x))
						return true;
				}
			}
		}
	}
	return false;

}
void findmemory()
{
	HWND hwnd = ::FindWindow(NULL, _T("QQ游戏 - 连连看角色版"));
	DWORD d;
	GetWindowThreadProcessId(hwnd, &d);
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, d);
	LPVOID buff = LPVOID(&arr);
	SIZE_T g;
	ReadProcessMemory(handle, LPCVOID(0x00189F78), buff, 11 * 19, &g);
}
void run(int num)
{
first: 
	HWND hwnd = ::FindWindow(NULL, _T("QQ游戏 - 连连看角色版"));
	DWORD d;
	GetWindowThreadProcessId(hwnd, &d);
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, d);
	LPVOID buff = LPVOID(&arr);
	SIZE_T g;
	ReadProcessMemory(handle, LPCVOID(0x00189F78), buff, 11 * 19, &g);
	//SendMessage(hwnd, WM_LBUTTONDOWN, 0, MAKELPARAM(28, 192));//31  35
	POINT a;
	POINT b;
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (arr[i][j] == 0)
			{
				continue;
			}
			for (int t = i; t < 11; t++)
			{
				for (int h = 0; h < 19; h++)
				{
					
					if (arr[i][j] == arr[t][h]&&arr[i][j]!=0&&!(t==i&&h==j))
					{
						a.x = i; a.y = j;
						b.x = t; b.y = h;
						if (cheack2p(a, b))
						{
							SendMessage(hwnd, WM_LBUTTONDOWN, 0, MAKELPARAM(28 + 31 * j, 192 + 35 * i));
							SendMessage(hwnd, WM_LBUTTONUP, 0, MAKELPARAM(28 + 31 * j, 192 + 35 * i));
							Sleep(num);
							SendMessage(hwnd, WM_LBUTTONDOWN, 0, MAKELPARAM(28 + 31 * h, 192 + 35 * t));
							SendMessage(hwnd, WM_LBUTTONUP, 0, MAKELPARAM(28 + 31 * h, 192 + 35 * t));
							goto first;
						}
					}
				}
			}
		}
	}
}

void ClainlainkanDlg::OnBnClickedButtonBegin()
{
	UpdateData(true);
	CString Stime = _T("");
	int num;
	CWnd *p = GetDlgItem(IDC_EDIT1);
	p->GetWindowTextW(Stime);
	num = _ttoi(Stime);
	
	run(num);
	
}


void ClainlainkanDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
