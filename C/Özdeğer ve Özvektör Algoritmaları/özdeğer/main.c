#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, j, flag;

    float a[10][10], x0[10], x1[10], y[10], lambda, eps=1e-5;

    printf("Matrisin boyutunu giriniz: ");
    scanf("%d", &n);

    printf("Matrisin elemanlarini giriniz: \n\n");
    for(i = 1; i <= n; i++){
        for(j = 1;j <= n;j++){
            printf("Matrisin %d. satir %d. sutun elemanini giriniz: ", i, j);
            scanf("%f", &a[i][j]);
        }
        printf("\n");
    }

    printf("Girilen matris: \n");
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            printf("%f  ",a[i][j]);
        }
        printf("\n");
    }

    for(i = 1; i <= n; i++){
        x0[i]=1;
        x1[i]=1;
    }

    do{
        flag=0;
        for(i = 1; i <= n; i++){
            x0[i] = x1[i];
        }
        for(i = 1; i <= n; i++){
            y[i]=0;
            for(j = 1; j <= n; j++){
                y[i] += a[i][j]*x0[j];
            }
        }

        lambda=y[1];

        for(i = 2; i <= n; i++){
            if(lambda < y[i]){
                lambda = y[i];
            }
        }
        for(i = 1; i <= n; i++){
            x1[i] = y[i]/lambda;
        }
        for(i = 1; i <= n; i++){
            if(fabs(x0[i] - x1[i]) > eps){
                flag = 1;
            }
        }
    }while(flag==1);

    printf("\n\nEn buyuk ozdeger: %8.5f\n", lambda);

    printf("\n\nKarsilik gelen ozvektorler: ");

    for(i = 1; i <= n; i++){
        printf("%8.5f   ", x1[i]);
    }

    return 0;
}
