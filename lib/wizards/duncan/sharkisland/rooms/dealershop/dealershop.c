inherit "room/room";
inherit "room/shop_d";

object dealer;

reset(arg) {
        if(!dealer) {
            dealer = clone_object("/wizards/duncan/sharkisland/monsters/dealer.c");
            move_object(dealer, this_object());
}
  call_other("/wizards/duncan/sharkisland/virtual_map", "XX", 0);
        if(arg) return;

      short_desc = "Bait dealer's shop";
      long_desc ="This is the bait dealer's shop. The shop is quite small and it's made\n"+
                 "of wood. The ground is muddy because someone forget to built a floor\n"+
                 "in here. Two wooden shelves are placed next to the south and north wall.\n"+
                 "The shelves are full of glass bottles. A cash register is placed on\n"+
                 "a wooden table which is in the middle of the room. A huge shark's head\n"+
                 "is hanging from the ceiling. There's a doorway on the eastern wall.\n"+
                 "Burning torches are placed on the walls, lighting up the whole room.\n"+
                 "Available commands: list, buy <item>, peek <item>\n";
  
   set_not_out(1);
   set_light(3);

add_exit("out", "/wizards/duncan/sharkisland/virtual_map: 61 23");
add_exit("backroom", "/wizards/duncan/sharkisland/rooms/dealershop/backroom");

  load_item("/wizards/duncan/sharkisland/object/worm",15,8);
  load_item("/wizards/duncan/sharkisland/object/piscary",2,2);

items = allocate(12);
items[0] = "ground";
items[1] = "It's muddy and there are footprints on it.";
items[2] = "cash register";
items[3] = "The cash register is placed on a table. It's very old.";
items[4] = "table";
items[5] = "The wooden table is placed in the middle of the room. A cash register is on the table.";
items[6] = "shelves";
items[7] = "The shelves are full of glass bottles.";
items[8] = "glass bottle";
items[9] = "It's full of worms and mud.";
items[10] = "head";
items[11] = "A huge shark's head is hanging from the ceiling.";


property = allocate(3);
  property[0] = "no_spell";
  property[1] = "no_skill";
  property[2] = "no_kill";

}
init() 
{
  ::init();
  ::shop_commands();
}

save_shop() { }
restore_shop() { }

