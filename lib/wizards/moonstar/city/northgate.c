inherit "room/room";

reset(arg) {
  object ob,ob2;
  if(arg) return;
  add_exit("north", "out: 97 79");
  add_exit("south", "world/city/gold1");
  short_desc = "Northern gates of Duranghom";
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

