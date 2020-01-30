inherit "/room/map_daemon";

check_rooms(string str) {
if (str == "F") return clone_object("/wizards/yodin/areas/metsa/forest");
if (str == "p") return clone_object("/wizards/yodin/areas/metsa/plains");
if (str == "f") return clone_object("/wizards/yodin/areas/metsa/forest");

}

check_special_coords(x,y) {
    if(x == 28 && y == 23) return "/wizards/yodin/areas/metsa/entrance.c";
  return 0;
}
/* Fixed some bugs on map 12.12.08 -Kaappi */
get_map() {
map = allocate(33);
 /*          01234567890123456789012345678901234567890 */ 
   map[0] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[1] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[2] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[3] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[4] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[5] =  "^^^^^^pppppppp^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[6] =  "^^^^^^pppppppp^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[7] =  "^^^^^^pppppppp^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[8] =  "^^^^^^ppppppppp^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[9] =  "^^^^^^pppppp^^^^^^^^^^^^^^^^^^^^^^^^^^^^^f^^^^^^^^^^^^^^^^^^^^^^ff^^^^^^^^^";
  map[10] = "^^^^^^ppppp^^^^^^^^^^^^^^^^^^^^^^^^^^^^^f^f^^^^^^^^^^^^^^^^^F^^?ff?^^^^^^^^";
  map[11] = "^^^^^^pppp^^^^^^^^^^^^^^^^^^^^^^^^^f^^^f^^^ffff^^^^^^^^^^^^FF^^^^f^^^^^^^^^";
  map[12] = "^^^^^^pppp^^^^^^^^^^^^^^^^^^^^^^^^f^fff^^^^^^^^ffff^^^^^^^FFFF^^^^^FFFFF^^^";
  map[13] = "^^^^^^ppp^^^^^^^^^^^^^^^^^^^^^^^^^f^^f^^^^^^^^^^^^^f^^^^^FFFFF^^^^^^FFF^^^^";
  map[14] = "^^^^^^pppp^^^^^^^^^^^^^^^^^^^^^FFFF^^f^^^^^^^^^^^^^f^^^^FFFFFFF^^^^^FFF^^^^";
  map[15] = "^^^^^^pppp^^^^^^^^^^^^^^^^^^^pppppp^^ffffffffffffffff^^FFFFFFFFF^^^^FFFF^^^";
  map[16] = "^^^^^^ppp^^^^^^^^^^^^^^^^^^pppppppp^^^^^^^^^^^^^^^^^^^FFFFFFFFF^^^^FFFF^^^^";
  map[17] = "^^^^^^ppp^^^^^^^^^^^^^^^^^pppppppppp^^^^^^^^^^^^^^^^FFFFFFFFFF^^^^^FFFFF^^^"; 
  map[18] = "^^^^^^^ppp^^^^^^^^^^^^^^^pppppppppppp^^^^^^^^^^^^FFFFFFFFFF^^^^^FFFFFF^^^^^";
  map[19] = "^^^^^^^^pp^^^^^^^^^^^^^^pFppppppppppFp^^^^^^^^^FFFFFFFFFF^^^^^FFFFF^^^^^^^^";
  map[20] = "^^^^^^^^ppp^^^^^^^^^^^^^ppFppppppppFpp^^^^^^^^FFFFFFFFFFF^^^^^^^FFFF^^^^^^^";
  map[21] = "^^^^^^^^pppppp^^^^^^^^^^^pppppppppppp^^^^^^^^FFFFFFFFFFFFF^^^^FFFF^^^^^^^^^";
  map[22] = "^^^^^^^^^^^ppp^^^^^^^^^^^^pppppppppp^^^^^^^^^FFFFFFFFFFFFF^^^^^FFF^^^^^^^^^";
  map[23] = "^^^^^^^^^^^^ppp^^^^^^^^^^^^^?^^^^^^^FFFFFFFFFFFFFFFFFFF^^^^^^^FF^^^^^^^^^^^";
  map[24] = "^^^^^^^^^^^^^pppppppppppppp^^^^pp^^FFFFFFFFFFFFFFFFFFFFF^^^^^FFF^^^^^^^^^^^";
  map[25] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^FFFFFFFFFFFFFFFFFF^^^^^FFFFFFFFFFFFF^^^^^^^^^^^^";
  map[26] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^FFFFFFFFFFFFFFF^^^^^^^^FFFFFFFFFFF^^^^^^^^^^^";
  map[27] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^FFFFFFFFFFF^^^^^^^^^^^FFFFFFF^^^^^^^^^^^^";
  map[28] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[29] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[30] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[31] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[32] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  return map;
}