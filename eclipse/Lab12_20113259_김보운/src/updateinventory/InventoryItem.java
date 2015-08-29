package updateinventory;

import java.text.DecimalFormat;

public class InventoryItem
{
   private String name;
   private int units;
   private float price;
   private DecimalFormat fmt;
   
   public InventoryItem(String itemName, int numUnits, float cost)
   {
      name=itemName;
      units=numUnits;
      price=cost;
      fmt = new DecimalFormat("0.##");
   }
   
   public String toString()
   {
      return name + ":\t" + units + " at " + price+" = "
            + fmt.format((units*price));
   }
   
   public String getName()
   {
      return name;
   }
   
   public int getUnits()
   {
      return units;
   }
   
   public float getPrice()
   {
      return price;
   }
   public void restock(int addedUnits)
   {
      units += addedUnits;
   }
}