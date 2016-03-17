// ArchiveTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "ArchiveTest.h"
#include "Person.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ψһ��Ӧ�ó������

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// ��ʼ�� MFC ����ʧ��ʱ��ʾ����
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: ���Ĵ�������Է���������Ҫ
		_tprintf(_T("����: MFC ��ʼ��ʧ��\n"));
		nRetCode = 1;
	}
	else
	{
		setlocale(LC_ALL, "chs");  

		//����������д��Ķ���  
		CPerson tong(_T("Jack"), 28, false);  
		tong.setWords(_T("Hihihi..."));  

		CPerson bai(_T("Rick"), 27, true);  
		bai.setWords(_T("HeloHello!"));  

		//׼��д��  
		CFile oFile(_T("persons.archive"),CFile::modeCreate|CFile::modeWrite);  
		CArchive oar(&oFile, CArchive::store);  

		//���л���ȥ��  
		oar << &tong << &bai;  
		//oar.WriteObject(&tong);  
		//oar.WriteObject(&bai);  

		oar.Close();  
		oFile.Close();  

		//׼����ȡ  
		CFile iFile(_T("persons.archive"), CFile::modeRead);  
		CArchive iar(&iFile, CArchive::load);  

		CPerson *p1, * p2;  

		//���л�������  
		iar >> p1 >> p2;  
		//p1 = iar.ReadObject(RUNTIME_CLASS(CPerson));  
		//p2 = iar.ReadObject(RUNTIME_CLASS(CPerson));  

		//���������ǲ��ǻ��*_*ii  
		p1->say();  
		p2->say();  

		delete p1;  
		delete p2;  
	}

	return nRetCode;
}
