// ey.gellis@gmail.com
#ifndef DATA_STRCT_HPP
#define DATA_STRCT_HPP
namespace data {
	template<class T>
	class list {
		private:
			T* arr;
		public:
			int size;
			list() : arr(new T[1]), size(1) {};
			list(int init_size) : arr(new T[init_size]), size(init_size) {};
			list(T arr[]);
			~list() { delete [] arr; }
			T get(int index);
			void set(int index, T value);
			void push(T value);
			T pop();
			void remove(int index);
			bool empty();
	};
}

#endif
