inherit "/room/map_daemon";

check_rooms(string str) {
  if (str == "f") return clone_object("/wizards/yodin/areas/plains/forest.c");
  if (str == "p") return clone_object("/wizards/yodin/areas/plains/plains.c");

}

check_special_coords(x,y) {
  if(x == 26 && y == 21) return "/wizards/yodin/areas/plains/entrance.c";
  return 0;
}


get_map() {
  map = allocate(29);
 /*          1234567890123456789012345678901234567890*/
  map[0] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[1] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^pppp^^^^^^^^^^";
  map[2] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ppppppppppppppppppp^^^^ppppppppp^^^^^^";
  map[3] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ppppppppppppppp^pp^^^^^^^ppppppppppp^^^";
  map[4] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^f^^^^^^^^^^^^^^^^ppp^^^^^^ppppppppp^^^^^";
  map[5] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^fffffffff^^^^^^ppppppp^^ppppppp^^^^^^^";
  map[6] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^f^^^^^pppppppppp^^^^^^^^^^^^^";
  map[7] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^f^^^^^^^^^^^^^^p^^^^^^^^^^^^^";
  map[8] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^f^^^^^^^^^^^^^pppppppp^^^^^^^";
  map[9] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^f^^^^^^^^^^^^^p^pppp^^^^^^^^^^";
  map[10] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ppppp^^^^^^^^^^p^^p^ppppp^^^^^^^";
  map[11] = "^^^^^^^^^^^^^^^^^^^^^^f^^^^^^^^^^^^^^^^^ppppppp^^^^^^^^^p^p^^pppppppppp^^";
  map[12] = "^^^^^^^^^^^^^^^^^^^^^f^f^^^^^^^^^^^^^^^ppppppppp^^^^^^^^^p^^^^p^^^^^^^^^^";
  map[13] = "^^^^^^^^^^^^^^^^^^^^f^^^f^^^^^^^^^^^^^ppppppppppp^^^^^^^^^^^^^p^^^^^^^^^^";
  map[14] = "^^^^^^^^^^^^^^^^^^^f^^^^^f^^^^^^^^^^^^ppppppppppp^^^^^^^^^^^^^p^^^^^^^^^^";
  map[15] = "^^^^^^^^^^^^^^^^^^^^f^^^^^f^^^^^^^^^^^ppppppppppp^^^^^^^^^^^^f^^^^^^^^^^^";
  map[16] = "^^^^^^^^^^^^^^^^^^^^^f^^^^^f^^^^^^^^^^ppppppppppp^^^^^^^^^^^f^^^^^^^^^^^^";
  map[17] = "^^^^^^^^^^^^^^^^^^^^^^f^^^^^f^^^^^^^^^^f^^^^^^^^^^^^^^^^^^^^f^^^^^^^^^^^^";
  map[18] = "^^^^^^^^^^^^^^^^^^^^^^^f^^^^^f^^^^^^^^^f^^^^^^^^^^^^^^^^^^^^ppppppp^^^^^^";
  map[19] = "^^^^^^^^^^^^^^^^f^^^^^^^f^^^^^fffffffff^^^^^^^^^p^p^p^p^p^^^^ppppp^^^^^^^";
  map[20] = "^^^^^^^^^^^^^^^fff^^^^^^^f^^^^^^^^^^^^^^^^^^^^^p^p^p^p^p^pppp^^ppp^^^^^^^";
   map[21] = "^^^^^^^^^^^^^^^^^^^^^^^^^f?pppppp^^^^^^^^^^^^^p^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[22] = "^^^^^^^^^^^^^fffffffffffff^^^^^^^p^^^^^^^^^^^p^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[23] = "^^^^^^^^^^^^^^fffff^^^^^f^^^^^^^^^p^^^^^^^^^p^^^ffffffffffffff^^^^^^^^^^^";
  map[24] = "^^^^^^^^^^^^^^ffff^^^^^^^^^^^^^^^^^p^^^^^^^^^fffffffffffff^^^^^^^^^^^^^^^";
  map[25] = "^^^^^^^^^^^^^^^ff^^^^^^^^^^^^^^^^^^^p^^^^^^^^^^^ffffffffff^^^^^^^^^^^^^^^";
  map[26] = "^^^^^^^^^^^^^^^f^^^^^^^^^^^^^^^^^^^^^pppppppppppppffffffffff^^^^^^^^^^^^^";
  map[27] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[28] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  return map;
}
