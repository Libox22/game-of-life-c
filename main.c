// Il gioco della vita, le 4 REGOLE:
// 1) se una cella viva (1) ha meno di due celle accanto muore di solitudine
// 2) se una cella viva (1) ha più di tre celle vicine muore di sovraffollamento
// 3) se una cella viva (1) ha due o tre celle vive accanto continua a vivere
// 4) se una cella morta (0) ha esattamente tre celle vicine nasce una nuova vita

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>

void error(char *str)
{
    fprintf(stderr, "%s\n", str);
    exit(1);
}

int **allocMatrix(int sizeN, int sizeM)
{
    int **Matrix = malloc(sizeof(int *) * sizeN);
    if (!Matrix)
        error("Allocazione fallita");
    for (int i = 0; i < sizeN; i++)
    {
        Matrix[i] = malloc(sizeof(int) * sizeM);
    }
    return Matrix;
}

void fillMatrix(int **M1, int sizeN, int sizeM)
{
    for (int i = 0; i < sizeN; i++)
    {
        for (int j = 0; j < sizeM; j++)
        {
            float p = (float)rand() / (float)RAND_MAX;
            //modifica il valore per aumentare la possibilità che una cella nasca viva o morta (valore più alto meno probabilità nasca viva mentre valore più basso più probabilità che nasca viva)
            if (p > 0.4)
            {
                M1[i][j] = 1;
            }
            else
            {
                M1[i][j] = 0;
            }
        }
    }
}

void printMatrix(int **M1, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j >= 100)
            {
                break;
            }
            printf("%d ", M1[i][j]);
        }
        printf("\n");
    }
}

int countNeighbors(int **M1, int i, int j, int sizeN, int sizeM)
{
    int c = 0;
    for (int di = -1; di <= 1; di++)
    {
        for (int dj = -1; dj <= 1; dj++)
        {
            if (di == 0 && dj == 0)
                continue;
            int ni = di + i;
            int nj = dj + j;
            if (ni >= 0 && ni < sizeN && nj >= 0 && nj < sizeM)
            {
                c += M1[ni][nj];
            }
        }
    }
    return c;
}

void control(int **M1, int sizeN, int sizeM)
{
    int **M2 = allocMatrix(sizeN, sizeM);
    int c = 0;
    for (int i = 0; i < sizeN; i++)
    {
        for (int j = 0; j < sizeM; j++)
        {
            c = countNeighbors(M1, i, j, sizeN, sizeM);
            if (M1[i][j] == 1)
            {
                if (c < 2 || c > 3)
                    M2[i][j] = 0;
                else
                    M2[i][j] = 1;
            }
            else
            {
                if (c == 3)
                    M2[i][j] = 1;
                else
                    M2[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < sizeN; i++)
    {
        for (int j = 0; j < sizeM; j++)
        {
            M1[i][j] = M2[i][j];
        }
    }
    for (int i = 0; i < sizeN; i++)
        free(M2[i]);
    free(M2);
}

void setCursor(int x, int y)
{
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(int argc, char *argv[])
{
    printf("Before starting the game, set the window to full screen to avoid printing issues.");
    Sleep(2000);
    printf("\n\n");
    int sN, sM;
    printf("Insert the size of rows and cols |1,50| and |1,100|: ");
    scanf("%d %d", &sN, &sM);
    if (sN > 50 || sN < 1 || sM > 100 || sM < 1){
        printf("ERROR: Rows: 1,50 and Columns: 1,100");
        Sleep(3000);
        exit(1);
    }
    printf("Rows: %d, Cols: %d \n", sN, sM);
    printf("\n\n");
    int **M1 = allocMatrix(sN, sM);
    srand(time(NULL));
    fillMatrix(M1, sN, sM);
    int i = 0;
    //Modifica il valore (ora è impostato a 200) per effettuare più cicli, dopo di che compila ed esegui.
    while (i < 200)
    {
        setCursor(0, 3);
        printMatrix(M1, sN, sM);
        control(M1, sN, sM);
        Sleep(100);
        i++;
    }

    Sleep(1000);
    for (int i = 0; i < sN; i++)
    {
        free(M1[i]);
    }
    free(M1);
    return 0;
}