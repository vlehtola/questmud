inherit "room/room";
init() {
  ::init();
  add_action("leap", "leap");
}
 
leap(str) {
  if(str != "window") return;
  write("Tama texti tulee playerille.\n");
  say(""+this_player()->query_name()+" tekee jotain huoneessa, siis taa teksti tulee.\n");
  move_object(this_player(),"/wizards/walla/huone/johon/ikkuna/vie");
  command("look");
  return 1;
}
 
 
  reset(arg) {
  add_exit("north","/wizards/jenny/huone/x");
  add_exit("south","/wizards/jenny/huone/y");
   short_desc = "shortdesc";
  long_desc =
"tanne sit kirjotat\n" +
"kaikkee pienta salaa ja skeidaa\n" +
"esim etta tossa vasemmassa kulmassa niin loytyy pienehko ikkuna\n" +
"siita voipi hypata ulos?.\n";
 
 
}
