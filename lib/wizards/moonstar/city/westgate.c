inherit "room/room";

reset(arg) {
  object ob,ob2;
  if(arg) return;
  add_exit("west", "out: 95 80");
  add_exit("east", "world/city/mainstr1");
  short_desc = "Western gates of Duranghom";
  long_desc = "You are standing in an arched tunnel in the city wall. Strong iron gates\n" +
     "guard the passage to Duranghom, the glorious human city that stands to the\n" +
	"east, its streets are crowded by busy people.\n";
  
  if(!ob) {
    ob = clone_object("/world/monsters/gateguard");
    move_object(ob, this_object());
  }
  if(!ob2) {
    ob2 = clone_object("/world/monsters/gateguard");
    move_object(ob2, this_object());
  }
}

