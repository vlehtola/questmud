inherit "room/room";
object monster;

reset(arg) 
{
  if(!monster) 
  { 
    monster = clone_object("/wizards/jhary/npc/kituras");
    move_object(monster, this_object());
  }
          
  if(arg) return;
  add_exit("north","/wizards/jhary/room/dwarves/dwarf13");
  short_desc = "In a shop";
  long_desc = "You step inside the one and only 'Dwarven-General-Store'. \n"+
              "This does not mean, that you can get here all you need, \n"+
              "but a lot of things are sold at the shop. The room is \n"+
              "separated after the first third with a large desk and behind \n"+
              "there is Kituras the seller. It's said, that he makes fair \n"+
              "prices and doesn't flog trash. Behind the dwarf huge racks \n"+
              "store wares till beneath the roof. At the front of the \n"+
              "counter you could read a sign and get important informations \n"+
              "how to make a maybe good deal here. You can get outside to \n"+
              "the north.\n";
}
                                        
