module concurrent.rwlock;


template<typename T>
template<typename ...Args>
concurrent::rwlock<T>::rwlock(Args&& ...args) : m_data { std::forward<Args>(args)... }
{
}

template<typename T>
concurrent::rwlock<T>::rwlock(T&& data) noexcept : m_data { std::move(data) }
{
}

template<typename T>
template<typename F, typename ...Args>
auto concurrent::rwlock<T>::read(F&& func, Args&& ...args) const 
{
	std::shared_lock lock { m_mutex };
	return std::invoke(std::forward<F>(func), m_data, std::forward<Args>(args)...);
}

template<typename T>
template<typename F, typename ...Args>
auto concurrent::rwlock<T>::write(F&& func, Args&& ...args) 
{
	std::unique_lock lock { m_mutex };
	return std::invoke(std::forward<F>(func), m_data, std::forward<Args>(args)...);
}

