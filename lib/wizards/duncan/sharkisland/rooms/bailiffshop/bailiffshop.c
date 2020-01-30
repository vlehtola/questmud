inherit "room/room";
inherit "room/shop_d";

object bailiff;

reset(arg) {
        if(!bailiff) {
            bailiff = clone_object("/wizards/duncan/sharkisland/monsters/bailiff.c");
            move_object(bailiff, this_object());
}
  call_other("/wizards/duncan/sharkisland/virtual_map", "XX", 0);
        if(arg) return;

      short_desc = "Water bailiff's shop";
      long_desc ="A small wooden house is built on the island. The house is owned by the\n"+
                 "water bailiff of the island. He's keeping a small shop for the people\n"+ 
                 "who are interested about fishing. The walls are covered with fishing\n"+
                 "nets and other fishing stuff. A small shelf is placed next to the north\n"+
                 "wall. A wooden table is in the middle of the room. A cash register is\n"+
                 "on table. A huge portrait is hanging from the south wall. There's a\n"+
                 "doorway on the eastern wall. The shop is lit up with a few torches.\n"+
                 "Available commands: list, buy <item>, peek <item>\n";
  
   set_not_out(1);
   set_light(3);

add_exit("out", "/wizards/duncan/sharkisland/virtual_map: 69 11");
add_exit("east", "/wizards/duncan/sharkisland/rooms/bailiffshop/room1");

  load_item("/wizards/duncan/sharkisland/object/hook",5,8);
  load_item("/wizards/duncan/sharkisland/object/line",5,8);

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

