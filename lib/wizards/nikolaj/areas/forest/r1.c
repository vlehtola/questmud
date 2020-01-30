inherit "room/room";
#define AREA "/wizards/nikolaj/areas/forest/"

reset(arg) {
  add_exit("out","/wizards/nikolaj/workroom.c");
  add_exit("north",AREA+"r2.c");
  add_exit("northwest",AREA+"r3.c");

  short_desc = "Entrance to the forest";
  long_desc = "First impression of this place is breath-taking. Huge mossclad oaktrees are growing "+
              "everywhere, the treetops hardly let any light in. Although nothing living is seen, "+
              "the scratch and rustle in the ground and trees speak for themselves. Seagulls are "+
              "screaming at the skies, maybe there's water somewhere near.\n";
             
  items = allocate(16);
  items[0] = "oaks";
  items[1] = "These oaktrees seems to be considerably old. "+
             "The bark is very thick and covered with moss";
  items[2] = "trees";
  items[3] = "These oaktrees seems to be considerably old. "+
             "The bark is very thick and covered with moss";
  items[4] = "oaktrees";
  items[5] = "These oaktrees seems to be considerably old. "+
             "The bark is very thick and covered with moss";
  items[6] = "treetops";
  items[7] = "Treetops are high above you, "+
             "they are hardly letting any light in";
  items[8] = "animals";
  items[9] = "They cannot actually be seen, "+
             "but all those noises around tell that "+
             "lots of animals are hiding somewhere here";
  items[10] = "ground";
  items[11] = "Ground is covered with vegetation, fallen branches and dead leaves";
  items[12] = "seagulls";
  items[13] = "Seagulls are flying somewhere high above the forest. "+
              "They are hard to spot from here, since the treetops block the sight";
  items[14] = "bark";
  items[15] = "Bark of the trees is considerably thick. "+
              "Trees must have grown for ages here";
}

