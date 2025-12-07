#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
char *generateRandomString(int length) {
    static const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *randomString = malloc(length + 1);
    if (randomString) {
        for (int i = 0; i < length; i++) {
            int index = rand() % (sizeof(charset) - 1);
            randomString[i] = charset[index];
        }
        randomString[length] = '\0';
    }
    return randomString;
}
menu(int input3, double balance, int saved_pin){
    int a, b, c, d,number,pin, agent_secret;
    double amount, sendMoneyFee = 5, cashOutFee;
    char reference[50], phn[15], ch;
    char date_str[12];
    time_t currentTime;
    struct tm *localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);
    strftime(date_str, sizeof(date_str), "%d/%m/%Y", localTime);
    srand(time(NULL));
    int length = 8;
    char *randomStr = generateRandomString(length);

    switch(input3){
    case 0:
        system("cls");
        printf("ckash\n");
        printf("1.Send Money\n");
        printf("2.Send Money to Non-ckash User\n");
        printf("3.Mobile Recharge\n");
        printf("4.Payment\n");
        printf("5.Cash Out\n");
        printf("6.Pay Bill\n");
        printf("7.Add Money\n");
        printf("8.Download ckash App\n");
        printf("9.My ckash\n");
        printf("10.Reset PIN\n");
        scanf("%d", &a);
        switch(a){
        //send money option *
        case 1:
            system("cls");
            printf("Enter Receiver cKash Account No: ");
            scanf("%d", &number);
            system("cls");
            printf("Enter Amount:");
            scanf("%lf", &amount);
            system("cls");
            printf("Enter Reference:");
            scanf("%s", &reference);
            system("cls");
            printf("Send Money.\nTo:%d\nAmount:TK %.2lf\nReference: %s\nEnter Menu PIN to confirm:\n", number, amount, reference, pin);
            scanf("%d", &pin);
            if(pin == saved_pin){
                    if((amount + sendMoneyFee) <= balance){
                        balance = balance - (amount + sendMoneyFee);
                        system("COLOR 20");
                        system("cls");
                        printf("Send Money to TK %.2lf to %d Sucessful. Ref %s . Fee Tk %.2lf. Balance Tk %.2lf. TrxID %s ", amount, number,reference, sendMoneyFee, balance, randomStr );
                        free(randomStr);
                        FILE *file = fopen("statements.txt", "a");
                        FILE *balanceFile = fopen("balance.txt", "w");
                        if(file == NULL || balanceFile == NULL){
                            perror("Error opening file");
                            return 1;
                        }
                        fprintf(file, "%s Send Money - Tk %.2lf\n", date_str, amount);
                        fprintf(balanceFile, "%.2lf", balance);
                        fclose(file);
                        fclose(balanceFile);
                    } else{
                        system("cls");
                        system("COLOR 47");
                        printf("Insufficient balance");
                    }
                }else{
                    system("cls");
                    system("COLOR 47");
                    printf("Wrong Pin");
                }
            break;
        //Send Money to Non-Ckash User option **
        case 2:
            system("cls");
            printf("Enter Receiver Number: ");
            scanf("%d", &number);
            system("cls");
            printf("Enter Amount: ");
            scanf("%lf", &amount);
            system("cls");
            printf("Enter Reference: ");
            scanf("%s", &reference);
            system("cls");
            printf("Send Money to Non-cKash User\nTo: %.2lf\nAmount: TK %d\nReference: %s\nEnter Menu PIN to confirm:\n", number, amount, reference);
            scanf("%d", &pin);
            system("cls");
            printf("Send Money to non-cKash user TK %d to %d Sucessful. Ref %s . Fee Tk 0.00. Balance Tk %d . TrxID KGFKIPOI ", amount, number,reference, balance );
            break;
        //Mobile Recharge option ***
        case 3:
            system("cls");
            printf("cKash\n");
            printf("1. Robi\n");
            printf("2. Airtel\n");
            printf("3. Banglalink\n");
            printf("4. Grameenphone\n");
            printf("5. Teletalk\n");
            printf("6. Get instant cashback on bKash Recharge\n");
            printf("0. Main menu\n");
            scanf("%d", &b);
            switch(b){
            //Robi number
            case 1:
                    system("cls");
                    printf("cKash\n");
                    printf("1. Prepaid\n");
                    printf("2. Postpaid\n");
                    printf("3. Auto-Recharge\n");
                    printf("4. Best Offer (Prepaid)\n");
                    printf("5. Prepaid Internet Packs\n");
                    printf("6. Prepaid voice Packs\n");
                    printf("7. Prepaid Bundle Packs\n");
                    printf("0. Main Menu\n");
                    scanf("%d", &c);
                    switch(c){
                    case 1:
                        system("cls");
                        printf("Enter Robi Number: ");
                        scanf("%s", &phn);
                        if(phn[2] == '8'){
                            system("cls");
                            printf("Enter recharge amount: ");
                            scanf("%lf", &amount);
                            system("cls");
                            printf("Enter menu pin to confirm: ");
                            scanf("%d", &pin);
                                if(pin == saved_pin){
                                    if(balance > amount){
                                    balance = balance - amount;
                                    system("COLOR 20");
                                    system("cls");
                                    printf("Mobile Recharge TK %.2lf Successful to %s. Fee Tk 0.00. Balance Tk %.2lf. TrxID %s", amount, phn, balance, randomStr);
                                    free(randomStr);
                                    FILE *file = fopen("statements.txt", "a");
                                    FILE *balanceFile = fopen("balance.txt", "w");
                                    if(file == NULL || balanceFile == NULL){
                                        perror("Error opening file");
                                        return 1;
                                    }
                                    fprintf(file, "%s Mobile Recharge - Tk %.2lf\n", date_str, amount);
                                    fprintf(balanceFile, "%.2lf", balance);
                                    fclose(file);
                                    fclose(balanceFile);
                                } else {
                                    system("cls");
                                    system("COLOR 47");
                                    printf("Insufficient Balance");
                                }
                            }else{
                                system("cls");
                                system("COLOR 47");
                                printf("Wrong Pin");
                            }
                        } else {
                            system("cls");
                            system("COLOR 47");
                            printf("Not Robi");
                        }
                        break;
                    }
                break;
                case 2:
                    system("cls");
                    printf("cKash\n");
                    printf("1. Prepaid\n");
                    printf("2. Postpaid\n");
                    printf("3. Auto-Recharge\n");
                    printf("4. Best Offer (Prepaid)\n");
                    printf("5. Prepaid Internet Packs\n");
                    printf("6. Prepaid voice Packs\n");
                    printf("7. Prepaid Bundle Packs\n");
                    printf("0. Main Menu\n");
                    scanf("%d", &c);
                    switch(c){
                    case 1:
                        system("cls");
                        printf("Enter Airtel Number: ");
                        scanf("%s", &phn);
                        if(phn[2] == '6'){
                            system("cls");
                            printf("Enter recharge amount: ");
                            scanf("%lf", &amount);
                            system("cls");
                            printf("Enter menu pin to confirm: ");
                            scanf("%d", &pin);
                            if(pin == saved_pin){
                                    if(balance > amount){
                                    balance = balance - amount;
                                    system("cls");
                                    system("COLOR 20");
                                    printf("Mobile Recharge TK %.2lf Successful to %s. Fee Tk 0.00. Balance Tk %.2lf. TrxID %s", amount, phn, balance, randomStr);
                                    free(randomStr);
                                    FILE *file = fopen("statements.txt", "a");
                                    FILE *balanceFile = fopen("balance.txt", "w");
                                    if(file == NULL || balanceFile == NULL){
                                        perror("Error opening file");
                                        return 1;
                                    }
                                    fprintf(file, "%s Mobile Recharge - Tk %.2lf\n", date_str, amount);
                                    fprintf(balanceFile, "%.2lf", balance);
                                    fclose(file);
                                    fclose(balanceFile);
                                } else {
                                    system("cls");
                                    system("COLOR 47");
                                    printf("Insufficient Balance");
                                }
                            }else{
                                system("cls");
                                system("COLOR 47");
                                printf("Wrong Pin");
                            }
                        } else {
                            system("cls");
                            system("COLOR 47");
                            printf("Not Airtel");
                        }
                        break;
                    }
                    break;
                    case 3:
                        system("cls");
                        printf("cKash\n");
                        printf("1. Prepaid\n");
                        printf("2. Postpaid\n");
                        printf("3. Auto-Recharge\n");
                        printf("4. Best Offer (Prepaid)\n");
                        printf("5. Prepaid Internet Packs\n");
                        printf("6. Prepaid voice Packs\n");
                        printf("7. Prepaid Bundle Packs\n");
                        printf("0. Main Menu\n");
                        scanf("%d", &c);
                        switch(c){
                        case 1:
                            system("cls");
                            printf("Enter Banglalink Number: ");
                            scanf("%s", &phn);
                            if(phn[2] == '9'){
                                system("cls");
                                printf("Enter recharge amount: ");
                                scanf("%lf", &amount);
                                system("cls");
                                printf("Enter menu pin to confirm: ");
                                scanf("%d", &pin);
                                if(pin == saved_pin){
                                    if(balance > amount){
                                    balance = balance - amount;
                                    system("cls");
                                    system("COLOR 20");
                                    printf("Mobile Recharge TK %.2lf Successful to %s. Fee Tk 0.00. Balance Tk %.2lf. TrxID %s", amount, phn, balance, randomStr);
                                    free(randomStr);
                                    FILE *file = fopen("statements.txt", "a");
                                    FILE *balanceFile = fopen("balance.txt", "w");
                                    if(file == NULL || balanceFile == NULL){
                                        perror("Error opening file");
                                        return 1;
                                    }
                                    fprintf(file, "%s Mobile Recharge - Tk %.2lf\n", date_str, amount);
                                    fprintf(balanceFile, "%.2lf", balance);
                                    fclose(file);
                                    fclose(balanceFile);
                                } else {
                                    system("cls");
                                    system("COLOR 47");
                                    printf("Insufficient Balance");
                                }
                            }else{
                                system("cls");
                                system("COLOR 47");
                                printf("Wrong Pin");
                            }
                        } else {
                            system("cls");
                            system("COLOR 47");
                            printf("Not Banglalink");
                        }
                        break;
                    }
                    break;
                    case 4:
                        system("cls");
                        printf("cKash\n");
                        printf("1. Prepaid\n");
                        printf("2. Postpaid\n");
                        printf("3. Auto-Recharge\n");
                        printf("4. Best Offer (Prepaid)\n");
                        printf("5. Prepaid Internet Packs\n");
                        printf("6. Prepaid voice Packs\n");
                        printf("7. Prepaid Bundle Packs\n");
                        printf("0. Main Menu\n");
                        scanf("%d", &c);
                        switch(c){
                        case 1:
                            system("cls");
                            printf("Enter Grammenphone Number: ");
                            scanf("%s", &phn);
                            if(phn[2] == '7'){
                                system("cls");
                                printf("Enter recharge amount: ");
                                scanf("%lf", &amount);
                                system("cls");
                                printf("Enter menu pin to confirm: ");
                                scanf("%d", &pin);
                                if(pin == saved_pin){
                                    if(balance > amount){
                                    balance = balance - amount;
                                    system("cls");
                                    system("COLOR 20");
                                    printf("Mobile Recharge TK %.2lf Successful to %s. Fee Tk 0.00. Balance Tk %.2lf. TrxID %s", amount, phn, balance, randomStr);
                                    free(randomStr);
                                    FILE *file = fopen("statements.txt", "a");
                                    FILE *balanceFile = fopen("balance.txt", "w");
                                    if(file == NULL || balanceFile == NULL){
                                        perror("Error opening file");
                                        return 1;
                                    }
                                    fprintf(file, "%s Mobile Recharge - Tk %.2lf\n", date_str, amount);
                                    fprintf(balanceFile, "%.2lf", balance);
                                    fclose(file);
                                    fclose(balanceFile);
                                } else {
                                    system("cls");
                                    system("COLOR 47");
                                    printf("Insufficient Balance");
                                }
                            }else{
                                system("cls");
                                system("COLOR 47");
                                printf("Wrong Pin");
                            }
                        } else {
                            system("cls");
                            system("COLOR 47");
                            printf("Not Grameenphone");
                        }
                        break;
                    }
                    break;
                    case 5:
                        system("cls");
                        printf("cKash\n");
                        printf("1. Prepaid\n");
                        printf("2. Postpaid\n");
                        printf("3. Auto-Recharge\n");
                        printf("4. Best Offer (Prepaid)\n");
                        printf("5. Prepaid Internet Packs\n");
                        printf("6. Prepaid voice Packs\n");
                        printf("7. Prepaid Bundle Packs\n");
                        printf("0. Main Menu\n");
                        scanf("%d", &c);
                        switch(c){
                        case 1:
                            system("cls");
                            printf("Enter Teletalk Number: ");
                            scanf("%s", &phn);
                            if(phn[2] == '5'){
                                system("cls");
                                printf("Enter recharge amount: ");
                                scanf("%lf", &amount);
                                system("cls");
                                printf("Enter menu pin to confirm: ");
                                scanf("%d", &pin);
                                if(pin == saved_pin){
                                    if(balance > amount){
                                    balance = balance - amount;
                                    system("cls");
                                    system("COLOR 20");
                                    printf("Mobile Recharge TK %.2lf Successful to %s. Fee Tk 0.00. Balance Tk %.2lf. TrxID %s", amount, phn, balance, randomStr);
                                    free(randomStr);
                                    FILE *file = fopen("statements.txt", "a");
                                    FILE *balanceFile = fopen("balance.txt", "w");
                                    if(file == NULL || balanceFile == NULL){
                                        perror("Error opening file");
                                        return 1;
                                    }
                                    fprintf(file, "%s Mobile Recharge - Tk %.2lf\n", date_str, amount);
                                    fprintf(balanceFile, "%.2lf", balance);
                                    fclose(file);
                                    fclose(balanceFile);
                                } else {
                                    system("cls");
                                    system("COLOR 47");
                                    printf("Insufficient Balance");
                                }
                            }else{
                                system("cls");
                                system("COLOR 47");
                                printf("Wrong Pin");
                            }
                        } else {
                            system("cls");
                            system("COLOR 47");
                            printf("Not Teletalk");
                        }
                        break;
                    }
                    break;
                    case 0:
                        menu(input3, balance, saved_pin);

            }
            break;
        //Payment option ****
        case 4:
            system("cls");
            printf("Enter Merchant ckash Account No: ");
            scanf("%d", &number);
            system("cls");
            printf("Enter Amount: ");
            scanf("%lf", &amount);
            system("cls");
            printf("Enter Reference: ");
            scanf("%s", &reference);
            system("cls");
            printf("Payment\nTo: %.2lf\nAmount: TK %d\nReference: %s\nEnter Menu PIN to confirm:\n", number, amount, reference);
            scanf("%d", &pin);
            break;
        //Cash Out option *****
        case 5:
            system("cls");
            printf("ckash\n");
            printf("1. From Agent\n");
            printf("2. From ATM\n");
            printf("3. Priyo Agent Number\n");
            printf("4. Set Priyo Agent Number to Cash Out at \n");
            printf("1.49%\n");
            printf("0. Main Menu\n");
            scanf("%d", &b);
            switch(b){
            case 1:
                system("cls");
                printf("Cash Out at 1.49 by adding 1 Priyo Agent\nNumber.\nDial *1023# select option 9 then select\noption 4\n");
                printf("Enter Agent cKash Account No: ");
                scanf("%d", &number);
                system("cls");
                printf("Cash Out at 1.49 from 1 Priyo Agent Number up to 25,000 Tk every month.\nDial *1023# select option 9 then select\noption 4\n");
                printf("Enter Amount: ");
                scanf("%lf", &amount);
                system("cls");
                printf("Cash Out at 1.49 from 1 Priyo Agent Number\n");
                printf("Cash Out\n");
                printf("To: %d\n", number);
                printf("Amount: Tk %.2lf\n", amount);
                printf("Enter Menu PIN to confirm: ");
                scanf("%d", &pin);
                cashOutFee = (14.50 * amount) / 1000.00;
                if(pin == saved_pin){
                    if(balance >= (amount + cashOutFee)){
                        balance = balance - (amount + cashOutFee);
                        system("cls");
                        system("COLOR 20");
                        printf("Cash Out  TK %.2lf to %d Sucessful. Fee Tk %.2lf. Balance Tk %.2lf. TrxID %s ", amount, number, cashOutFee, balance, randomStr );
                        free(randomStr);
                        FILE *file = fopen("statements.txt", "a");
                        FILE *balanceFile = fopen("balance.txt", "w");
                        if(file == NULL || balanceFile == NULL){
                            perror("Error opening file");
                            return 1;
                        }
                        fprintf(file, "%s Cash Out - Tk %.2lf\n", date_str, amount);
                        fprintf(balanceFile, "%.2lf", balance);
                        fclose(file);
                        fclose(balanceFile);
                    } else{
                        system("cls");
                        system("COLOR 47");
                        printf("Insufficient balance");
                    }
                }else{
                    system("cls");
                    system("COLOR 47");
                    printf("Wrong Pin");
                }
                break;
            case 0:
                system("cls");
                printf("returning to main menu will be updated soon...");
                Sleep(1000);
                menu(input3, balance, saved_pin);
                break;
            }
            break;
        //Pay Bill option ******
        case 6:
            system("cls");
            printf("Pay Bill\n");
            printf("1.Electricity (Prepaid)\n");
            printf("2.Electricity (Postpaid)\n");
            printf("3.Gas\n");
            printf("4.Water\n");
            printf("5.Internet and Phone\n");
            printf("6.TV\n");
            printf("7.city Services\n");
            printf("8.Education\n");
            printf("9.Financial Services\n");
            printf("10.Other\n");
            printf("0.Main Menu\n");
            scanf("%d", &b);
            ////Electricity (Prepaid)
                    switch(b){
                    case 1:
                            system("cls");
                            printf("Electricity (Prepaid)\n");
                            printf("1.Palli Bidyut\n");
                            printf("2.DESCO\n");
                            printf("3.DPDC\n");
                            printf("4.BPDB\n");
                            printf("5.Sylhet BPDB\n");
                            printf("Westtzone\n");
                            printf("NESCO\n");
                            printf("0.Main Menu\n");
                            scanf("%d", &c);
                            if(c==1){
                                system("cls");
                                printf("Palli Bidyut (Prepaid)\n");
                                printf("1.Bill Breakdown\n");
                                printf("2.Make Payment\n");
                                printf("0.Main Menu\n");
                                scanf("%d", &d);
                                switch(d){
                                case 1:
                                    system("cls");
                                    printf("Make Payment\n");
                                    printf("1.Input Meter Number\n");
                                    printf("2.Saved Accounts\n");
                                    printf("0.Main Menu\n");
                                    break;
                                }
                    }
                    break;
                    case 2:
                        //Electricity (Postpaid)
                        system("cls");
                        printf("Electricity (Postpaid)\n");
                        printf("1.Palli Bidyut\n");
                        printf("2.Palli Bidyut2\n");
                        printf("3.DESCO\n");
                        printf("4.NESCO\n");
                        printf("5.DPDC\n");
                        printf("6.Westzone\n");
                        printf("7.BPDB\n");
                        printf("0.Main Menu\n");
                        scanf("%d", &c);
                        switch(c){
                        case 1:
                                system("cls");
                                printf("Palli Bidyut(Postpaid)\n");
                                printf("1.Check Bill\n");
                                printf("2.Make Payment\n");
                                printf("0.Main Menu\n");
                        break;
                        case 2:
                                system("cls");
                                printf("Palli Bidyut2(Postpaid)\n");
                                printf("1.Chack Bill\n");
                                printf("2.Make Payment\n");
                                printf("0.Main Menu\n");
                        break;
                        case 3:
                                system("cls");
                                printf("DESCO(Postpaid)\n");
                                printf("1.Check Bill\n");
                                printf("2.Make Payment\n");
                                printf("0.Main Menu\n");

                        break;
                        case 4:
                                system("cls");
                                printf("NESCO(Postpaid)\n");
                                printf("1.Make Payment\n");
                                printf("2.Make Payment\n");
                                printf("0.Main Menu\n");
                        break;
                        case 5:
                                system("cls");
                                printf("DPDC(Postpaid)\n");
                                printf("1.Check Bill\n");
                                printf("2.Make Payment\n");
                                printf("0.Main Menu\n");
                        break;
                        case 6:
                                system("cls");
                                printf("West Zone\n");
                                printf("1.Check Bill\n");
                                printf("2.Make Payment\n");
                                printf("0.Main Menu\n");
                        break;
                        case 7:
                                system("cls");
                                printf("BPDB(Postpaid)\n");
                                printf("1.Check Bill\n");
                                printf("2.Make Payment\n");
                                printf("0.Main Menu\n");
                        break;
                        case 0:
                                system("cls");
                                printf("returning to main menu will be updated soon...");
                                Sleep(1000);
                                menu(input3, balance, saved_pin);
                        break;
                        }
                    break;
                    case 3:
                            //gas
                            system("cls");
                            printf("Gas\n");
                            printf("1.Jalalabad Gas\n");
                            printf("2.Sundarban Gas\n");
                            printf("3.Paschimanchal Gas\n");
                            printf("4.Karnaphuli Gas\n");
                            printf("0.Main Menu\n");
                            scanf("%d", &c);
                            switch(c){
                            case 1:
                                system("cls");
                                printf("Jalalabad Gas\n");
                                printf("1.Check Bill\n");
                                printf("2.Make Payment\n");
                                printf("0.Main Menu\n");
                            break;
                            case 2:
                                system("cls");
                                printf("Sundarban Gas\n");
                                printf("1.Check Bill\n");
                                printf("2.Make Paayment\n");
                                printf("0.Main Menu\n");
                            break;
                            case 3:
                                system("cls");
                                printf("Paschimanchal Gas\n");
                                printf("1.Check Bill\n");
                                printf("2.Make Paayment\n");
                                printf("0.Main Menu\n");
                           break;
                           case 4:
                                system("cls");
                                printf("Karnaphuli Gas\n");
                                printf("1.Check Bill\n");
                                printf("2.Make Payment\n");
                                printf("0.Main Menu\n");
                          break;
                          case 0:
                                system("cls");
                                printf("returning to main menu will be updated soon...");
                                Sleep(1000);
                                menu(input3, balance, saved_pin);
                         break;
                         }

                    break;
                    case 4:
                          //water
                            system("cls");
                            printf("Water\n");
                            printf("1.Dhaka WASA\n");
                            printf("2.Chattogram WASA\n");
                            printf("3.Rajshahi WASA\n");
                            printf("4.Khulna WASA (Metered)\n");
                            printf("0.Main Menu\n");
                            scanf("%d", &c);
                            switch(c){
                            case 1:
                               system("cls");
                               printf("Dhaka WASA\n");
                               printf("1.Check Bill\n");
                               printf("2.Make Paayment\n");
                               printf("0.Main Menu\n");
                           break;
                           case 2:
                               system("cls");
                               printf("Chattogram WASA\n");
                               printf("1.Check Bill\n");
                               printf("2.Make Payment\n");
                               printf("0.Main Menu\n");
                           break;
                           case 3:
                               system("cls");
                               printf("Rajshahi WASA\n");
                               printf("1.Check Bill\n");
                               printf("2.Make Paayment\n");
                               printf("0.Main Menu\n");
                           break;
                           case 4:
                               system("cls");
                               printf("Khulna WASA(Metered)\n");
                               printf("1.Check Bill\n");
                               printf("2.Make Payment\n");
                               printf("0.Main Menu\n");
                           break;
                           case 0:
                               system("cls");
                               printf("returning to main menu will be updated soon...");
                               Sleep(1000);
                               menu(input3, balance, saved_pin);
                           break;
                          }
                    break;
                    case 5:
                            //Internet and Phone
                            system("cls");
                            printf("Internet and Phone \n");
                            printf("1.BTCL\n");
                            printf("2.Link3\n");
                            printf("3.AmberIT\n");
                            printf("4.Carnival\n");
                            printf("5.Sam Online\n");
                            printf("6.Triangle\n");
                            printf("7.KS Network\n");
                            printf("8.Dot Internet\n");
                            printf("0.Main Manu\n");
                            scanf("%d", &c);
                            switch(c){
                            case 1:
                               system("cls");
                               printf("BTCL\n");
                               printf("1.Check Bill\n");
                               printf("2.Make Payment\n");
                               printf("0.Main Menu\n");
                           break;
                           case 2:
                               system("cls");
                               printf("Link3\n");
                               printf("1.Check Bill\n");
                               printf("2.Make Payment\n");
                               printf("0.Main Menu\n");
                           break;
                           case 3:
                               system("cls");
                               printf("AmberIT\n");
                               printf("1.Check Bill\n");
                               printf("2.Make Payment\n");
                               printf("0.Main Menu\n");
                           break;
                           case 4:
                               system("cls");
                               printf("Carnival\n");
                               printf("1.Check Bill\n");
                               printf("2.Make Payment\n");
                               printf("0.Main Menu\n");
                          break;
                          case 5:
                               system("cls");
                               printf("Sam Online\n");
                               printf("1.Check Bill\n");
                               printf("2.Make Payment\n");
                               printf("0.Main Menu\n");
                          break;
                          case 6:
                               system("cls");
                               printf("Triangle\n");
                               printf("1.Check Bill\n");
                               printf("2.Make Payment\n");
                               printf("0.Main Menu\n");
                          break;
                          case 7:
                               system("cls");
                               printf("KS Network LTD\n");
                               printf("1.Check Bill\n");
                               printf("2.Make Payment\n");
                               printf("0.Main Menu\n");
                          break;
                          case 8:
                               system("cls");
                               printf("Dot Internet\n");
                               printf("1.Check Bill\n");
                               printf("2.Make Payment\n");
                               printf("0.Main Menu\n");
                         break;
                         case 0:
                               system("cls");
                               printf("returning to main menu will be updated soon...");
                               Sleep(1000);
                               menu(input3, balance, saved_pin);
                        break;
                       }
                    break;
                    case 6:
                           //Internet and Phone
                            system("cls");
                            printf("TV\n");
                            printf("1.AKASH DTH\n");
                            printf("2.JCCL\n");
                            printf("3.Jadoo Digital\n");
                            printf("0.Main Menu\n");
                   break;
                   case 7:
                            //city services
                            system("cls");
                            printf("City Services\n");
                            printf("1.Sylhet City Corporation\n");
                            printf("0.Main Menu\n");

                   break;
                   case 8:
                            //education
                            system("cls");
                            printf("Education\n");
                            printf("1.GPCPSC\n");
                            printf("2.RCPSC\n");
                            printf("3.MUBC\n");
                            printf("4.VNSC\n");
                            printf("5.MCPSC\n");
                            printf("6.Eduman\n");
                            printf("7.KPBSC\n");
                            printf("8.Pay2Fee\n");
                            printf("9.Uttara University\n");
                            printf("0.Main Menu\n");

                  break;
                  case 9:
                           //financial services
                            system("cls");
                            printf("Financial Services\n");
                            printf("1.IPDC Finance\n");
                            printf("2.MetLife\n");
                            printf("3.Prime islami Life\n");
                            printf("4.Pragati Life\n");
                            printf("5.Guardian Life\n");
                            printf("6.Delta Life\n");
                            printf("7.Chartered Life\n");
                            printf("8.Alpha islami Life\n");
                            printf("9.Sandhani Life\n");
                            printf("10.Bengal Islami Life\n");


                  break;
                  case 10:
                           //other
                            system("cls");
                            printf("Other\n");
                            printf("1.Check Bill\n");
                            printf("2.Make Payment\n");
                            printf("0.Main Menu\n");
                 break;
                 case 0:
                            //return the main manue
                            system("cls");
                            printf("returning to main menu will be updated soon...");
                            Sleep(1000);
                            menu(input3, balance, saved_pin);

               break;}
        break;
        //Add Money option *******
        case 7:
            system("cls");
            printf("Add Money\n");
            printf("1.Add Money from Agent\n");
            printf("Enter your choice: \n");
            scanf("%d", &b);
            switch(b){
            case 1:
                system("cls");
                printf("Enter Agent cKash Account No: ");
                scanf("%d", &number);
                system("cls");
                printf("Enter Amount: ");
                scanf("%lf", &amount);
                system("cls");
                printf("Add Money\n");
                printf("From: %d\n", number);
                printf("Amount: Tk %.2lf\n", amount);
                printf("Enter code provided by Agent: \n");
                scanf("%d", &agent_secret);
                cashOutFee = (14.50 * amount) / 1000.00;
                balance = balance + amount;
                system("cls");
                system("COLOR 20");
                printf("Add Money TK %.2lf from %d Sucessful. Balance Tk %.2lf. TrxID %s ", amount, number, balance, randomStr );
                free(randomStr);
                FILE *file = fopen("statements.txt", "a");
                FILE *balanceFile = fopen("balance.txt", "w");
                if(file == NULL || balanceFile == NULL){
                    perror("Error opening file");
                    return 1;
                }
                fprintf(file, "%s Add Money - Tk %.2lf\n", date_str, amount);
                fprintf(balanceFile, "%.2lf", balance);
                fclose(file);
                fclose(balanceFile);
            }
            break;
        //Download ckash App option ********
        case 8:
            system("cls");
            printf("1.Get up to 125TK bonus & exclusive offers\non ckash APP! Download now!\n");
            printf("0.Main Menu\n");
            scanf("%d", &b);
            system("cls");
                if(b==1){
                  printf("You request has been processed successfully");
              } else if(b==0){
                 system("cls");
                 printf("returning to main menu will be updated soon...");
                 Sleep(1000);
                 menu(input3, balance, saved_pin);
             }
             break;
        //My Ckash option *********
        case 9:
            system("cls");
            printf("ckash\n");
            printf("1.Check Balance\n");
            printf("2.Request Statement\n");
            printf("3.Change PIN\n");
            printf("4.Prito Numbers\n");
            printf("5.Save Bill\n");
            printf("6.Update MNP\n");
            printf("7.Confirm iPhone Login\n");
            printf("8.iPhone PIN Reset\n");
            printf("9.Helpline\n");
            printf("0.Main Menu\n");
            scanf("%d", &b);
            system("cls");
            switch(b){
                case 1:
                    printf("Enter Menu PIN: ");
                    scanf("%d", &pin);
                    system("cls");
                    if(pin == saved_pin){
                        printf("Your current cKash Account balance is TK %.2lf.\ncKash App diye balance check ekdom simple!", balance);
                    }else{
                        printf("Wrong Pin");
                    }
                break;
                case 2:
                    printf("Enter Menu PIN: ");
                    scanf("%d", &pin);
                    system("cls");
                    if(pin == saved_pin){
                        FILE *file = fopen("statements.txt", "r");
                        if(file == NULL){
                            printf("Error opening file");
                            return 1;
                        }
                        while ((ch = fgetc(file)) != EOF) {
                            printf("%c", ch);
                        }
                        fclose(file);
                    }else{
                        printf("Wrong Pin");
                    }
                break;
                case 3:
                      printf("Enter old PIN: ");
                      scanf("%d", &pin);
                      if(pin == saved_pin){
                            printf("Enter New PIN: ");
                            scanf("%d", &a);
                            printf("You are about to change your pin. Are you sure? Y/N\n");
                            scanf(" %c", &ch);
                            if(ch == 'y' || ch == 'Y'){
                                system("COLOR 20");
                                printf("Pin successfully changed");
                                FILE *file = fopen("secret.txt", "w");
                                    if(file == NULL){
                                        perror("Error opening file");
                                        return 1;
                                    }
                                    fprintf(file, "%d", a);
                                    fclose(file);
                            } else if(ch == 'n' || ch == 'N'){
                                menu(input3, balance, saved_pin);
                            }
                        }else{
                            system("cls");
                            system("COLOR 47");
                            printf("Wrong Pin");
                        }
                break;
                case 0:
                        system("cls");
                        printf("returning to main menu will be updated soon...");
                        Sleep(1000);
                        menu(input3, balance, saved_pin);
                 break;
            }
            break;
        //Resent PIN Option **********
        case 10:
            system("cls");
            printf("Enter you cKash registered NID/Passport/\nDriving License Number:\n");
            break;
        default:
            system("cls");
            system("COLOR 47");
            printf("You entered wrong keyword. Please enter *1023# for cKash");
        }
        break;
    default:
        system("cls");
        system("COLOR 47");
        printf("USSD code invalid...\nPlease dial *1023# for cKash interface");
    }
}
int main()
{
    // system("COLOR 47");
    int input3, saved_pin, temp;
    double balance;
    FILE *file = fopen("balance.txt", "r");
    FILE *secret = fopen("secret.txt", "r");
    if(secret == NULL){
        printf("Welcome to Our Online Mobile Banking Platform \nSetup Pin for the first time...\n");
        printf("Enter a new pin: \n");
        scanf("%d", &saved_pin);
        printf("Confirm new pin: \n");
        scanf("%d", &temp);
        if(saved_pin == temp){
            FILE *secret = fopen("secret.txt", "w");
            fprintf(secret, "%d", saved_pin);
            printf("Pin successfully created\n");
            fclose(secret);
            system("cls");
        } else {
            system("COLOR 47");
            printf("Pin confirmation failed\n");
            return 1;
        }
    }
    if(file == NULL){
        FILE *file = fopen("balance.txt", "w");
        fprintf(file, "%lf", 0.00);
        fclose(file);
    }
    fscanf(file, "%lf", &balance);
    fscanf(secret, "%d", &saved_pin);
    fclose(file);
    fclose(secret);
    char input[50], input2[]="*1023#";
    printf("Please Enter *1023#:\n");
    scanf("%s", &input);
    input3 = (strcmp(input2, input));
    system("cls");
    menu(input3, balance, saved_pin);
    getch();
}


