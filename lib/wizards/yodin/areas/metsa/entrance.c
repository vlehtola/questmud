inherit "room/room";

reset(arg) {
call_other("/wizards/yodin/areas/metsa/virtual_map", "XX", 0);




  add_exit("north", "/wizards/yodin/areas/metsa/virtual_map: 28 23");
add_exit("out", "/wizards/yodin/areas/windmill/wm1.c");

  short_desc = "Large forest";
  long_desc =   "Trees are growing here and there, somewhat slowing\n"+
                "the your movement. You can see the sky above you\n"+
              "and hear the sounds of various animals. There is a\n"+
"multitude of plants and other flora growing here.\n";

}
