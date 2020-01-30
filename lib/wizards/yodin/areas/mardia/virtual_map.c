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
  if(x == 26 && y == 21) return "/wizards/yodin/areas/mardia/entrance.c";
  if(x == 11 && y == 4) return "/wizards/yodin/areas/mardia/entrance2.c";
  if(x == 59 && y == 5) return "/wizards/yodin/areas/mardia/entrance3.c";
  return 0;
}


get_map() {
  map = allocate(29);

 /*          1234567890123456789012345678901234567890*/
  map[0] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~R~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[1] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~RR~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[2] =  "~~~~~~~~~HHHH^^^HHHhhhhhhhhhhhhRRRFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF~~~~~~~~";
  map[3] =  "~~~~~~HHHHHH^^^H^^^hhhhhhhhhhhRRRFFFFFFFFFFFFFFFFFFFFFFFFssssss~~~~~~~~~~~";
  map[4] =  "~~~~~~HHHHf?^^^HHH^hhhh^hhhhhRRRFFFFFFFFFFFFFFFFFFssssssssssss~~~~~~~~~~~~";
  map[5] =  "~~HHHH^^^HH^^HH^^^hhhhh^hhhhRRFFFFFFFFFFFpppFFFFFFsssssssss?ssss~~~~~~~~~~";
  map[6] =  "~~~HHHHHHHHHHHHH^hhhhhhhhhhRRFFFFFFFFFFFppppppFFFssssssssssssssss~~~~~~~~~";
  map[7] =  "~~~~~~hhhhhhhhhhhhhhhhh^RRRRRFFFFFFFFFFpppppppppFFsssssssssssssss~~~~~~~~~";
  map[8] =  "RRRRRRRRRRRRFRRRRRRRRRRRR^FFFFFFFFFFFFFpppppppppFFsssssssssssssss~~~~~~~~~";
  map[9] =  "RRRRRRRRRRRRFRRRRRFFRRRRFFFFFFFFFFFFFpppppppppFFFFFFssssssssssss~~~~~~~~~~";
  map[10] = "~~~~~~~~~~~~FFFFFFFFFFFFFFFFFFFFFFFFpppppppppFFFFFssssssssssssssss~~~~~~~~";
  map[11] = "~~~~~~~~~FFFFFFFFFFFFFFFFFFFFFFFFFFppppppppppFFFFFFFssssssssssss~~~~~~~~~~";
  map[12] = "~~~~~~~FFFLLFFFFFFFFFFFFFFFFFFFFFFFFppppppFFFFFFFFFFFFFFFFFFFFFFFFFFF~~~~~";
  map[13] = "~~~~~~FFFLLLLFFFFFFFFFFFFFFFFFFFFFFFFpppppppppFFFFFFFFFFFFFFFFFFFFFFFFF~~~";
  map[14] = "~~~~~~FFLLLLFFFFFFFFFFFFFFFFFFFFFFFFFFFppppppFFFFFFFFFFFFFFFFFFFFFFFFF~~~~";
  map[15] = "~~~~~FFFLLLFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFppppppppFFFFFFFFFFFFF~~~~~~~~~~~~";
  map[16] = "~~~~FFFLLLLFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF~~~";
  map[17] = "~~FFFFFFLrFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF~~~";
  map[18] = "~~FFFFFFFFrFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF~~~~~~~";
  map[19] = "~~FFFFFFFFrrrrFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF~~~";
  map[20] = "~~FFFFFFFFfrrrFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF~~~";
  map[21] = "~~ffffffffpppfffffffffffff?fffffffFFFFFFFFFFFFFFFFFFFfffffffFFfffff~~~~~~~";
  map[22] = "~~FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF~~~~~~~~";
  map[23] = "~~FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF~~~~~~~~FFFFFFFFFFFFFFFFFFF~~~~~~~~";
  map[24] = "~~~~~~~~FFF~~~~~~FFFF~~~~~~~~~~~~~~~~~~~~~~~~~~~FFFFFFFFFFFFFFFFFF~~~~~~~~";
  map[25] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[26] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[27] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  map[28] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  return map;
}
