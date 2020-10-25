#include <stdio.h>
#include <conio.h>

int main(){
    int howManyMinutes, subscriptionFee, costOfMinutes, costOfMinutesInSub, pay;
    printf("How many minutes are you talking: ");
    scanf("%d", &howManyMinutes);
    printf("How much subscription fee costs: ");
    scanf("%d", &subscriptionFee);
    printf("How much minutes costs: ");
    scanf("%d", &costOfMinutes);
    costOfMinutesInSub = subscriptionFee / 499;
    if (costOfMinutesInSub > costOfMinutes){
        costOfMinutes = costOfMinutesInSub;
    }
    if (howManyMinutes < 499){pay = subscriptionFee;}
    else{pay = subscriptionFee + costOfMinutes * (howManyMinutes - 499);}
    printf("You must pay: %d\n\n", pay);

    int countOfMonth;
    float k, startSum, percents;

    printf("How much month: ");
    scanf("%d", &countOfMonth);
    printf("percents: ");
    scanf("%f", &percents);
    k = percents / 100;
    printf("start sum: ");
    scanf("%f", &startSum);
    for (int i = 0; i < countOfMonth; i++){
        startSum = startSum * (1 + k);
        printf("In %d month you must pay: %f\n", i+1, startSum);
    }

    getch();

    return 0;
}