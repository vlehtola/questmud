inherit "room/room";

reset(arg) {
call_other("/wizards/gynter/area3/virtual_map", "XX", 0);
  if(arg) return;
short_desc = "Gynter's areacollection";
long_desc = "Gynters collection of areas'.\n";
add_exit("workroom","/wizards/gynter/workroom");
add_exit("elem","/wizards/gynter/element/gateway.c");
add_exit("city1","/wizards/gynter/area2/city1/y");
add_exit("city2","/wizards/gynter/area2/city2/1");
add_exit("fig","/world/fighter/fighter");
add_exit("west","/wizards/gynter/area3/virtual_map: 9 15");
 add_exit("darke","/wizards/gynter/darke/entrance");
}
