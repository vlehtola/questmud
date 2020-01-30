inherit "room/room";

reset(arg) {
  object ob,ob2;
  if(arg) return;
  add_exit("south","out: 97 81");
  add_exit("north","world/city/wood4");
  short_desc = "Southern gates of Duranghom";
  long_desc = "You are standing in an arched tunnel in the city wall. Strong iron gates\n" +
     "guard the passage to Duranghom, the glorious human city that stands to the\n" +
	"east, its streets all crowded by busy people.\n";
  
  if(!ob) {
    ob = clone_object("/world/monsters/gateguard");
    move_object(ob, this_object());
  }
  if(!ob2) {
    ob2 = clone_object("/world/monsters/gateguard");
    move_object(ob2, this_object());
  }
}

