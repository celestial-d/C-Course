//name Zhang Duo
//implement

///////////////////////////////////////////////////////////////////////
// Class NodeSLList Implementation
//
// Description - This file implements a singly linked list.
///////////////////////////////////////////////////////////////////////
#include "NodeSLList.h"


///////////////////////////////////////////////////////////////////////
// default constructor
///////////////////////////////////////////////////////////////////////
NodeSLList::NodeSLList()
{ 
	head = tail = 0;
}

///////////////////////////////////////////////////////////////////////
// copy constructor
///////////////////////////////////////////////////////////////////////
NodeSLList::NodeSLList(NodeSLList & list)
{ 
	//initialize the new head and the new tail
	//then get the list
	head = tail = 0;
	IntNode *temp = list.head;
	//when not to the end of the list
	while (temp != NULL)
	{
		//initialize each new node
		IntNode *tempNew = new IntNode();
		//add each date of original list to the new list
		this->AddToTail(*temp);
		//move to the next node
		temp = temp->next;
	}
}

///////////////////////////////////////////////////////////////////////
// destructor
///////////////////////////////////////////////////////////////////////
NodeSLList::~NodeSLList()
{
	// call destroyList() to remove all nodes
	// and reset linked list
	DestroyList();
}

///////////////////////////////////////////////////////////////////////
// IsEmpty
///////////////////////////////////////////////////////////////////////
bool NodeSLList::IsEmpty()
{ 
	// if head is NULL, then the list is empty, and we will return true
	// otherwise, we will return false
	return (head == 0); 
}

///////////////////////////////////////////////////////////////////////
// GetSize
///////////////////////////////////////////////////////////////////////
int NodeSLList::GetSize()
{
	// check to see if the list is empty. if 
	// so, just return 0
	if ( IsEmpty() ) return 0;

	int size = 1;
	IntNode *p = head;
	// compute the number of nodes and return
	while (p != tail)
	{
		// until we reach the tail, keep counting
		size++;
		p = p->next;
	}
	return size;
}

///////////////////////////////////////////////////////////////////////
// AddToHead
///////////////////////////////////////////////////////////////////////
void NodeSLList::AddToHead(const IntNode & node)
{
	// create a new node, and make it the head. the 
	// previous head will become head->next
	IntNode * next = head;
	head = new IntNode;
	head->next = next;
	head->data = node.data;

	// if this is the first node, make the tail the 
	// same as the head
	if (tail == 0)
		tail = head;
}

///////////////////////////////////////////////////////////////////////
// DeleteFromHead
///////////////////////////////////////////////////////////////////////
IntNode NodeSLList::DeleteFromHead()
{
	IntNode temp;
	temp.data=0;
	temp.next=NULL;
	if (IsEmpty())
	{
		cout << "*****ERROR: Can't delete from head. List is Empty" << endl;
		return temp;
	}

	// get current value of node we are about to delete, 
	// so we can return it.
	temp.data = head->data;

	IntNode *tmp = head;

	// if there is only one node, set the head and pointer tails
	// to NULL (0)
	if (head == tail)
		head = tail = 0;

	// otherwise, move the head pointer to the next node 
	// in the list
	else
		head = head->next;

	// delete head node
	delete tmp;

	// return value of node that was deleted
	return temp;
}

///////////////////////////////////////////////////////////////////////
// AddToTail
///////////////////////////////////////////////////////////////////////
void NodeSLList::AddToTail(const IntNode & node)
{

		IntNode *p = new IntNode;
		p->data = node.data;
		p->next = NULL;
		if (tail == 0)
		{
			head = p;
		}
		else
		{
			tail->next = p;
		}
		tail = p;
}

///////////////////////////////////////////////////////////////////////
// DeleteFromTail
///////////////////////////////////////////////////////////////////////
IntNode NodeSLList::DeleteFromTail()
{
	IntNode nodeData;

	// get the current data at the tail
	nodeData.data = tail->data;


	// if there is only one node, delete the only node, and set the 
	// head and tail pointers to NULL (0) 
	if (head == tail)
	{
		delete head;
		head = tail =0;
	}

	// otherwise, traverse to the tail node and delete it
	else
	{
		IntNode * temp;
		// traverse to tail pointer
		for (temp = head; temp->next != tail; temp = temp->next);
		delete tail;
		tail = temp;
		tail->next = 0;
	}

	return nodeData;
}


///////////////////////////////////////////////////////////////////////
// DeleteNode
///////////////////////////////////////////////////////////////////////
IntNode NodeSLList::DeleteNode(int nodeNum)
{
	if (nodeNum <= 0) nodeNum = 1;
	IntNode *prev=head , *temp=head;
	IntNode current;

	// traverse to the node
	for (int loop=1; loop<nodeNum; loop++)
	{
		prev=temp, temp=temp->next;
		// check for case where nodeNum is > the number of 
		// nodes in the list. if we reach the tail before
		// we traverse to the node, delete the tail 
		if ( temp == tail )
			return DeleteFromTail();
	}

	// if deleting the head just call 
	// the appropriate member function 
	// and don't repeat that logic here
	if (temp == head) return DeleteFromHead();

	// otherwise, delete the node we traversed to
	prev->next = temp->next;
	current.data = temp->data;

	delete temp;

	return current;
}

///////////////////////////////////////////////////////////////////////
// InsertNode
///////////////////////////////////////////////////////////////////////
void NodeSLList::InsertNode(int nodeNum, const IntNode &node)
{
	IntNode *p;//use to find node
	IntNode *q;//use to find node
	p = head;//from head
	q = p;
	for (int i = 1; i < nodeNum; i++)
	{
		p = q;
		q = q->next;//find the nrd location 
		if (q == 0)
		{
			AddToTail(node);//if the number is the last node
		}
		
	}
	if (q == head)//if the number is the 1st
	{
		AddToHead(node);
	}

	IntNode *a = new IntNode;
	a->data = node.data;//insert node
	a->next = q;//insert node
	p->next = a;

}


///////////////////////////////////////////////////////////////////////
// UpdateNode
///////////////////////////////////////////////////////////////////////
void NodeSLList::UpdateNode(int nodeNum, const IntNode &node)
{
	IntNode *tmp = head;

	// traverse to the node, or to the last node, whichever comes
	// first. if the last node is reached, then that is the node
	// that is updated
	for (int i=1; i< nodeNum && tmp != tail; i++)
		tmp = tmp->next;

	tmp->data = node.data;
}

///////////////////////////////////////////////////////////////////////
// SortList
///////////////////////////////////////////////////////////////////////
void NodeSLList::SortList(unsigned int order)
{
	/*//initialize two new node to capture the node in the list
	IntNode *middle1 = new IntNode();
	IntNode *middle2 = new IntNode();
	//get the size of the list
	int n = this->GetSize();
	//ascending
	if (order == 1)
	{
		// traverse the whole list
		// and compare each two node
		for (int i = 0; i < n; i++)
		{
			*middle1 = RetrieveNode(i);
			for (int j = i + 0; j < n + 1; j++)
			{
				*middle2 = RetrieveNode(j);
				
				if (middle1->data >= middle2->data)
				{
					DeleteNode(j);
					InsertNode(i, *middle2);
					*middle1 = RetrieveNode(i);
				}
			}
		}
	}
	//descending
	if (order == 2)
	{
		for (int i = 1; i < n; i++)
		{
			*middle1 = RetrieveNode(i);
			for (int j = i + 1; j < n + 1; j++)
			{
				*middle2 = RetrieveNode(j);
				//if the back node is bigger than the previous node
				//then use the DeleteNode method to delete last node from the old position
				//and use the InsertNode method to insert it to the new position
				//this function do not just swap the value but update the next pointer
				if (middle1->data <= middle2->data)
				{
					DeleteNode(j);
					InsertNode(i, *middle2);
					*middle1 = RetrieveNode(i);
				}
			}
		}
	}*/
	IntNode temp1;
	IntNode temp2;
	int temp;
	for (int i = 0; i < GetSize(); i++)
	{
		for (int j = 0; j < GetSize(); j++)
		{
			if (order == 1)
			{
				if (RetrieveNode(i).data>= RetrieveNode(i+1).data)
				{
					temp1 = RetrieveNode(i);
					temp2 = RetrieveNode(i + 1);
					temp = temp1.data;
					temp1.data = RetrieveNode(i + 1).data;
					temp2.data = RetrieveNode(i).data;
					
				}
			}
				
		}
	}
}

///////////////////////////////////////////////////////////////////////
// DestroyList
///////////////////////////////////////////////////////////////////////
void NodeSLList::DestroyList()
{
	// while the list is NOT empy
	// keep removing the head node and make
	// the next node the head node
	for (IntNode *p; !IsEmpty(); )
	{
		p = head->next;
		delete head;
		head = p;
	}
	head = tail = 0;
}

///////////////////////////////////////////////////////////////////////
// operator=
///////////////////////////////////////////////////////////////////////
NodeSLList & NodeSLList::operator=(NodeSLList & list)
{
	/*this->DestroyList();
	IntNode *p;
	if (list.head != 0)
	{
		for (p = list.head; p != 0; p = p->next)//give every value
		{
			IntNode next;
			next.data = p->data;
			next.next = p->next;
			this->AddToTail(next);
		}
	}
	return *this;*/
	IntNode *p1;
	IntNode *p2 = list.head;
	for (p1 = head; p1 != 0; p1 = p1->next, p2 = p2->next)
	{
		p1->data = p2->data;
	}
	return list;
}

///////////////////////////////////////////////////////////////////////
// operator==
///////////////////////////////////////////////////////////////////////
bool NodeSLList::operator==(NodeSLList & list)
{
	if (GetSize() != list.GetSize())
	{
		return false;//if size is unsuitbale false
	}
	IntNode *p1;
	IntNode *p2 = list.head;
	for (p1 = head; p1!= 0; p1 = p1->next, p2 = p2->next)
	{
		if (p1->data != p2->data)
		{
			return false;//if data is unsuitbale false
		}
	}
	return true;
}

///////////////////////////////////////////////////////////////////////
// operator!=
///////////////////////////////////////////////////////////////////////
bool NodeSLList::operator!=(NodeSLList & list)
{
	if (GetSize() != list.GetSize())
	{
		return true;//if size is unsuitbale true
	}
	IntNode * p1;
	IntNode * p2 = list.head;
	for (p1 = head; p1 != 0; p1 = p1->next, p2 = p2->next)
	{
		if (p1->data != p2->data)
		{
			return true;//if data is unsuitbale true
		}
	}
	return false;
}

///////////////////////////////////////////////////////////////////////
// operator+
///////////////////////////////////////////////////////////////////////
NodeSLList NodeSLList::operator+(NodeSLList & list)
{
	NodeSLList q = *this;
	IntNode * p;
	
	if (list.head != 0)
	{
		for (p = list.head; p != 0; p = p->next)
		{
			IntNode next;//get value
			next.data = p->data;//give value
			next.next = p->next;
			q.AddToTail(next);//add value
		}
	}
	return q;
}


///////////////////////////////////////////////////////////////////////
// RetrieveNode
// 
// Description: retrieve data from a node without removing it from 
//              the list
// Input: node number (1-N; not 0-N-1)
// Output: none
// Returns: reference to node data
///////////////////////////////////////////////////////////////////////
IntNode & NodeSLList::RetrieveNode(int nodeNum) const
{
	IntNode *tmp = head;

	// traverse to the node, or to the last node, whichever comes
	// first
	for (int i=1; i< nodeNum && tmp != tail; i++)
		tmp = tmp->next;

	return *tmp;
}

ostream & operator<<(ostream & output, NodeSLList & list)
{
	IntNode *p;
	for (p = list.head; p != 0; p = p->next)
	{
		output << p->data << " ";
	}
	output << endl << endl;
	return output;
}


