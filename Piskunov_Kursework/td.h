typedef struct MusicalComposition{
    char name[80];
    char author[80];
    int year;
    struct MusicalComposition* prev;
    struct MusicalComposition* next;
} MusicalComposition;
