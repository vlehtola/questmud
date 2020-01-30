inherit "/room/map_daemon";

check_rooms(string str) {
  if (str == "F") return clone_object("/room/out/dense_forest");
  if (str == "p") return clone_object("/room/out/plains");
 // if (str == "R") return clone_object("/wizards/yodin/areas/island/river");//
 if (str == "h") return clone_object("/room/out/hills");
 if (str == "H") return clone_object("/room/out/high_hills");
 if (str == "s") return clone_object("/room/out/swamp");
 if (str == "=") return clone_object("/room/out/bridge");
 if (str == "\\") return clone_object("/room/out/nw_se_road");
 if (str == "/") return clone_object("/room/out/ne_sw_road");
 if (str == "|") return clone_object("/room/out/n_s_road");
}

check_special_coords(x,y) {
  if(x == 26 && y == 21) return "/wizards/yodin/areas/village/field/entrance";
  return 0;
}



get_map() {
  map = allocate(29);
  /*          1234567890123456789012345678901234567890*/
  map[0] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[1] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~hhhhhh~~~~~~~~~~~";
  map[2] =  "~~~~~~~~~~~~~~~~~~~~?~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~hhhhHHHhhhhh~~~~~~~~";
  map[3] =  "~~~~~~~~~~~~~~~~~~~~p~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~hhhhhHHH^^?Hhhhhh~~~~~";
  map[4] =  "~~~~~~~~~~~~~~~~~~~~ppp~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~hhhhhhH^^HHHHhhhhh~~";
  map[5] =  "~~~~~~~~~~~~~~~~~~~~~~ffffffffffRfffffffffffffff?~~~~~~hhhhhhH^^^^hh~~~~~";
  map[6] =  "~~~~~~~~~~~~~~~~~~fffffffffffffffRffffffffffffffffff~~~~hhhhhhHhhhhhh~~~~";
  map[7] =  "~~~~~~~~~~~~~~~fffffffpffffff?fffRffffffffffffffffffff~~/~~hhhhhhhh~~~~~~";
  map[8] =  "~~~~~~~~~~~~~fffffffffpffffffffffRfffffffffffffffffffffff~~~~~~~~~~~~~~~~";
  map[9] =  "~~~~~~~~~~~~~fffffffpffffffffffff=ffffffffffffffffffffff~~~~~~~~~~~~~~~~~";
  map[10] = "~~~~~~~~fffffffffpfffffffffffffffRfffffffffffffffffffff~~~~~~~~~~~~~~~~~~";
  map[11] = "~~~~~~fffffffffffpfffffffpfffffffRffffffffffffffffffffffff~~~~~~~~~~~~~~~";
  map[12] = "~~~~~~~~~~~~~~ffffffffffffffffffffRfffffffffffffffffffff~~~~~~~~~~~~~~~~~";
  map[13] = "~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~fffffffffffff~~~~~~~~~~~~~~~~~~~~~~~~";
  map[14] = "~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~fffff~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[15] = "~~~~~~~~~~~~~~~ppoFppfff~~~~~~~~~~~~~~~~~~~~~~~~~sss~~~~~~~~~~~~~~~~~~~~~";
  map[16] = "~~~~~~~~~~~~pppFppppFpppffffffffff~~~~~~~~~~~~~~sssss~~~~~~~~~~~~~~~~~~~~";
  map[17] = "~~~~~~~~~~~fffffffffpFppppppppppFO~~~~~~~~~~~~ssssssss~~~~~~~~~~~~~~~~~~~";
  map[18] = "~~~~~~~~~~fffffffppppppfffffffff~~\~~~~~~~~sssssssssss~~~~~~~~~~~~~~~~~~~";
  map[19] = "~~~~~~~~~~~fffffffffffpffffffff~~~~\~~~~~ssssssssssssss~~~~~~~~~~~~~~~~~~";
  map[20] = "~~~~~~~~~~~~fffffffffffffffff~~~~~~~\~~~sssssssssssss~~~~~~~~~~~~~~~~~~~~";
  map[21] = "~~~~~~~~~~~~ffffffffffffff?fff~~~~~~~\~sssssssssssss~~~~~~~~~~~~~~~~~~~~~";
  map[22] = "~~~~~~~~~~~~~~fffffffffff~~~~~~~~~~~~sssssssssssss~~~~~~~~~~~~~~~~~~~~~~~";
  map[23] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~sssssssssssss~~~~~~~~~~~~~~~~~~~~~~~~";
  map[24] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~sssssssssss~~~~~~~~~~~~~~~~~~~~~~~~";
  map[25] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ssssssss~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[26] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[27] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[28] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  return map;
}

