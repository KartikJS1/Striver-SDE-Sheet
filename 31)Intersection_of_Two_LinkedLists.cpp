int findIntersection(Node *headA, Node *headB)
{
    if (headA == NULL || headB == NULL)
        return NULL;

    Node *a = headA;
    Node *b = headB;

    // if a and b have different len, then we will stop the loop after second iteration
    while (a != b)
    {
        // for the end of first iteration, we just reset the pointer to the head of another linkedlist
        a = a == NULL ? headB : a->next;
        b = b == NULL ? headA : b->next;
    }
    return a;
}
