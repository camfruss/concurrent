export module queue.interface;

import <cstddef>;
import <initializer_list>;


export namespace concurrent 
{

	/*!
 	*  An unbounded queue abstract class 
	*/
	template <typename T>
	class queue 
	{
		public:
			queue() = default;
			virtual ~queue() = default;

			virtual T& front() const = 0; 
			virtual T& back() const = 0;
			
			virtual bool empty() const = 0;
			virtual std::size_t size() const = 0;

			virtual void push(const T& value) = 0;
			virtual void push(T&& value) = 0;

			void push_range(std::initializer_list<T> range)
			{
			}

			template<typename ...Args>
			void emplace(Args&& ...args) 
			{
			}

			template<typename Range>
			void emplace_range(Range&& range)
			{
			}

			virtual void pop() = 0;

			virtual void swap(queue& other) noexcept = 0;
	};

}
