/* example of questmud's outworld. (this is almost original) //Celtron */

inherit "room/virtual_map_d";

check_entry_room(int x, int y) {
  /* example */
  if(x == 3 && y == 3) return "/wizards/celtron/workroom";
  set_special_mark(3,3,"?"); /* alters a symbol on the map */
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
  case "=" : return "/room/out/bridge";
  case "s" : return "/room/out/swamp";
  }
}

start() {
  set_mapfile("/room/out/outmapdata");
  no_walk = ({ " ", "^", "~", "r", "#", });
}
