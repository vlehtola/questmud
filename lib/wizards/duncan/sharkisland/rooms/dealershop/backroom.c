inherit "room/room";

reset(arg) {
if(arg) return;

add_exit("back","/wizards/duncan/sharkisland/rooms/dealershop/dealershop.c");


short_desc = "Backroom in a small house";
long_desc = "This is the backroom of the bait dealer's shop. It seems like\n"+
            "this room is used for storing the baits. There are three shelves\n"+
            "next to south, north and east wall. The shelves are full of glass\n"+
            "bottles which contains worms and mud. A small pit is dug in the\n"+
            "muddy ground. Looks like someone has been searching something\n"+  
            "from the ground. It's quite cold in here.\n"; 

   set_not_out(1);
   set_light(3);          

items = allocate(8);
items[0] = "ground";
items[1] = "The ground is muddy. There's a small pit in the ground.";
items[2] = "shelves";
items[3] = "The shelves are full of glass bottles.";
items[4] = "glass bottle";
items[5] = "It's full of worms and mud.";
items[6] = "pit";
items[7] = "A small pit is dug in the ground. Maybe someone has been searching something from the ground.";

  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}
