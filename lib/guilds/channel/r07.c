inherit "room/room";

reset(arg) {

        if(arg) return;

  add_exit("north","/guilds/channel/r08");
  add_exit("east","/guilds/channel/r13");
  add_exit("south","/guilds/channel/r16");
  add_exit("west","/guilds/channel/r11");
  add_exit("down","/guilds/channel/r06");

  short_desc = "Huge hall";
  long_desc = "A huge and high hall. The ceiling raises high above your head and\n"+
              "it is full of religious paintings. There are small corridors in every\n"+
              "direction and they all look the same, holy symbols above them and white\n"+
              "marble pillars on both sides. Strange sticks attached to the pillars are\n"+
              "burning extremely brightly lighting the hall perfectly. A stairway leads\n"+
              "down to the first floor of the church of Cyral.\n"; 
              
  set_not_out(1);
  set_light(3);

  items = allocate(10);
  items[0] = "stairs";
  items[1] = "Stairs, made out of fine rock, leading upwards";
  items[2] = "pillars";
  items[3] = "Massive white pillars made out of fine marble";
  items[4] = "paintings";
  items[5] = "Colourful paintings of different religious heroes of the realm";
  items[6] = "symbols";
  items[7] = "Holy symbols of Cyral above the door openings";
  items[8] = "sticks";
  items[9] = "Burning white sticks attached to the pillars. They are burning brightly\n"+
             "and emitting a strong and sweet odor";


}


