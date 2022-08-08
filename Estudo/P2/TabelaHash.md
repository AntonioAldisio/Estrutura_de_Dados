# Tabela Hash (Tabela de dispersão)

## Introdução

Tabela hash é uma estrutura de dados especial,que associa chaves de pesquisa a valores. (Lembra o funcionamento de json).
A tabela hash é voltada para um sistema de busca. A vantagem não é necessário ter uma ordenação dos valores armazeados para realizar a busca.
Ela é composta por dois elementos chave e elemento.

## Codigos

[Fonte dos codigo](https://www.tutorialspoint.com/data_structures_algorithms/hash_table_program_in_c.htm)

```C
// Cria chave para tabela hash
// #define SIZE -> Tamanho desejado
int hashCode(int key) {
   return key % SIZE;
}
```

```C
// Busaca dado na tabela hash
struct DataItem *search(int key) {
   //get the hash
   int hashIndex = hashCode(key);
   //move in array until an empty
   while(hashArray[hashIndex] != NULL) {
      if(hashArray[hashIndex]->key == key)
         return hashArray[hashIndex];
      //go to next cell
      ++hashIndex;
      //wrap around the table
      hashIndex %= SIZE;
   }
   return NULL;
}
```

```C
// Inserir dado
void insert(int key,int data) {
   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->data = data;
   item->key = key;
   //get the hash
   int hashIndex = hashCode(key);
   //move in array until an empty or deleted cell
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
      //go to next cell
      ++hashIndex;
      //wrap around the table
      hashIndex %= SIZE;
   }
   hashArray[hashIndex] = item;
}
```

```C
struct DataItem* delete(struct DataItem* item) {
   int key = item->key;
   //get the hash
   int hashIndex = hashCode(key);
   //move in array until an empty
   while(hashArray[hashIndex] != NULL) {
      if(hashArray[hashIndex]->key == key) {
         struct DataItem* temp = hashArray[hashIndex];
         //assign a dummy item at deleted position
         hashArray[hashIndex] = dummyItem;
         return temp;
      }
      //go to next cell
      ++hashIndex;
      //wrap around the table
      hashIndex %= SIZE;
   }
   return NULL;
}
```
