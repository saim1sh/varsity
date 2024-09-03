package MoneyManagementSystem;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class BankingSystem {
   private User user;
   private String name;
   private String accountNumber;
   private int balance = 10000;
   private int depositCount = 0;

   public BankingSystem(String name, String accountNumber, User user) {
      this.name = name;
      this.accountNumber = accountNumber;
      this.user = user;
   }

   public void depositMoney(int amount) {
      balance += amount;
      System.out.println("Money deposited successfully. Current balance: " + balance);
      writeTransactionToLogFile("Deposit", amount);
      depositCount++;
   }

   public void withdrawMoney(int amount) {
      if (balance < amount) {
         System.out.println("Insufficient balance");
      } else {
         balance -= amount;
         System.out.println("Money withdrawn successfully. Current balance: " + balance);
         writeTransactionToLogFile("Withdrawal", amount);
      }
   }

   public void displayAccountDetails() {
      System.out.println("Account Details:");
      System.out.println("Name: " + name);
      System.out.println("Account Number: " + accountNumber);
      System.out.println("Balance: " + balance);
   }

   private void writeTransactionToLogFile(String transactionType, int amount) {
      try (FileWriter writer = new FileWriter("userAccount.txt", true)) {
         writer.write("Tk" + amount + " had been " + transactionType.toLowerCase() + " from your account\n");
      } catch (IOException e) {
         System.out.println("Error writing to log file: " + e.getMessage());
      }
   }
}