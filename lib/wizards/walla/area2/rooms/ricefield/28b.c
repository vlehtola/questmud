inherit "room/room";
 
reset(arg) {
 
  add_exit("south","/wizards/walla/area2/rooms/ricefield/27");
  short_desc = "going down to the ricefield";
  long_desc =
"tanne\n" +
"tulossa\n" +
"iso\n" +
"pitka\n" +
"hieno desci joskus.\n";

} 
init() {
  ::init();
  add_action("push", "push");

}
 
push(str) {
  if(str != "symbol") return;
  write("As you push the symbol, a small crack appears in the wall.\n");
  say("A small crack appears in the wall.\n");
  add_exit("crack","/wizards/walla/workroom");
  return 1;
}
 

