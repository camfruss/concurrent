export module concurrent.lockbased.queue;

import queue.interface;
import <mutex>;
import <queue>;


export namespace concurrent::lockbased 
{

	template <typename T>
	class queue : public concurrent::queue<T>
	{
		public:
			T& front() const override; 
			T& back() const override;
			
			bool empty() const override;
			std::size_t size() const override;

			void push(const T& value) override;
			void push(T&& value) override;

			void pop() override;

			void swap(queue& other) noexcept override;
		private:
			std::queue<T> m_queue;
			std::mutex m_mutex;		
	};

}
