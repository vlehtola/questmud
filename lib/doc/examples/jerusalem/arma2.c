inherit "room/room";
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/prostitute");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","wizards/nalle/jerusalem/arma1");
  add_exit("north","wizards/nalle/jerusalem/armb2");
  add_exit("east","wizards/nalle/jerusalem/arma3");
  short_desc = "Southern part of the Armenian Quarter";
  long_desc =
"This is southern part of the Armenian quarter of Jerusalem.\n" +
"The housing here is infamous for the pestilent creatures\n" +
"that lurk in peoples bedrooms spreading disease and death.\n" +           
"A couple of scantily clad prostitutes are huddled together\n" +
"around a monk, who seems to be lookiing for some carnal\n" +
"pleasures.\n";
}
 
init() {
    ::init();
   add_action("map", "map");
}
 
map(arg) {
    if (arg) {
        return 0;
    }
   cat("/wizards/nalle/jerusalem/amap");
   return 1;
}   


