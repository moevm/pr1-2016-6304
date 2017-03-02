struct MusicalComposition {
    char name[80];
    char author[80];
    int year;
    struct MusicalComposition * next;
    struct MusicalComposition * previous;
};

typedef struct MusicalComposition MusicalComposition;


