#include "f.h"
#include "bigheader.h"

int main()
{
	int choice = 0;
	int flag = 0;
	MusicalComposition *head = NULL;
	while (choice != 8)
	{
	//	system("cls");
		printf("\n~*~*~*~*~*~*~*~*~*~*~*~*~*~*~* Menu ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");
		printf("You have a choice of 7 different actions with musical list.      \n");
		printf("Choose one of them.\n");
		printf("\n -->  1. Create List\n");
		printf("   -->  2. Print List\n");
		printf("   -->  3. Add 3 extra elements after every even one\n");
		printf("   -->  4. Add a new element to the end of the list\n");
		printf("   -->  5. Remove elements with appropriate author\n");
		printf("   -->  6. Remove elements with appropriate name\n");
		printf("   -->  7. Number of elements\n");
		printf("\n");
		printf("   -->  8. Exit\n");
		printf("  ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n\n\n");


		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			head = added_str();
			flag = 1;
			break;
		case 2:
			if (flag == 0)
				printf("The list was not created. Choose the option 1 in the menu\n");
			else
			{
				system("cls");
				printf("List:\n");
				print_names(head);
				printf("\n");
				pause();
			}
			break;
		case 3:
			if (flag == 0)
				printf("The list was not created. Choose the option 1 in the menu");
			else
				threeEl(head);
			break;
		case 4:
			if (flag == 0)
				printf("The list was not created. Choose the option 1 in the menu");
			else
			{
				system("cls");

				push(head);
				printf("You added one new element\n");
				pause();
			}
			break;
		case 5:
			if (flag == 0)
				printf("The list was not created. Choose the option 1 in the menu");
			else {
                char a_rem[80];
				printf("Enter the name of author to remove all the elements including it\n");
				scanf("%s", a_rem);
				rem_author(head, a_rem);
				printf("Done!");
				pause();
			}
			break;
		case 6:
			if (flag == 0)
				printf("The list was not created. Choose the option 1 in the menu");
			else
			{
				system("cls");
				char name_for_remove[80];
				printf("Enter the name to remove from the list\n");
				scanf("%s", name_for_remove); //Считываем имя, по которому будет произведен
				removeEl(head, name_for_remove); //поиск элемента, необходимого для удаления
				pause(); //Задерживаем экран консоли
			}
			break;
		case 7:
			if (flag == 0)//Проверка на создание списка
                printf("The list was not created. Choose the option 1 in the menu");
			else
            {
                system("cls");
				printf("Number of elements in the list: %d\n\n", count(head)); //Выводим количество элементов в списке
				pause();//Задерживаем экран консоли
			}
			break;
		case 8:
		    break;
		default:
			system("cls");
			printf("There is no option. Maybe, you should try something else?\n\n"); //Выводим сообщение о ошибке, что данного пункта в меню нет
			pause();//Задерживаем экран консоли
		}
	}
	system("cls");
	return 0;
}
