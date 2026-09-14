typedef struct item Item;
typedef struct celula Celula;
typedef struct deque Deque;

Deque *cria_Deque();
void libera_Deque(Deque *dq);
int verificaDequeVazia(Deque *dq);
void insereFinal_Deque(Deque *dq, int chave);
void insereInicio_Deque(Deque *dq, int chave);
void removeInicio_Deque(Deque *dq);
void removeFinal_Deque(Deque *dq);
void imprime_Deque(Deque *dq);
