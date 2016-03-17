// ArchiveTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ArchiveTest.h"
#include "Person.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一的应用程序对象

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// 初始化 MFC 并在失败时显示错误
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: 更改错误代码以符合您的需要
		_tprintf(_T("错误: MFC 初始化失败\n"));
		nRetCode = 1;
	}
	else
	{
		setlocale(LC_ALL, "chs");  

		//创建两个待写入的对象  
		CPerson tong(_T("Jack"), 28, false);  
		tong.setWords(_T("Hihihi..."));  

		CPerson bai(_T("Rick"), 27, true);  
		bai.setWords(_T("HeloHello!"));  

		//准备写入  
		CFile oFile(_T("persons.archive"),CFile::modeCreate|CFile::modeWrite);  
		CArchive oar(&oFile, CArchive::store);  

		//序列化进去了  
		oar << &tong << &bai;  
		//oar.WriteObject(&tong);  
		//oar.WriteObject(&bai);  

		oar.Close();  
		oFile.Close();  

		//准备读取  
		CFile iFile(_T("persons.archive"), CFile::modeRead);  
		CArchive iar(&iFile, CArchive::load);  

		CPerson *p1, * p2;  

		//序列化出来了  
		iar >> p1 >> p2;  
		//p1 = iar.ReadObject(RUNTIME_CLASS(CPerson));  
		//p2 = iar.ReadObject(RUNTIME_CLASS(CPerson));  

		//看看他们是不是活的*_*ii  
		p1->say();  
		p2->say();  

		delete p1;  
		delete p2;  
	}

	return nRetCode;
}
