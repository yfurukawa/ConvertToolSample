#pragma once
class FileName
{
public:
	FileName();
	virtual ~FileName();
	CString fileNameWithPath();

protected:
	CString fileName_; //!< パスを含めたファイル名
};

