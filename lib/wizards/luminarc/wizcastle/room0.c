inherit "room/room";

reset(arg) {
  if(arg) return;
  add_exit("north", "/wizards/luminarc/wizcastle/room1.c");
  add_exit("out", "outmap: 115 147");  
short_desc = "Drawbridge";
  long_desc = "The big beautiful stone castle raises here. Two towers\n"+
              "are rising on the eastern side of the building. The first\n"+
              "tower is bit lower than the second one and a huge streamer\n"+ 
              "has been placed on the top of the higher tower. Big white\n"+
              "birds are flying all around the castle and singing their\n"+
              "beautiful songs. The only way to get inside to the castle\n"+ 
              "is a small drawbridge, which is currently lowered. A wide\n"+
              "moat with dirty water in it is surrounding the castle.\n"; 
  set_light(3);
}








