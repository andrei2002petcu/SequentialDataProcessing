#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "list.c"

//################### TASK 1 ##############################

double task1_average (ListNode *x) {

    double sum = 0;
    ListNode *aux = x;

    for (int i = 1; i <= 5; i++) {
        sum = sum + aux->elem;
        aux = aux->prev;
    }
    return sum/5;
}

double task1_deviation (ListNode *x, double average) {

    double sum = 0;
    for (int i = 1; i <= 5; i++) {
        sum += (x->elem - average) * (x->elem - average);
        x = x->prev;
    }
    return sqrt (sum/5);
}

void task1 (ListNode *head, ListNode *tail, int *dim) {

    if (*dim < 5) {
        return;
    }

    double average, deviation = 1;
    ListNode *i;
    
    for (i = tail; i->prev->prev->prev != head; i = i->prev)  {
        
        average = task1_average (i);
        deviation = task1_deviation (i, average);
        
        ListNode *j = i->prev->prev;
        if (j->elem < (average - deviation) || j->elem > (average + deviation)) {
            j->timestamp = -1;
        }
    }

    for (i = head; i != tail; i = i->next) {
        if (i->timestamp == -1) {
            i = i->prev;
            delete (&head, &tail, i->next, &(*dim));
        }
    }
}

//#################### TASK 2.1 ###########################

double sort (ListNode *x) {

    ListNode *head = NULL;
    ListNode *tail = NULL;
    ListNode *i, *j;
    double aux1;
    int dim = 0;

    for (int i = 1; i <= 5; i++) {
        push (&head, x->elem, x->timestamp, &dim);
        x = x->prev;
    }
    init_tail (head, &tail);

    for (i = head; i != tail; i = i->next ) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->elem < j->elem) {
                aux1 = i->elem;
                i->elem = j->elem;
                j->elem = aux1;
            }
        }
    }

    double aux = head->next->next->elem;
    mem_free (head);
    return aux;
}

void task_2_1 (ListNode **head, ListNode **tail, int *dim) {

    ListNode *head_median = NULL;
    ListNode *tail_median = NULL;
    ListNode *i;
    int dim_median = 0;

    for (i = *tail; i->prev->prev->prev != *head; i = i->prev)  {
        double aux = sort(i);
        push (&head_median, aux, i->prev->prev->timestamp, &dim_median);
    }
    init_tail (head_median, &tail_median);
    
    mem_free (*head);
    *head = head_median;
    *tail = tail_median;
    *dim = dim_median;
}

//#################### TASK 2.2 ###########################

void task_2_2 (ListNode **head, ListNode **tail, int *dim) {

    ListNode *head_median = NULL;
    ListNode *tail_median = NULL;
    ListNode *i;
    int dim_median = 0;

    for (i = *tail; i->prev->prev->prev != *head; i = i->prev)  {
        double aux = task1_average(i);
        push (&head_median, aux, i->prev->prev->timestamp, &dim_median);
    }
    init_tail (head_median, &tail_median);
    
    mem_free (*head);
    *head = head_median;
    *tail = tail_median;
    *dim = dim_median;
}

//####################### TASK 3 ##########################

void task_3 (ListNode *head, ListNode *tail) {

    ListNode *i;
    int dif;

    for (i = tail->prev; i != NULL; i = i->prev) {
        dif = i->timestamp - i->next->timestamp;
        if (dif >= 100 && dif <= 1000) {
            i->timestamp = (i->timestamp + i->next->timestamp) / 2;
            i->elem = (i->elem + i->next->elem) / 2;
        }
    }
}

//####################### TASK 4 ##########################

void task_4 (ListNode *head, ListNode *tail, int *dim) {

    ListNode *i, *j, *k;
    double w03 = (double)0.1 / 1.425, w13 = (double)0.325 / 1.425, w23 = (double)1 / 1.425;

    for (i = tail; i->prev->prev != head; i = i->prev) {
        if (i->prev->timestamp - i->timestamp > 1000) {
            double left0 = i->next->next->elem * w03;
            double left1 = i->next->elem * w13;
            double left2 = i->elem * w23;
            double right2 = i->prev->elem * w23;
            double right1 = i->prev->prev->elem * w13;
            double right0 = i->prev->prev->prev->elem * w03;
            int time = i->timestamp + 200;
            k = i;
            j = i->prev;

            while (time < j->timestamp) {
                double C = ((double)time - i->timestamp) / (j->timestamp - i->timestamp);
                double x = (double)(1 - C) * (left0 + left1 + left2) + C * (right0 + right1 + right2);

                ListNode *nou = (ListNode*) malloc(sizeof (ListNode));
                nou->elem = x;
                nou->timestamp = time;
                k->prev = nou;
                nou->next = k;
                j->next = nou;
                nou->prev = j;
                k = nou;
                *dim += 1;

                time += 200;
            }
        }
    }
}

//####################### TASK 5 ##########################

int delta (char *s) {

    char aux[11];
    int x = 0;
    
    strcpy (aux, s+4);
    for (int i = 0; i < strlen (aux); i++) {
        x = x*10 + (aux[i] - '0');
    }

    return x;
}

void task5 (ListNode *head, ListNode *tail, int x) {

    ListNode *i, *j;
    double aux1;
    
    for (i = head; i != tail; i = i->next ) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->elem < j->elem) {
                aux1 = i->elem;
                i->elem = j->elem;
                j->elem = aux1;
            }
        }
    }
    
    int bot= 0, top = 0, cnt = 0;
    if (tail->elem >=0) {
        while (top <= tail->elem) {
            top += x;
        }
        bot = top - x;
    }
    else {
        while (bot >= tail->elem) {
            bot -= x;
        }
        top = bot + x;
    }

    for (i = tail; i != NULL; i = i->prev) {
        if (i->elem >= bot && i->elem <= top) {
            cnt++;
        }
        else {
            if (cnt != 0) {
                printf ("[%d, %d] %d\n", bot, top, cnt);
            }
            cnt = 1;
            while (top <= i->elem) {
                top += x;
            }
            bot = top - x;
        }
    }
    printf ("[%d, %d] %d\n", bot, top, cnt);
}

int main (int argc, char *argv[]) {

    ListNode *head = NULL;
    ListNode *tail = NULL;
    int dim;
    init_lista (&head, &tail, &dim);
    
    for (int i = 1; i < argc; i++) {
        
        if (strcmp ("--e1", argv[i]) == 0) {
            task1 (head, tail, &dim);
        }

        else if (strcmp ("--e2", argv[i]) == 0) {
            task_2_1 (&head, &tail, &dim);
        }

        else if (strcmp ("--e3", argv[i]) == 0) {
            task_2_2 (&head, &tail, &dim);
        }

        else if (strcmp ("--u", argv[i]) == 0) {
            task_3 (head, tail);
        }
        else if (strcmp ("--c", argv[i]) == 0) {
            task_4 (head, tail, &dim);
        }
        else if (strstr (argv[i], "--st") != 0) {
            int x = delta (argv[i]);
            task5 (head, tail, x);       
            mem_free (head);
            return 0;
        }
    }
    
    printf ("%d\n", dim);
    printl (tail);
    mem_free (head);
    return 0;
}