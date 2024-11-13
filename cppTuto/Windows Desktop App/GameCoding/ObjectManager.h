#pragma once

class Object;

class ObjectManager
{
public:
	DECLARE_SINGLE(ObjectManager);

	~ObjectManager();

	void Add(Object* object);
	void Remove(Object* object);
	void Clear();

	const vector<Object*>& GetObjects() { return _objects; }

	template<typename T>
	T* CreateObject() {
		// type trait T가 Object Type이어야 한다면 아래 코드 (C#의 Where 같은)
		static_assert(std::is_convertible_v<T*, Object*>);

		T* object = new T();
		object->Init();

		return object;
	}

private:
	vector<Object*>_objects;
};

