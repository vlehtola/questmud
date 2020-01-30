inherit "/room/map_daemon";

check_rooms(string str) {
  if (str == "F") return clone_object("/wizards/yodin/areas/mardia/dense_forest");
if (str == "f") return clone_object("/wizards/yodin/areas/mardia/forest");
  if (str == "p") return clone_object("/wizards/yodin/areas/mardia/plains");
  if (str == "s") return clone_object("/wizards/yodin/areas/mardia/swamp");
  if (str == "H") return clone_object("/wizards/yodin/areas/mardia/high_hills");
  if (str == "h") return clone_object("/wizards/yodin/areas/mardia/hills");



}

check_special_coords(x,y) {
  if(x == 14 && y == 5) return "/wizards/yodin/areas/mardia/entrance.c";
 
  return 0;
}




get_map() {
  map = allocate(29);

 /*          1234567890123456789012345678901234567890*/
  map[0] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[1] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[2] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[3] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~p~~~~~~~p~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[4] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~p~~~~~~~p~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[5] =  "~~~~~~~~~~~~~~~~~~~~~~~?ff~~~~~~~p~~~~~~~p~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[6] =  "~~~~~~~~~~~~~~~~~~~~~fffff~~~~~~p~~~~~~~p~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[7] =  "~~~~~~~~~~~~~~~~~~~~ffffffffffffffffffff~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[8] =  "~~~~~~~~~~~~~~~~~~~~fffffffffpffffff~~~~p~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[9] =  "~~~~~~~~~~~~~~~~~~~~p~~~~~~~pfpffffff~~~~p~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[10] = "~~~~~~~~~~~~~~~~~~~p~~~~~~~p~~~p~~~~~p~~~~p~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[11] = "~~~~~~~~~~~~~~~~~~p~~~~~~~p~~~~~p~~~~~p~~~~p~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[12] = "~~~~~~~~~~~~~~~~~p~~~~~~~p~~~~~~~p~~~~~p~~~~p~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[13] = "~~~~~~~~~~~~~~~~p~~~~~~~p~~~~~~~~~p~~~~~p~~~~pp~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[14] = "~~~~~~~~~~~~~~~p~~~~~~~p~~~~~~~~~~~p~~~~~p~~~~p~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[15] = "~~~~~~~~~~~~~~p~~~~~~~p~~~~~~~~~~~~~p~~~~~p~~~~p~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[16] = "~~~~~~~~~~~~~p~~~~~~~p~~~~~~~~~~~~~~~p~~~~~p~~~~p~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[17] = "~~~~~~~~~~~~p~~~~~~~p~~~~~~~~~~~~~~~~~p~~~~~p~~~~p~~~~~~~~~~~~~~~~~~~~~~~~";
  map[18] = "~~~~~~~~~~~p~~~~~~~p~~~~~~~~~~~~~~~~~~~p~~~~~p~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[19] = "~~~~~~~~~~p~~~~~~~p~~~~~~~~~~~~~~~~~~~~~p~~~~~p~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[20] = "~~~~~~~~~~~~~~~~~p~~~~~~~~~~~~~~~~~~~~~~~p~~~~~p~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[21] = "~~~~~~~~~~~~~~~~p~~~~~~~~~~~~~~~~~~~~~~~~~p~~~~~p~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[22] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~p~~~~~~~~~~~~~~~~~~~~~~~~";
  map[23] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[24] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[25] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[26] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[27] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[28] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  return map;
}
