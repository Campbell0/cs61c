#include <stddef.h>
#include "ex10_ll_cycle.h"

int ll_has_cycle(node *head) {
    if(head == NULL) return 0;
    node* fast_ptr = head;
    node* slow_ptr = head;
    while (fast_ptr != NULL) {
        fast_ptr = fast_ptr->next;
        if(fast_ptr != NULL) {
            fast_ptr = fast_ptr->next;
        }
        else {
            return 0;
        }
        if(fast_ptr == NULL) {
            return 0;
        }
        slow_ptr = slow_ptr->next;
        if (fast_ptr == slow_ptr)
        {
            return 1;
        }
    }
    return 0;
}
