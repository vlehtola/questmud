inherit "/room/map_daemon";
int exit;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  exit = random(15)+1;
}

check_rooms(string str, string dir) {
  object ob;
  if (str == "g") {
    ob = clone_object("/wizards/celtron/cemetary/grave");
    exit -= 1;
    if(exit == 0) ob->set_guild_exit();
    return ob;
  }
  if (str == "o") return clone_object("/wizards/celtron/cemetary/grass");
  if (str == " ") {
    write("You decide to leave the cemetary.\n");
    this_player()->move_player("virtual /room/out/outmap 112 115");
    return 1;
  }
}

check_special_coords(x,y) {
  if(x == 29 && y == 8) return "/guilds/necro/base_guild";
  return 0;
}

get_map() {
  map = allocate(25);
 /*          1234567890123456789012345678901234567890 (exit 37 ja 15)*/
  map[0] =  "                                                                         ";
  map[1] =  "                                                                         ";
  map[2] =  "                                                                         ";
  map[3] =  "                                                                         ";
  map[4] =  "                                                                         ";
  map[5] =  "                                                                         ";
  map[6] =  "                           ggogoog                                       ";
  map[7] =  "                         ggooogogogo                                     ";
  map[8] =  "                         oogo?ggoo                                       ";
  map[9] =  "                           oggooog                                       ";
  map[10] = "                             gog                                         ";
  map[11] = "                                                                         ";
  map[12] = "                                                                         ";
  map[13] = "                                                                         ";
  map[14] = "                                                                         ";
  map[15] = "                                                                         ";
  map[16] = "                                                                         ";
  return map;
}
