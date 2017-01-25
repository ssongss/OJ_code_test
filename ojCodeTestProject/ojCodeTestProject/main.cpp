#include <iostream>
#include <string>
struct ListNode
{
	int       m_nKey;
	ListNode* m_pNext;
};

using namespace std;
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	if (pListHead == nullptr)
		return nullptr;
	ListNode *slow = pListHead;
	ListNode *fast = pListHead;

	for (unsigned int i = 0; i < k; i++)
	{
		if (fast->m_pNext == nullptr)
		{
			return nullptr;
		}

		fast = fast->m_pNext;
	}

	while (fast->m_pNext != nullptr)
	{
		slow = slow->m_pNext;
		fast = fast->m_pNext;
	}

	return slow;
}
int main()
{
	ListNode *pHead = new ListNode;
	ListNode *pCurNode = pHead;
	unsigned int k;
	unsigned int num;
	cin >> num;

	while (num--)
	{
		int tempValue;
		cin >> tempValue;
		pCurNode->m_nKey = tempValue;
		pCurNode->m_pNext = nullptr;
		ListNode *pTempNode= new ListNode;
		pTempNode->m_pNext = nullptr;
		pCurNode->m_pNext = pTempNode;
		pCurNode = pTempNode;
	}

	cin >> k;
	ListNode * res = FindKthToTail(pHead, k+1);
	if (res == nullptr)
		return 0;
	cout << res->m_nKey << endl;


	return 0;
}