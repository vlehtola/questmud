inherit "/room/map_daemon";

check_rooms(string str) {
  if (str == "b") return clone_object("/wizards/neophyte/island/beach");
  if (str == "h") return clone_object("/wizards/neophyte/island/hills");
  if (str == "p") return clone_object("/wizards/neophyte/island/plains");
  if (str == "r") return clone_object("/wizards/neophyte/island/river");
  if (str == "R") return clone_object("/wizards/neophyte/island/deep_river");
}

check_special_coords(x,y) {
  if(x == 3 && y == 12) return "/wizards/neophyte/city/entrance";
  return 0;
}


get_map() {
  map = allocate(8);
 /*          12345678901234567890123456789012345678901234567890 (exit 27 ja 26)*/
  map[0] =  "~~~~~~~~~~~~~~~~~~";
  map[1] =  "~~~~bbbbRbbbb~~~~~";
  map[2] =  "~~~bbhbbrbppb~~~~~";
  map[3] =  "~~~bbhhbrbp?pb~~~~";
  map[4] =  "~~~bbbbbRbbbbb~~~~";
  map[5] =  "~~~~b~b~~~bB~~~~~~";
  map[6] =  "~~~~~~~~~~~~~~~~~~";
  map[7] =  "~~~~~~~~~~~~~~~~~~";
  return map;
}
