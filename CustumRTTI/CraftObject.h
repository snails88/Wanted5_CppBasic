#pragma once
#include <memory>

// 커스텀 RTTI를 제공하는 기반 클래스
class CraftObject
{
public:
	virtual size_t GetType() const = 0;

	// 여기까지 올라오면 다른 타입
	virtual bool Is(size_t id) const
	{
		return false;
	}

	template<typename T>
	bool IsTypeOf() const
	{
		return Is(T::TypeId());
	}
};

// 스마트 포인터 형변환함수
template<typename T, typename U>
std::shared_ptr<T> Cast(const std::shared_ptr<U> object)
{
	if (!object)
	{
		return nullptr;
	}

	if (object->Is(T::TypeId()))
	{
		return std::static_pointer_cast<T>(object);
	}

	return nullptr;
}

#define TYPE_DECLARATIONS(Type, ParentType)							\
	using super = ParentType;										\
protected:															\
	static size_t TypeIdClass()										\
	{																\
		static int runTimeTypeId = 0;								\
		return reinterpret_cast<size_t>(&runTimeTypeId);			\
	}																\
public:																\
	static size_t TypeId()											\
	{																\
		return Type::TypeIdClass();									\
	}																\
	virtual size_t GetType() const override							\
	{																\
		return Type::TypeIdClass();									\
	}																\
	virtual bool Is(size_t id) const override						\
	{																\
		return (id == TypeIdClass()) ? true : ParentType::Is(id);	\
	}																