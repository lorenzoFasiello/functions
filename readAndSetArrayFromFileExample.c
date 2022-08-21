Array readAndSetArrayFromFile(FILE *file){
    Array list;
    initArray(&list, 1);
    char line[100];
    Container temp_container = {0, 0, 0};
    while ( ( fgets ( line, sizeof ( line), file))) {
        if ((sscanf(line, "%d %d %d[^\n]", &temp_container.num, &temp_container.posX, &temp_container.posY)) == 3) {
            insertArray(&list, temp_container);
        }
    }
    printf("size of containers: %d\n",list.size);
    return list;
}
