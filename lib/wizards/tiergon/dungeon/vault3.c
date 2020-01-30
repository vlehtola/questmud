inherit "room/room";
object monster,herbs;

reset(arg) {
if (!monster) {
    monster = clone_object("/wizards/tiergon/dungeon/monsters/lurker");
    move_object(monster, this_object());
}
if (!herbs) {
   herbs = clone_object("/wizards/tiergon/dungeon/herbs");
   move_object(herbs, this_object());
}
set_not_out(1);
add_exit("south","/wizards/tiergon/dungeon/topoffice");
  short_desc = "The supervisor's hidey-hole";
  long_desc = "The supervisor used to keep things he squirreled away from owners in this room until he was caught. "+
                "Since then he has only kept his guard and a few herbs to feed it.\n";
}
