inherit "room/room";

reset(arg) {
  if(arg) return;
  add_exit("east","/wizards/luminarc/wizcastle/upwest1");
  add_exit("down","/wizards/luminarc/wizcastle/basem");  
  add_exit("up","/wizards/luminarc/wizcastle/kitchen");
  short_desc = "Corridor";
  long_desc = "The small hall opens here. Ladders are leading to up and down.\n"+
              "Window on west wall gives small amount of light to room. Someone\n"+ 
              "is cooking food near by. An crystal item is hanging from the roof\n";
  property = allocate(1);
  set_light(3);
  items=allocate(4);
  items[0]="item";
  items[1]="This items looks pretty nice. Hundreds of crystal spliters are hanging from it. The light effect they create when the light beam hits on them is very beautiful";
}

