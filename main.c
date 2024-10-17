#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *temp = NULL;

void basaEkle(int veri) {
    struct node *eleman;
    eleman = (struct node *) malloc(sizeof(struct node));
    eleman->data = veri;
    eleman->next = start;
    start = eleman;
}

void sonaEkle(int veri) {
    struct node *eleman;
    eleman = (struct node *) malloc(sizeof(struct node));
    eleman->data = veri;
    eleman->next = NULL;

    if (start == NULL) {
        start = eleman;
    } else {
        temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = eleman;
    }
}

void bastansil()
{
	if(start!=NULL){
	
	temp=start->next;
	free(start);
	start=temp;
}
	else
	free(start);
}

void yazdir() {
	if(start!=NULL)
	{
	
    temp = start;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
	}
	else
	printf("ELEMAN YOKKK!!!!");
}

int main() {
    int sayi, adet = 0, secim, n;

    while (adet != 6) {
        printf("\nBasa eleman eklemek icin 1\n");
        printf("Sona eleman eklemek icin 2\n");
        printf("Bastan eleman silmek icin 3\n");
        printf("Seciminizi yapiniz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("\nBasa eklenecek elemanin degeri: ");
                scanf("%d", &sayi);
                basaEkle(sayi);
                yazdir();
                break;

            case 2:
                printf("\nSona eklenecek elemanin degeri: ");
                scanf("%d", &sayi);
                sonaEkle(sayi);
                yazdir();
                break;

            case 3:
            	bastansil();
            	yazdir();
            	break;
			
        }
        adet++;
    }

    return 0;
}
