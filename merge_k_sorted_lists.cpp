/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct QueueItem
{
    int elem;
    int pos;
    QueueItem(int x, int y):elem(x), pos(y){}
    bool operator <(const QueueItem& item) const
    {
        return elem > item.elem;
    }
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode * dummyNode = new ListNode(0);
        ListNode * currNode = dummyNode;
        vector<ListNode *> currHead = lists;
        priority_queue<QueueItem> p_queue;
        bool isAllNULL = true;
        for (int i = 0; i < currHead.size(); i++)
        {
            if (currHead[i] != NULL)
            {
                isAllNULL = false;
                p_queue.push(QueueItem(currHead[i] -> val, i));
            }
        }
        if (isAllNULL) return NULL;
        while(!p_queue.empty())
        {
            QueueItem frontQueue = p_queue.top();
            p_queue.pop();
            currNode -> next = new ListNode(frontQueue.elem);
            currNode = currNode -> next;
            if (currHead[frontQueue.pos] != NULL)
            {
                currHead[frontQueue.pos] = currHead[frontQueue.pos] -> next;
                if (currHead[frontQueue.pos] != NULL)
                {
                    p_queue.push(QueueItem(currHead[frontQueue.pos]->val, frontQueue.pos));
                }
            }
        }
        return dummyNode->next;
    }
};
