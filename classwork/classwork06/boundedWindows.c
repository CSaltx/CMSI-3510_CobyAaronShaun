#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

DWORD WINAPI producer(LPVOID);
DWORD WINAPI consumer(LPVOID);

int mutex = 1;
int full = 7;
int empty = 0;
int x = 0;

int wait_(int s)
{
   return (--s);
}

int signal_(int s)
{
   return (++s);
}

DWORD WINAPI producer(void *ignored)
{
   printf("Producer thread running...\n");
   while (1)
   {
      if (mutex == 1)
      {
         if (x != full)
         {
            mutex = wait_(mutex);
            x++;
            mutex = signal_(mutex);
            printf(" Producer produces the item %d\n", x);
         }
         else
         {
            printf("\tBuffer is full!!\n");
            Sleep(200);
         }
      }
      Sleep(100);
   }
   return 0;
}

DWORD WINAPI consumer(void *ignored)
{
   printf("Consumer thread running...\n");
   while (1)
   {
      if (mutex == 1)
      {
         if (x != empty)
         {
            mutex = wait_(mutex);
            x--;
            mutex = signal_(mutex);
            printf("Consumer consumes the item %d\n", x);
         }
         else
         {
            printf("\tBuffer is empty!!\n");
         }
         Sleep(200);
      }
      Sleep(100);
   }

   return 0;
}

int main()
{
   HANDLE hThread1;
   HANDLE hThread2;
   DWORD threadID1;
   DWORD threadID2;

   int n;
   int wait_(int);
   int signal_(int);
   int seconds = 0;
   int code = 0;

   printf("\nStarting program\n");
   printf("Parent started, children are next\n\n");
   hThread1 = CreateThread(NULL, 0, producer, (LPVOID)n, 0, &threadID1);
   if (hThread1)
   {
      printf("Producer thread\n");
   }
   else
   {
      fprintf(stderr, "Producer failed with code %d\n", hThread1);
   }
   hThread2 = CreateThread(NULL, 0, consumer, (LPVOID)n, 0, &threadID2);
   if (hThread2)
   {
      printf("Consumer thread\n");
   }
   else
   {
      fprintf(stderr, "Consumer failed with code %d\n", hThread2);
   }

   while (seconds < 25)
   {
      printf("parent is sleeping\n");
      Sleep(1000);
      seconds++;
   }
   printf("Parent done.\n\n");
   return 0;
}
