inherit "room/room";  
inherit "room/shop_d";

object monster; 

reset(arg) {
  ::reset(arg);
  if(!monster) {
    monster = clone_object("/wizards/nalle/jerusalem/monsters/eleini");
    move_object(monster, this_object());
  }
  if(arg) return;
  short_desc = "The El-Eini Store";
  long_desc = "You have entered a large room, with a long counter\n" +
              "and a man behind it at the end of the room. He is \n"+
              "one of the most important people of Jerusalem, thanks\n"+
              "to the great profits he makes with this store.\n"+
              "Available commands: list, buy <item>\n";
  add_exit("out", "/wizards/nalle/jerusalem/jewc3");
  /* mita on varastossa, kuinka paljon, min ja max */
  load_item("world/eq/torch",14,20);
  load_item("wizards/nalle/jerusalem/eq/bread",40,50);
  load_item("wizards/nalle/potion",10,12);
  load_item("wizards/nalle/potikka2",3,8);
  load_item("wizards/nalle/potikka3",3,8);
  
}
init() {
  ::init();
  ::shop_commands();
}
 






