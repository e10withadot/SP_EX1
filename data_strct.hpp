// ey.gellis@gmail.com
#ifndef DATA_STRCT_HPP
#define DATA_STRCT_HPP
namespace data {
	template<class K>
	class list_item {
		private:
			K value;
			bool empty;
		public:
			list_item() : empty(true) {};
			K get();
			void set(K value);
			bool isEmpty();
			void erase();
	};
	template<class T>
	class list {
		private:
			list_item<T>* arr;
			int size;
		public:
			list() : arr(new list_item<T>[1]), size(1) {};
			list(int init_size) : arr(new list_item<T>[init_size]), size(init_size) {};
			list(const list<T> &other) : arr(new list_item<T>[other.size]), size(other.size) {
				for (int i = 0; i < this->size; i++) {
					arr[i].set(other.arr[i].get());
				}
			}
			~list() { delete [] arr; }
			int getSize();
			T get(int index);
			void set(int index, T value);
			void push(T value);
			T pop();
			void remove(int index);
			bool empty();
	};
}

#endif
