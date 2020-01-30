inherit "/room/map_daemon";

check_rooms(string str) {

  if (str == "p") return clone_object("/wizards/duncan/island/plains");
  if (str == "h") return clone_object("/wizards/duncan/island/hills");
  if (str == "f") return clone_object("/wizards/duncan/island/forest");
  if (str == "|") return clone_object("/wizards/duncan/island/n_s_road");
  if (str == "-") return clone_object("/wizards/duncan/island/e_w_road");
  if (str == "+") return clone_object("/wizards/duncan/island/crossing");
  if (str == "b") return clone_object("/wizards/duncan/island/beach");
  if (str == "C") return clone_object("/wizards/duncan/island/cave");
}

check_special_coords(x,y) {
  if(x == 42 && y == 14) return "/wizards/neophyte/city/entrance";
  if(x == 27 && y == 26) return "/wizards/duncan/island/entrance";
  if(x == 65 && y == 9) return "/wizards/neophyte/city/lighthouse/entrance";
  return 0;
}


get_map() {
  map = allocate(33);
 /*          12345678901234567890123456789012345678901234567890 (exit 27 ja 26)*/
  map[0] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[1] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[2] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[3] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[4] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[5] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[6] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[7] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~hhhhhh~~~~~~~ppppppppppppppppp~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[8] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~hhhhhhhhhh~pppppppppppppppppppphhhh~~~~~~~~~~~~~~~~~~~~~~~";
  map[9] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~hhhhhhhhppppppppppppppppppppppp+---?hhh~~~~~~~~~~~~~~~~~~~~";
  map[10] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~hhhhhhhpppfffffffffffppppppppppp|phhhhhhhhhh~~~~~~~~~~~~~~~~~";
  map[11] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~hhhhhhhpppffffffffffffffpppppppppp|pppppppppppp~~~~~~~~~~~~~~~~";
  map[12] = "~~~~~~~~~~~~~~~~~~~~~~~~~hhhhhhhhpppffff#####ffffffppp+------+ppppppppppppp~~~~~~~~~~~~~~~";
  map[13] = "~~~~~~~~~~~~~~~~~~~~~~~~hhhChhhppppfffff#####fffffpppp|pppppppppppppppppppp~~~~~~~~~~~~~~~";
  map[14] = "~~~~~~~~~~~~~~~~~~~~~~~~hhhhhhppppffffff#####ffffffppp|ppppppppppppppppppp~~~~~~~~~~~~~~~~";
  map[15] = "~~~~~~~~~~~~~~~~~~~~~~~~hhhhpppppfffffffff|fffffffffpp|pppppppppppbbbbbbb~~~~~~~~~~~~~~~~~";
  map[16] = "~~~~~~~~~~~~~~~~~~~~~~~~~~ppppppppffffffff|ffffffffffp|ppppppppbbbbbbbbb~~~~~~~~~~~~~~~~~~";
  map[17] = "~~~~~~~~~~~~~~~~~~~~~~~~~~pppppppppppppppp+-----------+pppbbbbbbbbbbbbb~~~~~~~~~~~~~~~~~~~";
  map[18] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~pppppppppppppp|pppppppppppppbbbbbbbbbbbbb~~~~~~~~~~~~~~~~~~~~~";
  map[19] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~pppp+-------+ppbbbbbbbbbbbbbbbbbbbbbb~~~~~~~~~~~~~~~~~~~~~~~";
  map[20] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~pppp|pppppbbbbbbbbbbbbbbbbbbbbbbbb~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[21] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~pppp|pppbbb~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[22] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~p+---+pbbb~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[23] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~ppp|ppppbb~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[24] = "~~~~~~~~~~~~~~~~~~~~~~~~~~p+--+pppbb~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[25] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~|~bppbbb~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[26] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~?~bbbb~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[27] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[28] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[29] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[30] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[31] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[32] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  return map;
}
