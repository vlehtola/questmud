inherit "room/room";
object ob;
reset(arg) {
  if(arg) return;
  add_exit("west","/wizards/luminarc/wizcastle/room1");
  short_desc = "Eastern part of hall";
long_desc="Eastern side of the hall contains a big beautifully shaped mirror\n"+
          "which\ covers almost the whole wall. Two torches is placed on\n"+
          "both side of mirror. A long grass-like plant is groving on the\n"+ 
          "left side of the mirror.\n"; 
  set_light(3);
  ob = clone_object("/wizards/luminarc/wizcastle/humans/guard.c");
  move_object(ob, this_object());

items=allocate(6);
items[0]="mirror";
items[1]="This huge mirror covers almost the whole wall. It is well made";
items[2]="plant";
items[3]="This plant is very long. it reaches almost to the ceiling";
}




