inherit "room/room";

reset(arg) {
  object ob,ob2;
  if(arg) return;
  add_exit("east", "out: 99 80");
  add_exit("west", "world/city/mainst10");
  short_desc = "Eastern gates of Duranghom";
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

