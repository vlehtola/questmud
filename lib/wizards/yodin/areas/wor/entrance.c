inherit "room/room";

reset(arg) {
call_other("/wizards/yodin/areas/wor/virtual_map", "XX", 0);




 add_exit("north", "/wizards/yodin/areas/wor/virtual_map: 14 5");
add_exit("out", "?");

  short_desc = "Forest opening";
  long_desc =   "Trees are growing here and there, somewhat slowing\n"+
                "the your movement. You can see the sky above you\n"+
                "and hear the sounds of various animals. There is a\n"+
                "multitude of plants and other flora growing here.\n";
 

}
