/* cloned for each ambush case */
inherit "room/room";
#define AMBUSH_D	"/room/ambush/ambush_monster_d"
#define OUTMAP 		"/room/out/outmap"
#define FLEE		5
#define HORDE_VOID	"/guilds/necro/obj/summon_void"

string terrain;
int coord_x, coord_y;

void allow_flee() {
  int rnd_x, rnd_y, i;
  if(this_object()->query_valid_dir("flee")) return;

  if(!random(2)) rnd_x = random(FLEE);  else rnd_x = - random(FLEE);
  if(!random(2)) rnd_y = random(FLEE);
  else rnd_y = - random(FLEE);

  for(i=0; i < 2; i++) {
    if(OUTMAP->generate_room((coord_x+rnd_x), (coord_y+rnd_y), OUTMAP->get_map_char((coord_x+rnd_x),(coord_y+rnd_y)) )) {
      if(!random(3)) tell_room(this_object(), "You notice a possibility to flee.\n");
      add_exit("flee", "virtual /room/out/outmap "+(coord_x+rnd_x)+" "+(coord_y+rnd_y));
      return;
    }
    if(rnd_x < 0) rnd_x = -rnd_x;
    else if(rnd_y < 0) rnd_y = -rnd_y;
    else if(rnd_x > 0) rnd_x = -rnd_x;
    else rnd_y = -rnd_y;
  }

}


/* outmap calls this func to start the ambush */
start(string t, int x, int y, object original_room) {
  terrain = t;
  coord_x = x;
  coord_y = y;
  add_exit("leave", "outmap: "+x+" "+y);
  generate_descs(original_room);
  AMBUSH_D->get_monsters(terrain, coord_x, coord_y, this_object());
}

generate_descs(object original_room) {
  short_desc = original_room->short();
  long_desc = original_room->query_long();
  if(!short_desc) {
    short_desc = "In wilderness";
    long_desc = "Deep in wilderness, no signs of habitation can be seen.\n"+
		"These parts of Deleria are definetly not the safest.\n";
  }
}

init() {
  ::init();
  add_action("player_leave", "leave");
  add_action("player_leave", "flee");
}

player_leave() {
  remove_call_out("destruction");
  call_out("destruction", 20);
  return 0;
}

destruction() {
  int i;
  object *ob;
  ob = all_inventory(this_object());
  for(i=0; i < sizeof(ob); i++) {
    if(ob[i] && living(ob[i]) ) {
      if(!ob[i]->query_npc()) {
	return; 
      } else if(ob[i]->query_horde_master()) {
	move_object(ob[i], HORDE_VOID);
	ob[i] = 0;
      }
    }
  }
  /* ja sitten poks */
  for(i=0; i < sizeof(ob); i++) {
    if(ob[i] && present(ob[i], this_object()) )
	destruct(ob[i]);
  }
  destruct(this_object());
}
