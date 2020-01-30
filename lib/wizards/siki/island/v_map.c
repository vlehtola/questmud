inherit "/room/map_daemon";

check_rooms(string str) {
  if (str == "b") return clone_object("/wizards/siki/island/bush");
  if (str == "p") return clone_object("/wizards/siki/island/plains");
  if (str == "h") return clone_object("/wizards/siki/island/hills");
  if (str == "H") return clone_object("/wizards/siki/island/hhills");
}

check_special_coords(x,y) {
  if(x == 19 && y == 5) return "/wizards/siki/island/entrance";
  if(x == 15 && y == 13) return "/wizards/siki/island/ahouse1";
  if(x == 15 && y == 16) return "/wizards/siki/island/bhouse1";
  if(x == 30 && y == 13) return "/wizards/siki/island/chouse1";
  if(x == 18 && y == 17) return "/wizards/siki/island/dhouse1";
  if(x == 22 && y == 12) return "/wizards/siki/island/cave1";
}

get_map() {
  map = allocate(26);
 /*        012345678901234567890123456789012345678901234567 */
map[0] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
map[1] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
map[2] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
map[3] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
map[4] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
map[5] =  "~~~~~~~~~~~~~~~~~~~?~~pp~~~~~~~~~~~~~~~~~~~~~~";
map[6] =  "~~~~~~~~~~~~~~~~~~pppppp~~~~~~~~~~~~~~~~~~~~~~";
map[7] =  "~~~~~~~~~~~~~~~~~ppppbp~~~~~~~~~~~~~~~~~~~~~~~";
map[8] =  "~~~~~~~~~~~~~~~~ppbbpppbp~~~~~pp~~~~~~~~~~~~~~";
map[9] =  "~~~~~~~~~~~~~~~~pbbppppppp~~ppp~~~~~~~~~~~~~~~";
map[10] = "~~~~~~~~~~~~~~~ppppphHHhhhpbbp~~~~~~~~~~~~~~~~";
map[11] = "~~~~~~~~~~~~~~~~ppbHH^^^Hhpp~~~~~~~~~~~~~~~~~~";
map[12] = "~~~~~~~~~~~~~~bpbphh^^?H^hhppp~~~~~~~~~~~~~~~~";
map[13] = "~~~~~~~~~~~~~bb?bbphH^^Hh^hppp?~~~~~~~~~~~~~~~";
map[14] = "~~~~~~~~~~~~~~ppphhh^^^HHhhpbbp~~~~~~~~~~~~~~~";
map[15] = "~~~~~~~~~~~~~~bpppphhhhhpppppppbppp~~~~~~~~~~~";
map[16] = "~~~~~~~~~~~~ppp?pppphppp~~~~~pppppp~~~~~~~~~~~";
map[17] = "~~~~~~~~~~~~~pppbb?ppp~~~~~~~~~~~pppp~~~~~~~~~";
map[18] = "~~~~~~~~~~~~~~~ppppbbbpp~~~~~~~~~~~~p~~~~~~~~~";
map[19] = "~~~~~~~~~~~~~~~~~ppbbbbbbpp~~~~~~~~~~~~~~~~~~~";
map[20] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
map[21] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
map[22] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
map[23] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

map[24] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
map[25] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
return map;
}
