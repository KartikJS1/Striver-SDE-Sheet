
Node *rotate(Node *head, int k)
{
    // edge cases
    if (!head || !head->next || k == 0)
        return head;

    // compute the length
    Node *curr = head;
    int len = 1;
    while (curr->next && ++len)
    {
        curr = curr->next;
    }

    // go till that node
    curr->next = head;
    k = k % len;
    k = len - k;
    while (k--)
        curr = curr->next;

    // make the node head and break connection
    head = curr->next;
    curr->next = NULL;

    return head;
}