inherit "room/room";
object mob;
reset(arg)
{
if(!mob) {
 mob = clone_object("/wizards/yodin/areas/village/monsters/storagekeeper");
 move_object(mob, this_object());
}

if(arg) return;


short_desc = "Storeroom";
long_desc =
"This is quite small storage. Everywhere around you there are\n" +
"many shelving full of bread, cheese and ham. In the corner of the\n" +
"room is dusty table and wooden chair. You can see storagekeeper\n" +
"behind one shelf.\n";

property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";

  set_light(3);
  add_exit("south", "vh14.c");




}
