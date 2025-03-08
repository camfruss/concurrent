module concurrent.lockbased.queue;


namespace concurrent::lockbased {

	template <typename T>
	T& queue<T>::front() const
	{
	}
	
	template <typename T>
	T& queue<T>::back() const
	{
	}
	
	template <typename T>
	bool queue<T>::empty() const
	{
	}
	
	template <typename T>
	std::size_t queue<T>::size() const
	{
	}
	
	template <typename T>
	void queue<T>::push(const T& value)
	{
	}
	
	template <typename T>
	void queue<T>::push(T&& value)
	{
	}
	
	template <typename T>
	void queue<T>::pop()
	{
	}
	
	template <typename T>
	void queue<T>::swap(queue& other) noexcept
	{
	}

}

