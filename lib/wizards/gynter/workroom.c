inherit "room/room";

reset(arg) {
  if(arg) return;
  short_desc = "Gynter's workroom";
  long_desc = "Gynter's Workroom\n";
  add_exit("cs","/world/city/cs");
  add_exit("inn","/world/city/inn");
  add_exit("post","/world/city/post");
  add_exit("guild","/world/city/innstabl");
  add_exit("marriage","/wizards/nalle/marriage/marriage_room");
  add_exit("banroom","/room/banroom");
  add_exit("eventroom","/wizards/siki/event_room");
add_exit("areas","/wizards/gynter/areas");
}
