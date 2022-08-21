typedef struct{
    int num;
    int posX;
    int posY;
} example;

typedef struct { //determina le dimensioni dell'array
    example *array;
    size_t used;
    size_t size;
} Array;

void initArray(Array *a, size_t initialSize) { //Permette di inizializzare l'array
    a->array = malloc(initialSize * sizeof(Container));
    a->used = 0;
    a->size = initialSize;
}

void insertArray(Array *a, example element){ //
    if (a->used == a->size) {
        a->size += 1;
        a->array = realloc(a->array, a->size * sizeof(example));
    }
    a->array[a->used++] = element;
}

void freeArray(Array *a){ //libera l'array
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

void removeElementByIndex(Array *a, int index){ //rimuove elementi dall'array (index)
    Array temp_array;
    initArray(&temp_array, 1);

    for (int i=0; i<a->size; i++) // scorro l'array a
    {
            if (i==index) //Quando incontro index lo salto (continue)
            {
                continue;
            }
        insertArray(&temp_array, a->array[i]);
    }
    a->array = temp_array.array;
    a->size = temp_array.size;
    a->used = temp_array.used;
}

void printArray(Array *a){ //stampa l'array
    for(int k=0; k < a->size; k++)
    {
        printf ("num: %d posX: %d posY: %d \n", a->array[k].num, a->array[k].posX, a->array[k].posY);
    }
}

int main(){
Array list = readAndSetArrayFromFile(fp);
printArray(&list);
return 0;
}
