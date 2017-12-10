#pragma once
#include "FileDaoFactory.h"
class TextFileDaoFactory :
	public FileDaoFactory
{
public:
	TextFileDaoFactory();
	virtual ~TextFileDaoFactory();
};

