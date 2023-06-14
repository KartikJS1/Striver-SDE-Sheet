LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    if (head == NULL)
        return head;
    LinkedListNode<int> *newhead = new LinkedListNode<int>(0);
    LinkedListNode<int> *new_curr = newhead;
    LinkedListNode<int> *curr = head;
    unordered_map<LinkedListNode<int> *, LinkedListNode<int> *> umap;
    while (curr)
    {
        LinkedListNode<int> *temp = new LinkedListNode<int>(curr->data);
        umap.insert({curr, temp});

        new_curr->next = temp;
        new_curr = new_curr->next;
        curr = curr->next;
    }
    curr = head;
    new_curr = newhead->next;

    while (curr)
    {
        LinkedListNode<int> *random = curr->random;
        LinkedListNode<int> *newnode = umap[random];
        new_curr->random = newnode;

        new_curr = new_curr->next;
        curr = curr->next;
    }

    return newhead->next;
}