inherit "room/room";

reset(arg) {

  if(arg) return;
  add_exit("east","out: 175 95");
  add_exit("north","out: 175 95");
  add_exit("west","out: 175 95");
  add_exit("enter","/guilds/abjurer/corridor");

  short_desc = "The tower of Abjuration";
  long_desc = 
"A massive castle-like tower raises high infront of you. It raises high,\n"+
"even higher than the mountains behind it. A path made out of flat rocks\n"+
"leads inside the tower. Huge stone double doors are open and a bright\n"+
"light comes from the tower. It seems to glow warmth and harmony.\n";

}
