inherit "room/room";
string master, tmp;
object drago;

reset(arg) {
 if(arg) return;
 set_light(3);
 set_not_out(1);
 short_desc = "Test room";
 long_desc = "Next room ->\n";
 add_exit("east", "/wizards/rimber/test/room1.c");
}

init() {
 ::init();
 add_action("reclaim", "reclaim");
}

reclaim(str) {
 object drage;
 if(!str) {
  write("Reclaim what?\n");
  return 1;
 }
 if(sscanf(str, "dragon %s", tmp) == 1) {
 if(!tmp) write("Use 'reclaim dragon <type>'\n");
 master = this_player()->query_name();
 drage = clone_object("/wizards/rimber/test/dragon.c");
 drage->setType(tmp);
 object pilli = clone_object("/wizards/rimber/test/whistle.c");
 move_object(drage, this_object());
 move_object(pilli, this_player());
 drage->masteri();
 pilli->setDragon(drage);
 return 1;
 }
}

string master() { return master; }
