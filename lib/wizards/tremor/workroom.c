inherit "room/room";

reset(arg) {
  if(arg) return;
short_desc = "Tremorin nyrkkipaja";
add_exit("cs","/world/city/cs");
add_exit("forest","/wizards/tremor/wood_elven_village/entrance");
long_desc = "Nyrkkipajassa on kaikilla lysti�.\n";
  set_light(1);
}
