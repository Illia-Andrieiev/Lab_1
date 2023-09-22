
template<typename T>
class ListNode
{
private:
	T data;
	ListNode<T> *next;
public:
	ListNode(T data, ListNode<T>* next);
};

