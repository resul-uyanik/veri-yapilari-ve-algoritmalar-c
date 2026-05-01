#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10  // Hash tablosunun boyutu

// Hash tablosunda bir girdiyi temsil eden yapı
typedef struct {
    int key;             // Anahtar (integer)
    char value[50];      // Değer (string)
    int isOccupied;      // Boş olup olmadığını kontrol için bayrak (0: boş, 1: dolu)
} HashTableEntry;

// Hash tablosu
HashTableEntry hashTable[TABLE_SIZE];

// Hash fonksiyonu
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Hash tablosunu başlat
void initializeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].key = 0;
        hashTable[i].value[0] = '\0';
        hashTable[i].isOccupied = 0; // Başlangıçta tüm girişler boş
    }
}

// Hash tablosuna bir değer ekle
void insert(int key, char* value) {
    int hashIndex = hashFunction(key);
    int originalIndex = hashIndex;  // Başlangıç indeksini sakla
    int i = 0;

    // Linear Probing ile boş yer bulana kadar ilerle
    while (hashTable[hashIndex].isOccupied) {
        // Eğer aynı anahtar varsa, güncelleme yap
        if (hashTable[hashIndex].key == key) {
            strcpy(hashTable[hashIndex].value, value);
            printf("Key %d already exists, value updated to '%s'.\n", key, value);
            return;
        }
        hashIndex = (originalIndex + ++i) % TABLE_SIZE; // Sıradaki pozisyona git

        // Tüm tabloyu dolaştıysak
        if (hashIndex == originalIndex) {
            printf("Hash table is full, cannot insert key %d.\n", key);
            return;
        }
    }

    // Boş yeri bulduk, anahtar ve değeri ekle
    hashTable[hashIndex].key = key;
    strcpy(hashTable[hashIndex].value, value);
    hashTable[hashIndex].isOccupied = 1; // İşaretle
    printf("Key %d inserted at index %d.\n", key, hashIndex);
}

// Hash tablosunda bir anahtar ara
char* search(int key) {
    int hashIndex = hashFunction(key);
    int originalIndex = hashIndex; // Başlangıç indeksini sakla
    int i = 0;

    // Linear Probing ile doğru anahtarı arar
    while (hashTable[hashIndex].isOccupied) {
        if (hashTable[hashIndex].key == key) {
            return hashTable[hashIndex].value; // Anahtarı bulduk
        }
        hashIndex = (originalIndex + ++i) % TABLE_SIZE;

        // Tüm tabloyu dolaştıysak
        if (hashIndex == originalIndex) {
            break;
        }
    }
    return NULL; // Anahtar bulunamadı
}

// Hash tablosunu yazdır
void displayHashTable() {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].isOccupied) {
            printf("[%d]: (Key: %d, Value: %s)\n", i, hashTable[i].key, hashTable[i].value);
        } else {
            printf("[%d]: (Empty)\n", i);
        }
    }
}

// Ana program
int main() {
    int choice, key;
    char value[50];

    // Hash tablosunu başlat
    initializeHashTable();

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Key (integer): ");
                scanf("%d", &key);
                printf("Enter Value (string): ");
                scanf("%s", value);
                insert(key, value);
                break;
            case 2:
                printf("Enter Key to Search: ");
                scanf("%d", &key);
                char* result = search(key);
                if (result != NULL) {
                    printf("Value: %s\n", result);
                } else {
                    printf("Key not found!\n");
                }
                break;
            case 3:
                displayHashTable();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
