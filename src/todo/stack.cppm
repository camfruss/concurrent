export module stack;

import <atomic>;
import <memory>;
import <optional>;


export namespace concurrent
{

	/**
	 * An unbounded lock-free stack. 
	 */
	template<typename T>
	class stack 
	{
		private:
			struct Node
			{
				Node(const T& value) : m_nextNode { nullptr }, m_nodeValue { value } 
				{
				};

				std::unique_ptr<Node> m_nextNode;
				T m_nodeValue;
			};

		public: 
			stack() = default;
			~stack() = default;

			stack(const stack& rhs) = delete;  // delete copy ctor
			stack& operator=(const stack& rhs) = delete;  // delete copy assignment

			/**
			 * @return The topmost element in the stack if non-empty, otherwise std::nullopt
			 */
			std::optional<T> top() const;

			/**
			 * @return True if the stack is empty. False otherwise. 
			 */
			bool empty() const;

			/**
			 * @return An approximation of the number of elements in the stack. 
			 */
			std::size_t size() const;

			/**
			 * @param value
			 */
			void push(const T& value);

			/**
			 * @param value
			 */
			void push(T&& value);

			/**
			 * Removes the topmost element from the stack. 
			 */
			void pop();

			/**
			 * Swaps the contents of the stack with other.
			 * @param other 
			 */
			void swap(stack& other) noexcept;

		private:
			std::unique_ptr<Node> m_head;
			atomic<std::size_t> m_size;
	}

}
