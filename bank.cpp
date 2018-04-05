#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
#define COUNTOF(array) (sizeof(array) / sizeof(array[0]))

//クラス定義
class Account{
public:
  int id; //配列の番号 = id
  std::string password;
  int balance;
  };

class AccountController{
public:

  // 残高照会
  void balanceInquiry(Account array[],int id){
    printf("残高 : %d円\n",array[id].balance);
  }

  //操作選択
  int input_action;
  int selectAction(){
    printf("\n--------------------------\n");
    printf("操作を選んでください\n");
    printf("1 : 残高照会\n2 : 預金\n3 : 引き出し\n");
    cin >> input_action;
    if(input_action == 1 || input_action == 2 || input_action == 3){
      return input_action;
    }else{
      printf("1,2,3から選んでください!!\n\n");
      selectAction();
    }
    return 0;
  }

  void runAction(Account array[],int id,int action){
    if(action == 1){
      balanceInquiry(array,id);
    }else if(action == 2){
      deposit(array,id);
    }else if(action == 3){
      withdraw(array,id);
    }
  }

  //預け入れ
  int input_money;
  void deposit(Account array[],int id){
    printf("\n--------------------------\n");
    printf("預金額を入力してください\n");
    cin >> input_money;
    array[id].balance += input_money;
  }

  void withdraw(Account array[],int id){
    printf("\n--------------------------\n");
    printf("引き出す額を入力してください\n");
    cin >> input_money;
    if(array[id].balance >= input_money){
      array[id].balance -= input_money;
    }else{
      printf("もうお金がありません;;;;\n");
    }
  }
};

class BankController{
public:
  Account member[10];
  int id = 0;
  //アカウント作成
  std::string password;
  int balance;
  void createAccount(){
    printf("\n--------------------------\n");
    printf("新規アカウント登録\n");
    printf("パスワードを入力してください\n");
    cin >> password;
    printf("預金額を入力してください\n");
    cin >> balance;
    member[id].id = id;
    member[0].password = password;
    member[0].balance = balance;
    printf("登録しました.idは %d です\n\n\n",id);
    id++;
    selectAction();
  }

  //ログイン
  int input_id;
  std::string input_password;
  int login(){
   printf("\n--------------------------\n");
   printf("ログイン\nidを入力してください\n");
   cin >> input_id;
   printf("パスワードを入力してください\n");
   cin >> input_password;
   // printf("%s %s\n",member[input_id].password.c_str(),input_password.c_str());
   if(member[input_id].password == input_password){
    return input_id;
   }
   printf("パスワードが違います.\n");
   return login();
   }

  //操作選択
  int input_action;
  int selectAction(){
    printf("\n--------------------------\n");
    printf("操作を選んでください\n");
    printf("1 : 新規アカウント作成\n2 : ログイン\n");
    cin >> input_action;
    if(input_action == 1){
      createAccount();
    }else if(input_action == 2){
      login();
    }else{
      printf("1,2から選んでください!!\n\n");
      selectAction();
    }
    return 0;
  }


};

int main(void)
{
  
  BankController bankController;
  AccountController accountController;


  int id = bankController.selectAction();

  while(true){
  accountController.runAction(bankController.member,id,accountController.selectAction());
  }
  return 0;
}