inherit "room/room";
object monster;

reset(arg) {
   if (!monster) {
   monster = clone_object("/wizards/tiergon/dungeon/monsters/bcguard2");
   move_object(monster, this_object()); }
set_not_out(3);
add_exit("east","/wizards/tiergon/dungeon/b2");
add_exit("west","/wizards/tiergon/dungeon/b4");
  short_desc = "Entrance to the chapel of Morai";
  long_desc = "This is the entance to the chapel of Morai the Betrayer built by the Black Circle. "+
                "Looks like the Circle keeps a guard here at all times.\n"+
                "The room is lit by a torch.\n";
items = allocate (2);
items[0] = "torch";
items[1] = "A metallic torch burning with a crimson flame";
}
