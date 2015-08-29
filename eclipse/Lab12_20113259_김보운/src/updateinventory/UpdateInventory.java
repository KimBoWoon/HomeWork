package updateinventory;

import java.io.*;
import java.util.StringTokenizer;

public class UpdateInventory 
{
   public static void main(String[] args)
   {
      final int MAX = 100;
      BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
      InventoryItem[] items = new InventoryItem[MAX];
      StringTokenizer tokenizer;
      String line, name, readFile = "inventory.dat", writeFile = "inventory.dat";
      int units, count = 0;
      int addedUnits;
      float price;
      
      try 
      {
         FileReader fr = new FileReader(readFile);
         BufferedReader inFile = new BufferedReader(fr);
         
         line = inFile.readLine();
         while(line != null)
         {
            tokenizer = new StringTokenizer(line);
            name = tokenizer.nextToken();
            try
            {
               units = Integer.parseInt(tokenizer.nextToken());
               price = Float.parseFloat(tokenizer.nextToken());
               items[count++]  = new InventoryItem(name, units, price);
            }
            catch(NumberFormatException exception)
            {
               System.out.println("Error in input. Line ignored.");
               System.out.println(line);
            }
            line = inFile.readLine();
         }
         inFile.close();
         
         System.out.println("\nEnter the number of additional units of each item: ");
         
         FileWriter fw = new FileWriter(writeFile);
         BufferedWriter outFile = new BufferedWriter(fw);
         //BufferedWriter bw = new BufferedWriter(new FileWriter("TestData.txt"));
         for(int scan = 0; scan < count; scan++)
         {
        	System.out.println(items[scan].getName());
        	System.out.print("몇 개를 추가할까요? : ");
        	addedUnits = in.read() - '0';
        	in.read();
        	items[scan].restock(addedUnits);
        	in.read();
            System.out.println(items[scan]);
            outFile.write(items[scan].getName() + " " + items[scan].getUnits() + " " + items[scan].getPrice() + "\r\n");
         }
         outFile.close();
      }
      catch(FileNotFoundException exception)
      {
         System.out.println("The file " + readFile + " was not found.");
      }
      catch(IOException exception)
      {
      }

   }
}