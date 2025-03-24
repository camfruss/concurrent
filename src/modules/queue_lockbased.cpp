module concurrent.lockbased.queue;


namespace concurrent::lockbased {

	template <typename T>
	const T& queue<T>::front() const
	{
		std::lock_guard lock { m_mutex };
		return static_cast<const T&>(m_queue.front());
	}
	
	template <typename T>
	const T& queue<T>::back() const
	{
		std::lock_guard lock { m_mutex };
		return static_cast<const T&>(m_queue.back());
	}
	
	template <typename T>
	bool queue<T>::empty() const
	{
		std::lock_guard lock { m_mutex };
		return m_queue.empty();
	}
	
	template <typename T>
	std::size_t queue<T>::size() const
	{
		std::lock_guard lock { m_mutex };
		return m_queue.size();
	}
	
	template <typename T>
	void queue<T>::push(const T& value)
	{
		std::lock_guard lock { m_mutex };
		m_queue.push(value);
	}
	
	template <typename T>
	void queue<T>::push(T&& value)
	{
		std::lock_guard lock { m_mutex };
		m_queue.push(value);
	}
	
	template <typename T>
	void queue<T>::pop()
	{
		std::lock_guard lock { m_mutex };
		m_queue.pop();
	}
	
	template <typename T>
	void queue<T>::swap(queue& other) noexcept
	{
	}

}

