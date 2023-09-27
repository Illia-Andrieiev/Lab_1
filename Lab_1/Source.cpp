#include "Graf.cpp"
#include "Tree.cpp"
#include "ArrayList.cpp"
using namespace std;
int main() {
	List<int> *ar = new ArrayList<int>();
	ar->pushBack(2);
	ar->pushBack(4);
	ar->pushBack(6);
	ar->pushBack(8);
	int edges[] = { 0,1,0,2,3,4,0,4,1,2,1,3,1,4,2,3,2,4,};
	//cout  << endl << ar->size() << endl;
	ar->pushIndex(3, 3);
	//int res = ar->removeIndex(2);
	//cout << res << endl;
	ar->print();
	//cout << endl << ar->size() << endl;
	//List<int>* copy = new ArrayList<int>();
	//copy->addAll(ar);
	//copy->print();
	Graf<int>* graf = new Graf<int>(ar);
	graf->addEdges(edges, 18);
	graf->print();
	//dddar->print();
	//cout << graf->containsEdge(&edges[18]) << endl;
	//List<Graf<int>*>* comp = graf->findConnectionComponent();
	//cout << comp->size() << endl;
	//for (int i = 0; i < comp->size(); i++) {
	//	comp->get(i)->print();
	//	//cout << comp->get(i)->vertexAmount()<< endl;
	//}
	cout << endl<< graf->isConnectedVertex(0,1)<< endl;
	Graf<int>* ostTree = graf->findOstTree();
	ostTree->print();
	//cout << graf->nomerOfVertex(84) << endl;
	//Tree<int>* tree = new Tree<int>(ar, 2);
	//tree->print();
	//cout << endl;
	//ar->print();

	system("pause");
	return 0;
}