inherit "obj/monster";

reset(arg) {

    int i;
    ::reset(arg);
    if(arg) { return; }
    i = random(30);
    if(i>0) {

    set_level(42);
    set_name("sea-gull");
    set_alias("gull");
    set_short("A small sea-gull eating a fish");
    set_long("A small sea-gull is standing on the ground and eating a fish. Its feathers\n"+
             "are brown and its head is white. Its nails are razor-sharp. The sea-gull's\n"+
             "wingspread is over one meters.\n");
    set_animal(1);
    set_aggressive(0);
    set_gender(0); 
    set_al(20);
        }
    if(i>5) {

    set_level(47);
    set_name("sea-gull");
    set_alias("gull");
    set_short("A medium sea-gull eating a fish");
    set_long("A medium sea-gull is standing on the ground and eating a fish. Its feathers\n"+
             "are black and its head is brown. Its nails are razor-sharp. The sea-gull's\n"+
             "wingspread is over one and a half meters.\n");
    set_animal(1);
    set_aggressive(0);
    set_gender(0);
    set_al(10);
      }


    if(i>15) {

    set_level(52);
    set_name("sea-gull");
    set_alias("gull");
    set_short("A big sea-gull eating a fish");
    set_long("A big sea-gull is standing on the ground and eating a fish. Its feathers\n"+
             "are white and its head is yellow. Its nails are razor-sharp. The sea-gull's\n"+
             "wingspread is over two meters.\n");
    set_animal(1);
    set_aggressive(1);
    set_gender(0);
    set_al(-10);
      }

    if(i==0) {

    set_level(57);
    set_name("sea-gull");
    set_alias("gull");
    set_short("A massive sea-gull eating a fish");
    set_long("A massive sea-gull is standing on the ground and eating a fish. Its feathers\n"+
             "are white and its head is black. Its nails are razor-sharp. The sea-gull's\n"+
             "wingspread is over three meters.\n");
    set_animal(1);
    set_aggressive(1);
    set_gender(0);
    set_al(-20);
 }
}
