package MoneyManagementSystem;
import java.util.Scanner;

public class Main {
   public static void main(String[] args) {
      Scanner scanner = new Scanner(System.in);
      System.out.println("Money Management Solution");
      System.out.println("1. Register your account");
      System.out.println("2. Login to your account");
      int choice = scanner.nextInt();

      if (choice == 1) {
         System.out.println("Enter your name:");
         String name = scanner.next();
         System.out.println("Enter your account number:");
         String accountNumber = scanner.next();
         System.out.println("Enter your phone number:");
         String phone = scanner.next();
         System.out.println("Enter your new password:");
         String password = scanner.next();

         User user = new User(phone, password);
         BankingSystem bankingSystem = new BankingSystem(name, accountNumber, user);

         try (FileWriter writer = new FileWriter(phone + ".dat")) {
            writer.write(user.getPhone() + "\n" + user.getPassword());
         } catch (IOException e) {

            System.out.println("Error writing to file: " + e.getMessage());
         }

         System.out.println("Successfully registered");
      } else if (choice == 2) {
         System.out.println("Enter your phone number:");
         String phone = scanner.next();
         System.out.println("Enter your password:");
         String password = scanner.next();

         User user = null;
         BankingSystem bankingSystem = null;

         try {
            user = loadUserFromLogFile(phone);
            bankingSystem = new BankingSystem("", "", user);
         } catch (Exception e) {
            System.out.println("Phone number not registered");
         }

         if (bankingSystem != null) {
            if (user.getPassword().equals(password)) {
               char cont = 'y';
               while (cont == 'y') {
                  System.out.println("MENU");
                  System.out.println("1. Deposit Money");
                  System.out.println("2. Withdraw Money");
                  System.out.println("3. Account details");
                  System.out.println("4. Exit");
                  int option = scanner.nextInt();

                  switch (option) {
                     case 1:
                        System.out.println("Enter the amount you want to deposit:");
                        int depositAmount = scanner.nextInt();
                        bankingSystem.depositMoney(depositAmount);
                        break;
                     case 2:
                        System.out.println("Enter the amount you want to withdraw:");
                        int withdrawAmount = scanner.nextInt();
                        bankingSystem.withdrawMoney(withdrawAmount);
                        break;
                     case 3:
                        bankingSystem.displayAccountDetails();
                        break;
                     case 4:
                        System.out.println("Exiting...");
                        return;
                     default:
                        System.out.println("Invalid choice");
                  }

                  System.out.println("Do you want to continue?");
                  System.out.print("Enter y for yes, n for no: ");
                  cont = scanner.next().charAt(0);
               }
            } else {
               System.out.println("Incorrect password");
            }
         }
      }
   }

   private static User loadUserFromLogFile(String phone) throws Exception {
      File file = new File(phone + ".dat");
      if (!file.exists()) {
         throw new Exception("Phone number not registered");
      }

      try (Scanner scanner = new Scanner(file)) {
         String storedPhone = scanner.nextLine();
         String storedPassword = scanner.nextLine();

         return new User(storedPhone, storedPassword);
      }
   }
}