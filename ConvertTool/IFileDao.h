#pragma once

class FileName;

class IFileDao
{
public:
	IFileDao() {};
	virtual ~IFileDao() {};
	virtual bool openReadOnly(FileName* fileName) = 0;
	virtual void close() = 0;
};

