inherit "room/room";
object mob01, mob02;
int childnum;

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/village/house01");
  add_exit("east", "/wizards/ahma/orc/village/vil10");
  short_desc = "Western part of Orgam street";
  long_desc = "########### The Orgam street ends in thick forest. A hut-like building is\n" + 
              "#    H   |# located in north. There are no doors in the doorway, so it can\n" + 
              "#    *---+# be entered anytime. In south the road is lined with green bushes.\n" + 
              "#         # A fallen, wooden tricycle is lying near the western wall of the\n" + 
              "########### hut. Some birds are holding a concerto on the branches of the tree in west.\n";

  items = allocate(4);
  items[0] = "tricycle";
  items[1] = "Looks like the wooden tricycle has taken a lot of damage due to many\n" + 
             "collissions with different objects. Though wood is not a convenient\n" +
             "material for making a tricycle, seems that someone has had a lot of\n" +
             "fun with this simple, clumsy object";
  items[2] = "birds";
  items[3] = "Some common wagtails have landed on a branch of a nearby tree. They are\n" +
             "singing their charasteristic tune, but it feels somehow more soothing in\n" + 
             "this very place than anywhere else";

  if(childnum < 2) { if(!mob01) { move_object(mob01 = clone_object("/wizards/ahma/orc/mob/child"), this_object()); childnum++; } }
  if(childnum < 2) { if(!mob02) { move_object(mob02 = clone_object("/wizards/ahma/orc/mob/child"), this_object()); childnum++; } }
}

init() {
  ::init();
  add_action("map", "map");
}

map() {
  tell_object(this_player(), read_file("/wizards/ahma/orc/map"));
  return 1;
}

childdead() {
  childnum--;
}
