inherit "/room/map_daemon";

check_rooms(string str) {

  if (str == "c") return clone_object("/wizards/walla/lemmings/rooms/lvl3/cave");
  if (str == "X") return clone_object("/wizards/walla/lemmings/rooms/lvl3/pillar");

}

check_special_coords(x,y) {
  if(x == 29 && y == 5) return "/wizards/walla/lemmings/rooms/shared/entrance";
  if(x == 16 && y == 19) return "/wizards/walla/lemmings/rooms/shared/3stairs";
  return 0;
}


get_map() {
map = allocate(30);
 /*          0        10        20        30        40        50      */
 /*          123456789012345678901234567890123456789012345678901234567*/
  map[0] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[1] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[2] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[3] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[4] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[5] =  "^^^^^^^^^^^^^^^^ccccccccccccc?cccccccccccc^^^^^^^^^^^^^";
  map[6] =  "^^^^^^^^^^^^^^^cccccXcccccXccccXcccXcccccccc^^^^^^^^^^^";
  map[7] =  "^^^^^^^^^^^^^^^ccccccccccccccXcccccccccccccc^^^^^^^^^^^";
  map[8] =  "^^^^^^^^^^^^^^^^cccccccXccccccccXccccccccc^^^^^^^^^^^^^";
  map[9] =  "^^^^^^^^^^^^^^^^cccXccccccccccccccccXccccc^^^^^^^^^^^^^";
  map[10] = "^^^^^^^^^^^^^^^^^^cccccc~~~~~~cccccccXccc^^^^^^^^^^^^^^";
  map[11] = "^^^^^^^^^^^^^^^^^^^ccXcc~~~~~~cccccccccXc^^^^^^^^^^^^^^";
  map[12] = "^^^^^^^^^^^^^^^^^^^^cccc~~~~~~~cccXcccccc^^^^^^^^^^^^^^";
  map[13] = "^^^^^^^^^^^^^^^^^^^^ccc~~~~~~~~ccccccccc^^^^^^^^^^^^^^^";
  map[14] = "^^^^^^^^^^^^^^^^^^^^^cXc~~~ccccXcccccXc^^^^^^^^^^^^^^^^";
  map[15] = "^^^^^^^^^^^^^^^^^^^^^ccccccXcccccccccc^^^^^^^^^^^^^^^^^";
  map[16] = "^^^^^^^^^^^^^^^^^^^^^^ccXccccXcccc^^^^^^^^^^^^^^^^^^^^^";
  map[17] = "^^^^^^^^^^^^^^^^^^^^ccccccXccc^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[18] = "^^^^^^^^^^^^^^^^^^^cccccc^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[19] = "^^^^^^^^^^^^^^^^?cc^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[20] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[21] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[22] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[23] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[24] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
 /*          123456789012345678901234567890123456789012345678901234567*/ 
 /*          0        10        20        30        40        50      */

  return map;

}


