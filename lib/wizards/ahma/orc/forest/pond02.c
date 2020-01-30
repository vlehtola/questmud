inherit "room/room";
int i;
object mob01, mob02, ob;

reset(arg) {
  add_exit("surface", "/wizards/ahma/orc/forest/for11");
  add_exit("cave", "/wizards/ahma/orc/forest/cave01");
  short_desc = "Diving in a forest pond";
  long_desc = "You are diving near the bottom of the sparkling blue forest pond. The cave mouth\n" +
              "is located in west and surface can be seen high above where the bubbles rise.\n";

  if(!mob01) { move_object(mob01 = clone_object("/wizards/ahma/orc/mob/seashell"), this_object()); }
  if(!mob02) {
    move_object(mob02 = clone_object("/wizards/ahma/orc/mob/seashell"), this_object());
    present("seashell", this_object())->secname();
  }
  set_blocker("seashell", "cave");
  set_water(10);
}

init() {
  ::init();
  add_action("surface", "surface");
  add_action("cave", "cave");
  call_out("makeharm", 2);
  i = 1;
}

surface() {
  call_out("message", 2);
  i = 0;
  return;
}

cave() {
  i = 0;
  return;
}

message() {
  ob = this_player();
  call_other("/wizards/ahma/orc/forest/for11", "comingup", ob);
}

makeharm() {
  if(this_player()->query_race() == "lizardman" || this_player()->query_name() == "Seashell") return;
  if(i) {
  if(this_player()->query_current_room() == "/wizards/ahma/orc/forest/pond02") { 
  write("\nYou are running out of air and feel that your consciousness is getting weaker.\n");
  this_player()->hit_with_spell(200 + random(51));
  call_out("makeharm", 3); }
  }
}

checkshell() {
  if(!mob01) { move_object(mob01 = clone_object("/wizards/ahma/orc/mob/seashell"), this_object()); }
  if(!mob02) {
    move_object(mob02 = clone_object("/wizards/ahma/orc/mob/seashell"), this_object());
    present("seashell", this_object())->secname();
  }
}
