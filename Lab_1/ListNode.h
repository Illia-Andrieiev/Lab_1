template<typename T>
class ListNode
{
public:
	T data;
	ListNode<T>* next;
	ListNode(T data, ListNode<T>* next) {
		this->data = data;
		this->next = next;
	}
};