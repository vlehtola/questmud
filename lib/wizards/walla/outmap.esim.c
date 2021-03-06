inherit "room/virtual_map_d";

#define AREA_D "/daemons/area_entry_d"
#define CASTLE_D "/castle/obj/castle_location_d"
#define AMBUSH_CHANCE 10 /* x0.001 */

check_entry_room(int x, int y) {
  string file;
  file = CASTLE_D->get_castle_entrance(x, y);
  if(file) return file;

  return AREA_D->check_special_coords(x,y);
}

/* kaikki roadit on safe zonea */
status ambush_safe_zone(string t) {
  switch(t) {
  case "+": return 1;
  case "-": return 1;
  case "/": return 1;
  case "|": return 1;
  case "\\": return 1;
  case "?": return 1;
  case "#": return 1;
  case "=": return 1;
  }
/*  if(this_player()->query_wiz()) tell_object(this_player(), "NOSAFE\n"); */
  return 0;
}

object room_loaded(object room, int x, int y, string map_symbol) {
  object aroom, ob;
  int i;
  if(this_player()->query_npc()) return 0;
  if(file_name(room)[0..9] != "/room/out/") return 0;
  if(ambush_safe_zone(map_symbol)) return 0;

  if(this_player()->query_invisible()) {
    tell_object(this_player(), "You avoid an ambush by being invisible.\n");
    return 0;
  }
  if(random(1000) > AMBUSH_CHANCE ) return 0;
  if(this_player()->query_skills("hiking") > random(200)) {
    tell_object(this_player(), "Due to your knowledge in hiking, you succeed to avoid an ambush.\n");
    return 0;
  }
  aroom = clone_object("/room/ambush/ambush_room");
  aroom->start(map_symbol, x, y, room);
  return aroom;
}

get_terrain_ep_cost(string msymbol) {
  switch(msymbol) {
  case "f": return 3;
  case "F": return 4;
  case "h": return 4;
  case "H": return 6;
  case "s": return 8;
  case "p": return 1;
  }
}

get_minimap_size(string msymbol) {
  switch(msymbol) {
  case "f" : return 3;
  case "F" : return 2;
  case "s" : return 3;
  }
}

query_room_file(string letter) {
  switch(letter) {
  case "p" : return "/room/out/plains";
  case "f" : return "/room/out/forest";
  case "F" : return "/room/out/dense_forest";
  case "-" : return "/room/out/w_e_road";
  case "|" : return "/room/out/n_s_road";
  case "/" : return "/room/out/ne_sw_road";
  case "+" : return "/room/out/road_crossing";
  case "h" : return "/room/out/hills";
  case "H" : return "/room/out/high_hills";
/*  case "r" : return "/room/out/river"; */
  case "=" : return "/room/out/bridge";
  case "s" : return "/room/out/swamp";
  }
}

start() {
  set_mapfile("/room/out/outmapdata");
  no_walk = ({ " ", "^", "~", "r", "#", });
  AREA_D->reset_special_marks();
  CASTLE_D->reset_special_marks();
/*  set_special_mark(20,20,"?"); */
}
