typedef struct ListNode {
    double elem;
    int timestamp;
    struct ListNode *next;
    struct ListNode *prev;
}ListNode;

void push (ListNode **head, double x_elem, int y_stamp, int *dim) {

    ListNode *nou = (ListNode*)malloc (sizeof (ListNode));
    nou->elem = x_elem;
    nou->timestamp = y_stamp;

    nou->next = *head;
    nou->prev = NULL;

    if (*head != NULL) {
        (*head)->prev = nou;
    }

    *head = nou;
    *dim += 1;
}

void init_tail (ListNode *head, ListNode **tail) {

    while (head->next != NULL) {
        head = head->next;
    }

    *tail = head;
}

void init_lista (ListNode **head, ListNode **tail, int *dim) {

    double x_elem;
    int n, y_stamp;
    *dim = 0;
    scanf ("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf ("%d%lf", &y_stamp, &x_elem);
        push (&(*head), x_elem, y_stamp, &(*dim));
    }
    init_tail (*head, &(*tail));
}

void delete (ListNode **head, ListNode **tail, ListNode *nod, int *dim) {

    if (*head == NULL || nod == NULL) {
        return;
    }

    if (*head == nod) {
        *head = nod->next;
    }

    if (*tail == nod) {
        *tail = nod->prev;
    }

    if (nod->next != NULL) {
        nod->next->prev = nod->prev;
    }

    if (nod->prev != NULL) {
        nod->prev->next = nod->next;
    }

    *dim -= 1;
    free(nod);
}

void printl (ListNode *tail) {

    while (tail != NULL){
        printf ("%d %.02lf\n", tail->timestamp, tail->elem);
        tail = tail->prev;
    }
}

void mem_free (ListNode *head) {

    ListNode *aux;
    while (head != NULL) {
        aux = head;
        head = head->next;
        free(aux);
    }
}