inherit "room/room";
int unlocked = 0;
object monster01;

reset(arg) {

  if(arg) return;
    if (!monster01) {
        monster01 = clone_object("/wizards/ahma/castle/mob/mob18"); 
        move_object(monster01, this_object());
    }

  add_exit("down", "/wizards/ahma/castle/rooms/area09b");
  short_desc = "In the watch tower";
  long_desc = "The eastern watch tower of castle Lhavorak.\n" +
              "The watch tower is simply built room made of stone. There is a window on\n" + 
              "each wall to give view to all four main cardinal points. The tower is\n" + 
              "about 30 feet in height and from the windows it can be seen over long\n" + 
              "distances. The shutters from the western and northern windows have been\n" + 
              "torn off letting the wind blow soft gusts into the tower.\n" + 
              "The western window gives out to the beautiful city of Duranghom, and\n" + 
              "from the northern window can be seen the Forest of Despair, where a\n" + 
              "mythical Troll race is rumoured to live.\n" + 
              "There is a weapon cabinet located on the southern wall.\n";
  items = allocate(4);
  items[0] = "cabinet";
  items[1] = "The weapon cabinet is carved from sturdy oak-tree and the moving parts\n" + 
             "are from reinforced steel. The lock which is holding the two doors\n" + 
             "closed is made of sturdy looking iron. There is a keyhole on the lock";
  items[2] = "lock";
  items[3] = "In the lock seems to be stuffed some rubbish, making it impossible to open\n" + 
             "even if you would have a correct key";
}

init() {
  ::init();
  add_action("open", "open");
  add_action("unlock", "unlock");
}

open(str) {
  if(str == "cabinet" || str == "door") {
  write("The cabinet is locked tightly. You cannot open it.\n");
  }
}