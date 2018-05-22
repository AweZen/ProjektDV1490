#pragma once

template<typename T>
class List
{
private:
	// for you to specify   
	class Node
	{
	public:
		T element;
		Node * next;
		Node(T element, Node* next)
		{
			this->element = element;
			this->next = next;
		};
		~Node()
		{
			//döda _next
		};
	};
	Node * first;
	int nrOf;
public:
	List();
	virtual ~List();
	List(const List& other);
	List& operator=(const List& other);
	void insertAt(int pos, const T& element) throw(...);	// placerar element på den positionen pos. Undantag ska kastas om pos är orimlig. 
	T getAt(int pos) const throw(...);						//returnerar en kopia på det element som finns på position pos. Undantag ska kastas om pos är orimlig
	void removeAt(int pos) throw(...);						// tar bort det element som finns på pos. Undantag ska kastas om pos är orimlig. 
	bool removeElement(const T& element);					//tar bort element om det finns i listan, returnerar sant om borttagning genomförst och falskt annars 
	bool findElement(const T& toFind) const;				//returnerar sant om toFind finns i listan och falskt annars. 
	int length() const;										//returnerar antalet element som finns i listan 
	void getAll(T arr[], int cap) throw(...);	//om kapaciteten cap på arrayen är tillräcklig fylls arrayen arr med kopior av elementen i listan 
												//i samma ordning som dessa är placerade i listan.
												//Undantag ska kastas om kapaciteten cap inte är tillräcklig.
};

template<typename T>
List<T>::List()
{
	this->first = nullptr;
	this->nrOf = 0;
}

template<typename T>
List<T>::~List()
{
	for (int i = this->nrOf-1; i >= 0; i--) {
		removeAt(i);
	}
}

template<typename T>
List<T>::List(const List & other)
{
	this->first = nullptr;
	Node * walker = this->first;
	this->nrOf = 0;

	for (int i = 0; i < other.length(); i++)
	{
		insertAt(i, other.getAt(i));
	}
}

template<typename T>
List<T> & List<T>::operator=(const List<T> & other)
{
	if (this != &other) {
		for (int i = this->nrOf; i > 0; i--) {
			Node * walker = this->first;
			for (int j = 0; j < i; j++) {
				walker = walker->next;
			}
			delete walker;
			this->nrOf--;
		}
		T element;
		this->first = nullptr;
		this->nrOf = 0;
		Node * walker = this->first;


		for (int i = 0; i < other.length(); i++)
		{
			insertAt(i, other.getAt(i));

		}
		return *this;
	}
}

template<typename T>
void List<T>::insertAt(int pos, const T & element) throw(...)
{
	if (pos< 0 || pos> this->nrOf)
	{
		throw "Warning! The position you picked is not on the list!";
	}
	if (pos == 0)
	{
		Node * newElement = new Node(element, this->first);
		newElement->next = this->first;
		this->first = newElement;
	}
	else
	{
		Node * walker = this->first;
		for (int i = 0; i < pos - 1; i++)
		{
			walker = walker->next;
		}
		Node * newElement = new Node(element, walker->next);
		newElement->next = walker->next;
		walker->next = newElement;
	}
	this->nrOf++;
}

template<typename T>
T List<T>::getAt(int pos) const throw(...)
{
	T element;
	Node * walker = this->first;
	if (pos< 0 || pos> this->nrOf)
	{
		throw "Warning! The position you picked is not on the list!";
	}
	else if (this->nrOf == 0)
	{
		throw "Warning! Queue is empty!";
	}
	for (int i = 0; i < pos; i++)
	{
		walker = walker->next;
	}
	element = walker->element;
	return element;
}

template<typename T>
void List<T>::removeAt(int pos) throw(...)
{
	Node * toRemove;

	Node * walker = this->first;
	if (pos< 0 || pos> this->nrOf)
	{
		throw "Warning! The position you picked is not on the list!";
	}
	else if (this->nrOf == 0)
	{
		throw "Warning! Queue is empty!";
	}
	if (pos == 0) {
		toRemove = first;
		this->first = first->next;
		delete toRemove;
	}
	else {
		for (int i = 0; i < pos - 1; i++)
		{
			walker = walker->next;
		}
		toRemove = walker->next;
		walker->next = toRemove->next;
		delete toRemove;
	}
	this->nrOf--;
}

template<typename T>
bool List<T>::removeElement(const T & element)
{
	Node * walker = this->first;
	Node * toRemove;
	bool found = false;
	bool firstElement = false;
	if (walker->element == element) {
		toRemove = walker;
		this->first = walker->next;
		delete toRemove;
		this->nrOf--;
		found = true;
		firstElement = true;
	}
	for (int i = 0; i < this->nrOf - 1 && found == false; i++)
	{
		if (walker->next->element == element) {
			found = true;
		}
		else {
			walker = walker->next;
		}
	}
	if (found == true && firstElement == false) {
		toRemove = walker->next;
		if (toRemove->next == nullptr) {
			walker->next == nullptr;
		}
		else {
			walker->next = toRemove->next;

		}
		delete toRemove;
		this->nrOf--;
	}
	return found;
}

template<typename T>
bool List<T>::findElement(const T & toFind) const
{
	bool found = false;
	Node * walker = this->first;
	if (walker->element == toFind) {
		found = true;
	}
	for (int i = 0; i < nrOf - 1 && found == false; i++)
	{
		walker = walker->next;
		if (walker->element == toFind) {
			found = true;
		}
	}

	return found;
}

template<typename T>
int List<T>::length() const
{
	return this->nrOf;
}

template<typename T>
void List<T>::getAll(T arr[], int cap) throw(...)
{
	T element;
	Node * walker = this->first;
	if (cap< this->nrOf)
	{
		throw "Cap not enough!";
	}
	for (int i = 0; i < this->nrOf; i++)
	{
		arr[i] = this->getAt(i);
	}

}
