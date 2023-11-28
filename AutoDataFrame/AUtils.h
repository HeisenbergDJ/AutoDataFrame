#pragma once
//类参数声明
#define CLASS_VAR_DECLEAR(VAR_TYPE,VAR_NAME) CLASS_VAR_DECLEAR_HELPER(VAR_TYPE,VAR_NAME)

#define CLASS_VAR_DECLEAR_HELPER(VAR_TYPE,VAR_NAME) \
private:\
	VAR_TYPE m##VAR_NAME;\
public:\
	inline void Set##VAR_NAME(VAR_TYPE VAR_NAME##_) \
	{m##VAR_NAME = VAR_NAME##_;}\
	inline VAR_TYPE Get##VAR_NAME(void)\
	{return m##VAR_NAME;}\
	inline VAR_TYPE* Get##VAR_NAME##Addr(void)\
	{return &m##VAR_NAME;}