inherit "room/room";
object monster, monster2;

reset(arg) {
  if(!monster) { 

    monster = clone_object("/wizards/tiergon/dungeon/monsters/miner1");
    move_object(monster,this_object()); }
  if(!monster2) {

    monster2 = clone_object("/wizards/tiergon/dungeon/monsters/miner2");
    move_object(monster2,this_object()); }   
    if(arg) return;
set_not_out(1);
add_exit("north","/wizards/tiergon/dungeon/1xroad");
add_exit("south","/wizards/tiergon/dungeon/entrance");
  short_desc = "Just inside the mining tunnel";
  long_desc = "The tunnel slopes smoothly downwards.\n"+
                "As you examine the smooth gray walls you decide that the people who originally designed this gold mine must have been geniuses.\n";
}
