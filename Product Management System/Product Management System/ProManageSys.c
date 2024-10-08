#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>




#define MAX_NAME 30
#define MAX_PRODUCTS 10




struct Product {
	char name[MAX_NAME];
	int price;
	int stock;
};

struct User {
	char username[MAX_NAME];
	int password;
	int product_count;
	struct Product products[MAX_PRODUCTS];
};

void updatePrice(struct User* user, int productIndex, int newPrice) {

	if (productIndex >= 0 && productIndex < user->product_count) {
		user->products[productIndex].price = newPrice;
		printf("%s adli urunun yeni fiyati %d\n", user->products[productIndex].name, newPrice);
	}
	else {
		printf("Gecersiz urun indeksi..");
	}
}

void updateStock(struct User* user, int productIndex, int newStock) {

	if (productIndex >= 0 && productIndex < user->product_count) {
		user->products[productIndex].stock = newStock;
		printf("%s adli urunun yeni stogu %d\n", user->products[productIndex].name, newStock);
	}
	else {
		printf("Gecersiz urun indeksi..");
	}

}


int main() 
{
	
	struct User user1;

	strcpy(user1.username, "admin");
	user1.password = 1234;
	user1.product_count = 1;

	strcpy(user1.products[0].name, "elma");
	user1.products[0].price = 3;
	user1.products[0].stock = 50;


	char input_name[MAX_NAME];
	int input_password;
	int newStock;
	int newPrice;
	int choice;

	printf("Isim girin:");
	scanf("%s", input_name);
	printf("Sifre girin:");
	scanf("%d", &input_password);

	if (strcmp(user1.username, input_name) == 0 && user1.password == input_password) {
		
		printf("Markete girildi..");

		while (1) {
			printf("Bir secim yapin\n");
			printf("1. Fiyat yenileme\n");
			printf("2. Stok yenileme\n");
			printf("3. Cikis\n");
			scanf("%d", &choice);

			if (choice == 1) {
				printf("Yeni fiyat:");
				scanf("%d", &newPrice);
				updatePrice(&user1, 0, newPrice);
			}
			else if (choice == 2) {
				printf("Yeni stok:");
				scanf("%d", &newStock);
				updateStock(&user1, 0, newStock);
			}
			else if (choice == 3) {
				printf("Cikis yapýlýyor.");
				return 0;
			}
			else {
				printf("Gecersiz secim.");
			}
		}
	}
	else 
	{
		printf("Hatali bilgi girdiniz.");
	}

	return 0;

}