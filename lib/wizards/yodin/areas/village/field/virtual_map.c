inherit "/room/map_daemon";

check_rooms(string str) {
  if (str == "F") return clone_object("/wizards/yodin/areas/village/field/forest");
  if (str == "p") return clone_object("/wizards/yodin/areas/village/field/plains");

}

check_special_coords(x,y) {
  if(x == 26 && y == 21) return "/wizards/yodin/areas/village/field/entrance";
  return 0;
}


get_map() {
  map = allocate(29);
 /*          1234567890123456789012345678901234567890*/
  map[0] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[1] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[2] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[3] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[4] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[5] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[6] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[7] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[8] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[9] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[10] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[11] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[12] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[13] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[14] = "^^^^^^^^^^^^^^^^^^^^^^^^^pppppppp^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[15] = "^^^^^^^^^^^^^^^^^^^^^^^^ppFppppFpp^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[16] = "^^^^^^^^^^^^^^^^^^^^^^^pppFppppFppp^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[17] = "^^^^^^^^^^^^^^^^^^^^^^pFppppppppppFp^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[18] = "^^^^^^^^^^^^^^^^^^^^^^ppFppppppppFpp^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[19] = "^^^^^^^^^^^^^^^^^^^^^^^ppFFFFFFFFpp^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[20] = "^^^^^^^^^^^^^^^^^^^^^^^^pppppppppp^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[21] = "^^^^^^^^^^^^^^^^^^^^^^^^^^?^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[22] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[23] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[24] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[25] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[26] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[27] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[28] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  return map;
}