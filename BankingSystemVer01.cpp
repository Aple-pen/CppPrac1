#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;
void showMenu(void)
{
    cout << "====MENU====" << endl;
    cout << "1. 계좌 개설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
    cout << "선택 : ";
}

void createAccount(void);
void printAccountInfo(void);
void deposit(void);
void withDraw(void);
void quitProgram(void);

typedef struct
{
    int accId;
    int balance;
    char cusName[NAME_LEN];
} Account;

Account accArr[100];
int accNum = 0;

int main()
{
    int choice = 0;
    while (1)
    {
        showMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            createAccount();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withDraw();
            break;
        case 4:
            printAccountInfo();
            break;
        case 5:
        default:
            quitProgram();
            return 0;
        }
    }
    return 0;
}

void createAccount(void)
{ //계좌 계설
    int id;
    char name[NAME_LEN];
    int balance;

    cout << "====계좌 개설====" << endl;
    cout << "계좌ID : ";
    cin >> id;
    cout << "이름 : ";
    cin >> name;
    cout << "입금액 : ";
    cin >> balance;

    accArr[accNum].accId = id;
    accArr[accNum].balance = balance;
    strcpy(accArr[accNum].cusName, name);

    accNum++;
}
void deposit(void)
{ //입금
    int id;
    int balance;
    cout << "계좌 ID : ";
    cin >> id;
    cout << "입금액 : ";
    cin >> balance;
    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i].accId == id)
        {
            accArr[i].balance += balance;
        }
        else
        {
            cout << "유효하지 않은 ID 입니다." << endl
        }
    }
    cout << "입금 완료" << endl;
}

void withDraw(void)
{ //출금
    int id;
    int balance;
    cout << "계좌 ID : ";
    cin >> id;
    cout << "입금액 : ";
    cin >> balance;
    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i].accId == id)
        {
            if (accArr[i].balance < balance)
            {
                cout << "잔액이 부족합니다." << endl;
                return;
            }
            else
            {
                accArr[i].balance -= balance;
                cout << "출금 완료" << endl;
                return;
            }
        }
        else
        {
            cout << "유효하지 않은 ID 입니다." << endl
        }
    }
}

void printAccountInfo(void)
{
    for (int i = 0; i < accNum; i++)
    {
        cout << "=================" << endl;
        cout << "계좌 ID : " << accArr[i].accId << endl;
        cout << "이름 : " << accArr[i].cusName << endl;
        cout << "입금액 : " << accArr[i].balance << endl;
        cout << "=================" << endl;
    }
}

void quitProgram(void)
{
    cout << "프로그램이 종료되었습니다." << endl;
}