#pragma once
#include "FileDaoFactory.h"
class BinaryFileDaoFactory :
	public FileDaoFactory
{
public:
	BinaryFileDaoFactory();
	virtual ~BinaryFileDaoFactory();
};

