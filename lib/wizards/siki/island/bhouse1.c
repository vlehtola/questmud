inherit "room/room";
object monster;

reset(arg) {
     if(arg) return;
    if(!monster) {
        monster = clone_object("/wizards/siki/island/monsters/houseguard");
        move_object(monster, this_object());
        }

  add_exit("south","/wizards/siki/island/v_map: 15 16");
  add_exit("north","/wizards/siki/island/v_map: 15 16");
  add_exit("east","/wizards/siki/island/v_map: 15 16");
  add_exit("west","/wizards/siki/island/v_map: 15 16");
  add_exit("enter","/wizards/celtron/ogremage/1");


  short_desc = "Infront of a wooden hut";
  long_desc = "A small wooden hut with a plat roof. The huge tree trunks are\n"+
              "covered with moss. There is nothing growing infront of the door, only\n"+
              "hard terrain.\n";


}
