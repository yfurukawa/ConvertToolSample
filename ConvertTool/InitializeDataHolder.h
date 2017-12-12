/*!-----------------------------------------------------------------------------
@file       InitializeDataHolder.h
@brief      固定データ初期化クラスの定義ファイル
@attention  なし
------------------------------------------------------------------------------*/
#if !defined(EA_5FEFA57B_12D6_4582_BA6D_62A518B9C27A__INCLUDED_)
#define EA_5FEFA57B_12D6_4582_BA6D_62A518B9C27A__INCLUDED_

// インクルードファイル ======================================================


// クラスの前方宣言 =======================================================
class IniFileDao;

// マクロの宣言 ================================================================

// 型の宣言 ==================================================================


// クラス定義 ==================================================================
/*!-----------------------------------------------------------------------------
@class      InitializeDataHolderクラス
@brief      固定データを初期化する。
@note       なし
@attention  なし
@see        なし
------------------------------------------------------------------------------*/
class InitializeDataHolder
{

public:
	virtual ~InitializeDataHolder();
    static InitializeDataHolder* getInstance();
    CString getKey1();
    CString getKey2();
    CString getOutputDir();
    void writeOutputDir(CString outputDir);
    
private:
    CString key1_;
    CString key2_;
    CString outputDir_;
    InitializeDataHolder();
    InitializeDataHolder(const InitializeDataHolder& other){}
    InitializeDataHolder& operator=(const InitializeDataHolder& other){}
    void readIniFile();
    static InitializeDataHolder* own_;
    IniFileDao* iniFileDao_;
};
#endif // !defined(EA_5FEFA57B_12D6_4582_BA6D_62A518B9C27A__INCLUDED_)
