#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Описание структуры
typedef struct MusicalComposition
{
    char name[80];
    char author[80];
    int year;
    struct MusicalComposition* next;
    struct MusicalComposition* prev;
} MusicalComposition;

//создание одного элемента типа структуры
MusicalComposition* createMusicalComposition(char *name, char* author, int year)
{
    MusicalComposition* rr = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    strcpy(rr->name, name);
    strcpy(rr->author, author);
    rr->year = year;
    rr->next = NULL;
    rr->prev = NULL;
    return rr;
}

//создание двусвязного списка из нескольких элементов типа структруры
MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
    MusicalComposition *head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
    MusicalComposition *prev = head;
    MusicalComposition *current;
    for (int i = 1; i < n; ++i)
    {
        current = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
        current->prev = prev;
        prev->next = current;
        prev = current;
    }
    return head;
}

//ввод данных для создания нового элемента типа структуры
MusicalComposition* ReturnElement()
{
    char name[80];
    char author[80];
    int year;
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter author: ");
    scanf("%s", author);
    printf("Enter year: ");
    scanf("%d", &year);
    MusicalComposition* element = createMusicalComposition(name, author, year);
    return element;
}

//добавление элемента в конец списка
void push(MusicalComposition* head, MusicalComposition* element)
{
    while (head->next)
        head = head->next;
    head->next = element;
    element->prev = head;
    element->next = NULL;
}

//добавление нескольких элементов в конец списка
void pushn(MusicalComposition* head)
{
    int n, i=0;
    printf("Enter number of compositions to push:\n");
    scanf("%d", &n);
    printf("Enter compositions(nay):\n");
    while (i<n)
    {
        MusicalComposition* element_for_push = ReturnElement();
        push(head, element_for_push);
        i++;
    }
}

//поиск и удаление элемента по названию
void removeEl(MusicalComposition*head)
{
    char name_for_remove[80];
    printf("Enter name: \n");
    scanf("%s", name_for_remove);
    while (head)
    {
        if (strcmp(head->name, name_for_remove) == 0)
        {
            if (head->next == NULL)
            {
                head->prev->next = NULL;
                return;
            }
            else if (head->prev == NULL)
            {
                *head=*head->next;
                head->prev=NULL;
                return;
            }
            else
            {
                head->prev->next = head->next;
                head->next->prev = head->prev;
                return;
            }
            break;
        }
        head = head->next;
    }

}

//счетчик элементов
int count(MusicalComposition*head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
};

//вывод названий
void print_names(MusicalComposition *head)
{
    while (head)
    {
        printf("%s\n", head->name);
        head = head->next;
    }
}

//меняет половины местами (центральный элемент оказывается в правой половине до перестановки)
MusicalComposition* PomenyatPolovinyMestami(MusicalComposition** head)
{
    int n=1;
    int r;
    MusicalComposition *nachalo=(MusicalComposition*)malloc(sizeof(MusicalComposition));
    nachalo = *head;
    MusicalComposition *tmp=(MusicalComposition*)malloc(sizeof(MusicalComposition));
    tmp = *head;
    r = count(tmp);
    while (2*n<=r)
    {
        tmp=tmp->next;
        n++;
    }
    tmp->prev->next=NULL;
    tmp->prev=NULL;
    while (tmp->next)
    {
        tmp=tmp->next;
    }
    tmp->next=nachalo;
    nachalo->prev=tmp;
    while (tmp->prev)
    {
        tmp=tmp->prev;
    }
    return tmp;
}

//меняет местами элементы, симметрично расположенные относительно элемента с номером, соответствующим введенному
void PomenyatOtnosN(MusicalComposition* head)
{
    int n, i=1;
    printf("Enter number: ");
    scanf("%d", &n);
    MusicalComposition* nachalo=(MusicalComposition*)malloc(sizeof(MusicalComposition));
    nachalo = head;
    while (i<n)
    {
        nachalo=nachalo->next;
        i++;
    }
    MusicalComposition* frw=(MusicalComposition*)malloc(sizeof(MusicalComposition));
    MusicalComposition* bck=(MusicalComposition*)malloc(sizeof(MusicalComposition));
    char* temp[80];
    int* year;
    frw = nachalo->next;
    bck = nachalo->prev;
    while (frw&&bck)
    {
        strcpy(temp, frw->author);
        strcpy(frw->author, bck->author);
        strcpy(bck->author, temp);
        strcpy(temp, frw->name);
        strcpy(frw->name, bck->name);
        strcpy(bck->name, temp);
        year=frw->year;
        frw->year=bck->year;
        bck->year=year;
        frw=frw->next;
        bck=bck->prev;
    }
}

//меню и первоначальный ввод данных
int main()
{
    printf("Enter length:\n");
    int length;
    scanf("%d", &length);
    printf("Enter compositions:\n");

    char **names = (char**)malloc(sizeof(char*)*length);
    char **authors = (char**)malloc(sizeof(char*)*length);
    int *years = (int*)malloc(sizeof(int)*length);
    int i;
    for (i = 0; i < length; ++i)
    {
        char name[80];
        char author[80];
        printf("Enter name %d: ", i+1);
        scanf("%s", name);
        printf("Enter author %d: ", i+1);
        scanf("%s", author);
        printf("Enter year %d: ", i+1);
        scanf("%d", &years[i]);
        names[i] = (char*)malloc(sizeof(char*)*(strlen(name) + 1));
        authors[i] = (char*)malloc(sizeof(char*)*(strlen(author) + 1));

        strcpy(names[i], name);
        strcpy(authors[i], author);
    }

    MusicalComposition *head = createMusicalCompositionList(names, authors, years, length);
    while (1)
    {
        int j;
        printf("Choose action:\n1.Add element\n2.Add some elements\n3.Delete element by name\n4.Swap halves\n5.Swap elements from both sides of N\n6.Print list\n");
        scanf("%d", &j);
        switch (j)
        {
        case 1:
        {
            MusicalComposition* elfpush = ReturnElement();
            push (head, elfpush);
            break;
        }
        case 2:
        {
            pushn(head);
            break;
        }
        case 3:
        {
            removeEl(head);
            break;
        }
        case 4:
        {
            head=PomenyatPolovinyMestami(&head);
            break;
        }
        case 5:
        {
            PomenyatOtnosN(head);
            break;
        }
        case 6:
        {
            print_names(head);
            break;
        }
        }
        getchar();
        getchar();
        if (system("cls"))
            system("clear");
    }
    return 0;
}
