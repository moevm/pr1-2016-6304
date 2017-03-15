typedef struct MusicalComposition{
    struct MusicalComposition* previous;
    struct MusicalComposition* next;
    char name[80];
    char author[80];
    int year;
}MusicalComposition;
