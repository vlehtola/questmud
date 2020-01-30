inherit "room/room";
object monster, monster2;

reset(arg) {
  if(!monster) { 

    monster = clone_object("/wizards/tiergon/dungeon/monsters/bcfighter");
    move_object(monster,this_object()); }
  if(!monster2) {

    monster2 = clone_object("/wizards/tiergon/dungeon/monsters/bcfighter");
    move_object(monster2,this_object()); }   
    if(arg) return;
set_not_out(2);
add_exit("east","/wizards/tiergon/dungeon/3xroad");
add_exit("west","/wizards/tiergon/dungeon/b2");
  short_desc = "A new tunnel";
  long_desc = "The tunnel slopes smoothly downwards.\n"+
                "The walls are supernaturally smooth and look like they have been recently finished. They were probably made by the Black Circle wizards\n"+
                "The tunnel is lit by an eerie magical radiance.\n";
}
