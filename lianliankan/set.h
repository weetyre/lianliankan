#pragma once
class set :public CPtrArray
{
	DECLARE_SERIAL(set)//序列化第一步
public:
	set();
	~set();
	void Serialize(CArchive& ar);
};

