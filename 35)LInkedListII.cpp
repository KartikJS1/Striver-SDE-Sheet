Node *firstNode(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;
    Node *entry = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            while (slow != entry)
            {
                slow = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return NULL;
}