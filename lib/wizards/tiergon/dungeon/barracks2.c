inherit "room/room";
object monster, monster2, monster3;

reset(arg) {
  if(!monster) { 

    monster = clone_object("/wizards/tiergon/dungeon/monsters/miner1");
    move_object(monster,this_object()); }
  if(!monster2) {

    monster2 = clone_object("/wizards/tiergon/dungeon/monsters/miner2");
    move_object(monster2,this_object()); }   
  if(!monster3) {
    monster3 = clone_object("/wizards/tiergon/dungeon/monsters/miner3");
    move_object(monster3,this_object()); }
  if(arg) return;
set_not_out(1);
add_exit("east","/wizards/tiergon/dungeon/2xroad");
  short_desc = "In the barracks";
  long_desc = "This room's walls have been covered with wood to keep the heat in better.\n"+
              "There  are two rows of seven beds. Several are covered with blood\n";
}
