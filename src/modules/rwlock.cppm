export module concurrent.rwlock;

import <mutex>;
import <shared_mutex>;
import <utility>;


namespace concurrent
{
	
	template<typename T>
	class rwlock
	{
		public:
			template<typename ...Args>
			explicit rwlock(Args&& ...args);
			explicit rwlock(T&& data) noexcept;
			
			rwlock(const rwlock&) = delete;
			rwlock& operator=(const rwlock&) = delete;

			template<typename F, typename ...Args>
			auto read(F&& func, Args&& ...args) const;

			template<typename F, typename ...Args>
			auto write(F&& func, Args&& ...args);
		private:
			std::shared_mutex m_mutex; 
			T m_data;
	};

}

