inherit "room/room";
object monster;
int vemp;
 
reset(arg) {
 if(!monster) {
    monster = clone_object("/wizards/tiergon/dungeon/monsters/looter");
    move_object(monster, this_object()); }
  if(arg) return;
set_not_out(1);
add_exit("south","/wizards/tiergon/dungeon/top2");
  short_desc = "The supervisor's office";
  long_desc = "The once-beautiful office is dominated by a huge ebony desk.\n"+
              "A huge painting of the owner of the mine covers one wall.\n";
items = allocate (4); 
items[0] = "painting";
items[1] = "The painting isn't actually hung on the wall, you can't decide how it has been actually put there.";
items[2] = "desk";
items[3] = "The ebony desk is a truly fine piece of furniture, pity it looks so heavy";
}
init() {
  ::init();
  add_action("plus", "open");
  add_action("plus", "pull");
 }
plus(str) {
  if(str == "painting") {
  if(vemp == 1) { return; } 
  tell_room(this_object(), "As you try to remove the painting, the whole northern wall collapses with a deafening crash!\n");
  add_exit("north","/wizards/tiergon/dungeon/vault3");
  vemp = 1;
  return 1;
}
}
