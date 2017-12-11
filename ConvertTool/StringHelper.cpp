/*!-----------------------------------------------------------------------------
@file       StringHelper.cpp
@brief      
@attention  �Ȃ�
------------------------------------------------------------------------------*/
#include "StdAfx.h"
#include "StringHelper.h"

/*!-----------------------------------------------------------------------------
@brief      �f�t�H���g�R���X�g���N�^
@note       �N���X���\�z����B
@param[in]  �Ȃ�
@return     �Ȃ�
@attention  �Ȃ�
------------------------------------------------------------------------------*/
StringHelper::StringHelper(void)
{
}

/*!-----------------------------------------------------------------------------
@brief      �f�X�g���N�^
@note       �N���X��j������B
@param      �Ȃ�
@return     �Ȃ�
@attention  �Ȃ�
------------------------------------------------------------------------------*/
StringHelper::~StringHelper(void)
{
}

/*!-----------------------------------------------------------------------------
@brief      
@note       
@param      
@return     �Ȃ�
@attention  �Ȃ�
------------------------------------------------------------------------------*/


// FullPath -> �t�@�C����(�g���q�t)
CString StringHelper::GetFileName( CString strPath )
{
	// �t�@�C�����̕����p
	TCHAR szDrv[ 1024 + 1 ] = _T("");
	TCHAR szDir[ 1024 + 1 ] = _T("");
	TCHAR szFile[ 1024 + 1 ] = _T("");
	TCHAR szType[ 1024 + 1 ] = _T("");
	TCHAR szAppPath[1024+1] = _T("");

	// �p�X�𕪊�����B
	#if 1400 <= _MSC_VER
		::_tsplitpath_s( strPath, szDrv, 1024, szDir, 1024, szFile, 1024, szType, 1024 );
	#else
		::_tsplitpath( strPath, szDrv, szDir, szFile, szType );
	#endif

	// ��΃p�X�ɕϊ�
	TCHAR* pszName = NULL;
	CString strFileName;
	strFileName.Format( _T("%s%s"), szFile, szType );
	return strFileName;
}

/*!-----------------------------------------------------------------------------
@brief      
@note       
@param      
@return     �Ȃ�
@attention  �Ȃ�
------------------------------------------------------------------------------*/
void StringHelper::Split(CStringArray* pstrArray,LPCTSTR szTarget,LPCTSTR szDelimiter)
{
    if(!szTarget)
        return;
    if(!szDelimiter)
        return;
    if(!pstrArray)
        return;

    pstrArray->RemoveAll();

    CString strTarget(szTarget);
    size_t intDelimiterLen=0;
    size_t intStart=0;
    int intEnd=0;

    strTarget += szDelimiter;
    intDelimiterLen = _tcslen(szDelimiter);
    intStart = 0;
    while (intEnd = strTarget.Find(szDelimiter, intStart), intEnd >= 0)
    {
        pstrArray->Add(strTarget.Mid(intStart, intEnd - intStart));
        intStart = intEnd + intDelimiterLen;
    }
    return;
}

void StringHelper::GetRootPath( CString* const pstrPath )
{
	// �t�@�C�����̕����p
	TCHAR szDrv[ 1024 + 1 ] = _T("");
	TCHAR szDir[ 1024 + 1 ] = _T("");
	TCHAR szFile[ 1024 + 1 ] = _T("");
	TCHAR szType[ 1024 + 1 ] = _T("");
	TCHAR szAppPath[1024+1] = _T("");

	// ���W���[���̃p�X���擾����B
	::GetModuleFileName( NULL, szAppPath, sizeof(szAppPath) );

	// �p�X�𕪊�����B
	#if 1400 <= _MSC_VER
		::_tsplitpath_s( szAppPath, szDrv, 1024, szDir, 1024, szFile, 1024, szType, 1024 );
	#else
		::_tsplitpath( szAppPath, szDrv, szDir, szFile, szType );
	#endif

	// ���[�g�p�X������
	TCHAR szPath[1024+1] = _T("");
	#ifdef _DEBUG
	wsprintf( szAppPath, _T("%s%s"), szDrv, szDir );
	#else
	wsprintf( szAppPath, _T("%s%s"), szDrv, szDir );
	#endif

	// ��΃p�X�ɕϊ�
	TCHAR* pszName = NULL;
	::GetFullPathName( szAppPath, 1024, szPath, &pszName );
	pstrPath->Format( szPath );
}

