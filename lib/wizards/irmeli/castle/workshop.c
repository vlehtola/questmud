

inherit "room/room";
inherit "room/shop_d";

object stoneworker;

reset(arg) {
        if(!stoneworker) {
            stoneworker = clone_object("/wizards/irmeli/castle/monsters/stoneworker.c");
            move_object(stoneworker, this_object());
}
  call_other("/wizards/moonstar/areas/asgroth/virtual_map", "XX", 0);
        if(arg) return;
      short_desc = "Stoneworkers workshop";
      long_desc ="A stoneworkers workshop provides stones for house building and other\n"+
                 "important tasks. It's hard to breathe in here because of the stone\n"+
                 "dust which is covering the workshop. There are huge storage unit\n"+
                 "next to the east wall. It's full of different sized stones. A cash\n"+
                 "register is placed on a wooden table which is located in the\n"+
                 "northeast corner. The floor is full of different kind of tools.\n"+
                 "Available commands: list, buy <item>, peek <item>\n";
    add_exit("south", "/wizards/moonstar/areas/asgroth/virtual_map: 39 11");
  load_item("/wizards/irmeli/castle/object/mediumrock",8,8);
  load_item("/wizards/irmeli/castle/object/bigrock",8,8);
  load_item("/wizards/irmeli/castle/object/smallrock",8,8);

items = allocate(8);
items[0] = "storage unit";
items[1] = "The storage unit is full of different sized stones.";
items[2] = "cash register";
items[3] = "The cash register is grey. It's very old.";
items[4] = "table";
items[5] = "The wooden table is placed in the northeast corner. A cash register is on the table.";
items[6] = "tools";
items[7] = "The ground is full of tools. The tools are used for stone shaping.";


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

