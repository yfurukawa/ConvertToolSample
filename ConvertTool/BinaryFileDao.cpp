/*!-----------------------------------------------------------------------------
@file       BinaryFileDao.cpp
@brief      �o�C�i���t�@�C���ւ̃A�N�Z�X��񋟂���
@attention  �Ȃ�
------------------------------------------------------------------------------*/
#include "StdAfx.h"
#include "BinaryFileDao.h"
#include "FileName.h"

/*!-----------------------------------------------------------------------------
@brief      �f�t�H���g�R���X�g���N�^
@note       �N���X���\�z����B
@param[in]  �Ȃ�
@return     �Ȃ�
@attention  �Ȃ�
------------------------------------------------------------------------------*/
BinaryFileDao::BinaryFileDao(void)
{
}

/*!-----------------------------------------------------------------------------
@brief      �f�X�g���N�^
@note       �N���X��j������B
@param      �Ȃ�
@return     �Ȃ�
@attention  �Ȃ�
------------------------------------------------------------------------------*/
BinaryFileDao::~BinaryFileDao(void)
{
}

/*!-----------------------------------------------------------------------------
@fn         �w�肳�ꂽ�t�@�C�����o�C�i���`���œǂݍ��ݐ�p�ŃI�[�v������
@brief      �t�@�C���I�[�v��
@param[in]  fileName�@�t�@�C����
@return     �I�[�v�����ʁi�����Ftrue�A���s�Ffalse�j
@attention  �Ȃ�
@detail     �����œn���ꂽ�t�@�C�����o�C�i���`���œǂݍ��ݐ�p�ŃI�[�v�����܂��B
�@�@�@�@�@�@�w�肳�ꂽ�t�@�C�������݂��Ȃ��ꍇ�A��O���������܂����A
      �@�@�@�����͌p������܂�
------------------------------------------------------------------------------*/
bool BinaryFileDao::open(FileName* fileName)
{
    if(!tmbFile_.Open(fileName->fileNameWithPath(),
        CFile::modeRead /*| CFile::shareExclusive*/ | CFile::typeBinary, &fileException_))
    {
        TRACE( _T("Can't open file %s, error = %u\n"),
            fileName, fileException_.m_cause );
        return false;
    }
    else
    {
        return true;
    }
}

/*!-----------------------------------------------------------------------------
@fn         �I�[�v���ς݂̃t�@�C������A�f�[�^��ǂݍ���
@brief      �f�[�^�ǂݍ���
@note       �w��t�@�C���̃o�b�t�@�[�Ǎ��A�͈͔���
@param[out] readBuffer  �ǂݍ��񂾃f�[�^�̕ۑ���ƂȂ�o�b�t�@�ւ̃|�C���^
@param[in]  readSize  �ǂݍ��ރo�C�g��
@return     (���͈́Ftrue�@�͈͊O�Ffalse)
@attention  �Ȃ�
------------------------------------------------------------------------------*/
bool BinaryFileDao::readData(void* readBuffer, int readSize)
{
    if( tmbFile_.Read(readBuffer, readSize) == readSize ){
        return true;
    }
    else
    {
        return false;
    }
}

/*!-----------------------------------------------------------------------------
@fn         �I�[�v���ς݂̃t�@�C�����N���[�Y����
@brief      �t�@�C���N���[�Y
@param      �Ȃ�
@return     �Ȃ�
@attention  �Ȃ�
@detail     �I�[�v���ς݂̃t�@�C�����N���[�Y����
------------------------------------------------------------------------------*/
void BinaryFileDao::close()
{
    if( tmbFile_.m_hFile != CFile::hFileNull) tmbFile_.Close();
}

/*!-----------------------------------------------------------------------------
@fn         ���݂̃|�C���^�̈ʒu��Ԃ�
@brief      �|�C���^�ʒu��Ԃ�
@param      �Ȃ�
@return     �|�C���^�̈ʒu
@attention  �Ȃ�
@detail     �f�[�^��ǂݍ��ދN�_�ƂȂ�|�C���^�ʒu��Ԃ�
------------------------------------------------------------------------------*/
ULONGLONG BinaryFileDao::getPosition()
{
    return tmbFile_.GetPosition();
}

/*!-----------------------------------------------------------------------------
@fn         �t�@�C���T�C�Y���擾����
@param      �Ȃ�
@return     �Ȃ�
@attention  �t�@�C���T�C�Y[byte]
@detail     �I�[�v���ς݂̃t�@�C���T�C�Y���擾���܂�
------------------------------------------------------------------------------*/
ULONGLONG BinaryFileDao::getFileSize()
{
    return tmbFile_.GetLength();
}