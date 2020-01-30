inherit "/room/map_daemon";

check_rooms(string str) {
  if (str == "E") return clone_object("/wizards/gynter/darke/city/tunnels/etunnel");
  if (str == "s") return clone_object("/wizards/gynter/darke/city/tunnels/stunnel");
  if (str == "S") return clone_object("/wizards/gynter/darke/city/tunnels/stunnel2");
  if (str == "D") return clone_object("/wizards/gynter/darke/city/tunnels/dtunnel");
}

check_special_coords(x,y) {
  if(x == 30 && y == 6) return "/wizards/gynter/darke/city/Tcity";
  return 0;
}

get_map() {
   map = allocate(40);
  /*          0123456789012345678901234567890123456789012345678901234567890123456789 */
   map[0] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
   map[1] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
   map[2] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
   map[3] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
   map[4] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
   map[5] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
   map[6] =  "^^^^^^^^^^^^^^^^^^^^^^^s^^^^^^?^^^^^^^^ssssssssssssssD^^^^^^^^^^^^^^^^";
   map[7] =  "^^^^^^^^^^^^^^^^^^^^^^^s^^^^^^E^^^^^^^sssss^^^^^^^^^^^^^^^^^^^^^^^^^^^";
   map[8] =  "^^^^^^^^^^^^^^^^^^^^^^sss^^^^^E^^SSSSS^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
   map[9] =  "^^^^^^^^^^^^^^^^^^^^^^sss^^^^^E^^SSSSS^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[10] =  "^^^^^^^^^^^^^^^^^^^^^^s^sss^^^E^^^^s^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[11] =  "^^^^^^^^^^^^^^^^^^^^^ss^^^^s^E^ss^^s^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[12] =  "^^^^^^^^^^^^^^^^^^^^s^^^^^^^E^^^ss^s^^D^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[13] =  "^^^^^^^^^^^^^^^^^^^s^^^^^^^^E^^^^s^s^sss^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[14] =  "^^^^^^^^^^ssss^^^^s^^^^^^^^^E^^^D^sss^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[15] =  "^^^^^^^^^^ssssssss^^^^^^^^^^E^^^^^^s^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[16] =  "^^^^^^^^^^ssss^^s^^^^^^^^^^^D^^^^^ss^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[17] =  "^^^^^^^^^^^^^^^^s^^^^^^^^^^^^D^^^s^ss^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[18] =  "^^^^^^^^^^^^^^^^s^^^^^^^^DDDD^^^D^^s^s^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[19] =  "^^^^^^^^^^^^^^^^s^^^^^^^^D^DDD^^^^^s^^s^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[20] =  "^^^^^^^^^^^^^^^^s^^^^^^^DDD^D^D^^^SSS^^s^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[21] =  "^^^^^^^^^^^^^^^^s^^^D^^^^D^DDDD^^^SSS^^^SSSSSSSSSSSS^^^^^^^^^^^^^^^^^^";
  map[22] =  "^^^^^^^^^^^^^^^^s^^^^DDDD^^^D^^^^^SSS^^^SSSSSSSSSSSS^^^^^^^^^^^^^^^^^^";
  map[23] =  "^^^^^^^^^^^^^^^^s^^^^^^^D^^DD^^^^^SSS^^^SSSSSSSSSSSS^^^^^^^^^^^^^^^^^^";
  map[24] =  "^^^^^^^^^^^SSSSSSSSSSS^^^DD^^^^^^^SSS^^^SSSSSSSSSSSS^^^^^^^^^^^^^^^^^^";
  map[25] =  "^^^^^^^^^^^SSSSSSSSSSS^^^^^^^^^^^^^S^^^^SSSSSSSSSSSS^^^^^^^^^^^^^^^^^^";
  map[26] =  "^^^^^^^^^^^SSSSSSSSSSS^^SSSSSSS^SS^S^SS^SSSSSSSSSSSS^^^^^^^^^^^^^^^^^^";
  map[27] =  "^^^^^^^^^^^SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS^^^^^^^^^^^^^^^^^^";
  map[28] =  "^^^^^^^^^^^SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS^^^^^^^^^^^^^^^^^^";
  map[29] =  "^^^^^^^^^^^^^^SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS^^^^^^^^^^^^^^^^^^^^^";
  map[30] =  "^^^^^^^^^^^^^^^^^^^^SSSSSSSSSSSSSSSSSSSSSSS^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[31] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^SSSSS^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[32] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^S^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[33] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[34] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[35] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[36] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[37] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  map[38] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
  return map;
}