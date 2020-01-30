inherit "room/room"; object ob; reset(arg) {
  if(arg) return;
  add_exit("east","/wizards/luminarc/wizcastle/room1");
  short_desc = "Western part of hall";
long_desc="The western side of the mainhall looks like a weapon gallery. Walls\n" +
          "are full of all kinds of weapons; Swords, hammers, axes. Two big torches\n" +
          "give a nice and warm feeling to this place. In the middle of everything\n" +
          "there is a big silver shield, which shines strangely while the torces\n"+ 
          "flicker on the wall.\n"; 
  property = allocate(1);
  set_light(3);
items = allocate(4);
items[0]="shield";
items[1]="A well crafted silver shield. There are some strange runes embedded in it";
items[2]="runes";
items[3]="These old runes looks pretty dusty. Maybe you should rub them";
ob = clone_object("/wizards/luminarc/wizcastle/humans/guard.c");
move_object(ob, this_object());
ob = clone_object("/wizards/luminarc/wizcastle/humans/guard.c");
move_object(ob, this_object());
}
init() {
  ::init();
  add_action("rub", "rub"); 
}
rub(str) {
  if(str == "runes") {
        write("You feel dizzy..\n");
        this_player()->move_player("XX#/wizards/luminarc/wizcastle/round");
        return 1;
  }
}
