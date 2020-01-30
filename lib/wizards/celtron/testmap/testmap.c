inherit "room/virtual_map_d";

reset(arg) {
  if(arg) return;
  set_mapfile("/wizards/celtron/testmap/testmap.map");  
}

query_room_file(string str) {
  if(str == "p") return "/wizards/celtron/testmap/plains";
  if(str == "f") return "/wizards/celtron/testmap/forest";
}
