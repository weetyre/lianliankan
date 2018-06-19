#include "stdafx.h"
#include "set.h"

IMPLEMENT_SERIAL(set, CPtrArray, 1)//序列化第一步

set::set()
{
}


set::~set()
{
}

void set::Serialize(CArchive & ar)
{
	CObject::Serialize(ar);
	//关键代码  
	if (ar.IsStoring()) {
		//序列化  
		ar << m_nSize << m_nMaxSize << m_nGrowBy;
		
	}
	else {
		//反序列化  
		//ar >> *(*(this->m_pData));
		ar >> m_nSize >>m_nMaxSize >> m_nGrowBy;
	}
}
