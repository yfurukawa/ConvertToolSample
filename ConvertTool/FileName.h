#pragma once
class FileName
{
public:
	FileName();
	virtual ~FileName();
	CString fileNameWithPath();

protected:
	CString fileName_; //!< �p�X���܂߂��t�@�C����
};

