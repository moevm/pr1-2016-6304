struct MusicalComposition{				//Объявляем структуру
    char name[80];		
    char author[80];
    int year;
    struct MusicalComposition *next, * prev; //Указатели на 
};										//связанные элементы.
typedef struct MusicalComposition MusicalComposition;	
//Присваиваем, для удобства, новое имя типу-структуре




