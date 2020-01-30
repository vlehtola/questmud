inherit "room/room";
object monster;

reset(arg) {
if(!monster) {
monster = clone_object("/wizards/belar/dwarf/monsters/gdw2.c");
move_object(monster, this_object());
if(arg) return;
}
add_exit("hut","/wizards/belar/dwarf/rooms/hut1.c");
add_exit("east","/wizards/belar/dwarf/entrance.c");
short_desc = "The city wall";
long_desc = "The city walls are very high. They are covered with very rare and\n"+
            "very fragile vines. Along vines is a white flowers growing from\n"+
            "vines. There is a huge tree and in its shadow lies a red hut.\n"+
            "The hut is obviously habited by some creature.\n";
items = allocate(2);
  items[0] = "wall";
  items[1] = "The wall vines cover the whole wall";
}

