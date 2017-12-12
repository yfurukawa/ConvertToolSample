/*!-----------------------------------------------------------------------------
@file       InitializeDataHolder.h
@brief      �Œ�f�[�^�������N���X�̒�`�t�@�C��
@attention  �Ȃ�
------------------------------------------------------------------------------*/
#if !defined(EA_5FEFA57B_12D6_4582_BA6D_62A518B9C27A__INCLUDED_)
#define EA_5FEFA57B_12D6_4582_BA6D_62A518B9C27A__INCLUDED_

// �C���N���[�h�t�@�C�� ======================================================


// �N���X�̑O���錾 =======================================================
class IniFileDao;

// �}�N���̐錾 ================================================================

// �^�̐錾 ==================================================================


// �N���X��` ==================================================================
/*!-----------------------------------------------------------------------------
@class      InitializeDataHolder�N���X
@brief      �Œ�f�[�^������������B
@note       �Ȃ�
@attention  �Ȃ�
@see        �Ȃ�
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
