#include <iostream>
#include <vector>
#include <iterator>

static bool flag_heapify = true;

template <typename T>
void Swap(T& node, T& parent)
{
	T temp = node;
	node = parent;
	parent = temp;
}


template <typename T>
bool Compare(const T &node, const T &parent)
{
	if (node > parent)
		return true;
	else
		return false;
}


template <typename T>
void Heapify(std::vector<T>& array, const int &index)
{
	// offset by 1 due to 0-indexing of c++
	int index_current = index - 1;
	int index_parent = (index - 1) / 2;

	if (index_current < 1) return;

	if(Compare(array[index_current], array[index_parent]))
	{
		// if true, then execute the following
		Swap(array[index_current], array[index_parent]);
		Heapify(array, index_parent+1);
	}
	
}


template <typename T>
void Print(std::vector<T> &array)
{
	for (typename std::vector<T>::iterator itr = array.begin(); itr != array.end(); itr++)
	{
		std::cout << *itr << "  ";
	}
	puts("");
}

int main(void)
{
	std::vector<int> array = { 10, 8, 8, 7, 6, 5, 4, 3, 12 };
	Print(array);



	Heapify(array, array.size());
	Print(array);
}