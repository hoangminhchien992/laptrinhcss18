#include <math.h>
#include <stdio.h>
#include <string.h>
struct Dish {
  int id;
  char name[50];
  double price;
};
struct Dish menu[100] = {
    {1, "Pizza", 12.99}, {2, "Burger", 8.99}, {3, "Pasta", 10.99},
    {4, "Salad", 6.99},  {5, "Sushi", 15.99},
};

int main(void) {
  int choice;   
  int size = 5; 
  do {
    printf("\n--------Menu--------\n");
    printf("1. In ra giá trị các phần tử có trong menu món ăn\n");
    printf("2. Thêm một phần từ vào vị trí chỉ định\n");
    printf("3. Sửa một phần từ ở vị trí chỉ định\n");
    printf("4.  Xóa một phần từ ở vị trí chỉ định\n");
    printf("5. Sắp xếp các phần tử\n");
    printf("6. Tìm kiếm phần tử theo name nhập vào\n");
    printf("7. Thoát\n");
    printf("Mời bạn nhập lựa chọn: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1: {
      for (int i = 0; i < size; i++) {
        printf("%d %s %.2f \n", menu[i].id, menu[i].name, menu[i].price);
      }
      break;
    }

    case 3: {
      int position;
      printf("Nhập vị trí cần chỉnh sửa: ");
      scanf("%d", &position);
      if (position < 0 || position >= size) {
        printf("Vị trí không hợp lệ");
      } else {
        scanf("%d", &menu[position].id);
        scanf("%lf", &menu[position].price);
        fgets(menu[position].name, 50, stdin);
      }
      break;
    }

    case 4: {
      int position; 
      printf("Nhập vị trí cần xóa: ");
      scanf("%d", &position);
      struct Dish newMenu[size - 1];
      // Gán các phần tử mảng cũ sang mảng mới
      for (int i = 0; i < position; i++) {
        newMenu[i] = menu[i]; 
      }
      for (int i = position + 1; i < size; i++) {
        newMenu[i - 1] = menu[i];
      }
      // Gán lại các số của mảng mới về mảng cũ ban đầu
      for (int i = 0; i < size - 1; i++) {
        menu[i] = newMenu[i];
      }
      size--;
      break;
    }
    case 5: {
      for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
          if (menu[j].price > menu[j + 1].price) {
            double temp = menu[j].price;
            menu[j].price = menu[j + 1].price;
            menu[j + 1].price = temp;
          }
        }
      }
      break;
    }
    case 6: {
      char searchName[50];
      printf("Nhập tên món ăn: ");
      fgets(searchName, 50, stdin);
      for (int i = 0; i < size; i++) {
        if (strcmp(menu[i].name, searchName) == 0) {
          printf("%s", menu[i].name);
          printf("%lf", menu[i].price);
          printf("%d", menu[i].id);
          break;
        }
      }
      break;
    }
    case 7: {
      printf("Thoát trương trình\n");
      break;
    }
    default: {
      printf("Lựa chọn không hợp lệ\n");
    }
    }

  } while (choice != 7);
  
  return 0;
}