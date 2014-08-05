
template <class T> 
class SmartPtr
{
public:
		SmartPtr(T *p = 0);
		~SmartPtr();

		SmartPtr(const SmartPtr<T>& sp);
		SmartPtr<T>& operator=(const SmartPtr<T>& sp);
		
		T* operator->() const;
		T& operator*() const;
		operator T*() const;

private:
		void AddRef();
		void Release();

		T* m_pRef;
		unsigned int* m_pRefCount;
};


template <class T> 
SmartPtr<T>::SmartPtr(T *p) : m_pRef(p), m_pRefCount(0)
{
		AddRef();
}

template <class T> 
SmartPtr<T>::~SmartPtr()
{
		Release();
}

template <class T> 
SmartPtr<T>::SmartPtr(const SmartPtr<T>& sp)
{
		m_pRef = sp.m_pRef;
		m_pRefCount = sp.m_pRefCount;
		AddRef();
}

template <class T> 
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T>& sp)
{
		if(*this != sp){
				Release();
				m_pRef = sp.m_pRef;
				m_pRefCount = sp.m_pRefCount;
				AddRef();
		}

		return this;
}

template <class T> 
T* SmartPtr<T>::operator->() const
{
		return m_pRef;
}

template <class T> 
T& SmartPtr<T>::operator*() const
{
		return *m_pRef;
}

template <class T> 
SmartPtr<T>::operator() const
{
		return m_pRef;
}

template <class T> 
void SmartPtr<T>::AddRef()
{
		if(0 == m_pRef)
				return;
		if(0 == m_pRefCount){
				m_pRefCount = new unsigned int(0);
		}
		(*m_pRefCount)++;
}

template <class T> 
void SmartPtr<T>::Release()
{
		if(0 ==  m_pRefCount)
				return;

		if(--(*m_pRefCount) == 0){
				delete m_pRef;
				delete m_pRefCount;
		}
}


