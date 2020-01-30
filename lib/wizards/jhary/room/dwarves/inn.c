inherit "room/room";
object monster;

reset(arg) 
{
  if(arg) return;
  add_exit("down","/wizards/jhary/room/dwarves/pub");
  short_desc = "At a restaurant";
  long_desc = "A tasty smell of different spices and herbs floats into \n"+
              "your nose. It's hard to differ it, but you like the mixture \n"+
              "and suddenly feel slightly hungry. That's luck, you are \n"+
              "right here in a restaurant and it isn't difficult to get a \n"+
              "meal or snack. You have to order at a counter and can sit \n"+
              "down at a table and eat the food. Sure you also can carry \n"+
              "it outside, if you are in hurry. Downwards you can drink \n"+
              "an aperitif in the bar to start the meal.\n";
}
                                        
