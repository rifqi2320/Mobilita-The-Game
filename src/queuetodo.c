#include "queuetodo.h"

void CreateQueue(Queue *q){
	IDX_HEAD(*q) = -1;
	IDX_TAIL(*q) = -1;
}

boolean isEmpty(Queue q){
    return(IDX_HEAD(q) == -1) && (IDX_TAIL(q) == -1);
}

boolean isFull(Queue q){
	return(IDX_HEAD(q) == 0) && (IDX_TAIL(q) == 100-1);
}

int length(Queue q){
	if (isEmpty(q)){
		return 0;
	}
	return(IDX_TAIL(q) - IDX_HEAD(q)) + 1;
}

void enqueue(Queue *q, ElType val){
	if (isEmpty(*q)){
		IDX_HEAD(*q) = 0;
		IDX_TAIL(*q) = 0;
	} else {
		if (IDX_TAIL(*q)==100-1){
			int i;
			for (i = IDX_HEAD(*q); i <= IDX_TAIL(*q); i++){
				(*q).buffer[i-IDX_HEAD(*q)] = (*q).buffer[i];
			}
			IDX_TAIL(*q) -= IDX_HEAD(*q);
			IDX_HEAD(*q) = 0;
		}
		IDX_TAIL(*q)++;
	}
	TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val){
	*val = HEAD(*q);
	if (IDX_HEAD(*q) == IDX_TAIL(*q)){
		IDX_HEAD(*q) = -1;
		IDX_TAIL(*q) = -1;
	} else {
		IDX_HEAD(*q)++;
	}
}